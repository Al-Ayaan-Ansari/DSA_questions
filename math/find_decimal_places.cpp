// You are given three integers ‘X’, ‘Y’ and ‘N’. Find the value of division X / Y up to ‘N’ decimal places.

// You should return a string that represents the value X / Y up to ‘N’ decimal places. This string must have ‘N’ digits after decimals. You don’t need to round off the result to ‘N’ decimal places, just find the first ‘N’ places after decimals.

// Note:

// 1. It is guaranteed that division X / Y is always finite.

// Example:

// Consider X = 5, Y = 4 and N = 5, then you should return “1.25000”. 
// Note, here we add 3 trailing zeros so that it has exactly 5 digits after decimals.    


#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string findDivision(int x, int y, int n) {
	string ans;
    int integer =x/y;
	ans.push_back(integer+'0');
    ans.push_back('.');
    int decimal=x%y*pow(10,n)/y;
    string deci =to_string(decimal);
    cout<<deci<<endl;
    ans =ans+deci;

	return ans;
}

int main(){
    cout<<findDivision(5,4,5);

}