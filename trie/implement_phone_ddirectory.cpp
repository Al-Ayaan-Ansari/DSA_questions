#include<iostream> 
#include<vector>
#include<string>
using namespace std;

                                                     //do a dry run for 4-5 testcases to get good
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class Trie{


    public:

        TrieNode* root;
        Trie(){
            root=new TrieNode('\0');
        }

        void insertchar(TrieNode* root,string word){
            //base case
            if(word.length()==0){
                root->isterminal=true;
                return;
            }
            int index=word[0]-'a';
            TrieNode* child;
            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            //abscent
            else{
                child=new TrieNode(word[0]);
                root->children[index]=child;
            }

            ///RECURSION
            insertchar(child,word.substr(1));


        }

        void insertword(string word){
                insertchar(root,word);
        }
        void printSuggestion(TrieNode* curr,vector<string> &temp, string prefix){
            if(curr->isterminal){
                temp.push_back(prefix);
            }

            for(char ch='a';ch<='z';ch++){

                TrieNode* next=curr->children[ch-'a'];
                if(next!=NULL){
                    prefix.push_back(ch);
                    printSuggestion(next, temp,prefix);
                    prefix.pop_back();
                } 

            }
        }

        vector<vector<string>> getSuggestion(string str){
            TrieNode* prev=root;
            string prefix="";
            vector<vector<string>> output;
            for(int i=0;i<str.length();i++){
                char lastchr=str[i];
                prefix.push_back(lastchr);
                //if lastcharectot present or not
                TrieNode* curr=prev->children[lastchr-'a'];
                if(curr==NULL){
                    break;
                }
                
                //if found
                vector<string> temp;
                printSuggestion(curr,temp,prefix);
                output.push_back(temp);
                temp.clear();
                prev=curr;
            }
            return output;
        }
};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t=new Trie();

    //insert all elements
    for(int i=0;i<contactList.size();i++){
        t->insertword(contactList[i]);
    }

    return t->getSuggestion(queryStr);
}

int main(){
    vector<string> input;
    input = {"cod", "coding", "codding", "code" ,"coly"};
    string str="coding";
    vector<vector<string>> ans=phoneDirectory(input,str);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}