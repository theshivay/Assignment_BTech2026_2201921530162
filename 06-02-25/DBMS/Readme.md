# 596. Classes More Than 5 Students - Leetcode  

## Problem Statement  
Given a `Courses` table with `student` and `class` columns, find all classes that have at least 5 students.  

## Coding Platform  
- Leetcode  

## Approach & Solution  
1. Use `GROUP BY class` to group students based on their class.  
2. Use `HAVING COUNT(class) >= 5` to filter classes that have 5 or more students.  

## SQL Query  
```sql
# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(class) >= 5;
```

## Complexity Analysis
- **Time Complexity** : O(n) (scanning the table and grouping data)
- **Space Complexity** : O(1) (constant extra space)

