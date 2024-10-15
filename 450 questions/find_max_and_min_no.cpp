//find max and min no. in the given array


#include<iostream>
#include<vector>
using namespace std;

void printarr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> max_min(vector<int> v){
    int asize=v.size();
    for(int i=0;i<asize;i++){
        for(int j=0;j<asize-i-1;j++){
            if(v[j]>v[j+1]){
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    vector<int> ans;
    ans.push_back(v[0]);
    ans.push_back(v[asize-1]);
    return ans;

}

int main(){
    vector<int> v={3,4,5,2,6,3,1234,674435,11,-222};
    //max_min(v);
    printarr(max_min(v));
}