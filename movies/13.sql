--write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred

SELECT name FROM people WHERE id IN (
    SELECT person_id WHERE movies_id IN (
        SELECT movies_id FROM stars WHERE people_id IN (
        SELECT id FROM people WHERE name = 'Kevin Bacon' )
        INTERSECT
        SELECT movies_id FROM stars WHERE people_id IN (
        SELECT id FROM people )
    )
);