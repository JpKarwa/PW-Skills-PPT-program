/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form* [x1,y1,x2,y2,...,xn,yn].

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3

Output: [2,3,5,4,1,7]

Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

*/


#include<iostream>
#include<vector>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans;

    for(int i=0;i<n;i++){
        ans.push_back(nums[i]);
        ans.push_back(nums[n+i]);
    }

    return ans;
}

int main(){
    vector<int> nums={2,5,1,3,4,7};
    int n=3;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    nums=shuffle(nums,3);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}