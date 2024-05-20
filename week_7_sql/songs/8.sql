--SQL query that lists the names of the songs that feature other artists (use like and the % cause that says where you can match things)
SELECT name
FROM songs
WHERE name LIKE '%feat.%';

