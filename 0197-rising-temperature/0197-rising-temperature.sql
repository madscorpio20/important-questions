# Write your MySQL query statement below

select distinct w1.id from Weather as w1 inner join Weather as w2 ON w1.temperature > w2.temperature AND DATEDIFF(w1.recordDate, w2.recordDate) = 1; 