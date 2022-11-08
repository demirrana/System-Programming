#include <stdio.h>

int main ()
{

   printf("The game has started!\n\n");

   int count = 0; //determines if R's or Y's turn
   
   char board[6][7];
   int row = 6;
   int col = 7;
   for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
         board[i][j] = '_';
   
   printf("X 0 1 2 3 4 5 6 X\n");
   printf("0 %c %c %c %c %c %c %c 0\n", board[0][0] , board[0][1] , board[0][2] , board[0][3] , board[0][4] , board[0][5] , board[0][6]);
   printf("0 %c %c %c %c %c %c %c 0\n", board[1][0] , board[1][1] , board[1][2] , board[1][3] , board[1][4] , board[1][5] , board[1][6]);
   printf("0 %c %c %c %c %c %c %c 0\n", board[2][0] , board[2][1] , board[2][2] , board[2][3] , board[2][4] , board[2][5] , board[2][6]);
   printf("0 %c %c %c %c %c %c %c 0\n", board[3][0] , board[3][1] , board[3][2] , board[3][3] , board[3][4] , board[3][5] , board[3][6]);
   printf("0 %c %c %c %c %c %c %c 0\n", board[4][0] , board[4][1] , board[4][2] , board[4][3] , board[4][4] , board[4][5] , board[4][6]);
   printf("0 %c %c %c %c %c %c %c 0\n", board[5][0] , board[5][1] , board[5][2] , board[5][3] , board[5][4] , board[5][5] , board[5][6]);
   printf("X 0 1 2 3 4 5 6 X\n\n");
   
   int player; //determines which player's move will be executed

   while (count >= 0) {

      int gameEnd = 0;
      
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < col; j++)
         {
            if (board[i][j] == '_')
               gameEnd++;
         }
      }
      
      if (gameEnd == 0)
      {
         printf("The game has ended!\n");
         break;
      }
      
      if (count % 2 == 0) {
         printf("Player 1's Turn (R):\n");
         player = 1;
      }
      else {
         printf("Player 2's Turn (Y):\n");
         player = 2;
      }
      
      int move;
      printf("Enter a move: ");
      scanf("%d", &move);
      printf("\n");
      
      if (move < 0 || move > 6) {
      
         printf("Entered move is not valid!\n\n");
         
         printf("X 0 1 2 3 4 5 6 X\n");
         printf("0 %c %c %c %c %c %c %c 0\n", board[0][0] , board[0][1] , board[0][2] , board[0][3] , board[0][4] , board[0][5] , board[0][6]);
         printf("0 %c %c %c %c %c %c %c 0\n", board[1][0] , board[1][1] , board[1][2] , board[1][3] , board[1][4] , board[1][5] , board[1][6]);
         printf("0 %c %c %c %c %c %c %c 0\n", board[2][0] , board[2][1] , board[2][2] , board[2][3] , board[2][4] , board[2][5] , board[2][6]);
         printf("0 %c %c %c %c %c %c %c 0\n", board[3][0] , board[3][1] , board[3][2] , board[3][3] , board[3][4] , board[3][5] , board[3][6]);
         printf("0 %c %c %c %c %c %c %c 0\n", board[4][0] , board[4][1] , board[4][2] , board[4][3] , board[4][4] , board[4][5] , board[4][6]);
         printf("0 %c %c %c %c %c %c %c 0\n", board[5][0] , board[5][1] , board[5][2] , board[5][3] , board[5][4] , board[5][5] , board[5][6]);
         printf("X 0 1 2 3 4 5 6 X\n\n");
         
         continue;
      }
      
      int columnIsFull = 0;
      
      for (int i = row - 1; i >= 0; i--) {
      
         if (board[i][move] == '_') {
         
            if (player == 1)   board[i][move] = 'R';
            else               board[i][move] = 'Y';

            break;
         }
         if (i == 0) { //that means the column is full
         
            printf("The column is full, try again!\n\n");
            
            printf("X 0 1 2 3 4 5 6 X\n");
            printf("0 %c %c %c %c %c %c %c 0\n", board[0][0] , board[0][1] , board[0][2] , board[0][3] , board[0][4] , board[0][5] , board[0][6]);
            printf("0 %c %c %c %c %c %c %c 0\n", board[1][0] , board[1][1] , board[1][2] , board[1][3] , board[1][4] , board[1][5] , board[1][6]);
            printf("0 %c %c %c %c %c %c %c 0\n", board[2][0] , board[2][1] , board[2][2] , board[2][3] , board[2][4] , board[2][5] , board[2][6]);
            printf("0 %c %c %c %c %c %c %c 0\n", board[3][0] , board[3][1] , board[3][2] , board[3][3] , board[3][4] , board[3][5] , board[3][6]);
            printf("0 %c %c %c %c %c %c %c 0\n", board[4][0] , board[4][1] , board[4][2] , board[4][3] , board[4][4] , board[4][5] , board[4][6]);
            printf("0 %c %c %c %c %c %c %c 0\n", board[5][0] , board[5][1] , board[5][2] , board[5][3] , board[5][4] , board[5][5] , board[5][6]);
            printf("X 0 1 2 3 4 5 6 X\n\n");
            
            columnIsFull++;
         }
      }
      
      if (columnIsFull == 1) //when column is full, goes back to the first situation
         continue;
      
      //printing after the valid move is done
      printf("X 0 1 2 3 4 5 6 X\n");
      printf("0 %c %c %c %c %c %c %c 0\n", board[0][0] , board[0][1] , board[0][2] , board[0][3] , board[0][4] , board[0][5] , board[0][6]);
      printf("0 %c %c %c %c %c %c %c 0\n", board[1][0] , board[1][1] , board[1][2] , board[1][3] , board[1][4] , board[1][5] , board[1][6]);
      printf("0 %c %c %c %c %c %c %c 0\n", board[2][0] , board[2][1] , board[2][2] , board[2][3] , board[2][4] , board[2][5] , board[2][6]);
      printf("0 %c %c %c %c %c %c %c 0\n", board[3][0] , board[3][1] , board[3][2] , board[3][3] , board[3][4] , board[3][5] , board[3][6]);
      printf("0 %c %c %c %c %c %c %c 0\n", board[4][0] , board[4][1] , board[4][2] , board[4][3] , board[4][4] , board[4][5] , board[4][6]);
      printf("0 %c %c %c %c %c %c %c 0\n", board[5][0] , board[5][1] , board[5][2] , board[5][3] , board[5][4] , board[5][5] , board[5][6]);
      printf("X 0 1 2 3 4 5 6 X\n\n");
      
      //control of win case
      int win = 0;
      
      for (int i = row - 1; i >= 3; i--) //vertical case
         for (int j = col - 1; j >= 0; j--) {
         
            if (board[i][j] == board[i - 1][j] && board[i - 1][j] == board[i - 2][j] && board[i - 2][j] == board[i - 3][j] && board[i][j] != '_') {
            
               printf("Player %d has won!\n\n", player);
               win++;
            }
         }
         
      for (int j = col - 1; j >= 3; j--) //horizontal case
         for (int i = row - 1; i >= 0; i--) {
         
            if (board[i][j] != '_' && board[i][j] == board[i][j - 1] && board[i][j - 1] == board[i][j - 2] && board[i][j - 2] == board[i][j - 3]) {
            
               printf("Player %d has won!\n\n" , player);
               win++;
            }
         }
         
      for (int i = row - 1; i >= 3; i--) //diagonal case (from right bottom corner to the left upper corner)
         for (int j = col - 1; j >= 3; j--) {
         
            if (board[i][j] != '_' && board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i - 2][j - 2] && board[i][j] == board[i - 3][j - 3]) {
            
               printf("Player %d has won!\n\n" , player);
               win++;
            }
         }
         
      for (int i = 0; i <= 2; i++) //diagonal case (from left bottom corner to the right upper corner)
         for (int j = col - 1; j >= 3; j--) {
         
            if (board[i][j] != '_' && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3]) {
            
               printf("Player %d has won!\n\n" , player);
               win++;
            }
         }
         
      if (win == 1)
         break;
         
      count++;

   }
   
   return 0;
}
