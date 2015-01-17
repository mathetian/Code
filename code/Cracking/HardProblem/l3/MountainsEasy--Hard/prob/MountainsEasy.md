# [MountainsEasy](http://community.topcoder.com/tc?module=ProblemDetail&rd=15487&pm=12380)
*Single Round Match 567 Round 1 - Division II, Level Three*

## Statement
Manao is developing a simple 2-D computer game. The screen of the game is H pixels high and W pixels wide (1 <= H, W <= 50).

Manao is currently working on the background which should be filled with several mountains. The contents of the screen are stored in an array of characters pix where pix[x, y] gives the contents of the pixel at column x, row y. Both indices are 0-based. Columns are numbered left to right and rows are numbered bottom to top. Character 'X' denotes a part of a mountain and character '.' means that this pixel is not covered by any mountains.

Manao wants to draw *N* mountains in order to achieve the necessary background. The i-th (0-based index) mountain is described by its peak position (X[i], Y[i]), 0 <= X[i] < W, 0 <= Y[i] < H. In order to draw the mountains, the following pseudocode is used:

Fill all elements of pix with '.' characters.

For 0<=i<N:

For 0<=x<W:

For 0<=y<=Y[i] - |x - X[i]|:

pix[x, y] := 'X'

For example, consider three mountains with peaks at (1, 1), (2, 2) and (4, 1). Once these mountains are drawn on a screen with H = 3, W = 6, the resulting picture will look as follows:
..X...
.XXXX.
XXXXXX

You are given a String[] *picture* describing the background which Manao wants to obtain. It contains H elements and each element contains W characters. The required value of pix[x, y] is given by x-th character of *picture*[H-y-1]. In other words, elements of *picture* list the rows of the screen from top to bottom.

You are also given an int *N*. Count the number of sequences S of exactly *N* mountains such that when you draw all mountains from S on the screen as described above, the result will match the given *picture*. Return this number modulo 1,000,000,009.

Note that the order of mountains in a sequence is important. Sequences containing the same mountains, but in a different order, are distinct. It is guaranteed that there exists at least one way to obtain the given *picture* by drawing exactly *N* mountains.

## Definitions
- *Class*: `MountainsEasy`
- *Method*: `countPlacements`
- *Parameters*: `String[], int`
- *Returns*: `int`
- *Method signature*: `int countPlacements(String[] picture, int N)`

## Constraints
- *picture* will contain between 1 and 50 elements, inclusive.
- Each element of *picture* will be between 1 and 50 characters long, inclusive.
- All elements of *picture* will be of the same length.
- Each element of *picture* will consist of 'X' and '.' characters only.
- *N* will be between 1 and 50, inclusive.
- *picture* can be obtained by drawing exactly *N* mountains according to the rules given in the problem statement.

## Examples
### Example 1
#### Input
<c>["X.",<br /> "XX"],<br />1</c>
#### Output
<c>1</c>
#### Reason
This is a mountain (0, 1).

### Example 2
#### Input
<c>["X.",<br /> "XX"],<br />2</c>
#### Output
<c>5</c>
#### Reason
Here one of the mountains is completely covered by the other. The five possible sequences are: 
(0, 1), (0, 1)
(0, 1), (0, 0)
(0, 1), (1, 0)
(0, 0), (0, 1)
(1, 0), (0, 1)

### Example 3
#### Input
<c>["X.X",<br /> "XXX"],<br />2</c>
#### Output
<c>2</c>
#### Reason
The two possible sequences are:
(0, 1), (2, 1)
(2, 1), (0, 1)

### Example 4
#### Input
<c>["X.X",<br /> "XXX"],<br />3</c>
#### Output
<c>24</c>
### Example 5
#### Input
<c>["......",<br /> "X..X..",<br /> "XXXXXX",<br /> "XXXXXX"],<br />3</c>
#### Output
<c>6</c>
#### Reason
There are three mountains (0, 2), (3, 2), (5, 1) placed in any order.

### Example 6
#### Input
<c>["......",<br /> "X..X..",<br /> "XXXXXX",<br /> "XXXXXX"],<br />4</c>
#### Output
<c>300</c>
### Example 7
#### Input
<c>["....X...X..",<br /> "...XXX.XXX.",<br /> "XXXXXXXXXXX"],<br />10</c>
#### Output
<c>764632413</c>

