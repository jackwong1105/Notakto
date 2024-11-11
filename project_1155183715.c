#include <stdio.h>

void initGameBoard(int gameBoard[3][3]) {
    gameBoard[0][0] = 55;
    gameBoard[0][1] = 56;
    gameBoard[0][2] = 57;

    gameBoard[1][0] = 52;
    gameBoard[1][1] = 53;
    gameBoard[1][2] = 54;

    gameBoard[2][0] = 49;
    gameBoard[2][1] = 50;
    gameBoard[2][2] = 51;
}
/* Display the specified game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[3][3]) {
    printf("|%c|%c|%c|\n",gameBoard[0][0],gameBoard[0][1],gameBoard[0][2]);
    printf("|%c|%c|%c|\n",gameBoard[1][0],gameBoard[1][1],gameBoard[1][2]);
    printf("|%c|%c|%c|\n",gameBoard[2][0],gameBoard[2][1],gameBoard[2][2]);
}
/* Display the two game boards on the screen.
   Implemented for you already and no change is needed */
void printTwoGameBoards(int gameBoard1[3][3], int gameBoard2[3][3]) {
    printf("\n");
    printf("# Game Board 1 #\n");
    printGameBoard(gameBoard1);
    printf("# Game Board 2 #\n");
    printGameBoard(gameBoard2);
}
/* Return 1 if the specified game board is dead (i.e., having three-in-a-row of crosses), otherwise return 0. */
int isGameBoardDead(int gameBoard[3][3]){
    int i,j;
    for (i = 0; i < 3; i++) {
        if (gameBoard[i][0] == 88 && gameBoard[i][1] == 88 && gameBoard[i][2] == 88) {
            return 1;
        }
    }
    for (j = 0; j < 3; j++) {
        if (gameBoard[0][j] == 88 && gameBoard[1][j] == 88 && gameBoard[2][j] == 88) {
            return 1;
        }
    }
    if (gameBoard[0][0] == 88 && gameBoard[1][1] == 88 && gameBoard[2][2] == 88) {
        return 1;
    }
    if (gameBoard[0][2] == 88 && gameBoard[1][1] == 88 && gameBoard[2][0] == 88) {
        return 1;
    }
    return 0;
}
/* Update the specific game board according to the user input.
   The user input may not be valid, but you can assume that it must be an integer. */
void updateGameBoard(int gameBoard[3][3]) {
    int cellno;
    int is_valid = 0;
    printf("Choose the cell:\n");
    while(is_valid == 0){
        scanf("%d",&cellno);
        if(cellno==1){
            if(gameBoard[2][0] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[2][0] = 88;
                is_valid = 1;
            }
        }
        else if(cellno==2){
            if(gameBoard[2][1] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[2][1] = 88;
                is_valid = 1;
            }
        }
        else if(cellno==3){
            if(gameBoard[2][2] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[2][2] = 88;
                is_valid = 1;
            }
        }
        else if(cellno==4){
            if(gameBoard[1][0] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[1][0] = 88;
                is_valid = 1;
            }
        }
        else if(cellno==5){
            if(gameBoard[1][1] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[1][1] = 88;
                is_valid = 1;
            }
        }
        else if(cellno==6){
            if(gameBoard[1][2] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[1][2] = 88;
                is_valid = 1;
            }
        }
        else if(cellno==7){
            if(gameBoard[0][0] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[0][0] = 88;
                is_valid = 1;
            }
        }
        else if(cellno==8){
            if(gameBoard[0][1] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[0][1] = 88;
                is_valid = 1;
            }
        }
        else if(cellno==9){
            if(gameBoard[0][2] == 88){
                printf("The chosen cell is occupied. Please input again:\n");
            }
            else{
                gameBoard[0][2] = 88;
                is_valid = 1;
            }
        }
        else if((cellno!=1) || (cellno!=2) || (cellno!=3) || (cellno!=4) || (cellno!=5) ||
          (cellno!=6) || (cellno!=7) || (cellno!=8) || (cellno!=9)){
            printf("Input out of range. Please input again:\n");
        }
    }
}
/* Choose a game board and place a cross according to the user inputs.
   The user input may not be valid, but you can assume that it must be an integer. */
