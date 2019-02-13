//
//  ViewController.m
//  2048 Game
//
//  Created by Cameron Viezel on 2/1/19.
//  Copyright © 2019 Cameron Viezel. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *l1;
@property (weak, nonatomic) IBOutlet UILabel *l2;
@property (weak, nonatomic) IBOutlet UILabel *l3;
@property (weak, nonatomic) IBOutlet UILabel *l4;
@property (weak, nonatomic) IBOutlet UILabel *l5;
@property (weak, nonatomic) IBOutlet UILabel *l6;
@property (weak, nonatomic) IBOutlet UILabel *l7;
@property (weak, nonatomic) IBOutlet UILabel *l8;
@property (weak, nonatomic) IBOutlet UILabel *l9;
@property (weak, nonatomic) IBOutlet UILabel *l10;
@property (weak, nonatomic) IBOutlet UILabel *l11;
@property (weak, nonatomic) IBOutlet UILabel *l12;
@property (weak, nonatomic) IBOutlet UILabel *l13;
@property (weak, nonatomic) IBOutlet UILabel *l14;
@property (weak, nonatomic) IBOutlet UILabel *l15;
@property (weak, nonatomic) IBOutlet UILabel *l16;
@property (weak, nonatomic) IBOutlet UIButton *up;
@property (weak, nonatomic) IBOutlet UIButton *right;
@property (weak, nonatomic) IBOutlet UIButton *down;
@property (weak, nonatomic) IBOutlet UIButton *left;
@property (weak, nonatomic) IBOutlet UILabel *lwinlose;
@property (weak, nonatomic) IBOutlet UILabel *pauseScreen;

@property (nonatomic, strong) NSTimer *timer;
@property (weak, nonatomic) IBOutlet UILabel *lTime;
@property (weak, nonatomic) IBOutlet UIButton *clearBtn;
@property (weak, nonatomic) IBOutlet UIButton *pauseBtn;

@property (strong, nonatomic) IBOutlet UISwipeGestureRecognizer *sLeft;
@property (strong, nonatomic) IBOutlet UISwipeGestureRecognizer *sDown;
@property (strong, nonatomic) IBOutlet UISwipeGestureRecognizer *sRight;
@property (strong, nonatomic) IBOutlet UISwipeGestureRecognizer *sUp;


@end

@implementation ViewController
@synthesize timer;
@synthesize lTime;

int board[4][4];
bool winFlag = false;
bool gameFlag = true;
UILabel * screen[4][4];
int timeCount = 0;
int finalTime = 0;
bool pauseFlag = false;

NSMutableString *s;

- (void)clearBoard{
    _lwinlose.text = @"";
    lTime.text = @"";
    timeCount = 0;
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }
}
- (void)colorLabel:(UILabel *)x
{
    int values[11] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int red = 255;
    if([x.text  isEqual: @"0"]) //0
    {
        [x setText:@""];
    }
    for(int i = 0; i < 11; i++)
    {
        if([x.text isEqual:([NSString stringWithFormat:@"%d", values[i]])])
        {
            red -= 20 * i;
            [x setTextColor: [UIColor colorWithRed:255/255.f green:red/255.f blue:red/255.f alpha:1.0]];
        }
    }
}
- (void)printBoard
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            //NSMutableString * temp = [NSMutableString stringWithString:@"s"];
            NSMutableString * temp = [NSMutableString stringWithFormat:@"%d\t", board[i][j]];
            [s appendString:temp];
            NSLog(@"%d (%d,%d)", board[i][j], i, j);
            screen[i][j].text = [NSString stringWithFormat:@"%d", board[i][j]];
            [self colorLabel:screen[i][j]];
        }
        NSLog(@"\n");
        [s appendString:@"\n"];
    }
    NSLog(@"\n");
    //NSLog(@"%@", s);
    
}

