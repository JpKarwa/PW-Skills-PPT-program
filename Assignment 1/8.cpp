/*
Q8. You have a set of integers s, which originally contains all the numbers from 1 to n. 

Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

*/

#include<iostream>
#include<vector>
using namespace std;


vector<int> misDup(vector<int>&nums){
    int n=nums.size();
    vector<int> ans;
    vector<int>freq(n+1,0);
    int twice,missing;
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }
    for(int i=1;i<n+1;i++){
        if(freq[i]>1) twice=i;
        if(freq[i]==0) missing=i;
    }
    ans.push_back(twice);
    ans.push_back(missing);
    return ans;
}

int main(){
    vector<int> nums={1,2,2,4};
    vector<int> ans=misDup(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}