import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Error: incorrect number of arguments")
        sys.exit(1)

    # Open and Read database file into a variable
    str_counts = []

    with open(sys.argv[1], newline='') as str_file:
        str_reader = csv.DictReader(str_file)
        for person in str_reader:
            str_counts.append(person)
    # print(str_counts)

    # Open and Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as dna_file:
        dna_sequence = dna_file.readline()
        # print(dna_sequence)

    # Find longest match of each STR in DNA sequence calling the longest_match function
    first_dict = str_counts[0]
    sub_sequences = list(first_dict.keys())[1:]
    # print(sub_sequences)

    longest_sequence = {}
    for sub_sequence in sub_sequences:
        longest_sequence[sub_sequence] = longest_match(dna_sequence, sub_sequence)
    # print(longest_sequence)

    # Check database for matching profiles
    match_found = False
    for each_str_count in str_counts:
        keys = list(each_str_count.keys())[1:]
        if all(int(each_str_count[key]) == int(longest_sequence[key]) for key in keys):
            print(each_str_count['name'])
            match_found = True
    if not match_found:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
