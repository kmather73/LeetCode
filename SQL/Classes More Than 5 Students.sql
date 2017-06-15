SELECT class FROM 
    (SELECT student, class, count(DISTINCT student, class) as Counts 
        FROM courses
        GROUP BY class) as T
    WHERE T.Counts >= 5
