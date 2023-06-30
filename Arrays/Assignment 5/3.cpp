/*
Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

**Example 1:**

**Input:** nums = [-4,-1,0,3,10]

**Output:** [0,1,9,16,100]

**Explanation:** After squaring, the array becomes [16,1,0,9,100].

After sorting, it becomes [0,1,9,16,100].

*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums){
    int i=0;
    int j=nums.size()-1;

    vector<int> ans(nums.size());

    for(int k=ans.size()-1;k>=0;k--){
        if(abs(nums[j])>abs(nums[i])){
            ans[k]=nums[j]*nums[j];
            j--;
        }
        else{
            ans[k]=nums[i]*nums[i];
            i++;
        }
    }

    return ans;
}

int main(){
    vector<int> nums={-4,-1,0,3,10};

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    
    nums=sortedSquares(nums);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}