/*
Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order,
return a sorted array of only the integers that appeared in all three arrays.
Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

Output: [1,5]

Explanation: Only 1 and 5 appeared in the three arrays.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPresent(vector<int> &arr,int x){
    int s=0;
    int e=arr.size()-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]==x) return true;
        else if(arr[mid]>x) e=mid-1;
        else s=mid+1;
    }

    return false;
}

vector<int> intersectionOfThreeSortedArrays(vector<int> arr1,vector<int> arr2,vector<int> arr3){
    int n1=arr1.size();
    int n2=arr2.size();
    int n3=arr3.size();

    vector<int> ans;

    for(int i=0;i<n1;i++){
        if(i!=0 && arr1[i]==arr1[i-1]){
            continue;
        }
        int ele=arr1[i];
        if(isPresent(arr2,ele) && isPresent(arr3,ele)){
            int count1=count(arr1.begin(),arr1.end(),ele);
            int count2=count(arr2.begin(),arr2.end(),ele);
            int count3=count(arr3.begin(),arr3.end(),ele);

            int minCount=min(count1,count2);
            minCount=min(minCount,count3);

            for(int i=0;i<minCount;i++){
                ans.push_back(ele);
            }
        }
    }
    
    return ans;
}
int main(){
    vector<int> arr1={1,2,3,4,5};
    vector<int> arr2={1,2,5,7,9};
    vector<int> arr3={1,3,4,5,8};

    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<arr3.size();i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;

    vector<int> intersection=intersectionOfThreeSortedArrays(arr1,arr2,arr3);
    for(int i=0;i<intersection.size();i++){
        cout<<intersection[i]<<" ";
    }
}