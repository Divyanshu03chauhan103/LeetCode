# Write your MySQL query statement below
SELECT * ,
    CASE
        WHEN X+Y>Z AND X+Z>Y AND Y+Z>X THEN 'Yes'
        ELSE 'No'
    END
    TRIANGLE
FROM TRIANGLE;
