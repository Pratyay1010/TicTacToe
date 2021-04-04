import numpy as np
import os
os.system("CLS")

#2d array to store the player position
board=np.array([[' ',' ',' '],[' ',' ',' '],[' ',' ',' ']])

p1,p2='x','o' #player1->x player2->o
p=p1

while True:
    while True:
        n=int(input("Enter the posistion (1-9):-")) #position input
        if(n%3==0): #for position divisible by 3
            board[n//3-1][2]=p
            os.system("CLS")
            break

        elif(board[n//3][n-3*(n//3)-1]!=p1 and board[n//3][n-3*(n//3)-1]!=p2): #not divisible by 3 value
            board[n//3][n-3*(n//3)-1]=p
            os.system("CLS")
            break
        else:
            print("Already Filled!!\Choose deffernet no:-\n ")

    print(board) #board
    
    #changing player
    if(p==p1):
        p=p2
    else:
        p=p1

    #Win Statements

    #Horizontal
    flag=0
    win=0
    for i in range(3):
        for j in range(1,3):
            if(board[i][0]==board[i][j] and board[i][0]!=' '):
                flag=1
            else:
                flag=0
                break
        if(flag==1):
            print("h")
            print(board[i][0]," Wins")
            win=1
            break
    if win==1:
        break

    #Vertical
    flag=0
    win=0
    for i in range(3):
        for j in range(1,3):
            if(board[0][i]==board[j][i] and board[0][i]!=' '):
                flag=1
            else:
                flag=0
                break
        if(flag==1):
            print("v")
            print(board[0][i]," Wins")
            win=1
            break
    if win==1:
        break

    #Diagonal
    flag=0
    win=0
    for i in range(1,3):
        if(board[0][0]==board[i][i] and board[0][0]!=' '):
            flag=1
        if(board[0][2]==board[0+i][2-i] and board[0][2]!=' '):
            flag=2
        else:
            flag=0
            break
    if(flag==1):
        print("d1")
        print(board[0][0]," Wins")
        win=1
        break
    elif(flag==2):
        print("d2")
        print(board[0][2]," Wins")
        win=1
        break
    if win==1:
        break

    #Draw Statements
    if(" " not in board):
        print("Draw")
        break
