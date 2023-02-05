--write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating.
--For movies with the same rating, order them alphabetically by title

SELECT movies.title, ratings.rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
ORDER BY ratings.rating DESC, movies.title;


--(SELECT title AS titles1 FROM movies WHERE year = 2010)
--UNION
--(SELECT rating AS ratings1 FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2010))
--ORDER BY rating DESC, title;
