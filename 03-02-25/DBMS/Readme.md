# 595. Big Countries - Leetcode

## Problem Statement
Given a table `World`, write an SQL query to find all countries with an area of at least 3,000,000 km² or a population of at least 25,000,000.

### Example:
**Input Table:**
```
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan | 38928346   | 652230  |
| Canada      | 37742154   | 9984670 |
| China       | 1439323776 | 9596961 |
| India       | 1380004385 | 3287263 |
| USA         | 331002651  | 9833517 |
+-------------+------------+---------+
```
**Output:**
```
+--------+------------+---------+
| name   | population | area    |
+--------+------------+---------+
| Canada | 37742154   | 9984670 |
| China  | 1439323776 | 9596961 |
| India  | 1380004385 | 3287263 |
| USA    | 331002651  | 9833517 |
+--------+------------+---------+
```

---

## Platform
Solved on **Leetcode**: [Big Countries](https://leetcode.com/problems/big-countries/)

---

## Approach

### SQL Query Explanation
**Query:**
```sql
SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000;
```

**Explanation:**
1. Selects the `name`, `population`, and `area` columns from the `World` table.
2. Uses a `WHERE` clause to filter countries that have:
   - `area >= 3,000,000` **or**
   - `population >= 25,000,000`.

**Time Complexity:** O(n) (Scans all rows in the table)  
**Space Complexity:** O(1) (Query runs in constant space)

---

