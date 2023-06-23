/*
Q7. Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

*/

#include<iostream>
#include<vector>
using namespace std;

void moveZeros(vector<int>&nums){
    int n=nums.size();
    int i=0;
    int j=0;
    while(j<n){
        if(nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }
}
int main(){
    vector<int> nums={0,1,0,3,12};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    moveZeros(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}