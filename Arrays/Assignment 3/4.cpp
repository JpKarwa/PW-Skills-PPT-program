/*
Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in
order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

int searchInsertPosition(vector<int> &nums,int target){
    int n=nums.size();

    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return s;
}

int main(){
    vector<int> nums={1,3,5,6};
    int target=5;

    cout<<searchInsertPosition(nums,target);
}