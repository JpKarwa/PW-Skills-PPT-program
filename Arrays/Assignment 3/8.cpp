/*
Given an array of meeting time intervals where intervals[i] = [starti, endi],
determine if a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canAttend(vector<vector<int>> intervals){
    if(intervals.size()==0) return true;

    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<intervals[i-1][1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> intervals={{0,30},{5,10},{15,20}};
    cout<<canAttend(intervals);
}
