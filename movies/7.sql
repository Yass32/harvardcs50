--write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating.
--For movies with the same rating, order them alphabetically by title
CREATE TABLE TestTable AS
SELECT customername, contactname
FROM customers;

CREATE TABLE NewTable AS
SELECT title FROM movies WHERE year = 2010 ORDER BY title AS titles1
SELECT rating FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2010) ORDER BY rating DESC AS ratings1;