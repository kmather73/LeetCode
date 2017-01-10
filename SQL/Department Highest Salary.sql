# Write your MySQL query statement below
SELECT Department.Name as Department, Employee.Name as Employee, Salary
FROM Employee INNER JOIN Department
ON Employee.DepartmentId = Department.Id
WHERE  (DepartmentId, Salary) in 
    (SELECT DepartmentId, max(Salary) as Salary 
     FROM Employee GROUP BY DepartmentId);
