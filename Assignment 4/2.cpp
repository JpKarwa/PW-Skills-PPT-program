/*
Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

- answer[0] *is a list of all distinct integers in* nums1 *which are not present in* nums2.
- answer[1] *is a list of all distinct integers in* nums2 *which are not present in* nums1.

Note that the integers in the lists may be returned in **any** order.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]

Output: [[1,3],[4,6]]

Explanation:

For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].

For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<int> elementInOneArray(vector<int> &nums1,vector<int> &nums2){
    vector<int> ans;
    set<int> onlyInFirst;
    for(auto ele:nums1){
        int occurences=count(nums2.begin(),nums2.end(),ele);
        if(occurences==0) onlyInFirst.insert(ele);
    }
    for(auto itr:onlyInFirst){
        ans.push_back(itr);
    } 

    return ans;
}

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> ans(2);
    
    ans[0]=elementInOneArray(nums1,nums2);
    ans[1]=elementInOneArray(nums2,nums1);

    return ans;
}

int main(){
    vector<int> nums1={1,2,3};
    vector<int> nums2={2,4,6};

    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<nums2.size();i++){
        cout<<nums2[i]<<" ";
    }
    cout<<endl;
    
    vector<vector<int>> diff=findDifference(nums1,nums2);

    for(int i=0;i<diff.size();i++){
        for(int j=0;j<diff[i].size();j++){
            cout<<diff[i][j]<<" ";
        }
        cout<<endl;
    }
}