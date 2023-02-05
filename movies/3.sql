--write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order
SELECT title FROM movies
   ...> Where year >= 2018
   ...> ORDER BY title;