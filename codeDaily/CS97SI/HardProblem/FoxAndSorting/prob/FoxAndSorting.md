# [FoxAndSorting](http://community.topcoder.com/tc?module=ProblemDetail&rd=15037&pm=11572)
*Single Round Match 535 Round 1 - Division II, Level Three*

## Statement
Fox Jiro and Eel Saburo are good friends. Saburo uses a strange way to compare integers. Please help Jiro understand it.

For a positive integer n, let d(n) be the sum of its digits in base 10. For example, d(407) = 4+0+7 = 11.

When comparing two different integers x and y, Saburo first compares their sums of digits, i.e., the values d(x) and d(y). If they differ, the one with the smaller sum is smaller.
For example, for Saburo 50 is smaller than 16, because d(50) < d(16).

If the numbers have the same sum of digits, Saburo compares them lexicographically (i.e., as strings).
For example, for Saburo the number 111 is smaller than the number 3, because d(111) = d(3) and "111" < "3".
Also, the number 470 is smaller than 4700, because "470" < "4700".

Let A be the sequence of integers {0, 1, ..., 999999999999999998, 999999999999999999 (10^18 - 1)}.
Let B be the sequence A, ordered according to Saburo's rules.
You are given a long *idx*, representing a 1-based index into B.
Return the corresponding element of B.

## Definitions
- *Class*: `FoxAndSorting`
- *Method*: `get`
- *Parameters*: `long`
- *Returns*: `long`
- *Method signature*: `long get(long idx)`

## Notes
- Given two distinct strings A and B, we say that A is lexicographically smaller than B if either A is a prefix of B, or A has a smaller character than B on the first position on which they differ.

## Constraints
- *idx* will be between 1 and 1,000,000,000,000,000,000 (10^18), inclusive.

## Examples
### Example 1
#### Input
<c>10</c>
#### Output
<c>100000000</c>
#### Reason
First 10 elements of B are: {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}.

### Example 2
#### Input
<c>1000000000000000000</c>
#### Output
<c>999999999999999999</c>
#### Reason
The last element.

### Example 3
#### Input
<c>58</c>
#### Output
<c>100000000100</c>
### Example 4
#### Input
<c>314159265358979</c>
#### Output
<c>646003042230121105</c>
### Example 5
#### Input
<c>271828182845904523</c>
#### Output
<c>132558071125756493</c>

