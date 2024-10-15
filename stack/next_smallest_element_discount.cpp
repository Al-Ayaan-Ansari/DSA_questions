// You are given an integer array prices where prices[i] is the price of the ith item in a shop.

// There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

// Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.


//leetcode question no. 1475. Final Prices With a Special Discount in a Shop



#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> finalPrices(vector<int> prices) {
        stack<int> st;
        int n=prices.size();
        vector<int> ans(n);
        st.push(0);
        for(int i=n-1;i>=0;i--){
            int curr=prices[i];
            while(st.top()>curr){
                st.pop();
            }
            ans[i]=curr-st.top();
            st.push(curr);

        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        return ans;
}
int main(){
    vector<int> prices={3,2,5,1,2,4,2};
    finalPrices(prices);
}