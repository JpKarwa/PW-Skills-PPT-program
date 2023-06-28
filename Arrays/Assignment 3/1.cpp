/*
Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int nearestsum=nums[0]+nums[1]+nums[2];
    for(int i=0;i<nums.size()-1;i++){
        
        int start=i+1;
        int end=nums.size()-1;

        while(start<end){
            int currentsum =nums[start]+nums[end]+nums[i];
                if(abs(currentsum-target)<abs(nearestsum-target)){
                    nearestsum=currentsum;
                } 
            if(currentsum<target){
                start++;
            } else {
                end--;
            }
        }
        
    }
    return nearestsum;
}

int main(){
    vector<int> nums={-1,2,1,-4};
    int target=1;
    cout<<threeSumClosest(nums,target);
}