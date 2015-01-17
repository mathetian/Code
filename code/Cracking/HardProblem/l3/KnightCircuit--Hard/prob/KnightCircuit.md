# [KnightCircuit](http://community.topcoder.com/tc?module=ProblemDetail&rd=15186&pm=10966)
*Single Round Match 564 Round 1 - Division II, Level Three*

## Statement
The (*a*,*b*)-knight is a chess piece that moves by jumping, just as a regular knight, but the jump is *a* cells in one direction, *b* in the other. Formally, an (*a*,*b*)-knight standing on the cell (x,y) can move to any of the following eight cells:
(x+*a*,y+*b*), (x+*a*,y-*b*), (x-*a*,y+*b*), (x-*a*,y-*b*), (x+*b*,y+*a*), (x+*b*,y-*a*), (x-*b*,y+*a*), and (x-*b*,y-*a*).
Of course, if the (*a*,*b*)-knight is close to the edge of the board, some of these cells might not be on the board.
It is not allowed to jump to a cell that is not on the board.

A knight circuit is a sequence of cells on a chess board that starts and ends with the same cell.
Each consecutive pair of cells in the knight circuit must correspond to a single jump of the (*a*,*b*)-knight.
The knight circuit may visit each cell arbitrarily many times.
The size of a knight circuit is the number of different cells visited by the circuit.

You are given the ints *w* and *h*: the width (in columns) and the height (in rows) of a rectangular chessboard. You are also given the ints *a* and *b*: the parameters of your knight. Return the maximum knight circuit size that can be obtained on the given board. You are free to choose any cell as the start of your circuit.

## Definitions
- *Class*: `KnightCircuit`
- *Method*: `maxSize`
- *Parameters*: `int, int, int, int`
- *Returns*: `long`
- *Method signature*: `long maxSize(int w, int h, int a, int b)`

## Constraints
- *w*, *h* will each be between 1 and 100000, inclusive.
- *a* and *b* will each be between 1 and 10, inclusive.
- *a* and *b* will not be equal.

## Examples
### Example 1
#### Input
<c>1,<br />1,<br />2,<br />1</c>
#### Output
<c>1</c>
#### Reason
This is a 1x1 board. Note that a sequence that consists of a single cell is considered to be a valid knight circuit.

### Example 2
#### Input
<c>3,<br />20,<br />1,<br />3</c>
#### Output
<c>11</c>
### Example 3
#### Input
<c>100000,<br />100000,<br />1,<br />2</c>
#### Output
<c>10000000000</c>
#### Reason
It is possible to make a circuit that contains every cell on the board.

### Example 4
#### Input
<c>3,<br />3,<br />1,<br />2</c>
#### Output
<c>8</c>
### Example 5
#### Input
<c>30,<br />30,<br />8,<br />4</c>
#### Output
<c>64</c>
### Example 6
#### Input
<c>32,<br />34,<br />6,<br />2</c>
#### Output
<c>136</c>

