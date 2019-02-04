#include <iostream>
#include <cstdlib>

using namespace std;

int board[4][4];
bool winFlag = false;

void printBoard()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      cout << board[i][j] << "\t";
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
void generateNewTile()
{
  int openX[16] = {0};
  int openY[16] = {0};
  int count = 0; //counts how many open tiles are available
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
void checkWin(int x)
{
  if(x == 2048)
  {
    cout << "You win!" << endl;
  }
  winFlag = true;
}
void swipeUp()
{
  for(int j = 0; j < 4; j++)
  {
    for(int i = 1; i < 4; i++)
    {
      int n = 0;
      while(n < 3)
      {
        for(int k = 3; k > 0; k--)
        {
          if(board[k-1][j] == 0)
          {
            board[k-1][j] = board[k][j];
            board[k][j] = 0;
          }
        }
        n++;
      }
      if(board[i-1][j] == board[i][j] && board[i][j] != 0)
      {
        board[i-1][j] = 2*board[i][j];
        checkWin(board[i-1][j]);
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
  generateNewTile();
}
void swipeDown()
{
  for(int j = 0; j < 4; j++)
  {
    for(int i = 2; i >= 0; i--)
    {
      int n = 0;
      while(n < 3)
      {
        for(int k = 0; k < 3; k++)
        {
          if(board[k+1][j] == 0)
          {
            board[k+1][j] = board[k][j];
            board[k][j] = 0;
          }
        }
        n++;
      }
      if(board[i+1][j] == board[i][j] && board[i][j] != 0)
      {
        board[i+1][j] = 2*board[i][j];
        checkWin(board[i+1][j]);
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
  generateNewTile();
}
void swipeLeft()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 1; j < 4; j++)
    {
      int n = 0;
      while(n < 3)
      {
        for(int k = 3; k > 0; k--)
        {
          if(board[i][k-1] == 0)
          {
            board[i][k-1] = board[i][k];
            board[i][k] = 0;
          }
        }
        n++;
      }
      if(board[i][j-1] == board[i][j] && board[i][j] != 0)
      {
        board[i][j-1] = 2*board[i][j];
        checkWin(board[i][j-1]);
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
  generateNewTile();
}
void swipeRight()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 2; j >= 0; j--)
    {
      int n = 0;
      while(n < 3)
      {
        for(int k = 0; k < 3; k++)
        {
          if(board[i][k+1] == 0)
          {
            board[i][k+1] = board[i][k];
            board[i][k] = 0;
          }
        }
        n++;
      }
      if(board[i][j+1] == board[i][j] && board[i][j] != 0)
      {
        board[i][j+1] = 2*board[i][j];
        checkWin(board[i][j+1]);
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
  generateNewTile();
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

  generateNewTile();
  generateNewTile();

  //board[0][0] = 1024;
  //board[0][1] = 1024;
  printBoard();

  char c;
  while(c != 'e' && !winFlag)
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
