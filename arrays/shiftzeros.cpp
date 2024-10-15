#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printvec(vector <int> vec){
    int asize=vec.size();
    for(int i=0;i<asize;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
/*void shiftzeros(vector <int> vec){
    int asize=vec.size();
    for(int i=0;i<asize;i++){
        if(vec[i]==0){
            int a =vec[i];
            vec.emplace_back(a);
            vec.erase(vec.begin()+i);
        }

    }
}
*/

int main(){
    vector <int> vec={4,0,1,0,56,0,0,99};
    printvec(vec);
    int asize=vec.size();
    int j=0;
    for(int i=0;i<asize;i++){
        if(vec[i]!=0){
            swap(vec[i],vec[j]);
            j++;
        }
    }



    printvec(vec);

}