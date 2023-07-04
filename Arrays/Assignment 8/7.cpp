/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

**Example 1:**

**Input:** s = "3[a]2[bc]"

**Output:** "aaabcbc"
*/

#include<iostream>
using namespace std;

string solve(string &s,int &index){
    string ans = "";
    while(index < s.length() && s[index] != ']'){
        if(isdigit(s[index])){
            string number = "";
            while(index < s.length() && isdigit(s[index])){
                number.push_back(s[index]);
                index++;
            }
            index++;
            string smallans = solve(s,index);
            int iteration  =  stoi(number);
            while(iteration-- !=0){
                ans.append(smallans);
            }
            index++;
        }
        if(s[index] >= 'a' && s[index] <='z'){
            ans+=s[index++];
        }
    }
    return ans;
}

string decodeString(string s) {
    int idx=0;
    return solve(s,idx); 
}

int main(){
    string s="3[a]2[bc]";
    cout<<decodeString(s);
}