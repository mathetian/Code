# [TheTilesDivTwo](http://community.topcoder.com/tc?module=ProblemDetail&rd=15495&pm=12501)
*Single Round Match 575 Round 1 - Division II, Level Three*

## Statement
John and Brus have a rectangular chessboard with black and white tiles.
Rows and columns of the chessboard are numbered starting from 0.
The cell at row i, column j is black if i+j is even and it is white if i+j is odd.

Some of the cells of the chessboard are occupied by chess pieces.
You are given a String[] *board*.
For each i and j, the j-th character of the i-th element (0-based indices) of *board* is 'X' if the cell in row i, column j of the chessboard contains a chess piece.
Otherwise, the j-th character of the i-th element of *board* is '.'.

John and Brus also have an infinite supply of L-shaped tiles.
Each tile consists of three squares which are of the same size as the cells of the chessboard.
I.e., each tile looks as follows:
OO
O

John and Brus want to place some of the tiles onto their chessboard, according to the following rules:
Each tile may be rotated by any multiple of 90 degrees.
Each tile must cover exactly three cells of the chessboard.
Tiles are not allowed to overlap.
Tiles are not allowed to cover the cells that are already occupied by the chess pieces.
The corner cell of each tile must cover a black cell of the chessboard.

Return the maximum number of tiles John and Brus can place on the board according to the above rules.

## Definitions
- *Class*: `TheTilesDivTwo`
- *Method*: `find`
- *Parameters*: `String[]`
- *Returns*: `int`
- *Method signature*: `int find(String[] board)`

## Constraints
- *board* will contain between 1 and 4 elements, inclusive.
- Each element of *board* will contain between 1 and 47 characters, inclusive.
- All elements of *board* will contain the same number of characters.
- Each element of *board* will consist of only characters 'X' and '.'.

## Examples
### Example 1
#### Input
<c>["X.X",<br /> "...",<br /> "X.X"]</c>
#### Output
<c>1</c>
#### Reason
Since only one black cell is available, just one tile can be placed on the board.

### Example 2
#### Input
<c>["...",<br /> "...",<br /> "..."]</c>
#### Output
<c>2</c>
### Example 3
#### Input
<c>["......X.X.XXX.X.XX."]</c>
#### Output
<c>0</c>
### Example 4
#### Input
<c>["X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",<br /> ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",<br /> "....XX....X.XX..X.X...XX.X..XXXXXXX..X",<br /> "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."]</c>
#### Output
<c>13</c>

