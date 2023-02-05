--write a SQL query to list the titles of the five highest rated movies (in order)
--that Chadwick Boseman starred in, starting with the highest rated.

SELECT name FROM people
    WHERE id IN (
    SELECT person_id FROM directors
    WHERE movie_id IN (
    SELECT movie_id FROM ratings
    WHERE movie_id IN (SELECT title FROM movies) AND rating >= 9.0
    ));

    SELECT title FROM movies
    WHERE id IN (
    SELECT person_id FROM directors
    WHERE movie_id IN (
    SELECT movie_id FROM ratings
    WHERE movie_id IN (SELECT title FROM movies) AND rating >= 9.0
    ));