/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumProduct(vector<int> nums){
    int n=nums.size();

    if(n==3){
        int ans=nums[n-1]*nums[n-2]*nums[n-3];
        return ans;
    }

    sort(nums.begin(),nums.end());
    int prod1=nums[n-1]*nums[n-2]*nums[n-3];
    int prod2=nums[0]*nums[1]*nums[n-1];

    int maxProduct=max(prod1,prod2);

    return maxProduct;
}
int main(){
    vector<int> nums={1,2,3};
    cout<<maximumProduct(nums);
}