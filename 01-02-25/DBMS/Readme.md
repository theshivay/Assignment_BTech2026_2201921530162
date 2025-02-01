# 1327. List the Products Ordered in a Period - Leetcode

## Problem Statement
Given a `Products` table and an `Orders` table, write an SQL query to find the product names and the total number of units ordered in February 2020 (between `2020-02-01` and `2020-02-29`). Only include products where the total ordered units are at least 100.

---

## Platform
Solved on **Leetcode**: [List the Products Ordered in a Period](https://leetcode.com/problems/list-the-products-ordered-in-a-period/)

---

## Approach

### Using SQL Query
**Algorithm:**
1. Use `JOIN` to combine `Products` and `Orders` tables based on `product_id`.
2. Filter orders placed in February 2020 using `WHERE` with the `BETWEEN` clause.
3. Use `GROUP BY` to group the results by `product_id`.
4. Use `HAVING` to filter out products with total ordered units less than 100.

**SQL Query:**
```sql
SELECT p.product_name, SUM(o.unit) AS unit
FROM Products p
JOIN Orders o ON p.product_id = o.product_id
WHERE o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY o.product_id
HAVING unit >= 100;
```

**Explanation:**
- `JOIN` combines the two tables based on `product_id`.
- `WHERE` filters orders placed in February 2020.
- `SUM(o.unit)` calculates the total units ordered.
- `GROUP BY` groups by `product_id`.
- `HAVING unit >= 100` ensures only products with at least 100 units ordered are included.

---

