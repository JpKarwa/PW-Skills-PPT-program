/*
Given two strings s1 and s2, return *the lowest **ASCII** sum of deleted characters to make two strings equal*.

**Example 1:**

**Input:** s1 = "sea", s2 = "eat"

**Output:** 231

**Explanation:** Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.

Deleting "t" from "eat" adds 116 to the sum.

At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
*/

#include<iostream>
#include<vector>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int n=s1.size();
    int m=s2.size();
    int sum1=0,sum2=0;
    for(auto i:s1) sum1+=i;
    for(auto i:s2) sum2+=i;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=s1[i-1]+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }   
    }
    return (sum1+sum2)-2*dp[n][m];
}

int main(){
    string s1="sea";
    string s2="eat";
    cout<<minimumDeleteSum(s1,s2);
}