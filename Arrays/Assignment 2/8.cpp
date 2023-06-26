/*
You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0

Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
*/

#include<iostream>
#include<vector>
using namespace std;

int minimumScore(vector<int> &nums,int k){
    int n=nums.size();
    int mini=nums[0];
    int maxi=nums[0];
    
    for(int i=1;i<n;i++){
        mini=min(mini,nums[i]);
    }
    for(int i=1;i<n;i++){
        maxi=max(maxi,nums[i]);
    }
    mini=mini+k;
    maxi=maxi-k;
    
    int ans=maxi-mini;
    if(ans<0) return 0;
    return ans;
}

int main(){
    vector<int>nums={1};
    int k=0;
    cout<<minimumScore(nums,0);
}