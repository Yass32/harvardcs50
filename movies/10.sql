--write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0
SELECT name FROM people
    WHERE id IN (
    SELECT person_id FROM stars
    WHERE movie_id IN (SELECT id FROM movies WHERE year = 2004)
    ) ORDER BY birth;