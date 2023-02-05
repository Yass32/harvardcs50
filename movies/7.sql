--write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating.
--For movies with the same rating, order them alphabetically by title
CREATE TABLE TestTable AS
SELECT customername, contactname
FROM customers;

CREATE TABLE NewTable AS
(SELECT title AS titles1 FROM movies WHERE year = 2010 ORDER BY title )
(SELECT rating AS ratings1 FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2010) ORDER BY rating DESC) ;

CREATE TABLE new_table AS
SELECT titles1, ratings1
FROM movies
JOIN ratings;
--ON table1.column = table2.column;