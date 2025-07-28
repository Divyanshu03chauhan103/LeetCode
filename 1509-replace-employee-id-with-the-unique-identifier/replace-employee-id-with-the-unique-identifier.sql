# Write your MySQL query statement below
SELECT B.UNIQUE_ID, A.NAME FROM EMPLOYEES AS A
LEFT JOIN EmployeeUNI AS B 
ON A.ID=B.ID;