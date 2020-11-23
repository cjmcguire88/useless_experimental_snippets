/*  Connect Four 
   [TERMINAL EDITION]
    by Jason McGuire  */

#include <stdio.h>

int drop_chip(int, int, int board[6][7]);
int scan_board(int, int board[6][7]);
void update_board(int board[6][7]);

int main() {
    int winner = 0;                 // Used for while loop in main 
    int choice;                     // The column # chosen by the player 
    int player1 = 1, player2 = 2;   // Used to differentiate players in functions
    int board[6][7] = {             // The game board as a 2D array
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0}
    };

    while (winner == 0) {
        /* Player 1's turn */
        printf("Player 1 pick a column (1-7): ");
        scanf("%d", &choice);
        
        /* "Drops chip" into chosen column then prints updated board */
        board[6][7] = drop_chip(player1, choice, board);
        update_board(board);
        
        /* Checks for four in a row */
        winner = scan_board(player1, board);
        if (winner > 0) {
            break;
        }
        
        /* Player 2's turn */
        printf("Player 2 pick a column (1-7): ");
        scanf("%d", &choice);
        
        board[6][7] = drop_chip(player2, choice, board);
        update_board(board);
        
        winner = scan_board(player2, board);
    }
    printf("Player %d is the winner", winner);
}

int drop_chip(int player, int x, int board[6][7]) {
    int i;
    /* Looks for the first empty space in the chosen
        column and changes it to player # */
    for (i=5; i>=0; i--) {
        if (board[i][x-1] == 0) {
            board[i][x-1] = player;
            break;
        }
    }
    return board[6][7];
}

int scan_board(int winner, int x[6][7]) {
    int i, j;
    
    for (i=5; i>=0; i--) {
        /* Check for four in a row vertically */
        if (x[i][j] == x[i-1][j] && x[i-1][j] == x[i-2][j] && x[i-2][j] == x[i-3][j]) {
            return winner;
        }
        for (j=0; i<=6; i++) {
            /* Check horizontally */
            if (x[i][j] == x[i][j+1] && x[i][j+1] == x[i][j+2] && x[i][j+2] == x[i][j+3]) {
                return winner;
            /* Check diagonally(reverse) */
            } else if (x[i][j] == x[i-1][j+1] && x[i-1][j+1] == x[i-2][j+2] && x[i-2][j+2] == x[i-3][j+3]) {
                return winner;
            /* Check diagonally(forward) */
            } else if (x[i][j] == x[i+1][j+1] && x[i+1][j+1] == x[i+2][j+2] && x[i+2][j+2] == x[i+3][j+3]) {
                return winner;

            } else {
                return 0;
            }
        }
    }
}

void update_board(int x[6][7]) {
    /* Prints the board */
    printf("__________________________________________________________\n"
           "|   ___     ___     ___     ___     ___     ___     ___   |\n"
           "|  /   \\   /   \\   /   \\   /   \\   /   \\   /   \\   /   \\  |\n"
           "| |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |\n"
           "|  \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/  |\n"
           "|   ___     ___     ___     ___     ___     ___     ___   |\n"
           "|  /   \\   /   \\   /   \\   /   \\   /   \\   /   \\   /   \\  |\n"
           "| |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |\n"
           "|  \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/  |\n"
           "|   ___     ___     ___     ___     ___     ___     ___   |\n"
           "|  /   \\   /   \\   /   \\   /   \\   /   \\   /   \\   /   \\  |\n"
           "| |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |\n"
           "|  \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/  |\n"
           "|   ___     ___     ___     ___     ___     ___     ___   |\n"
           "|  /   \\   /   \\   /   \\   /   \\   /   \\   /   \\   /   \\  |\n"
           "| |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |\n"
           "|  \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/  |\n"
           "|   ___     ___     ___     ___     ___     ___     ___   |\n"
           "|  /   \\   /   \\   /   \\   /   \\   /   \\   /   \\   /   \\  |\n"
           "| |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |\n"
           "|  \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/  |\n"
           "|   ___     ___     ___     ___     ___     ___     ___   |\n"
           "|  /   \\   /   \\   /   \\   /   \\   /   \\   /   \\   /   \\  |\n"
           "| |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |  %d  | |\n"
           "|  \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/  |\n"
           "|_________________________________________________________|\n",
            x[0][0], x[0][1], x[0][2], x[0][3], x[0][4], x[0][5], x[0][6],
            x[1][0], x[1][1], x[1][2], x[1][3], x[1][4], x[1][5], x[1][6],
            x[2][0], x[2][1], x[2][2], x[2][3], x[2][4], x[2][5], x[2][6],
            x[3][0], x[3][1], x[3][2], x[3][3], x[3][4], x[3][5], x[3][6],
            x[4][0], x[4][1], x[4][2], x[4][3], x[4][4], x[4][5], x[4][6],
            x[5][0], x[5][1], x[5][2], x[5][3], x[5][4], x[5][5], x[5][6]);
}