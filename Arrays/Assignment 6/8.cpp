/*
**Question 8**

Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

**Example 1:**

**Input:** mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]

**Output:**

[[7,0,0],[-7,0,3]]

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &mat1,vector<vector<int>> &mat2){
    int m = mat1.size();
    int n = mat2.size();
    int l = mat2[0].size();
    vector<vector<int>> ans(m, vector<int>(l));

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < l; ++j){
            for(int k = 0; k < n; ++k){
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> mat1={{1,0,0},{-1,0,3}};
    vector<vector<int>> mat2={{7,0,0},{0,0,0},{0,0,1}};

    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++){
            cout<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<mat2.size();i++){
        for(int j=0;j<mat2[i].size();j++){
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<vector<int>> ans=multiply(mat1,mat2);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}