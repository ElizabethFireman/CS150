--SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in,
--starting with the highest rated
-- movies, ratings, people, stars
SELECT title
FROM movies
LEFT JOIN ratings on movies.id = ratings.movie_id
WHERE id IN (
    SELECT stars.movie_id
    FROM stars
    WHERE stars.person_id IN (
        SELECT people.id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
)
ORDER BY rating DESC
LIMIT 5;

