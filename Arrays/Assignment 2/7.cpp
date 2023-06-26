/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true
*/

#include<iostream>
#include<vector>
using namespace std;

bool isMonotonic(vector<int>& nums) {
    int n=nums.size();
    bool inc=true;
    bool dec=true;
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]) inc=false;
    }
    for(int i=0;i<n-1;i++){
        if(nums[i]<nums[i+1]) dec=false;
    }

    return inc||dec;
}

int main(){
    vector<int> nums={1,2,2,3};
    if(isMonotonic(nums)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}