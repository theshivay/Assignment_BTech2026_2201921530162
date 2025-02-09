# 1211. Queries Quality and Percentage - Leetcode

## Problem Statement
Given a table `Queries` with columns `query_name`, `rating`, and `position`, write an SQL query to calculate:
1. **Quality**: The average of `rating/position` for each `query_name`, rounded to two decimal places.
2. **Poor Query Percentage**: The percentage of queries with a rating lower than 3 for each `query_name`, rounded to two decimal places.

## Coding Platform
- Leetcode

## Approach & Solution
1. Use `SUM(rating/position) / COUNT(rating)` to calculate the quality of each query.
2. Use `SUM(rating < 3) / COUNT(*) * 100` to calculate the percentage of poor queries.
3. Use `ROUND()` to ensure values are rounded to two decimal places.
4. Group by `query_name` to get results for each unique query.

**SQL Query:**
```sql
select query_name,
round((sum(rating/position)/count(rating)),2) as quality, 
round((sum(case when rating < 3 then 1 else 0 end)/(count(*)))*100,2) as poor_query_percentage
from Queries
group by query_name;
```

## Complexity Analysis
- **Time Complexity**: O(n) (Single scan with aggregation operations)
- **Space Complexity**: O(1) (Constant space usage)

