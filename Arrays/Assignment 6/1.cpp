/*
A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

**Example 1:**

**Input:** s = "IDID"

**Output:**

[0,4,1,3,2]
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> diStringMatch(string s) {
    int n=s.length();
    vector<int> ans(n+1,0);
    int lo=0,hi=n;
    for(int i=0;i<n;i++){
        if(s[i]=='I'){
            ans[i]=lo;
            lo++;
        }
        else{
            ans[i]=hi;
            hi--;
        }
    }
    ans[n]=lo;
    return ans;
}

int main(){
    string s="IDID";
    vector<int> perm=diStringMatch(s);
    for(int i=0;i<perm.size();i++){
        cout<<perm[i]<<" ";
    }
}