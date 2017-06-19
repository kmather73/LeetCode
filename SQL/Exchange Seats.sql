SELECT id - 1 as id, student FROM seat
        WHERE id % 2 = 0
UNION
    SELECT id + 1 as id, student FROM seat
        WHERE id % 2 = 1 AND
         id NOT IN
            (SELECT S1.id as id
                FROM seat as S1 join (select max(id) as id FROM seat) as S2
                WHERE S1.id % 2 = 1 and S1.id = S2.id ) 
        
UNION 
    SELECT S1.id as id, S1.student 
    FROM seat as S1 join (select max(id) as id, student FROM seat) as S2
        WHERE S1.id % 2 = 1 and S1.id = S2.id
        
ORDER BY id
