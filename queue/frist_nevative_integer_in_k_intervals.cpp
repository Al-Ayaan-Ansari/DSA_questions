#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
vector<int> firstNegativeInteger(vector<int> arr, int k, int n)
{
    vector<int> ans;
    queue<int> d;
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            d.push(i);
        }
    }
    if(d.size()>0){
        ans.push_back(arr[d.front()]);
    }
    else{
        ans.push_back(0);
    }

    for(int i=k;i<n;i++){
        if(!d.empty()&&i-d.front()>=k){
            d.pop();
        }
        if(arr[i]<0){
            d.push(i);
        }

        if(d.size()>0){
        ans.push_back(arr[d.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}
