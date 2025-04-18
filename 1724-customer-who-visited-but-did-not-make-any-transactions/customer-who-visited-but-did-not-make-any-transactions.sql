# Write your MySQL query statement below

SELECT CUSTOMER_ID , COUNT(CUSTOMER_ID) AS COUNT_NO_TRANS
FROM VISITS  AS V LEFT JOIN TRANSACTIONS AS T
ON V.VISIT_ID = T.VISIT_ID
WHERE ISNULL(TRANSACTION_ID)
GROUP BY CUSTOMER_ID;
