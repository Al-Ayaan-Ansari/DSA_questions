#include <iostream>
#include <math.h>
using namespace std;


int main(){

    int n;
    int i=0;
    int ans=0;
    cout<<"Enter a binary no."<<endl;
    cin>>n;
    while(n!=0){

        int bit= n%10;
        ans= bit*pow(2,i) + ans;
        i++;

        n=n/10;
    }
    cout<<ans;
}
