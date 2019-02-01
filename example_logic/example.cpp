#include <iostream>
#include <cstdlib>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace std;

int board[4][4];

void printBoard()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}
void generateBoard()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      int ans[3] = {2, 4, 8};
      int x = ans[rand() % 3];
      board[i][j] = x;
    }
  }
}
void swipe(int direction)
{
  if(direction == UP)
  {
    for(int j = 0; j < 4; j++)
    {
      for(int i = 1; i < 4; i++)
      {
        for(int k = 3; k > 0; k--)
        {
          if(board[k-1][j] == 0)
          {
            board[k-1][j] = board[k][j];
            board[k][j] = 0;
          }
        }

        if(board[i-1][j] == board[i][j] && board[i][j] != 0)
        {
          board[i-1][j] = 2*board[i][j];
          board[i][j] = 0;
          for(int k = 3; k > 0; k--)
          {
            if(board[k-1][j] == 0)
            {
              board[k-1][j] = board[k][j];
              board[k][j] = 0;
            }
          }
        }
        //cout << i << endl;
        //printBoard();
      }
    }
  }
}
void clearBoard()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      board[i][j] = 0;
    }
  }
}
int main()
{
  clearBoard();
  generateBoard();
  board[0][0] = 2;
  board[1][0] = 2;
  board[2][0] = 2;
  board[3][0] = 2;
  printBoard();
  swipe(1);
  printBoard();
  /*
  clearBoard();
  board[0][0] = 2;
  board[1][0] = 2;
  board[2][0] = 2;
  board[3][0] = 2;
  printBoard();
  longSwipe(1);
  printBoard();
  */
}
