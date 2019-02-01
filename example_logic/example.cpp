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
void shortSwipe(int direction)
{
  if(direction == UP)
  {
    for(int i = 3; i > 0; i--)
    {
      for(int j = 0; j < 4; j++)
      {
        if(board[i-1][j] == 0)
        {
          board[i-1][j] = board[i][j];
          board[i][j] = 0;
        }
        else if(board[i][j] == board[i-1][j])
        {
          board[i-1][j] *= 2;
          board[i][j] = 0;
        }
      }
    }
  }
}
void longSwipe(int direction)
{
  if(direction == UP)
  {
    for(int i = 1; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        if(board[i-1][j] == 0)
        {
          board[i-1][j] = board[i][j];
          board[i][j] = 0;
        }
        else if(board[i][j] == board[i-1][j])
        {
          board[i-1][j] *= 2;
          board[i][j] = 0;
        }
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
  //generateBoard();
  board[0][0] = 2;
  board[1][0] = 2;
  board[2][0] = 2;
  printBoard();
  shortSwipe(1);
  printBoard();
  clearBoard();
  board[0][0] = 2;
  board[1][0] = 2;
  board[2][0] = 2;
  printBoard();
  longSwipe(1);
  printBoard();
}
