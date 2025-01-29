# Customers Who Never Order - Leetcode Solution

## Problem Statement
Given a table `Customers` and a table `Orders`, write an SQL query to find all customers who never placed an order.

### Table: Customers
| id | name  |
|----|-------|
| 1  | Alice |
| 2  | Bob   |
| 3  | Tom   |

### Table: Orders
| id | customerId |
|----|-----------|
| 1  | 3         |
| 2  | 3         |

### Expected Output
| Customers |
|-----------|
| Alice     |
| Bob       |

---

## Platform
Solved on **Leetcode**: [Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/)

---

## Approach
1. Use a `LEFT JOIN` between the `Customers` and `Orders` tables on `customerId`.
2. Filter out customers where `customerId` in `Orders` is `NULL`, meaning they have not placed any orders.

---

## SQL Query
```sql
SELECT name AS Customers
FROM Customers AS c
LEFT JOIN Orders AS o ON c.id = o.customerId
WHERE o.customerId IS NULL;
```

---
