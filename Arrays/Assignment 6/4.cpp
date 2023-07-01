/*
Given a binary array nums, return *the maximum length of a contiguous subarray with an equal number of* 0 *and* 1.

**Example 1:**

**Input:** nums = [0,1]

**Output:** 2

**Explanation:**

[0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int i,j,k,c=0;
    for(i=0;i<nums.size();i++){
        if(nums[i]==0)
        nums[i]=-1;
    }
    for(i=1;i<nums.size();i++){
        nums[i]=nums[i]+nums[i-1];
    }

    unordered_map<int,int>map;
    map[0]=-1;
    for(i=0;i<nums.size();i++){
        int need=nums[i];
        if(map.find(need)!=map.end()){
            j=map[need];
            c=max(c,i-j);
        }
        else
        map[nums[i]]=i;
    }
    return c;
}

int main(){
    vector<int> nums={0,1};
    cout<<findMaxLength(nums);
}