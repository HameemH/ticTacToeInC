#include<stdio.h>
#include <stdbool.h>
int winningDecision(int mat[][4],int n)
{
    int i;
    for(i=1;i<=3;i++)
    {
        if(mat[i][1]== mat[i][2] && mat[i][2]==mat[i][3] && mat[i][1]!= -1)
        {
            return mat[i][1];
        }
    }
    for(int j=1;i<=3;i++)
    {
        if(mat[1][j]==mat[2][j] && mat[2][j]==mat[3][j] && mat[1][j]!= -1)
        {
            return mat[1][j];
        }
    }for(i=1;i<=3;i++)
    {
        if(mat[1][1]==mat[2][2] && mat[2][2]==mat[3][3] && mat[1][1]!= -1)
        {
            return mat[1][1];
        }
        else if(mat[1][3]==mat[2][2] && mat[2][2]==mat[3][1] && mat[1][3] != -1)
        {
            return mat[1][3];
        }
    }
    return -1;
}

void printCell(int mat[][4],int n)
{
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(mat[i][j]== -1) printf(" ");
           if(mat[i][j]==1)printf("X");
           if(mat[i][j]==2)printf("0");
           if(j<n)printf("\t|\t");
        }
        printf("\n");
        if(i<n) printf("____________________________________");
        printf("\n\n");
    }
}
int main()
{
    int n=3;
    int mat[4][4];
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mat[i][j]=-1;

        }
    }

    printCell(mat,n);
    bool player1=true;
    bool player2=false;
    while(true)
    {
        if(player1==true)
        {
            Flag:
            int r,c;
            printf("Player One Turn,Enter Row and Column, ");
            scanf("%d %d",&r,&c);
            if(mat[r][c] != -1)
            {
                printf("Invaid Cell\n");
                goto Flag;
            }
            mat[r][c]=1;
            player1=false;
            player2=true;
        }
        else
        {
            Flag1:
            int r,c;
            printf("Player Two Turn,Enter Row and Column, ");
            scanf("%d %d",&r,&c);
            if(mat[r][c] != -1)
            {
                printf("Invaid Cell\n");
                goto Flag1;
            }
            mat[r][c]=2;
            player2=false;
            player1=true;
        }
        printCell(mat,n);

        if(winningDecision(mat,n)==1)
        {
            printf("Player One has Won..\n");
            break;
        }
        else if(winningDecision(mat,n)==2)
        {
            printf("Player Two has Won..\n");
            break;
        }

    }


    return 0;
}
