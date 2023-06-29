/*
Given a 2D integer array matrix, return *the **transpose** of* matrix.

The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

Output: [[1,4,7],[2,5,8],[3,6,9]]

*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m=matrix.size();  //rows
    int n=matrix[0].size(); //columns
    vector<vector<int>> t(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            t[i][j]=matrix[j][i];
        }
    }
    return t;
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    matrix=transpose(matrix);

    cout<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}