/*
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

**Example 1:**

**Input:** s = "abcdefg", k = 2

**Output:**

"bacdfeg"
*/

#include<iostream>
using namespace std;

string reverseStr(string s, int k) {
    int n=s.size();
    for(int i=0;i<n;i+=2*k){
        int start=i;
        int end=min(i+k-1,n-1);
        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
    return s;
}

int main(){
    string s="abcdefg";
    int k=2;
    cout<<reverseStr(s,k);
}