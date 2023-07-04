/*
Given a string s containing only three types of characters: '(', ')' and '*', return true *if* s *is **valid***.

The following rules define a **valid** string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

**Example 1:**

**Input:** s = "()"

**Output:**

true
*/

#include<iostream>
#include<stack>
using namespace std;

bool checkValidString(string s) {
    int n = s.length();
    stack<int> open;
    stack<int> star;

    for(int i = 0; i < n ; i++){
        if(s[i]=='(')open.push(i);
        else if(s[i]=='*')star.push(i);
        else{
            if(open.empty() && star.empty())return false;
            if(!open.empty())open.pop();
            else star.pop();
        }
    }

    if(!open.empty()){
        if(open.size()>star.size())return false;
        else{
            while(!open.empty()){
                if(open.top()>star.top())return false;
                star.pop();
                open.pop();
            }
        }
    }

    return true;
}

int main(){
    string s="()";
    cout<<checkValidString(s);
}