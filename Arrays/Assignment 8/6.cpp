/*
Given two strings s and p, return *an array of all the start indices of* p*'s anagrams in* s. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

**Input:** s = "cbaebabacd", p = "abc"

**Output:** [0,6]

**Explanation:**

The substring with start index = 0 is "cba", which is an anagram of "abc".

The substring with start index = 6 is "bac", which is an anagram of "abc".
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    unordered_map<char,int> mp1,mp2;
    int k=p.size();
    vector<int> ans;
    for(int i=0;i<k;i++){
        mp1[p[i]]++;
        mp2[s[i]]++;
    }
    if(mp1==mp2)ans.push_back(0);
    for(int i=k;i<s.size();i++){
        mp2[s[i]]++;
        mp2[s[i-k]]--;
        if(mp2[s[i-k]]==0) {
            mp2.erase(s[i-k]);       
        }
        if(mp1==mp2){
            ans.push_back(i-k+1);
        }
    }
    return ans;
}

int main(){
    string s="cbaebabacd";
    string p="abc";
    vector<int> ans=findAnagrams(s,p);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}