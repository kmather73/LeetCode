# Write your MySQL query statement below
SELECT W1.Id 
FROM Weather as W1 LEFT JOIN Weather as W2 
ON TO_DAYS(W1.Date) = TO_DAYS(W2.Date) + 1
WHERE W1.Temperature > W2.Temperature
