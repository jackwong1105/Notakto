# Notakto

Notakto is a game played by two players on multiple 3x3 game boards. It is said to be invented by Bob
In this project, the following game rules are used.
There are only two 3x3 game boards, which are empty initially.
Two players take turns to choose a game board and place a cross (X) on an unoccupied cell.
A game board is dead if it has three-in-a-row of crosses (in horizontal, vertical or diagonal).
Players cannot choose a dead game board to place a cross.
Players cannot skip their turns.
When there is only one non-dead game board left, the player who places the last cross to make
it dead (i.e., having three-in-a-row of crosses) loses the game. In other words, the other player
is the winner.

The main() function invokes the initGameBoard() function twice to initialize the two game boards one
by one. 

The main() function prints the following message to ask for the number of human players:
Enter the number of human players [1-2]:
Here you can assume that the user must be valid (either 1 or 2).
o If there are two human players, they are Player 1 and Player 2.
o If there is only one human player, he/she is Player 1 and another player is the computer player.
For both cases, Player 1 moves first.

In the beginning of each turn, the main() function invokes the printTwoGameBoards() function, which
displays the two game boards on the screen. Empty cells are displayed with numbers (similar to a
NumPad, having 1 at the bottom left corner and 9 at the top right corner). Occupied cells are displayed
with crosses.

The isGameBoardDead() function returns 1 if the specified game board is dead ((i.e., having three-in-a-
row of crosses). Otherwise, it returns 0.

Placing Cross by Human Player
Depending on who the current player is, the main() function prints one of the following messages:
②
 Player 1's turn #
 Player 2's turn #
and then invokes the placeCrossByHumanPlayer() function, which first prints the following message to
ask the current human player to choose the game board:
Choose the game board:
You can assume that the user inputs must be integers. But the user input may not be valid. When the
input is not 1 or 2, print the following message and read the input again:
Input out of range. Please input again:
When the chosen game board is dead, print the following message and read the input again:
The chosen game board is dead. Please input again:
The above checking will be repeated until the input is valid.
After a valid game board is chosen, the placeCrossByHumanPlayer() function will invoke the
updateGameBoard() function, which first prints the following message to ask the current human player
to place a cross on the chosen game board.
Choose the cell:
You can assume that the user inputs must be integers. But the user input may not be valid. When the
input is not in the range of 1 to 9, print the following message and read the input again:
Input out of range. Please input again:
When the chosen cell is occupied (i.e., has a cross already), print the following message and read the
input again:
The chosen cell is occupied. Please input again:
The above checking will be repeated until the input is valid. Note that the game board will not be
chosen again if the input for the cell is invalid.
After a valid cell is chosen, the updateGameBoard() function will update the chosen game board
accordingly.

Placing Cross by Computer Player
When it is the computer’s turn, the main() function prints the following message:
# Computer's turn #
and then invokes the placeCrossByComputerPlayer() function, which determines the next move of the
computer player and updates the corresponding game board accordingly. The choices of the game
board and the cell will also be printed on the screen with the following messages:
Choose the game board:
Choose the cell:
Choosing the game board
o Case A: Both game boards are not dead (i.e., not having three-in-a-row of crosses)
 If the first game board has fewer crosses than the second game board, choose
the first game board.
 Otherwise, choose the second game board.
o Case B: One of the game boards is dead
 Choose the other one that is not dead.
 Placing the cross
o Case A: Both game boards are not dead
If the first game board was chosen:
 Place the cross on the unoccupied cell with the smallest number (no
matter whether this move will make the game board dead or not)
If the second game board was chosen:
 Place the cross on the unoccupied cell with the largest number (no
matter whether this move will make the game board dead or not).
Case B: One of the game boards is dead
 If the first game board was chosen:
 Place the cross on the unoccupied cell with the smallest number that
will not make the game board dead (i.e., not to lose the game).
If all possible moves will make the game board dead, place the cross on
the unoccupied cell with the smallest number (i.e., lose the game).
If the second game board was chosen:
 Place the cross on the unoccupied cell with the largest number that will
not make the game board dead (i.e. not to lose the game).
If all possible moves will make the game board dead, place the cross on
the unoccupied cell with the largest number (i.e., lose the game).
Checking Whether the Game Ends
At the end of each turn, the main() function checks whether the game ends. If yes, display the two
game boards, print one of the following messages according who the winner is:
Congratulations! Player 1 wins!
Congratulations! Player 2 wins!
Computer wins!
and terminate the program. If no, the game continues to the next player’s turn.
