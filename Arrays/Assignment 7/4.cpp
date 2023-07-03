/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

**Example 1:**

**Input:** s = "Let's take LeetCode contest"

**Output:** "s'teL ekat edoCteeL tsetnoc"
*/


#include<iostream>
using namespace std;

void reverse(string &s,int start,int end){
    while(start<end){
        swap(s[start++],s[end--]);
    }
}
string reverseWords(string s) {
    int i=0;
    for(int j=0;j<=s.size();j++){
        if(j==s.size() || s[j]==' '){
            int start=i;
            int end=j-1;
            reverse(s,start,end);
            i=j+1;
        }
    }
    return s;
}

int main(){
    string s="Let's take LeetCode contest";
    cout<<reverseWords(s);
}