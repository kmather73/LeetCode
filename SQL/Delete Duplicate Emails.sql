# Write your MySQL query statement below
DELETE P
FROM Person P, Person Q
WHERE P.Email = Q.Email AND Q.Id < P.Id
