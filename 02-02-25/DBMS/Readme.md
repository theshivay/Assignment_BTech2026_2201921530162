# 511. Game Play Analysis I - Leetcode

## Problem Statement
Write an SQL query to find the first login date of each player from the `Activity` table.

### Example:
**Input:**
Activity table containing player login events.

**Output:**
Each player's first login date.

---

## Platform
Solved on **Leetcode**: [Game Play Analysis I](https://leetcode.com/problems/game-play-analysis-i/)

---

## Approach

### SQL Query Explanation:
1. Use `GROUP BY` to group data by `player_id`.
2. Use `MIN(event_date)` to get the earliest login date for each player.

**SQL Query:**
```sql
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;
```

**Key Concepts:**
- `GROUP BY` to group data by player.
- `MIN()` to get the earliest event date.

---
