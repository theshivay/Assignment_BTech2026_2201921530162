# 182. Duplicate Emails - Leetcode 

## Problem Statement
Write a SQL query to find all duplicate emails in a table named `Person`.

### Table Schema
The `Person` table is defined as follows:
```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| Id          | int     |
| Email       | varchar |
+-------------+---------+
Id is the primary key column for this table.
```
### Example
**Input:**
```
+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | a@example.com    |
| 2  | b@example.com    |
| 3  | a@example.com    |
+----+------------------+
```
**Output:**
```
+------------------+
| Email            |
+------------------+
| a@example.com    |
+------------------+
```

---

## Platform
Solved on **Leetcode**: [Duplicate Emails](https://leetcode.com/problems/duplicate-emails/)

---

## Approach

### Using GROUP BY and HAVING Clause
**Algorithm:**
1. Group the rows by the `Email` column.
2. Use the `HAVING` clause to filter groups where the count of emails is greater than 1.
3. Select the `Email` column from the filtered groups.

**Code:**
```sql
# Write your MySQL query statement below
SELECT email AS Email
FROM Person
GROUP BY Email
HAVING COUNT(*) > 1;
```

**Explanation:**
- `GROUP BY Email`: Groups rows with the same email.
- `HAVING COUNT(*) > 1`: Ensures that only emails appearing more than once are included.
- `SELECT Email`: Outputs the duplicate emails.

**Time Complexity:** O(n) (where n is the number of rows in the table)  
**Space Complexity:** O(1) (no additional storage is used apart from the result set)

---

