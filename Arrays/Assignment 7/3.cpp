/*
Given two non-negative integers, num1 and num2 represented as string, return *the sum of* num1 *and* num2 *as a string*.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

**Example 1:**

**Input:** num1 = "11", num2 = "123"

**Output:**

"134"
*/


#include<iostream>
#include<algorithm>
using namespace std;

string addStrings(string &num1,string &num2){
    string result;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    
    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
        int digitSum = digit1 + digit2 + carry;
        
        result += std::to_string(digitSum % 10);
        carry = digitSum / 10;
        
        i--;
        j--;
    }
    
    if (carry > 0) {
        result += std::to_string(carry);
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string num1="11";
    string num2="123";
    cout<<addStrings(num1,num2);
}