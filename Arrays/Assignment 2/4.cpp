/*
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
*/

#include<iostream>
#include<vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int N=flowerbed.size();        // size of flowerbed
    int canBePlant=0;             // plant can be planted with following non-adjacen=flower rule
    if(n==0) return true;
    if(N==1 && flowerbed[0]==0 && n==1) return true;
    if(N==1 && flowerbed[0]==1 && n==1) return false;
    if(flowerbed[0]==0 && flowerbed[1]==0){
        flowerbed[0]=1;
        canBePlant++;
    }
    if(flowerbed[N-1]==0 && flowerbed[N-2]==0){
        flowerbed[N-1]=1;
        canBePlant++;
    }
    for(int i=1;i<N-1;i++){
        if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
            canBePlant++;
            flowerbed[i]=1;
        };
    }
    if(canBePlant>=n) return true;
    else return false;
}

int main(){
    vector<int> flowerbed={1,0,0,0,1};
    int n=1;
    if(canPlaceFlowers(flowerbed,n)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}