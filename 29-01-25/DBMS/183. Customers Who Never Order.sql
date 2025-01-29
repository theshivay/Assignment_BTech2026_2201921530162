-- # Write your MySQL query statement below
select name as Customers
from Customers as c
Left join Orders as o on c.id = o.customerId
where o.customerId is NULL;


-- Approach 1st
-- select name as Customers
-- from Customers
-- where Id not in (
--     select CustomerId from Orders
-- );
