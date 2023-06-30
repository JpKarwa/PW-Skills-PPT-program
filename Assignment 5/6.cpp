/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

**Example 1:**

**Input:** nums = [4,3,2,7,8,2,3,1]

**Output:**
[2,3]
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
    
    for(int i=0;i<nums.size();i++){ 
        int indexOfElem = abs(nums[i]) - 1;
        nums[indexOfElem] = - nums[indexOfElem];
        
        
        if(nums[indexOfElem]>0)
            duplicates.push_back(indexOfElem+1);
    }
    return duplicates;
}

int main(){
    vector<int> nums={4,3,2,7,8,2,3,1};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    vector<int> duplicate=findDuplicates(nums);
    for(int i=0;i<duplicate.size();i++){
        cout<<duplicate[i]<<" ";
    }
}