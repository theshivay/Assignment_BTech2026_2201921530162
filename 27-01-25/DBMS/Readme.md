# 175. Combine Two Tables - Leetcode Solution

## Problem Statement
Given two tables, `Person` and `Address`, write a SQL query to retrieve the first name, last name, city, and state of each person. If a person does not have an address, include their name with `NULL` values for city and state.

### Schema
**Person Table:**
| Column Name | Type    |
|-------------|---------|
| personId    | int     |
| firstName   | varchar |
| lastName    | varchar |

**Address Table:**
| Column Name | Type    |
|-------------|---------|
| addressId   | int     |
| personId    | int     |
| city        | varchar |
| state       | varchar |

### Example Data
**Person Table:**
| personId | firstName | lastName |
|----------|-----------|----------|
| 1        | John      | Doe      |
| 2        | Jane      | Smith    |

**Address Table:**
| addressId | personId | city   | state |
|-----------|----------|--------|-------|
| 1         | 1        | Boston | MA    |

### Expected Output
| firstName | lastName | city   | state |
|-----------|----------|--------|-------|
| John      | Doe      | Boston | MA    |
| Jane      | Smith    | NULL   | NULL  |

---

## Platform
Solved on **Leetcode**: [Combine Two Tables](https://leetcode.com/problems/combine-two-tables/)

---

## Approach

### SQL Query Explanation
**Algorithm:**
1. Use a `LEFT JOIN` to combine the `Person` and `Address` tables on the `personId` column.
2. Select the required columns (`firstName`, `lastName`, `city`, `state`) from both tables.
3. The `LEFT JOIN` ensures that all rows from the `Person` table are included, even if there is no matching row in the `Address` table.

**Query:**
```sql
SELECT firstName, lastName, city, state
FROM Person AS p
LEFT JOIN Address AS a ON p.personId = a.personId;
```

**Time Complexity:** O(n) (Assuming index on `personId` for efficient join)  
**Space Complexity:** O(1) (No additional storage beyond the result set)
