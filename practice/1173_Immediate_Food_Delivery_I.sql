/*
1173. Immediate Food Delivery I
Table: Delivery

+-----------------------------+---------+
| Column Name                 | Type    |
+-----------------------------+---------+
| delivery_id                 | int     |
| customer_id                 | int     |
| order_date                  | date    |
| customer_pref_delivery_date | date    |
+-----------------------------+---------+
delivery_id is the primary key of this table.
The table holds information about food delivery to customers that make orders at some date and specify a preferred delivery date (on the same order date or after it).
 

If the customer's preferred delivery date is the same as the order date, then the order is called immediate; otherwise, it is called scheduled.

Write an SQL query to find the percentage of immediate orders in the table, rounded to 2 decimal places.
*/
# Write your MySQL query statement below
SELECT 
  ROUND(SUM(order_date = customer_pref_delivery_date) / COUNT(delivery_id) * 100, 2)
  AS immediate_percentage
  FROM Delivery
  ;
