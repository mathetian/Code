# [FoxAndGo2](http://community.topcoder.com/tc?module=ProblemDetail&rd=15706&pm=12809)
*Single Round Match 594 Round 1 - Division II, Level Three*

## Statement
Fox Ciel is teaching her friend Jiro to play Go.
Ciel has just placed some white tokens onto a board.
She now wants Jiro to find the best possible sequence of moves.
(This is defined more precisely below.)

You are given a String[] *board*.
Character j of element i of *board* represents the cell (i,j) of the board:
'o' is a cell with a white token and '.' is an empty cell.
At least one cell on the board will be empty. Note that there are currently no black tokens on the board.

Each Jiro's move consists of adding a single black token to the board.
The token must be placed onto an empty cell.
Once Jiro places the token, some white tokens will be removed from the board according to the rules described in the next paragraphs.

The tokens on the board can be divided into connected components using the following rules:
If two tokens of the same color lie in cells that share an edge, they belong to the same component.
Being in the same component is transitive: if X lies in the same component as Y and Y lies in the same component as Z, then X lies in the same component as Z.

Note that each component of tokens is either completely white or completely black. Each component of tokens is processed separately.
For each component we check whether it is adjacent to an empty cell.
(That is, whether there are two cells that share an edge such that one of them is empty and the other contains a token from the component we are processing.)
If there is such an empty cell, the component is safe and its tokens remain on the board.
If there is no such empty cell, the component is killed and all its tokens are removed from the board.

There are also the following additional rules:
All white components must be processed before black ones (in any order).
If at least one white token was removed, then black components must not be processed at all.
Otherwise, all black components must be processed (in any order).
If at least one black token was removed, this is called a "suicide move". Such moves are invalid and Jiro is not allowed to make them.

Jiro's score is the total number of white tokens removed from the board after each of his moves is evaluated.
Return the maximal score he can get for the given board.

## Definitions
- *Class*: `FoxAndGo2`
- *Method*: `maxKill`
- *Parameters*: `String[]`
- *Returns*: `int`
- *Method signature*: `int maxKill(String[] board)`

## Constraints
- n will be between 2 and 19, inclusive.
- *board* will contain exactly n elements.
- Each element in *board* will contain exactly n characters.
- Each character in *board* will be 'o' or '.'.
- There will be at least 1 '.' in *board*.

## Examples
### Example 1
#### Input
<c>["...",<br /> ".o.",<br /> "..."]</c>
#### Output
<c>1</c>
#### Reason
.A.
BoC
.D.
Jiro can put black pieces at A,B,C,D (in any order).

### Example 2
#### Input
<c>["o.",<br /> "oo"]</c>
#### Output
<c>3</c>
#### Reason
Jiro needs to place the black token into the empty cell. After that, the white component becomes unsafe and will be killed. The black component won't be processed, so the black token will remain on board.

### Example 3
#### Input
<c>[".o.o.",<br /> "o.o.o",<br /> ".o.o.",<br /> "o.o.o",<br /> ".o.o."]</c>
#### Output
<c>0</c>
#### Reason
Regardless of which empty cell he chooses, he will never kill any white component with this single black token.
On the other hand, his black token would always be killed.
Therefore, Jiro has no valid move on this board.

### Example 4
#### Input
<c>[".o.o.",<br /> "o.o.o",<br /> ".o.o.",<br /> "o.o.o",<br /> "....."]</c>
#### Output
<c>10</c>
### Example 5
#### Input
<c>[".o.o.o.o.o.",<br /> "o.ooo.ooo.o",<br /> ".o.......o.",<br /> "oo.......oo",<br /> ".o...o...o.",<br /> "o...o.o...o",<br /> ".o...o...o.",<br /> "oo.......oo",<br /> ".o.......o.",<br /> "o.ooo.ooo.o",<br /> ".o.o.o.o.o."]</c>
#### Output
<c>4</c>
### Example 6
#### Input
<c>["...ooo.....",<br /> "...o.o.....",<br /> ".ooo.ooo...",<br /> ".o.....o...",<br /> ".ooo.ooo...",<br /> "...o.o.....",<br /> "...ooo.....",<br /> "....o......",<br /> "....o...ooo",<br /> "....ooooo.o",<br /> "........ooo"]</c>
#### Output
<c>38</c>
### Example 7
#### Input
<c>["ooooooooooo",<br /> "o.........o",<br /> "o...ooo...o",<br /> "o...o.o...o",<br /> "o...ooo...o",<br /> "o....o....o",<br /> "o....oooooo",<br /> "o..........",<br /> "o.......ooo",<br /> "o.......o.o",<br /> "ooooooooooo"]</c>
#### Output
<c>0</c>
#### Reason
Sometimes, making no moves at all is an optimal strategy.

### Example 8
#### Input
<c>["oo.o.ooo.o..o..",<br /> "...ooo.o..oo.oo",<br /> "o..o.o.ooo.o..o",<br /> "oo.......oo.ooo",<br /> "..oo.o.o.o.ooo.",<br /> "..oo..oo..o.ooo",<br /> "oo.o.oo..o.oooo",<br /> ".oo.o..ooo.o.oo",<br /> "o..o.o.o.o.oo..",<br /> ".oo.oo...o....o",<br /> "o.o.oo....oo..o",<br /> ".o.o..o.oo..ooo",<br /> "o.o.o..o..o....",<br /> "ooo.oooooooo..o",<br /> "o..oo.o..o.ooo."]</c>
#### Output
<c>60</c>

