# 577. Employee Bonus - Leetcode  

## Problem Statement  
Given two tables, `Employee` and `Bonus`, write a SQL query to find the names and bonuses of employees who have a bonus less than 1000 or do not have a bonus at all.  

## Coding Platform  
- Leetcode  

## Approach & Solution  
1. Perform a `LEFT JOIN` between the `Employee` table and the `Bonus` table using `empId`.  
2. Select the employee's name and bonus.  
3. Use `WHERE` to filter employees whose bonus is either less than 1000 or `NULL` (i.e., they have no bonus).  

**SQL Query:**  
```sql
select a.name, b.bonus
from Employee a 
left join Bonus b on a.empId = b.empId
where b.bonus < 1000 or b.bonus is null;
```

## Complexity Analysis  
- **Time Complexity**: O(n) (depends on the number of employees and bonuses)  
- **Space Complexity**: O(1) (query runs in constant space)  