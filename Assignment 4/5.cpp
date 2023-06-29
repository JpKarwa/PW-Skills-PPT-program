/*
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.

Given the integer n, return *the number of **complete rows** of the staircase you will build*.

Input: n = 5

Output: 2

Explanation: Because the 3rd row is incomplete, we return 2.
*/

#include<iostream>
using namespace std;

int arrangeCoins(int n) {
    int lo=1;
    int hi=n;

    while(lo<=hi){
        long long k=lo+(hi-lo)/2; 
        long long m=k*(k+1)/2; 
        if(m > n) hi=k-1;
        else if(m < n) lo=k+1;
        else if(m == n){
            return k;
        }
    }
    return hi;
}

int main(){
    int n=5;
    cout<<arrangeCoins(n);
}