-- Keep a log of any SQL queries you execute as you solve the mystery.
--NEED: NAME from PEOPLE TABLE- phone, passport, LP, and person ID
-- Understand the crime
SELECT description
FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2023
AND street = 'Humphrey Street';
--Find who was interviewed and what they had to say about the theft- look for interviews taht mention bakery
SELECT id, name, transcript
FROM interviews
WHERE day = 28 AND month = 7
AND transcript LIKE '%bakery%';
-- start by looking into the footage from the bakery (get a short list)
SELECT license_plate
FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute > 15 AND minute < 30
AND activity = 'exit';

-- look into atm transaction to get account number (short list of #)
SELECT account_number, person_id
FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2023
AND atm_location = 'Leggett Street';

-- look into phone logs to try to get some phone numbers
SELECT caller
FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2023
AND duration < 60;

--Find potential flights
SELECT id,
FROM flights
WHERE origin_airport_id IN (
    SELECT id
    FROM airports
    WHERE city = 'Fiftyville'
)
AND day = 29 AND month = 7 AND year = 2023
ORDER BY hour
LIMIT 1;

-- get short list of passport numbers
SELECT passport_number
FROM passengers
WHERE flight_id = 36;

-- Find name of thief and id of thief
SELECT name, id
FROM people
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE day = 28 AND month = 7 AND year = 2023
    AND duration < 60
)
AND passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = 36
)
AND license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute > 15 AND minute < 30
    AND activity = 'exit'
)
AND id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE day = 28 AND month = 7 AND year = 2023
    AND atm_location = 'Leggett Street')

);
-- narrow down the thief from 3 to 1 useing atm information
SELECT person_id
FROM bank_accounts
WHERE account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE day = 28 AND month = 7 AND year = 2023
    AND atm_location = 'Leggett Street'
);
-- Find city Bruce went to
SELECT destination_airport_id
FROM flights
    WHERE origin_airport_id IN (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
        )
    AND day = 29 AND month = 7 AND year = 2023
    ORDER BY hour
    LIMIT 1;
-- Find airpoort name
SELECT full_name
FROM airports
WHERE id = 4;
-- Find accomplice
SELECT receiver
FROM phone_calls
WHERE caller = (
    SELECT phone_number
    FROM people
    where id = (
        SELECT id
        FROM people
        WHERE phone_number IN (
            SELECT caller
            FROM phone_calls
            WHERE day = 28 AND month = 7 AND year = 2023
            AND duration < 60)
            AND passport_number IN (
            SELECT passport_number
            FROM passengers
            WHERE flight_id = 36)
            AND license_plate IN (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute > 15 AND minute < 30
            AND activity = 'exit')
            AND id IN (
            SELECT person_id
            FROM bank_accounts
            WHERE account_number IN (
            SELECT account_number
            FROM atm_transactions
            WHERE day = 28 AND month = 7 AND year = 2023
            AND atm_location = 'Leggett Street'))
    )
    AND day = 28 AND month = 7 AND year = 2023
    AND duration < 60
);
-- Find name of person using phone number
SELECT name
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE caller = (
        SELECT phone_number
        FROM people
        where id = (
            SELECT id
            FROM people
            WHERE phone_number IN (
            SELECT caller
            FROM phone_calls
            WHERE day = 28 AND month = 7 AND year = 2023
            AND duration < 60)
            AND passport_number IN (
            SELECT passport_number
            FROM passengers
            WHERE flight_id = 36)
            AND license_plate IN (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute > 15 AND minute < 30
            AND activity = 'exit')
            AND id IN (
            SELECT person_id
            FROM bank_accounts
            WHERE account_number IN (
            SELECT account_number
            FROM atm_transactions
            WHERE day = 28 AND month = 7 AND year = 2023
            AND atm_location = 'Leggett Street')))
    AND day = 28 AND month = 7 AND year = 2023
    AND duration < 60)

);
