# 181. Employees Earning More Than Their Managers - Leetcode

## Problem Statement
Given a table `Employee` with the following columns:
- `id` (Employee ID)
- `name` (Employee's name)
- `salary` (Employee's salary)
- `managerId` (ID of the manager for the employee)

The task is to find all employees who earn more than their managers. The solution should return the employee's name.

## Coding Platform
- LeetCode

## Approach and Solution Explanation
1. **Join the Employee Table**: The `Employee` table is joined with itself to compare the employees with their respective managers. We join `Employee` (`e`) with `Employee` (`m`) on the condition that `e.managerId = m.id`.
   
2. **Filter the Employees**: Apply the condition `e.salary > m.salary` to find employees who earn more than their managers.

3. **Select the Result**: Finally, we select the `name` of the employee who satisfies the condition.

### SQL Query:
```sql
SELECT e.name AS Employee
FROM Employee e
JOIN Employee m ON e.managerId = m.id
WHERE e.salary > m.salary;
```