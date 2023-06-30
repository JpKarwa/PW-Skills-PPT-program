/*
An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.

Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

**Example 1:**

**Input:** changed = [1,3,4,2,6,8]

**Output:** [1,3,4]

**Explanation:** One possible original array could be [1,3,4]:

- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.

Other original arrays could be [4,3,1] or [3,1,4].
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    if(changed.size()&1){return {};}
    sort(changed.begin(), changed.end());
    vector<int>ans;
    unordered_map<int, int>m;
    for(int i=0; i<changed.size(); i++){
        m[changed[i]]++;
    }
    for(int i=0; i<changed.size(); i++){
        if(m[changed[i]]==0){
            continue;
        }
        m[changed[i]]--;
        if(m[changed[i]*2]==0){
            return {};
        }
        m[changed[i]*2]--;
        ans.push_back(changed[i]);
    }
    return ans;
}

int main(){
    vector<int> changed={1,3,4,2,6,8};
    for(int i=0;i<changed.size();i++){
        cout<<changed[i]<<" ";
    }
    cout<<endl;

    vector<int> ans=findOriginalArray(changed);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}