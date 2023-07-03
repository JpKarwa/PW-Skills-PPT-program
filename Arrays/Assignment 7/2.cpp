/*
Given a string num which represents an integer, return true *if* num *is a **strobogrammatic number***.

A **strobogrammatic number** is a number that looks the same when rotated 180 degrees (looked at upside down).

**Example 1:**

**Input:** num = "69"

**Output:**
true

*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

bool strobogrammaticNumber(string &num){
    map<char,char> numbers;
    numbers['0']='0';
    numbers['1']='1';
    numbers['8']='8';
    numbers['6']='9';
    numbers['9']='6';

    int left = 0, right = num.length() - 1;
    while (left <= right) {
        char c = num[left];
        if (numbers.find(c) == numbers.end() || numbers[c] != num[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main(){
    string num="69";
    cout<<strobogrammaticNumber(num);
}