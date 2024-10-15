#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    
    while (i<=n){
        int num1=n;
        int val1=1;
        while(num1>=i){
            cout<<val1<<' ';
            val1=val1+1;
            num1=num1-1;


        }
        int num2=1;
        while(num2<i){
            cout<<'*'<<' ' ;
            num2=num2+1;

        }
        int num3=1;
        while(num3<i){
            cout<<'*'<<' ';
            num3=num3+1;
        }
        int num4=n;
        int val2=n-i+1;
        while(num4>=i){
            cout<<val2<<' ';
            val2=val2-1;
            num4=num4-1; 
        }
        cout<<endl;
        i=i+1;
        

        



        }
    

}