# 1084. Sales Analysis III - Leetcode   

## Problem Statement  
Given the `Product` and `Sales` tables, write a SQL query to find the `product_id` and `product_name` of products that were only sold in the first quarter of 2019 (January 1, 2019, to March 31, 2019) and not in any other period.  

### Example:  
**Input Tables:**  

**Product Table:**  
| product_id | product_name  |  
|------------|--------------|  
| 1          | Keyboard     |  
| 2          | Mouse        |  
| 3          | Monitor      |  

**Sales Table:**  
| sale_id | product_id | sale_date  |  
|---------|-----------|------------|  
| 1       | 1         | 2019-01-05 |  
| 2       | 2         | 2019-02-10 |  
| 3       | 1         | 2019-03-15 |  
| 4       | 3         | 2019-06-01 |  

**Output:**  
| product_id | product_name |  
|------------|-------------|  
| 2          | Mouse       |  

---

## Platform  
Solved on **Leetcode**: [Sales Analysis III](https://leetcode.com/problems/sales-analysis-iii/)  

---

## Approach  

1. Use a `LEFT JOIN` to combine the `Product` and `Sales` tables based on `product_id`.  
2. Filter the sales records for products sold strictly between `2019-01-01` and `2019-03-31`.  
3. Exclude products that have sales in any period outside this range using a subquery.  
4. Use `DISTINCT` to ensure unique product results.  

**SQL Query:**  

```sql
SELECT DISTINCT
    p.product_id, p.product_name
FROM Product p
LEFT JOIN Sales s ON p.product_id = s.product_id
WHERE sale_date BETWEEN '2019-01-01' AND '2019-03-31'
AND p.product_id NOT IN (
    SELECT DISTINCT product_id
    FROM Sales
    WHERE sale_date > '2019-03-31' OR sale_date < '2019-01-01'
);
```

**Time Complexity:** O(n log n) (Due to filtering and subquery execution)  

---