-(void) generateNewTile
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
        //cout << "using a random tile at " << openY[r] << " " << openX[r] << endl;
        board[openY[r]][openX[r]] = 2;
    }
    else
    {
        winFlag = false;
        gameFlag = false;
        //cout << "game over" << endl;
        _pauseScreen.hidden = false;
        _pauseScreen.text = @"Game over!";
        pauseFlag = true;
        //_lwinlose.text = @"You Lose!";
        //game over
    }
}
-(void) checkWin:(int)x
{
    if(x == 2048)
    {
        //cout << "You win!" << endl;
        finalTime = timeCount;
        winFlag = true;
        gameFlag = false;
        pauseFlag = true;
        _pauseScreen.hidden = false;
        _pauseScreen.text = @"You win!";
        //_lwinlose.text = @"You Win!";
        
    }
}
-(void)swipeUp
{
    for(int j = 0; j < 4; j++)
    {
        NSLog(@"hello");
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
                [self checkWin: board[i-1][j]];
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
    [self generateNewTile];
}
-(void) swipeDown
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
                [self checkWin:board[i+1][j]];
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
    [self generateNewTile];
}
- (void) swipeLeft
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
                [self checkWin: board[i][j-1]];
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
    [self generateNewTile];
}
- (void) swipeRight
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
                [self checkWin: board[i][j+1]];
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
    [self generateNewTile];
}
- (IBAction)pressUp:(id)sender {
    if(gameFlag && !pauseFlag)
        [self swipeUp];
    [self printBoard];
}
- (IBAction)pressRight:(id)sender {
    if(gameFlag && !pauseFlag)
        [self swipeRight];
    [self printBoard];
}
- (IBAction)pressDown:(id)sender {
    if(gameFlag && !pauseFlag)
        [self swipeDown];
    [self printBoard];
}
- (IBAction)pressLeft:(id)sender {
    if(gameFlag && !pauseFlag)
        [self swipeLeft];
    [self printBoard];
}
- (IBAction)swipeLeft:(id)sender {
    NSLog(@"left");
    [self pressLeft:sender];
}



- (IBAction)restartGame:(id)sender {
    [self clearBoard];
    [self generateNewTile];
    [self generateNewTile];
    [self printBoard];
    pauseFlag = false;
    gameFlag = true;
    winFlag = false;
    _pauseScreen.hidden = true;
    NSLog(@"clear button pressed");
    finalTime = 0;
    timeCount = 0;
}
-(void)incrementLabel
{
    if(!pauseFlag)
    {
        ++timeCount;
        [lTime setText:[NSString stringWithFormat:@"%d sec", timeCount]];
    }
    
}
- (IBAction)pause:(id)sender {
    NSLog(@"pause button pressed");
    if(!pauseFlag && gameFlag) //pausing game
    {
        pauseFlag = true;
        //[sender setTitle:@"Play" forState:UIControlStateNormal];
        _pauseScreen.text = @"Paused";
        _pauseScreen.hidden = false;
    }
    else if(pauseFlag && gameFlag) //unpausing game
    {
        pauseFlag = false;
        //[sender setTitle:@"Pause" forState:UIControlStateNormal];
        _pauseScreen.hidden = true;
    }
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [_sLeft setDirection:(UISwipeGestureRecognizerDirectionLeft)];
    /*[_sRight setDirection:(UISwipeGestureRecognizerDirectionRight)];
    [_sUp setDirection:(UISwipeGestureRecognizerDirectionUp)];
    [_sDown setDirection:(UISwipeGestureRecognizerDirectionDown)];
    */
    screen[0][0] = _l1;
    screen[0][1] = _l2;
    screen[0][2] = _l3;
    screen[0][3] = _l4;
    screen[1][0] = _l5;
    screen[1][1] = _l6;
    screen[1][2] = _l7;
    screen[1][3] = _l8;
    screen[2][0] = _l9;
    screen[2][1] = _l10;
    screen[2][2] = _l11;
    screen[2][3] = _l12;
    screen[3][0] = _l13;
    screen[3][1] = _l14;
    screen[3][2] = _l15;
    screen[3][3] = _l16;
    
    
    [self clearBoard];
    [self printBoard];
    [self generateNewTile];
    [self generateNewTile];
    [self printBoard];
    NSLog(@"hi");
    
    timer = [NSTimer scheduledTimerWithTimeInterval:1 repeats:YES block:^(NSTimer * _Nonnull timer) {
        [self performSelectorOnMainThread:@selector(incrementLabel) withObject:nil waitUntilDone:NO];
    }];
    //[self swipeUp];
    //[self printBoard];
    
    NSLog(@"test");
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
