SELECT id, name, salary,
    CASE WHEN sex = 'f' THEN 'm' ELSE 'f' END AS sex
    FROM salary
