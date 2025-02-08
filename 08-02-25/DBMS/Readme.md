# 610. Triangle Judgement - Leetcode

## Problem Statement
Given a table `Triangle` with three columns `x`, `y`, and `z`, representing the lengths of a triangle's sides, write an SQL query to determine if these sides can form a valid triangle. If they can, return 'Yes'; otherwise, return 'No'.

## Coding Platform
- Leetcode

## Approach & Solution
1. The triangle inequality theorem states that for three sides to form a valid triangle:
   - `x + y > z`
   - `y + z > x`
   - `z + x > y`
2. Use a `CASE` statement in SQL to check these conditions.
3. If all conditions hold, return 'Yes'; otherwise, return 'No'.

**SQL Query:**
```sql
-- Write your MySQL query statement below
SELECT x, y, z,
CASE
    WHEN x + y > z AND y + z > x AND z + x > y THEN 'Yes'
    ELSE 'No'
END AS triangle
FROM Triangle;
```

## Complexity Analysis
- **Time Complexity**: O(n) (since we are processing each row once)
- **Space Complexity**: O(1) (constant space usage)