void placeCrossByHumanPlayer(int gameBoard1[3][3], int gameBoard2[3][3]) {
    int gameboard = 0;
    int is_valid = 0;
    printf("Choose the game board:\n");
    while(is_valid == 0){
        scanf("%d",&gameboard);
        if(gameboard==1){
            if(isGameBoardDead(gameBoard1)){
                printf("The chosen game board is dead. Please input again:\n");
            }
            else{
                updateGameBoard(gameBoard1);
                is_valid = 1;
            }
        }
        else if(gameboard==2){
            if(isGameBoardDead(gameBoard2)){
                printf("The chosen game board is dead. Please input again:\n");
            }
            else{
                updateGameBoard(gameBoard2);
                is_valid = 1;
            }
        }
        else if((gameboard!=1)||(gameboard!=2)){
            printf("Input out of range. Please input again:\n");
        }
    }
}
/* Return the number of crosses on the specified game board. */
int countNumOfCrosses(int gameBoard[3][3]) {
   int count = 0;
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(gameBoard[i][j] == 88){
                count++;
            }
        }
    }
    return count;
}
void updateComputerGameboard2fromCaseA(int gameBoard[3][3]){
    printf("Choose the cell:\n");
    if(gameBoard[0][2]!=88){
        printf("9\n");
        gameBoard[0][2] = 88;
    }
    else if(gameBoard[0][1]!=88){
        printf("8\n");
        gameBoard[0][1] = 88;
    }
    else if(gameBoard[0][0]!=88){
        printf("7\n");
        gameBoard[0][0] = 88;
    }
    else if(gameBoard[1][2]!=88){
        printf("6\n");
        gameBoard[1][2] = 88;
    }
    else if(gameBoard[1][1]!=88){
        printf("5\n");
        gameBoard[1][1] = 88;
    }
    else if(gameBoard[1][0]!=88){
        printf("4\n");
        gameBoard[1][0] = 88;
    }
    else if(gameBoard[2][2]!=88){
        printf("3\n");
        gameBoard[2][2] = 88;
    }
    else if(gameBoard[2][1]!=88){
        printf("2\n");
        gameBoard[2][1] = 88;
    }
    else if(gameBoard[2][0]!=88){
        printf("1\n");
        gameBoard[2][0] = 88;
    }
}
void updateComputerGameboard1fromCaseA(int gameBoard[3][3]){
    printf("Choose the cell:\n");
    if(gameBoard[2][0]!=88){
        printf("1\n");
        gameBoard[2][0] = 88;
    }
    else if(gameBoard[2][1]!=88){
        printf("2\n");
        gameBoard[2][1] = 88;
    }
    else if(gameBoard[2][2]!=88){
        printf("3\n");
        gameBoard[2][2] = 88;
    }
    else if(gameBoard[1][0]!=88){
        printf("4\n");
        gameBoard[1][0] = 88;
    }
    else if(gameBoard[1][1]!=88){
        printf("5\n");
        gameBoard[1][1] = 88;
    }
    else if(gameBoard[1][2]!=88){
        printf("6\n");
        gameBoard[1][2] = 88;
    }
    else if(gameBoard[0][0]!=88){
        printf("7\n");
        gameBoard[0][0] = 88;
    }
    else if(gameBoard[0][1]!=88){
        printf("8\n");
        gameBoard[0][1] = 88;
    }
    else if(gameBoard[0][2]!=88){
        printf("9\n");
        gameBoard[0][2] = 88;
    }
}
void updateComputerGameboard1fromCaseB(int gameBoard[3][3]){
    
    printf("Choose the cell:\n");
    int i,j;
    int stop = 0;
    while(!stop){
        int k = 0;
        for(i=2;i>=0;i--){
            for(j=0;j<3;j++){
                if(gameBoard[i][j] != 88){
                    gameBoard[i][j] = 88;
                    if ( isGameBoardDead(gameBoard) ){
                        gameBoard[i][j] = 49 + k;
                        stop = 0;
                    }
                    else{
                        printf("%c\n",49 + k);
                        gameBoard[i][j] = 88;
                        stop = 1;
                        break;
                    }
                }
                k++;
                if(stop == 1){
                    break;
                }
            }
            if(stop == 1){
                break;
            }
        }
        if(stop == 1){
            break;
        }
        else{
            if(gameBoard[2][0]!=88){
                printf("1\n");
                gameBoard[2][0] = 88;
                stop = 1;
            }
            else if(gameBoard[2][1]!=88){
                printf("2\n");
                gameBoard[2][1] = 88;
                stop = 1;
            }
            else if(gameBoard[2][2]!=88){
                printf("3\n");
                gameBoard[2][2] = 88;
                stop = 1;
            }
            else if(gameBoard[1][0]!=88){
                printf("4\n");
                gameBoard[1][0] = 88;
                stop = 1;
            }
            else if(gameBoard[1][1]!=88){
                printf("5\n");
                gameBoard[1][1] = 88;
                stop = 1;
            }
            else if(gameBoard[1][2]!=88){
                printf("6\n");
                gameBoard[1][2] = 88;
                stop = 1;
            }
            else if(gameBoard[0][0]!=88){
                printf("7\n");
                gameBoard[0][0] = 88;
                stop = 1;
            }
            else if(gameBoard[0][1]!=88){
                printf("8\n");
                gameBoard[0][1] = 88;
                stop = 1;
            }
            else if(gameBoard[0][2]!=88){
                printf("9\n");
                gameBoard[0][2] = 88;
                stop = 1;
            }
        }
    }
}

