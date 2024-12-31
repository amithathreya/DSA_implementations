#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool eow;
    TrieNode() {
        eow = false;
        for(int i=0;i<26;i++) { child[i] = nullptr;}
    }
};

void insert(TrieNode* root, const string& key) 
{
    TrieNode* cur = root;
    for(char c:key) {
        if(cur->child[c-'a'] == nullptr) {
            TrieNode* newNode = new TrieNode();
            cur->child[c-'a'] = newNode;
        }
        cur = cur->child[c-'a'];
    }
    cur->eow = true;
}

bool search_key(TrieNode* root,const string& key)
{
    if(root == nullptr) {
        return false;
    }
    TrieNode* cur = root;
    for(char c:key) {
        if(cur->child[c-'a'] == nullptr) {
            return false;
        }
        cur = cur->child[c-'a'];
    }
    return cur->eow;
}


int main()
{
    TrieNode* root  = new TrieNode();
    vector<string>arr = {"do","dom","done"};
    for(string& s: arr) {
        cout<<"Key: "<<s<<"\n";
        insert(root,s);
    }
    for(string& s: arr) {
        cout<<"Key: "<<s<<"\n";
        if(search_key(root,s)) {
            cout<<"Present\n";
        } else {
            cout<<"Not present\n";
        }
    }
    return 0;
}