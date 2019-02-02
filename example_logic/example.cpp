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
void generateNewTile(int direction)
{
  int openX[16] = {0};
  int openY[16] = {0};
  int count = 0;
  int x;
  /*
  if(direction == UP || direction == DOWN)
  {
    if(direction == UP)
      x = 3;
    else if(direction == DOWN)
      x = 0;
    for(int i = 0; i < 4; i++)
    {
      if(board[x][i] == 0)
      {
        open[count] = i;
        count++;
      }
    }
    if(count > 0) //tile on the opposite side of the swipe is free
    {
      int r = rand() % count;
      board[x][open[r]] = 2;
    }
  }
  if(direction == RIGHT || direction == LEFT)
  {
    if(direction == LEFT)
      x = 3;
    else if(direction == RIGHT)
      x = 0;
    for(int i = 0; i < 4; i++)
    {
      if(board[i][x] == 0)
      {
        open[count] = i;
        count++;
      }
    }
    if(count > 0) //tile on the opposite side of the swipe is free
    {
      int r = rand() % count;
      board[open[r]][x] = 2;
    }
  }
*/
  if(count == 0) //no open tiles on opposite side, must use a random tile
  {
    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        if(board[i][j] == 0)
        {
          openY[count] = i;
          openX[count] = j;
          count++;
        }
      }
    }
    if(count != 0) //fill a random tile
    {
      int r = rand() % count;
      cout << "using a random tile at " << openY[r] << " " << openX[r] << endl;
      board[openY[r]][openX[r]] = 2;
    }
    else
    {
      cout << "game over" << endl;
      //game over
    }
  }

}
void swipeUp()
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
    }
  }
  generateNewTile(UP);
}
void swipeDown()
{
  for(int j = 0; j < 4; j++)
  {
    for(int i = 2; i >= 0; i--)
    {
      for(int k = 0; k < 3; k++)
      {
        if(board[k+1][j] == 0)
        {
          board[k+1][j] = board[k][j];
          board[k][j] = 0;
        }
      }
      if(board[i+1][j] == board[i][j] && board[i][j] != 0)
      {
        board[i+1][j] = 2*board[i][j];
        board[i][j] = 0;
        for(int k = 0; k < 3; k++)
        {
          if(board[k+1][j] == 0)
          {
            board[k+1][j] = board[k][j];
            board[k][j] = 0;
          }
        }
      }
    }
  }
  generateNewTile(DOWN);
}
void swipeLeft()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 1; j < 4; j++)
    {
      for(int k = 3; k > 0; k--)
      {
        if(board[i][k-1] == 0)
        {
          board[i][k-1] = board[i][k];
          board[i][k] = 0;
        }
      }
      if(board[i][j-1] == board[i][j] && board[i][j] != 0)
      {
        board[i][j-1] = 2*board[i][j];
        board[i][j] = 0;
        for(int k = 3; k > 0; k--)
        {
          if(board[i][k-1] == 0)
          {
            board[i][k-1] = board[i][k];
            board[i][k] = 0;
          }
        }
      }
    }
  }
  generateNewTile(LEFT);
}
void swipeRight()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 2; j >= 0; j--)
    {
      for(int k = 0; k < 3; k++)
      {
        if(board[i][k+1] == 0)
        {
          board[i][k+1] = board[i][k];
          board[i][k] = 0;
        }
      }
      if(board[i][j+1] == board[i][j] && board[i][j] != 0)
      {
        board[i][j+1] = 2*board[i][j];
        board[i][j] = 0;
        for(int k = 0; k < 3; k++)
        {
          if(board[i][k+1] == 0)
          {
            board[i][k+1] = board[i][k];
            board[i][k] = 0;
          }
        }
      }
    }
  }
  generateNewTile(RIGHT);
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
  board[1][0] = 0;
  board[2][0] = 2;
  //board[0][3] = 2;
  printBoard();

  char c;
  while(c != 'e')
  {
    cin >> c;
    if(c == 'w')
      swipeUp();
    else if(c == 's')
      swipeDown();
    else if(c == 'a')
      swipeLeft();
    else if(c == 'd')
      swipeRight();
    printBoard();
  }

}
