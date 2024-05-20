--SQL query that returns the average energy of songs that are by Drake
SELECT ROUND(AVG(energy),2)
FROM songs
JOIN artists ON artists.id = songs.artist_id
WHERE artists.name = 'Drake';

