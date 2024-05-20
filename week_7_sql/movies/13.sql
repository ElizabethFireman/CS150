--SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- find kevin bacon id
-- find id of movies kevin bacon stared in
-- find a list of ids of people with same movie ids
-- find names of people
SELECT DISTINCT name
FROM people
WHERE id IN (
    SELECT DISTINCT person_id
    FROM stars
    WHERE movie_id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id IN (
    SELECT id
    FROM people
    WHERE name = 'Kevin Bacon'))
)
AND name != 'Kevin Bacon';



