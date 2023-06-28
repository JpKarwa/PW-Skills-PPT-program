/*
You are given an inclusive range [lower, upper] and a sorted unique integer array
nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in
nums.

Return the shortest sorted list of ranges that exactly covers all the missing
numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.

Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]

Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
*/

#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> shortestList(vector<int> nums,int lower,int upper){
    vector<pair<int,int>> ans;
    if(nums.size()==0){
        pair<int,int> p;
        p.first=lower;
        p.second=upper;
        ans.push_back(p);
        return ans;
    }

    int start=lower;
    for(int ele:nums){
        if(start<ele){
            pair<int,int> p;
            p.first=start;
            p.second=ele-1;
            ans.push_back(p);
        }
        start=ele+1;
    }
    
    if(start<=upper){
        pair<int,int> p;
        p.first=start;
        p.second=upper;
        ans.push_back(p);
    }

    return ans;
}


int main(){
    vector<int> nums={0,1,3,50,75};
    vector<pair<int,int>> ans=shortestList(nums,0,99);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}