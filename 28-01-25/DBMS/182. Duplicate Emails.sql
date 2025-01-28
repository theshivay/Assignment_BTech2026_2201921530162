-- # Write your MySQL query statement below
select email as Email
from Person
group by Email 
Having Count(*) > 1;
