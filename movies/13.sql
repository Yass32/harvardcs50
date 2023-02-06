--write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred

SELECT name from people WHERE id IN (
    SELECT DISTINCT person_id FROM stars WHERE movie_id IN(
        SELECT movie_id FROM stars WHERE person_id IN (
            SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958
        )
    )
);

SELECT name
FROM people JOIN stars ON stars.person_id = people.id
WHERE id IN (
    SELECT person_id FROM stars WHERE movie_id IN(
        SELECT movie_id FROM stars WHERE person_id IN (
            SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958
        )
    )
);
SELECT name FROM people WHERE name != "Kevin Bacon" AND id IN
(SELECT DISTINCT person_id FROM stars WHERE movie_id IN
(SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = "1958")));
