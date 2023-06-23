/*
Q1. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example:
Input: nums = [2,7,11,15], target = 9
Output0 [0,1]

Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]

*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> twosum(vector<int> &nums,int target){
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> indices=twosum(nums,target);
    for(int i=0;i<indices.size();i++){
        cout<<indices[i]<<" ";
    }
    return 0;
}