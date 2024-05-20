--SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
--directors, ratings, people

SELECT DISTINCT name
FROM people
WHERE id IN (
    SELECT directors.person_id
    FROM directors
    WHERE directors.movie_id IN (
        SELECT ratings.movie_id
        FROM ratings
        WHERE rating >= '9.0'))
