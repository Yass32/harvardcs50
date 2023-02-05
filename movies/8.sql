--write a SQL query to list the names of all people who starred in Toy Story
SELECT person_id FROM stars WHERE movie_id IN ()

SELECT id FROM movies WHERE title = 'Toy Story'

SELECT name from songs WHERE artist_id IN (SELECT id  FROM artists WHERE name = 'Post Malone');