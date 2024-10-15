#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
        int asize=nums.size();
        for(int i=0;i<k;i++){
            int val=nums[asize-1-i];
            nums.resize(asize+1);
            nums.insert(nums.begin(),val);
            nums.erase(nums.end());
            
        }
}
void printvec(vector<int>vec){
    int a=vec.size();
    for(int i=0;i<a;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> val={34,43,2,24,2,24,242,422};
    rotate(val,6);
    printvec(val);
}
