# Write your MySQL query statement below
SELECT emp.employee_id, emp.name, COUNT(mang.employee_id) AS reports_count, ROUND(AVG(mang.age),0) AS average_age
FROM Employees emp
JOIN Employees mang
ON emp.employee_id = mang.reports_to
GROUP BY employee_id 
ORDER BY employee_id