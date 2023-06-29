/*
You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations

Input: m = 3, n = 3, ops = [[2,2],[3,3]]

Output: 4

Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
*/

#include<iostream>
#include<vector>
using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    int a = m;
    int b = n;
    for (auto i: ops){
        if (i[0] < a){
            a = i[0];
        }
        if (i[1] < b){
            b = i[1];
        } 
    }
    return (a * b);
}

int main(){
    int m=3,n=3;
    vector<vector<int>> ops={{2,2},{3,3}};

    cout<<maxCount(m,n,ops);
}