#include<iostream>
using namespace std;


bool isSafe(int** arr,int x,int y,int n){

    //checking in every column
    for(int row=0 ; row<x ; row++){
        if(arr[row][y]==1)
            return false;
    }
    //checking left digonal
    int row=x;
    int col=y;
    while (row>=0 && col>=0){
        if (arr[row][col]==1)
            return false;
        row--;
        col--;
    }
    //checking in right upper digonal
    row=x;
    col=y;
    while (row>=0 && col<n){
        if (arr[row][col]==1)
            return false;
        row--;
        col++;
    }
    return true;
}

bool nQueen(int** arr,int row,int n){
    if(row>=n) return true;

    for (int col=0;col<n;col++)
    {
        if( isSafe ( arr , row , col , n ) )
        {   
            arr[row][col]=1;

            if( nQueen( arr, row+1, n))
                return true;
            
            arr[row][col]=0; //Remove the Queen **Backtrack**
        }
    }
    return false;
}

int main(){

    int n;
    cout<<"Enter Number of rows: ";
    cin>>n;

    int** arr=new int*[n];

    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }

    if(nQueen(arr,0,n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
