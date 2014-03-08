# [FoxAndMountain](http://community.topcoder.com/tc?module=ProblemDetail&rd=15179&pm=11810)
*Single Round Match 557 Round 1 - Division II, Level Three*

## Statement
Fox Ciel lives in a beautiful countryside.
She loves climbing mountains.
Yesterday, she went hiking in the mountains.

Her trip can be described as a sequence of (n+1) integers: h[0], h[1], ..., h[*n*]. 
These values represent altitudes visited by Fox Ciel during the trip, in order.
Fox Ciel does not remember the precise sequence, but she remembers the following:
for each i, h[i] >= 0
h[0] = 0
h[*n*] = 0
for each i, abs(h[i+1]-h[i]) = 1

The last condition means that in each step the altitude of Fox Ciel either increased by 1, or decreased by 1.
We will call the two types of steps "steps up" and "steps down", respectively.
Steps up will be denoted 'U' and steps down will be denoted 'D'.

You are given the int *n*: the length of the trip.
In addition to the length, Fox Ciel remembers some contiguous segment of her trip.
You are given this segment as a String *history*.
Each character of *history* is either 'U' or 'D'.

Let X be the number of different trips that match everything that Fox Ciel remembers.
(Note that she may be mistaken, hence X may also be zero.)
Compute and return the value (X modulo 1,000,000,009).

## Definitions
- *Class*: `FoxAndMountain`
- *Method*: `count`
- *Parameters*: `int, String`
- *Returns*: `int`
- *Method signature*: `int count(int n, String history)`

## Constraints
- *n* will be between 1 and 50, inclusive.
- *history* will contain between 1 and *n* characters, inclusive.
- Each character in *history* will be either 'U' or 'D'.

## Examples
### Example 1
#### Input
<c>4,<br />"UUDD"</c>
#### Output
<c>1</c>
#### Reason
Fox Ciel remembers the entire history of her trip. The corresponding sequence of altitudes is {0, 1, 2, 1 ,0}.

### Example 2
#### Input
<c>4,<br />"DUUD"</c>
#### Output
<c>0</c>
#### Reason
Fox Ciel is mistaken. 
As *n*=4 and *history*="DUUD", the corresponding sequence of altitudes has to be {0, -1, 0, 1, 0}.
However, all altitudes must be non-negative, so there is no matching trip.

### Example 3
#### Input
<c>4,<br />"UU"</c>
#### Output
<c>1</c>
#### Reason
The complete history must be "UUDD".

### Example 4
#### Input
<c>49,<br />"U"</c>
#### Output
<c>0</c>
#### Reason
It is not hard to see that for an odd *n* the answer has to be 0.

### Example 5
#### Input
<c>20,<br />"UUUDUUU"</c>
#### Output
<c>990</c>
### Example 6
#### Input
<c>30,<br />"DUDUDUDUDUDUDUDU"</c>
#### Output
<c>3718</c>
### Example 7
#### Input
<c>50,<br />"U"</c>
#### Output
<c>946357703</c>
#### Reason
Don't forget to use the modulo operations during the calculation.


