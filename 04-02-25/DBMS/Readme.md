# 197. Rising Temperature - Leetcode

## Problem Statement
Given a `Weather` table, find all dates where the temperature is higher than the previous day.

### Example:
**Input:**
```
| id | recordDate | temperature |
|----|------------|-------------|
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
```
**Output:**
```
| id |
|----|
| 2  |
| 4  |
```

---

## Platform
Solved on **Leetcode**: [Rising Temperature](https://leetcode.com/problems/rising-temperature/)

---

## Approach

### SQL Query Explanation
**Query:**
```sql
SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 
AND w1.temperature > w2.temperature;
```

**Explanation:**
1. The query joins the `Weather` table with itself (`w1` and `w2`).
2. It checks if `w1.recordDate` is exactly one day after `w2.recordDate`.
3. It filters the results where `w1.temperature` is greater than `w2.temperature`.
4. The query returns the `id` of records meeting this condition.

**Time Complexity:** O(n²) (Self-join operation)  
**Space Complexity:** O(1) (No additional storage used)

---

