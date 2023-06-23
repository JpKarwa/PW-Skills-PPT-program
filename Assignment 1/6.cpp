/*
Q6. Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool containDuplicates(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++){
        if(nums[i]==nums[i+1]) return true;
    }
    return false;
}

int main(){
    vector<int>nums={1,2,3,1};
    cout<<containDuplicates(nums);
}