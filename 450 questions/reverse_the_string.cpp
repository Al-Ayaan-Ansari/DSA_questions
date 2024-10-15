//Given an array (or string), the task is to reverse the array/string.

#include<iostream>
#include<vector>
using namespace std;

void printarr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse(vector<int> nums){
    int s=0;
    int e=nums.size()-1;
    while(s<=e){
        swap(nums[s],nums[e]);
        s++;
        e--;
    }
    printarr(nums);
}

int main(){
    vector<int>v={1111,2222,33,444};
    reverse(v);
    printarr(v);

}