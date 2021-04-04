import numpy as np
import os

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
        
    """temp=a[0][0]
    flag=0
    for i in range(3):
        for j in range(3):
            if(a[i][j]==temp):
                flag=1
        if flag==1:
            print(a[i][0]+" Wins")
            break"""

    #Draw Statementas
    if(" " not in board):
        print("Draw")
        break