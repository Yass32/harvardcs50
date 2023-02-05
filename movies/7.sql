--write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating.
--For movies with the same rating, order them alphabetically by title
SELECT title FROM movies WHERE year = 2010
SELECT rating FROM ratings 