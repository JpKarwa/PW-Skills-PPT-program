/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

**Example 1:**

**Input:** coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]

**Output:** true*/


#include<iostream>
#include<vector>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int m=coordinates.size();
    if(m==2) return true;
    
    for(int i=0;i<m-2;i++){
        int num1=coordinates[i+1][1]-coordinates[i][1];
        int denom1=coordinates[i+1][0]-coordinates[i][0];

        int num2=coordinates[i+2][1]-coordinates[i+1][1];
        int denom2=coordinates[i+2][0]-coordinates[i+1][0];

        if(num1*denom2!=num2*denom1) return false;
    }
    return true;
}

int main(){
    vector<vector<int>> coordinates={{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    cout<<checkStraightLine(coordinates);
}

