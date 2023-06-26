/*
Alice has n candies, where the ith candy is of type candyType[i]. 
Alice noticed that she started to gain weight, so she visited a doctor. 

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even).
Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3

Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int maxDifferentType(vector<int>&candyType){
    map<int,int> candies;
    // Key -> Type of candies
    // Value -> No. of key type of candies
    int n=candyType.size();
    int canEat=n/2;
    for(auto itr:candyType){
        candies[itr]++;
    }
    int types=candies.size();
    if(types<canEat) return types;
    return canEat;
}

int main(){
    vector<int> candyType={1,1,2,2,3,3};
    cout<<maxDifferentType(candyType);
}