void updateComputerGameboard2fromCaseB(int gameBoard[3][3]){
    printf("Choose the cell:\n");
    int i,j;
    int stop = 0;
    while(!stop){
        int k = 0;
        for(i=0;i<3;i++){
            for(j=2;j>=0;j--){
                if(gameBoard[i][j] != 88){
                    gameBoard[i][j] = 88;
                    if ( isGameBoardDead(gameBoard) ){
                        gameBoard[i][j] = 57 - k;
                        stop = 0;
                    }
                    else{
                        printf("%c\n",57 - k);
                        gameBoard[i][j] = 88;
                        stop = 1;
                        break;
                    }
                }
                k++;
                if(stop == 1){
                    break;
                }
            }
            if(stop == 1){
                break;
            }
        }
        if(stop == 1){
            break;
        }
        else{
            if(gameBoard[0][2]!=88){
                printf("9\n");
                gameBoard[0][2] = 88;
                stop = 1;
            }
            else if(gameBoard[0][1]!=88){
                printf("8\n");
                gameBoard[0][1] = 88;
                stop = 1;
            }
            else if(gameBoard[0][0]!=88){
                printf("7\n");
                gameBoard[0][0] = 88;
                stop = 1;
            }
            else if(gameBoard[1][2]!=88){
                printf("6\n");
                gameBoard[1][2] = 88;
                stop = 1;
            }
            else if(gameBoard[1][1]!=88){
                printf("5\n");
                gameBoard[1][1] = 88;
                stop = 1;
            }
            else if(gameBoard[1][0]!=88){
                printf("4\n");
                gameBoard[1][0] = 88;
                stop = 1;
            }
            else if(gameBoard[2][2]!=88){
                printf("3\n");
                gameBoard[2][2] = 88;
                stop = 1;
            }
            else if(gameBoard[2][1]!=88){
                printf("2\n");
                gameBoard[2][1] = 88;
                stop = 1;
            }
            else if(gameBoard[2][0]!=88){
                printf("1\n");
                gameBoard[2][0] = 88;
                stop = 1;
            }
        }
    }
}

/* Determine the next move of the computer player and update the corresponding game board accordingly.
   You are required to exactly follow the strategy mentioned in the project specification.
   IMPORTANT: Using other strategies will result in mark deduction. */
