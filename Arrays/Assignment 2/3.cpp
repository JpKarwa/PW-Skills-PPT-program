/*
We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5

Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longestHarmoniousSubsequence(vector<int> &nums){
    int n=nums.size();

    sort(nums.begin(),nums.end());

    int start=0;
    int end=1;

    int maxLength=0;

    while(end<n){
        int diff=nums[end]-nums[start];

        if(diff==1){
            maxLength=max(maxLength,end-start+1);
            end++;
        }
        else if(diff<1){
            end++;
        }
        else if(diff>1){
            start++;
        }
    }
    return maxLength;
}

int main(){
    vector<int> nums={1,3,2,2,5,2,3,7};
    cout<<longestHarmoniousSubsequence(nums);
}