#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printarr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int kthsmallestno(vector<int> v,int k){
    sort(v.begin(),v.end());
    return v[k-1];

}

int main(){
    vector<int> v={3,4,5,2,6,3,1234,674435,11,-222};
    cout<< kthsmallestno(v,5);

}