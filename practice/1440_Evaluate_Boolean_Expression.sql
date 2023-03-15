/*
1440. Evaluate Boolean Expression
Table Variables:

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| name          | varchar |
| value         | int     |
+---------------+---------+
name is the primary key for this table.
This table contains the stored variables and their values.
 

Table Expressions:

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| left_operand  | varchar |
| operator      | enum    |
| right_operand | varchar |
+---------------+---------+
(left_operand, operator, right_operand) is the primary key for this table.
This table contains a boolean expression that should be evaluated.
operator is an enum that takes one of the values ('<', '>', '=')
The values of left_operand and right_operand are guaranteed to be in the Variables table.
 

Write an SQL query to evaluate the boolean expressions in Expressions table.

Return the result table in any order.
*/
# Write your MySQL query statement below
SELECT left_operand, operator, right_operand, 
  (CASE WHEN operator = '>' AND v1.value > v2.value THEN 'true'
    WHEN operator = '<' AND v1.value < v2.value THEN 'true'
    WHEN operator = '=' AND v1.value = v2.value THEN 'true'
    ELSE 'false'
  END) AS value
FROM Expressions
JOIN Variables v1
ON left_operand = v1.name
JOIN Variables v2
ON right_operand = v2.name
