#include<iostream> 
using namespace std;


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
            int index=word[0]-'A';
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
        bool searchchar(TrieNode* root,string word){
            //basecase
            if(word.length()==0){
                return root->isterminal;
            }

            int index=word[0]-'A';
            TrieNode* child;

            if(root->children[index]!=NULL)
                child=root->children[index];
            else{
                return false;
            }

            //recursion
            return searchchar(child,word.substr(1));


        }

        bool search(string word){
            return searchchar(root,word);

        }


};


int main(){
    Trie* t= new Trie();
    t->insertword("word");
}