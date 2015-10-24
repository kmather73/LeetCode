# Write your MySQL query statement below
SELECT Name 
FROM Customers 
LEFT OUTER JOIN Orders 
ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId is NULL
