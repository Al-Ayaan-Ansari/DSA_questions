#include<iostream> 
#include<vector>
using namespace std;
int longestMountain(vector<int>& arr) {
        int l=0,r=0;
        int s=0;
        int e=arr.size()-1;
        while(s<e){
            if(arr[s]<arr[s+1]){
                s++;
                l++;
                cout<<"l is "<<l<<" ";
            }
            else{
                s++;
                l=0;
            }
            if(arr[e]<arr[e-1]){
                e--;
                r++;
                cout<<"r is "<<r<<" "; 
            }
            else{
                r=0;
                e--;
            }
        }
        return l+r+1;
    }




int main(){
    //vector<int> arr = {2,1,4,7,3,2,5};
    vector<int> arr1={1,2,34,7,5,4,3,1,2,3,5};
    //cout<<longestMountain(arr)<<endl;
    cout<<longestMountain(arr1)<<endl;

}