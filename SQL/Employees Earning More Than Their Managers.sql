# Write your MySQL query statement below
Select E2.Name as Employee 
FROM Employee AS E1 INNER JOIN Employee AS E2
    ON E1.Id = E2.ManagerId 
    WHERE E1.Salary < E2.Salary;
