--write a SQL query that returns the average energy of songs that are by Drake
SELECT AVG(energy) from songs WHERE artist_id IN (SELECT id  FROM artists WHERE name = 'Drake');