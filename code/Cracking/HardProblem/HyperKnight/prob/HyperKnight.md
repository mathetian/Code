# [HyperKnight](http://community.topcoder.com/tc?module=ProblemDetail&rd=15181&pm=12201)
*Single Round Match 559 Round 1 - Division I, Level One*

## Statement
Fernando loves to play chess. One day he decided to play chess on an unusually large rectangular board. To compensate for the board's size he also decided to change the distance a knight can move in a single jump.

To describe the moves easily, we will now introduce a coordinate system. Each cell of the chessboard can be described using two integers (r,c): its row number and its column number. Now, if we have a piece at (r,c), the move (x,y) takes the piece to the cell (r+x,c+y).

The new chess piece will be called an (*a*,*b*)-hyperknight. The hyperknight always has 8 possible moves: (+*a*,+*b*), (+*a*,-*b*), (-*a*,+*b*), (-*a*,-*b*), (+*b*,+*a*), (+*b*,-*a*), (-*b*,+*a*), and (-*b*,-*a*). Note that the original chess knight is a (2,1)-hyperknight.

Of course, as the chessboard is finite, it is not always possible to make each of the 8 moves. Some of them may cause our hyperknight to leave the chessboard. A move is called valid if the destination cell is on the chessboard. Fernando would like to know the number of cells on his board such that his hyperknight will have exactly *k* valid moves from that cell.

You are given the ints *a*, *b*, *numRows*, *numColumns* and *k*. The values *numRows* and *numColumns* define the number of rows and number of columns on the chessboard, respectively. The other three values were already explained above. Compute and return the number of cells on the chessboard that have exactly *k* valid (*a*,*b*)-hyperknight moves.

## Definitions
- *Class*: `HyperKnight`
- *Method*: `countCells`
- *Parameters*: `int, int, int, int, int`
- *Returns*: `long`
- *Method signature*: `long countCells(int a, int b, int numRows, int numColumns, int k)`

## Notes
- If you wish, you may assume that the rows are numbered 0 through *numRows*-1 and columns 0 through *numColumns*-1. However, note that the actual row/column numbers do not matter, as long as they are consecutive.

## Constraints
- *a* will be between 1 and 1,000,000,000 (10^9), inclusive.
- *b* will be between 1 and 1,000,000,000 (10^9), inclusive.
- *a* will not be equal to *b*.
- *numRows* will be between 1 and 1,000,000,000 (10^9), inclusive.
- *numColumns* will be between 1 and 1,000,000,000 (10^9), inclusive.
- 2*max(*a*,*b*) will be strictly less than min(*numRows*,*numColumns*).
- *k* will be between 0 and 8, inclusive.

## Examples
### Example 1
#### Input
<c>2,<br />1,<br />8,<br />8,<br />4</c>
#### Output
<c>20</c>
#### Reason
This is a standard chessboard. We have a traditional chess knight and we are looking for cells such that the knight has exactly 4 valid moves.

### Example 2
#### Input
<c>3,<br />2,<br />8,<br />8,<br />2</c>
#### Output
<c>16</c>
### Example 3
#### Input
<c>1,<br />3,<br />7,<br />11,<br />0</c>
#### Output
<c>0</c>
### Example 4
#### Input
<c>3,<br />2,<br />10,<br />20,<br />8</c>
#### Output
<c>56</c>
### Example 5
#### Input
<c>1,<br />4,<br />100,<br />10,<br />6</c>
#### Output
<c>564</c>
### Example 6
#### Input
<c>2,<br />3,<br />1000000000,<br />1000000000,<br />8</c>
#### Output
<c>999999988000000036</c>

