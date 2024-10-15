#include <iostream>
#include <math.h>
using namespace std;


int main(){

    int n;
    float i=0;
    float ans=0;
    cout<<"entera positive no."<<endl;
    cin>>n;
    while(n!=0){

        int bit= n&1;
        ans = bit*pow(10,i) +ans;
        i++;
        n=n>>1;
    }
    cout<<ans;
}