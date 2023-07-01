/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

**Example 1:**

**Input:** n = 3

**Output:** [[1,2,3],[8,9,4],[7,6,5]]
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> a(n,vector<int>(n));
    //index initialisation
    int lb=0;
    int ub=n-1;
    int c=1;
    while(lb<=ub){
        //right
        for(int j=lb;j<=ub;j++){
            a[lb][j]=c++;
        }
        //down
        for(int i=lb+1;i<=ub;i++){
            a[i][ub]=c++;
        }
        //left
        for(int j=ub-1;j>=lb;j--){
            a[ub][j]=c++;
        }
        //up
        for(int i=ub-1;i>lb;i--){
            a[i][lb]=c++;
        }
        lb++;
        ub--;
    }
    return a;
}

int main(){
    int n=3;
    vector<vector<int>> matrix=generateMatrix(n);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}