void placeCrossByComputerPlayer(int gameBoard1[3][3], int gameBoard2[3][3]) {
    int countgameboard1,countgameboard2;
    int gameboard = 0;
    printf("Choose the game board:\n");
    if(isGameBoardDead(gameBoard1)||isGameBoardDead(gameBoard2)){ // Case B 
        if(isGameBoardDead(gameBoard1)){
            printf("2\n");
            gameboard = 2;
            updateComputerGameboard2fromCaseB(gameBoard2);
        }
        else if(isGameBoardDead(gameBoard2)){
            printf("1\n");
            gameboard = 1;
            updateComputerGameboard1fromCaseB(gameBoard1);
        }
    }
    else if( (!isGameBoardDead(gameBoard1)) && (!isGameBoardDead(gameBoard2)) ){ // Case A
        countgameboard1 = countNumOfCrosses(gameBoard1);
        countgameboard2 = countNumOfCrosses(gameBoard2);
        if(countgameboard1<countgameboard2){
            printf("1\n");
            gameboard = 1;
            updateComputerGameboard1fromCaseA(gameBoard1);
        }
        else if(countgameboard2<countgameboard1){
            printf("2\n");
            gameboard = 2;
            updateComputerGameboard2fromCaseA(gameBoard2);
        }
    }
}
/* The main function */
int main()
{
    /* Local variables */
    int gameBoard1[3][3];   // Represent Game Board 1
    int gameBoard2[3][3];   // Represent Game Board 2
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameEnd;            // 0: The game continues   1: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */
    initGameBoard(gameBoard1);
    initGameBoard(gameBoard2);
    currentPlayer = 1;
    gameEnd = 0;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid here
    
    /* Uncomment the following statements to test whether the printTwoGameBoards() and the placeCrossByHumanPlayer() functions are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
    //printTwoGameBoards(gameBoard1, gameBoard2);
    //printf("# Player 1's turn #\n");
    //placeCrossByHumanPlayer(gameBoard1, gameBoard2);
    //printTwoGameBoards(gameBoard1, gameBoard2);
    //printf("# Player 2's turn #\n");
    //placeCrossByHumanPlayer(gameBoard1, gameBoard2);
    //printTwoGameBoards(gameBoard1, gameBoard2);

    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer
       For both cases, Player 1 moves first
       Hint: use a while loop */

    // TODO: Complete this part
    if(numOfHumanPlayers==2){
        while(gameEnd==0){
            printTwoGameBoards(gameBoard1, gameBoard2);
            printf("# Player 1's turn #\n");
            placeCrossByHumanPlayer(gameBoard1, gameBoard2);
            if(isGameBoardDead(gameBoard1) && isGameBoardDead(gameBoard2)){
                printTwoGameBoards(gameBoard1, gameBoard2);
                printf("Congratulations! Player 2 wins!\n");
                gameEnd = 1;
                break;
            }

            printTwoGameBoards(gameBoard1, gameBoard2);
            printf("# Player 2's turn #\n");
            placeCrossByHumanPlayer(gameBoard1, gameBoard2);
            if(isGameBoardDead(gameBoard1) && isGameBoardDead(gameBoard2)){
                printTwoGameBoards(gameBoard1, gameBoard2);
                printf("Congratulations! Player 1 wins!\n");
                gameEnd = 1;
                break;
            }
        }
    }
    else if (numOfHumanPlayers==1){
        while(gameEnd==0){
            printTwoGameBoards(gameBoard1, gameBoard2);
            printf("# Player 1's turn #\n");
            placeCrossByHumanPlayer(gameBoard1, gameBoard2);
            if(isGameBoardDead(gameBoard1) && isGameBoardDead(gameBoard2)){
                printTwoGameBoards(gameBoard1, gameBoard2);
                printf("Computer wins!\n");
                gameEnd = 1;
                break;
            }
            printTwoGameBoards(gameBoard1, gameBoard2);
            printf("# Computer's turn #\n");
            placeCrossByComputerPlayer(gameBoard1, gameBoard2);
            if(isGameBoardDead(gameBoard1) && isGameBoardDead(gameBoard2)){
                printTwoGameBoards(gameBoard1, gameBoard2);
                printf("Congratulations! Player 1 wins!\n");
                gameEnd = 1;
                break;
            }
        }
    }

    return 0;
}