/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed.
Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
The remaining elements of nums are not important as well as the size of nums.
Return k.

Example :
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
*/

#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int> &nums,int val){
    int i=0,j=nums.size()-1;
    while(i<=j){
        if(nums[j]==val) j--;
        else if(nums[i]==val){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        else i++;
    }
    return i;
}

int main(){
    vector<int> nums={3,2,2,3};
    int val=2;
    cout<<removeElement(nums,val);
}