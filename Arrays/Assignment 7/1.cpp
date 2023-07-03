/*
Given two strings s and t, *determine if they are isomorphic*.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**

**Input:** s = "egg", t = "add"

**Output:** true
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isIsomorphic(string s, string t) {

    vector<int> v(150,1000);
    // checking w.r.t s
    for(int i=0;i<s.length();i++){
        int idx=int(s[i]);
        if(v[idx]==1000) v[idx]=s[i]-t[i];
        else if(v[idx]!=s[i]-t[i]) return false;
    }
    //empyting the vector
    for(int i=0;i<v.size();i++){
        v[i]=1000;
    }
    // checking w.r.t t
    for(int i=0;i<t.length();i++){
        int idx=int(t[i]);
        if(v[idx]==1000) v[idx]=t[i]-s[i];
        else if(v[idx]!=t[i]-s[i]) return false;
    }

    return true;
}

int main(){
    string s="egg";
    string t="add";
    cout<<isIsomorphic(s,t);
}