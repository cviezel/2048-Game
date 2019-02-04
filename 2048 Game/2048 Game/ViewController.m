//
//  ViewController.m
//  2048 Game
//
//  Created by Cameron Viezel on 2/1/19.
//  Copyright © 2019 Cameron Viezel. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *label1;
@property (weak, nonatomic) IBOutlet UILabel *label2;

@end

@implementation ViewController

int board[4][4];
bool winFlag = false;
UILabel * screen[2];

NSMutableString *s;

- (void)clearBoard{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            board[i][j] = 0;
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
            NSLog(@"%d", board[i][j]);
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
        //cout << "game over" << endl;
        //game over
    }
}
-(void) checkWin:(int)x
{
    if(x == 2048)
    {
        //cout << "You win!" << endl;
        winFlag = true;
    }
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self clearBoard];
    [self generateNewTile];
    [self generateNewTile];
    [self generateNewTile];
    [self printBoard];
    
    NSLog(@"test!");
    
    screen[0] = _label1;
    screen[1] = _label2;

    screen[0].text = @"2";
    screen[1].text = @"4";
    
    NSLog(@"%@", s);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
