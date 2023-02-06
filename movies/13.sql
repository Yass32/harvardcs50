--write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred

SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958

SELECT movies_id FROM stars WHERE person_id IN

