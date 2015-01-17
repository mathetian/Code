# [DivisibleSequence](http://community.topcoder.com/tc?module=ProblemDetail&rd=15187&pm=12274)
*Single Round Match 565 Round 1 - Division II, Level Three*

## Statement
A divisible sequence with starting value *N* and length *H* is a sequence of positive integers with the following properties:
The sequence has *H* elements, labeled A[0] through A[*H*-1].
A[0] equals *N*.
For each i between 0 and *H*-2, inclusive, A[i+1] divides A[i].

You are given the ints *N* and *H*.
Let C be the count of all divisible sequences with starting value *N* and length *H*.
Return the value (C modulo 1,000,000,009).

## Definitions
- *Class*: `DivisibleSequence`
- *Method*: `count`
- *Parameters*: `int, int`
- *Returns*: `int`
- *Method signature*: `int count(int N, int H)`

## Constraints
- *N* will be between 1 and 1,000,000,000, inclusive.
- *H* will be between 1 and 1,000,000,000, inclusive.

## Examples
### Example 1
#### Input
<c>5,<br />3</c>
#### Output
<c>3</c>
#### Reason
The three possible sequences are:

5, 5, 5

5, 5, 1

5, 1, 1

### Example 2
#### Input
<c>6,<br />3</c>
#### Output
<c>9</c>
#### Reason
The nine possible sequences are:

6, 6, 6

6, 6, 3

6, 6, 2

6, 6, 1

6, 3, 3

6, 3, 1

6, 2, 2

6, 2, 1

6, 1, 1

### Example 3
#### Input
<c>10,<br />2</c>
#### Output
<c>4</c>
#### Reason
A[1] can be equal to each of the divisors of the number 10. That is, A[1] can be 1, 2, 5, or 10.

### Example 4
#### Input
<c>1,<br />10000</c>
#### Output
<c>1</c>
#### Reason
The only possible sequence consists of all ones.

### Example 5
#### Input
<c>30,<br />4</c>
#### Output
<c>64</c>
### Example 6
#### Input
<c>25883,<br />100000</c>
#### Output
<c>991000009</c>

