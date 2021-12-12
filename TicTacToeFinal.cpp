// Unbeatable Game Of Tic-Tac-Toe
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
using namespace std;

// Functions
void PrintBoard();
int GameCheck();
int Defense();
int Offense();
void GameAI();
void PlayerInput();

// Varriables
int a[3][3];
int k;
int u;
int game=1;
char PlayerName[30];
char str[500];

// This Prints The 3x3 Board
void PrintBoard()
{
    int i;
    int j;

    cout<<"\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]==0)
                cout<<".\t";
            else if(a[i][j]==1)
                cout<<"X\t";
            else
                cout<<"O\t";
        }
        cout<<endl;
    }
}

// This checks if anyone's winning
int GameCheck()
{
    for(int i=0;i<3;i++)
        if((a[i][0]!=0&&a[i][0]==a[i][1]&&a[i][1]==a[i][2])||(a[0][i]!=0&&a[0][i]==a[1][i]&&a[1][i]==a[2][i]))
            return 1;
    
    if(a[0][0]!=0&&a[0][0]==a[1][1]&&a[1][1]==a[2][2])
        return 1;
    else if(a[0][2]!=0&&a[0][2]==a[1][1]&&a[1][1]==a[2][0])
        return 1;
    else
        return 0;
}

// Defense
int Defense(int c, int p, int b)
{
    if(b<3)
        return 0;
    else if(a[0][0]+a[1][1]+a[2][2]==2*c&&a[0][0]!=p&&a[1][1]!=p&&a[2][2]!=p)
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][i]==0)
            {
                a[i][i]=u;
                cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                return 1;
            }
        }
    }
    else if(a[0][2]+a[1][1]+a[2][0]==2*c&&a[0][2]!=p&&a[1][1]!=p&&a[2][0]!=p)
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][2-i]==0)
            {
                a[i][2-i]=u;
                cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                return 1;
            }
        }
    }
    else
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            if(a[i][0]+a[i][1]+a[i][2]==2*c&&a[i][0]!=p&&a[i][1]!=p&&a[i][2]!=p)
            {
                for(j=0;j<3;j++)
                {
                    if(a[i][j]==0)
                    {
                        a[i][j]=u;
                        cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                        return 1;                    }
                }
            }
            else if(a[0][i]+a[1][i]+a[2][i]==2*c&&a[0][i]!=p&&a[1][i]!=p&&a[2][i]!=p)
            {
                for(j=0;j<3;j++)
                {
                    if(a[j][i]==0)
                    {
                        a[j][i]=u;
                        cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// Offense and makes a move to move in the future
int Offense()
{
    int i;
    int j;

    if(a[0][0]+a[0][2]+a[2][0]+a[2][2]==k||a[0][0]+a[0][2]+a[2][0]+a[2][2]==2*k)
    {
        for(i=0;i<3;i++)
        {
            if( a[i][0]+a[i][1]+a[i][2]==u && (a[i][0]==u||a[i][1]==u||a[i][2]==u) )
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(a[i][j]==0)
                        {
                            a[i][j]=u;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(a[i][j]==0)
                        {
                            a[i][j]=u;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            return 1;
                        }
                    }
                }
            }
            if(a[0][i]+a[1][i]+a[2][i]==u && (a[0][i]==u||a[1][i]==u||a[2][i]==u))
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(a[j][i]==0)
                        {
                            a[j][i]=u;
                            cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(a[j][i]==0)
                        {
                            a[j][i]=u;
                            cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                            return 1;
                        }
                    }
                }
                
            }
        }
        
        if(a[0][0]+a[1][1]+a[2][2]==u && (a[0][0]==u||a[1][1]==u||a[2][2]==u))
        {
            for(i=2;i>=0;i--)
            {
                if((a[i][i]==0)&& ((a[i][0]+a[i][1]+a[i][2]==u&&(a[i][0]==u||a[i][1]==u||a[i][2]==u)) ||( (a[0][i]+a[1][i]+a[2][i]==u)&&(a[0][i]==u||a[1][i]==u||a[2][i]==u))))
                {
                    a[i][i]=u;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==k&&(a[i][0]==k||a[i][1]==k||a[i][2]==k))&&(a[0][i]+a[1][i]+a[2][i]==k&&(a[0][i]==k||a[1][i]==k||a[2][i]==k)))
                    {
                        a[i][i]=u;
                        cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    a[i][i]=u;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    return 1;
                }
            }
        }
        else if( a[0][2]+a[1][1]+a[2][0]==u && (a[0][2]==u||a[1][1]==u||a[2][0]==u))
        {
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0&&((a[i][0]+a[i][1]+a[i][2]==u&&(a[i][0]==u||a[i][1]==u||a[i][2]==u))||( (a[0][2-i]+a[1][2-i]+a[2][2-i]==u)&&(a[0][2-i]==u||a[1][2-i]==u||a[2][2-i]==u))))
                {
                    a[i][2-i]=u;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==k&&(a[i][0]==k||a[i][1]==k||a[i][2]==k))&&(a[0][2-i]+a[1][2-i]+a[2][2-i]==k&&(a[0][2-i]==k||a[1][2-i]==k||a[2][2-i]==k)))
                    {
                        a[i][2-i]=u;
                        cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    a[i][2-i]=u;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    return 1;
                }
            }
        }
    }
    else
    {
        if(a[0][0]+a[1][1]+a[2][2]==u && (a[0][0]==u||a[1][1]==u||a[2][2]==u))
        {
            for(i=2;i>=0;i--)
            {
                if((a[i][i]==0)&& ((a[i][0]+a[i][1]+a[i][2]==u&&(a[i][0]==u||a[i][1]==u||a[i][2]==u)) ||( (a[0][i]+a[1][i]+a[2][i]==u)&&(a[0][i]==u||a[1][i]==u||a[2][i]==u))))
                {
                    a[i][i]=u;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==k&&(a[i][0]==k||a[i][1]==k||a[i][2]==k))&&(a[0][i]+a[1][i]+a[2][i]==k&&(a[0][i]==k||a[1][i]==k||a[2][i]==k)))
                    {
                        a[i][i]=u;
                        cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    a[i][i]=u;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    return 1;
                }
            }
        }
        
        else if( a[0][2]+a[1][1]+a[2][0]==u && (a[0][2]==u||a[1][1]==u||a[2][0]==u))
        {
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0&&((a[i][0]+a[i][1]+a[i][2]==u&&(a[i][0]==u||a[i][1]==u||a[i][2]==u))||( (a[0][2-i]+a[1][2-i]+a[2][2-i]==u)&&(a[0][2-i]==u||a[1][2-i]==u||a[2][2-i]==u))))
                {
                    a[i][2-i]=u;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==k&&(a[i][0]==k||a[i][1]==k||a[i][2]==k))&&(a[0][2-i]+a[1][2-i]+a[2][2-i]==k&&(a[0][2-i]==k||a[1][2-i]==k||a[2][2-i]==k)))
                    {
                        a[i][2-i]=u;
                        cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                        return 1;
                    }
                }
            }
            
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    a[i][2-i]=u;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    return 1;
                }
            }
        }
        
        else
        {
            for(i=0;i<3;i++)
            {
                if( a[i][0]+a[i][1]+a[i][2]==u && (a[i][0]==u||a[i][1]==u||a[i][2]==u) )
                {
                    if(i==1)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=u;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                return 1;
                            }
                        }
                    }
                    else{
                        for(j=2;j>=0;j--)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=u;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                return 1;
                            }
                        }
                    }
                }
                else if(a[0][i]+a[1][i]+a[2][i]==u && (a[0][i]==u||a[1][i]==u||a[2][i]==u))
                {
                    if(i==1)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(a[j][i]==0)
                            {
                                a[j][i]=u;
                                cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for(j=2;j>=0;j--)
                        {
                            if(a[j][i]==0)
                            {
                                a[j][i]=u;
                                cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// AI For the Bot
void GameAI(int b)
{   
    // This looks for the winning move
    if(!Defense(u,k,b))
    {   
        // This looks for a Defensive move 
        if(!Defense(k,u,b))
        {
            if((a[0][0]+a[0][2]+a[2][0]+a[2][2]==k+u||a[0][0]+a[0][2]+a[2][0]+a[2][2]==k+2*u)&&a[1][1]==0)
            {
                for(int i=0;i<3;i+=2)
                {
                    for(int j=0;j<3;j+=2)
                        if(a[i][j]==0)
                        {
                            a[i][j]=u;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            goto end;
                        }
                }
                
            }
            else if(b==2&&a[1][1]==0)
            {
                a[1][1]=u;
                cout<<"Computer turn: 2 2\n";
                goto end;
            }
            if(!Offense())
            {
                if(b==0)
                {
                    time_t seconds;
                    time(&seconds);
                    srand((unsigned int) seconds);
                    int i,j;
                    a[(rand()%2)*2][(rand()%2)*2]=u;
                    for(i=0;i<3;i+=2)
                    {
                        for(j=0;j<3;j+=2)
                            if(a[i][j]==u)
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                    }
                }
                else if(a[1][1]==0)
                {
                    a[1][1]=u;
                    cout<<"Computer turn: 2 2\n";
                }
                else
                {
                    int i,j;
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=u;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                goto end;
                            }
                        }
                    }
                }
            }
        }
    }
end:
    cout<<endl;
}

// Retrieves Players Input
void PlayerInput()
{
    int r=0;
    int c=0;

    cout<<"Enter row: ";
    cin>>r;
    cout<<"Enter column: ";
    cin>>c;
    r--;
    c--;
    if(r>2||c>2||r<0||c<0)
    {
        cout<<(str,PlayerName);
        cout<<(str,", This is an Invalid Entry, Please enter a correct Value");
        puts(str);
        PlayerInput();
    }
    else if(a[r][c]!=0)
    {
        cout<<"This Spot Is Taken.\n";
        PlayerInput();
    }
    else
        a[r][c]=k;
}

// Executes Everything
int main()
{
    int i;
    int j;

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            a[i][j]=0;
    if(game==1)
    {
        // Display's Tic - Tac - Toe Word Art
        cout<<"\n___________.__                   ___________                         ___________            \n\\__    ___/|__| ____             \\__    ___/____    ____             \\__    ___/___   ____  \n  |    |   |  |/ ___\\    ______    |    |  \\__  \\ _/ ___\\    ______    |    | /  _ \\_/ __ \\ \n  |    |   |  \\  \\___   /_____/    |    |   / __ \\\\  \\___   /_____/    |    |(  <_> )  ___/ \n  |____|   |__|\\___  >             |____|  (____  /\\___  >             |____| \\____/ \\___  >\n                   \\/                           \\/     \\/                                \\/ \n";
        
        // Asks User for their Name & Greets them
        cout<<"Input Player Name: ";
        cin>>(PlayerName);
        cout<<(str,"\nHi ");
        cout<<(str, PlayerName);
        cout<<(str,", Lets Play a game of Tic Tac Toe.");
        puts(str);
    
        cout<<"";
        cout<<(str,PlayerName);
        cout<<(str,", do you want to go 1st or 2nd?\n(Enter 1 or 2)");
        puts(str);
    }
    else
    {
        cout<<(str,"\nLets See if you can beat me this time ");
        cout<<(str,PlayerName);
        cout<<(str,".\n");
        puts(str);
        
        cout<<(str,"\nOk ");
        cout<<(str,PlayerName);
        cout<<(str,", This time would you like to go go 1st or 2nd?\n(Enter 1 or 2)");
        puts(str);
    }
    
input:
    cin>>k;
    switch(k)
    {
        case 1:
            u=2;
            cout<<"\nSo you are X.\nI will be O.\nLets Start, Good Luck.";
            PrintBoard();
            for(i=0;i<9;)
            {
                PlayerInput();
                PrintBoard();
                i++;
                if(i>4)
                    if(GameCheck()) // This Accounts if the Player wins
                    {
                        cout<<(str,"\nOh, you won ");
                        cout<<(str,PlayerName);
                        cout<<(str," .\nCongrats! You were not supposed to win...Well this is embarrassing\nI need to improve my Algorithm.");
                        puts(str);
                        exit(0);
                        break;
                    }
                if(i>=8)
                    break;
                GameAI(i);
                PrintBoard();
                i++;
                if(i>5)
                    if(GameCheck())
                    {
                        cout<<(str,"\nI am unbeatable ");
                        cout<<(str,PlayerName);
                        puts(str);
                        break;
                    }
            }
            break;
            
        case 2:
            u=1;
            cout<<"\nSo you are O.\nI will be X.\nLets Start, Good Luck.";
            PrintBoard();
            for(i=0;i<9;)
            {
                GameAI(i);
                PrintBoard();
                i++;
                if(i>4)
                    if(GameCheck()) // This Accounts if the Player wins
                    {
                        cout<<(str,"\nI am unbeatable ");
                        cout<<(str,PlayerName);
                        puts(str);
                        break;
                    }
                if(i>=8)
                    break;
                PlayerInput();
                PrintBoard();
                i++;
                if(i>5)
                    if(GameCheck())
                    {
                        cout<<(str,"\nOh, you won ");
                        cout<<(str,PlayerName);
                        cout<<(str," .\nCongrats! You were not supposed to win...Well this is embarrassing\nI need to improve my Algorithm.");
                        puts(str);
                        exit(0);
                        break;
                    }
            }
            break;
        default:
            cout<<(str,PlayerName);
            cout<<(str,", you need to enter either a 1 or a 2.");
            puts(str);
            goto input;
            break;
    }
    if(!GameCheck())
    {
        if(game>1)
            cout<<"Well Played!\nBut you couldn't beat me this time too\n";
        else
            cout<<"Well Played!\nIt is a tie.\n";

    }
    char c;
    cout<<(str,PlayerName);
    cout<<(", Want to play again?");
    cout<<(str," y/n?");
    puts(str);
    cin>>c, "Player Choice: ";
    if(c=='y'||c=='Y')
    {
        game++;
        main();
    }
    else
        cout<<("\nThanks For Playing!");
        exit(0);
    return 0;
}