# [MuddyRoad2](http://community.topcoder.com/tc?module=ProblemDetail&rd=15177&pm=12189)
*Single Round Match 555 Round 1 - Division II, Level Three*

## Statement
Fox Ciel is going to walk along an unpaved road to her friend's house.
For our purposes, the road can be considered a one-dimensional polyline consisting of *N* segments.
The segments are numbered 0 through *N*-1 along the road.
At the beginning, Ciel stands on the segment number 0.
Her friend's house is on the segment number *N*-1.

Unfortunately, yesterday it rained, so some segments of the road are now muddy.
Ciel has new shoes, so she must only use the other, dry segments.
She knows that segments 0 and *N*-1 are dry.
The friend just called her and gave her two additional pieces of information:

Out of the remaining *N*-2 segments, exactly *muddyCount* are muddy.
There is an even number of ways how Ciel can get to the friend's house without stepping into the mud, while making steps of length at most 2.

We will now explain the second information in more detail.
When Ciel walks along the road, each of her steps has either length 1 or 2.
A step of length 1 takes her from segment i to segment i+1.
A step of length 2 takes her from segment i to segment i+2, skipping the (possibly, but not necessarily muddy) segment i+1.

Fox Ciel would like to use the information she has to determine how the road looks like.
Of course, there may be multiple configurations that match the information.
It is also possible that her friend was mistaken and there is no sequence of dry and muddy segments that matches what she told Ciel.

You are given the ints *N* and *muddyCount*.
Count all the ways the road can look like, and return that count modulo 555,555,555.

## Definitions
- *Class*: `MuddyRoad2`
- *Method*: `theCount`
- *Parameters*: `int, int`
- *Returns*: `int`
- *Method signature*: `int theCount(int N, int muddyCount)`

## Notes
- Zero (0) is also an even number. Hence, if Ciel cannot reach her friend's house without stepping into the mud, there is an even number of ways to reach the house.
- Two configurations of the road are different if some road segment is dry in one of them and muddy in the other.

## Constraints
- *N* will be between 2 and 555, inclusive.
- *muddyCount* will be between 0 and *N*-2, inclusive.

## Examples
### Example 1
#### Input
<c>5,<br />1</c>
#### Output
<c>2</c>
#### Reason
There are two possible configurations of the road: 
.#...
and
...#. (where '#' denotes a muddy segment and '.' a dry one).

### Example 2
#### Input
<c>5,<br />2</c>
#### Output
<c>2</c>
#### Reason
Possible configurations:

.##..
and
..##.

Note that in these configurations, there are no ways to go from part 0 to part 4 without stepping onto any muddy parts. You have to count this kind of configurations too, since 0 is an even number.

### Example 3
#### Input
<c>10,<br />4</c>
#### Output
<c>65</c>
### Example 4
#### Input
<c>314,<br />78</c>
#### Output
<c>498142902</c>
### Example 5
#### Input
<c>555,<br />222</c>
#### Output
<c>541606281</c>

