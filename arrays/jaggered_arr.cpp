#include<iostream>
using namespace std;



int main(){
    int row;
    cout<<"how many rows?";
    cin>>row;

    int**arr=new int*[row];
    for(int i=0;i<row;i++){
        int col;
        cout<<"no. of values in row "<<i<<' ';
        cin>>col;
        arr[i]=new int[col];
    }

    
    for(int i=0;i<row;i++){
        for(int j=0;j<1000;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}