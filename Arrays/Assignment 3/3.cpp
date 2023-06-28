/*
A permutation of an array of integers is an arrangement of its members into a
sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater
permutation of its integer. More formally, if all the permutations of the array are
sorted in one container according to their lexicographical order, then the next
permutation of that array is the permutation that follows it in the sorted container.

If such an arrangement is not possible, the array must be rearranged as the
lowest possible order (i.e., sorted in ascending order).

● For example, the next permutation of arr = [1,2,3] is [1,3,2].
● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reversePart(int i,int j,vector<int> &nums){
    while(i<j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    int idx=-1; //Pivot Index

    //finding pivot Index
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
    }    

    if(idx==-1){
        //pura array reverse krdo
        reversePart(0,n-1,nums);
        return;
    }

    //reverse from pivotIndex+1 to end
    reversePart(idx+1,n-1,nums);
    
    //Finding just greater element from element at idx
    int justGreater=-1;
    for(int i=idx+1;i<n;i++){
        if(nums[i]>nums[idx]){
            justGreater=i;
            break;
        }
    }

    //swap element at pivotIndex and justGreater;
    int temp=nums[idx];
    nums[idx]=nums[justGreater];
    nums[justGreater]=temp;
}

int main(){
    vector<int> nums={1,2,3};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
    cout<<endl;
    
    nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
    cout<<endl;
}