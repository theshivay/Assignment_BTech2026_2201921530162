# 196. Delete Duplicate Emails - Leetcode

## Problem Statement
Write an SQL query to delete all duplicate email entries in a table, keeping only the one with the smallest ID.

### Example Table: Person
| Id | Email         |
|----|-------------|
| 1  | a@b.com     |
| 2  | c@d.com     |
| 3  | a@b.com     |

**Output Table after query execution:**
| Id | Email         |
|----|-------------|
| 1  | a@b.com     |
| 2  | c@d.com     |

---

## Platform
Solved on **Leetcode**: [Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/)

---

## Approach

### SQL Query Approach
**Algorithm:**
1. Compare each row with another row in the same table.
2. Identify duplicate emails where `id` is greater for one entry.
3. Delete the duplicate entry while keeping the one with the smallest `id`.

**Code:**
```sql
# Write your MySQL query statement below
delete p1 
from Person p1, Person p2 
where p1.id > p2.id and p1.email=p2.email;
```

**Time Complexity:** O(n²) (Self-join comparison for duplicate entries)  
**Space Complexity:** O(1) (No extra space used)

---
