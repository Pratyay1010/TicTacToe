#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("CLS");
    char board[3][3]={{' ',' ',' '},
                  {' ',' ',' '},
                  {' ',' ',' '}};


    int player=0;
    char player1='X';
    char player2='O';
    int x,y;
    char winner=' ';
    int box_num;

    while(true)
    { 
        player_selection:
            if(player==0)
            {
                cout<<"\nPlayer 1 Play(1-9):- ";
                cin>>box_num;
            }
            else    
            {
                cout<<"\nPlayer 2 Play(1-9):- ";
                cin>>box_num;
            }

        switch(box_num)
        {
            case 1:
                x=0;
                y=0;
            break;
            case 2:
                x=0;
                y=1;
            break;
            case 3:
                x=0;
                y=2;
            break;
            case 4:
                x=1;
                y=0;
            break;
            case 5:
                x=1;
                y=1;
            break;
            case 6:
                x=1;
                y=2;
            break;
            case 7:
                x=2;
                y=0;
            break;
            case 8:
                x=2;
                y=1;
            break;
            case 9:
                x=2;
                y=2;
            break;
        }

        if(player==0)   
        {
            if(board[x][y]==' ')
            {
                board[x][y]=player1;
                player=1;
            }
            else
                {
                    cout<<"Already Selected";
                    goto player_selection;
                }
        }
        else            
        {
            if(board[x][y]==' ')
            {
                board[x][y]=player2;
                player=0;
            }
            else
            {
                cout<<"Already Selected";
                goto player_selection;
            }
                
        }
        system("CLS");

        //Board Display Funtion
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<" "<<board[i][j];
                if(j<2) cout<<" |";
            }
            cout<<endl;
            if(i<2)
            {
                cout<<"---|---|---";
                cout<<endl;
            }
        }

        //Winning Rules
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                //Vertical
                if(board[0][0]==board[0][1] && board[0][1]==board[0][2] && board[0][0]!=' ')
                {
                    winner = board[0][0];
                }
                else if(board[1][0]==board[1][1] && board[1][1]==board[1][2] && board[1][0]!=' ')
                {
                    winner = board[1][0];
                }
                else if(board[2][0]==board[2][1] && board[2][1]==board[2][2] && board[2][0]!=' ')
                {
                    winner = board[2][0];
                }

                //Horizontal
                if(board[0][0]==board[1][0] && board[1][0]==board[2][0] && board[0][0]!=' ')
                {
                    winner = board[0][0];
                }
                else if(board[0][1]==board[1][1] && board[1][1]==board[2][1] && board[0][1]!=' ')
                {
                    winner = board[0][1];
                }
                else if(board[0][2]==board[1][2] && board[1][2]==board[2][2] && board[0][2]!=' ')
                {
                    winner = board[0][2];
                }

                //Diagonal
                if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
                {
                    winner = board[0][0];
                }
                else if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
                {
                    winner = board[0][2];
                }
            }
        }

        if(winner!=' ')
        {
            system("CLS");
            if(winner==player1)
                cout<<"\nPlayer 1(X) Wins!!!!!\n";
            else
                cout<<"\nPlayer 2(O) Wins!!!!\n";
            
            break;
        }

        //Draw
        int flag=0;
        for(int l=0;l<3;l++)
        {
            for(int k=0;k<3;k++)
            {
                if(board[l][k]==' ')
                    flag=1;
            }
        }
        if(flag==0 && winner==' ')
        {
            system("CLS");
            cout<<"Draw!!\n\n";
            break;
        }

    }

    //Board
    for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<" "<<board[i][j];
                if(j<2) cout<<" |";
            }
            cout<<endl;
            if(i<2)
            {
                cout<<"---|---|---";
                cout<<endl;
            }
        }

    return 0;
}
