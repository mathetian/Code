# [LittleElephantAndXor](http://community.topcoder.com/tc?module=ProblemDetail&rd=15707&pm=12623)
*Single Round Match 595 Round 1 - Division II, Level Three*

## Statement
Little Elephant from the Zoo of Lviv likes integers.

You are given three ints *A*, *B* and *C*. Return the number of ordered pairs (X,Y) of integers such that 0 <= X <= *A*, 0 <= Y <= *B*, and the value (X XOR Y) is less than or equal to *C*.

## Definitions
- *Class*: `LittleElephantAndXor`
- *Method*: `getNumber`
- *Parameters*: `int, int, int`
- *Returns*: `long`
- *Method signature*: `long getNumber(int A, int B, int C)`

## Notes
- XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
- For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.

## Constraints
- *A*, *B* and *C* will each be between 1 and 1,000,000,000 (10^(9)), inclusive.

## Examples
### Example 1
#### Input
<c>2,<br />2,<br />1</c>
#### Output
<c>5</c>
#### Reason
There are 9 possible pairs in this case:
0 XOR 0 = 0
0 XOR 1 = 1
0 XOR 2 = 2
1 XOR 0 = 1
1 XOR 1 = 0
1 XOR 2 = 3
2 XOR 0 = 2
2 XOR 1 = 3
2 XOR 2 = 0
Among them, only 5 have XOR less than or equal to 1. Note that (0,1) and (1,0) are two different pairs.

### Example 2
#### Input
<c>4,<br />7,<br />3</c>
#### Output
<c>20</c>
### Example 3
#### Input
<c>10,<br />10,<br />5</c>
#### Output
<c>57</c>
### Example 4
#### Input
<c>774,<br />477,<br />447</c>
#### Output
<c>214144</c>
### Example 5
#### Input
<c>1000000000,<br />1000000000,<br />500000000</c>
#### Output
<c>468566946385621507</c>

