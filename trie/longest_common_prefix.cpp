#include<iostream>
using namespace std;
#include<vector>
#include<string>

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childcount;
    bool isterminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childcount=0;
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
                root->childcount++;
                root->children[index]=child;
            }

            ///RECURSION
            insertchar(child,word.substr(1));


        }

        void insertword(string word){
                insertchar(root,word);
        }

        void lcp(string firstword,string &ans){
            for(int i=0;i<firstword.length();i++){
                char ch=firstword[i];

                if(root->childcount==1){
                    ans.push_back(ch);
                    int index=ch-'a';
                    root=root->children[index];
                }
                else {
                    break;
                }
                if(root->isterminal){
                    break;
                }

            }
        }

};
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t=new Trie();

        for(int i=0;i<strs.size();i++){
            t->insertword(strs[i]);
        }
        string ans;
        string firststring=strs[0];
        t->lcp(firststring,ans);
        return ans;
    }



int main(){
    vector<string> a={"hello","helli","helcopy"};
    string ans=longestCommonPrefix(a);
    cout<<ans;
}