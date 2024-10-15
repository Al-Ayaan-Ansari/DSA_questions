#include<iostream> 
#include<string>
using namespace std;

void reverse_str(string& str,int s){
    int n=str.length();
    if(s>=n-1-s){
        return;
    }
    swap(str[s],str[n-1-s]);
    s++;
    
    reverse_str(str,s);
}

int main(){
    string str="asdghjkl;hgfdsghjkhgfdsafghj";
    int len=str.length()-1;
    reverse_str(str,0);
    cout<<str;
}