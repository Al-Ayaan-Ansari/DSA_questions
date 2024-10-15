#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void solve(vector<int> nums,int index,vector<vector<int>>&ans){
        //basecase
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans);
            swap(nums[i],nums[index]);
            
        }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size()==1){
            return {nums};
        }
        vector<vector<int>> ans;
        int index=0;
        solve(nums,index,ans);
        sort(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size()-1){
            if(ans[i]==ans[i+1]){
                ans.erase(ans.begin()+i);
                cout<<"working"<<endl;
            }
            else{
                i++;
                cout<<"not"<<endl;
            }
        }
        return ans;
    }

int main(){
    vector<int> nums={-1,2,-1,2,1,-1,2,1};
    vector<vector<int>> ans =permuteUnique(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}