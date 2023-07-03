/*
Given two strings s and t, return true *if they are equal when both are typed into empty text editors*. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

**Example 1:**

**Input:** s = "ab#c", t = "ad#c"

**Output:** true

**Explanation:**

Both s and t become "ac".
*/

#include<iostream>
#include<stack>
using namespace std;

string typed(string &s){
    stack<char> s1;
    string ans="";
    for(auto c:s){
        if(c!='#'){
            s1.push(c);
        }
        else if(!s1.empty()){
            s1.pop();
        }
    }

    while(!s1.empty()){
        ans+=s1.top();
        s1.pop();
    }
    return ans;
}

bool backspaceCompare(string s, string t) {
    string s_typed=typed(s);
    string t_typed=typed(t);
    return s_typed==t_typed;
}

int main(){
    string s="ab#c";
    string t="ad#c";
    cout<<backspaceCompare(s,t);
}