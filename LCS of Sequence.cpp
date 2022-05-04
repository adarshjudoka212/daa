#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;


char **B;

int LCS(char*, char*);
void print_LCS(char*,char**,int,int);

int main()
{
    cout<<"\n--------------------- LONGEST COMMON SUBSEQUENCE --------------------\n";
    char* str1=new char[100];
    char* str2=new char[100];
    cout<<"\nEnter str1 : ";
    cin>>str1;
    cout<<"\nEnter str2 : ";
    cin>>str2;
    int Result = LCS(str1,str2);
    cout<<"\nLongest common subsequence is of length: "<<Result;
    cout<<"\n\n--------------------------------------------------------------------\n";


    return 0;
}

void print_LCS(char* str1, char** B,int i ,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(B[i][j]=='!')
    {
        print_LCS(str1,B,i-1,j-1);
        cout<<str1[i-1];
    }


    else if(B[i][j]=='^')
    {
        print_LCS(str1,B,i-1,j);
    }
    else
    {
        print_LCS(str1,B,i,j-1);
    }
}

int LCS(char* str1, char* str2)
{
    int n= strlen(str1);
    int m= strlen(str2);

    int i,j;
    B=new char*[n+1];
    for(i=0; i<=n; i++)
    {
        B[i]=new char[m+1];
    }



    for(i=0; i<=n; i++)
    {
        B[i][0]=' ';
    }
    for(i=0; i<=m; i++)
    {
        B[0][i]=' ';
    }


    int **C=new int*[n+1];
    for(i=0; i<=n; i++)
    {
        C[i]=new int[m+1];
    }


    for(i=0; i<=n; i++)
    {
        C[i][0]=0;
    }
    for(i=0; i<=m; i++)
    {
        C[0][i]=0;
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {

            if(str1[i-1]==str2[j-1])
            {
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]='!';
            }
            else
            {
                if(C[i-1][j]>=C[i][j-1])
                {
                    C[i][j]=C[i-1][j];
                    B[i][j]='^';
                }
                else
                {
                    C[i][j]=C[i][j-1];
                    B[i][j]='<';
                }
            }
        }
    }




    cout<<"\nLCS is : ";
    print_LCS(str1,B,n,m);
    cout<<endl;

    return C[n][m];
}
