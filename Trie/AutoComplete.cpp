 // https://www.geeksforgeeks.org/auto-complete-feature-using-trie/ 



#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    struct TrieNode* child[26];
    bool isWord;
    
    TrieNode() {
        for(int i = 0; i < 26; i++) 
            child[i] = NULL;
        isWord = false;
    }
};

void insert(struct TrieNode* root, string key) {
    struct TrieNode* curr = root;
    
    for(int i = 0; i < key.length(); i++) {
        int idx = key[i] - 'a';
        if(curr->child[idx] == NULL)
            curr->child[idx] = new TrieNode();
        curr = curr->child[idx];
    }
    curr->isWord = true;
}
void suggestionsRec(struct TrieNode* root, string currPrefix) {
    // found a string in trie with the given prefix
    if(root->isWord)
        cout << currPrefix << endl;
    
    for(int i = 0; i < 26; i++) {
        if(root->child[i]) {
            char node = 'a' + i;
            suggestionsRec(root->child[i], currPrefix + node);
        }
    }
}
bool isLastNode(struct TrieNode* root) {
    for(int i = 0; i < 26; i++) {
        if(root->child[i])
            return 0; // is current node has a child then return 0 
    }
    // all children are null so return 1
    return 1;
}
int printAutoSuggestions(TrieNode* root, string query) {
    
    struct TrieNode* curr = root;
    for(char c : query) {
        int idx = c - 'a';
        if(curr->child[idx] == NULL)
            return 0;
        curr = curr->child[idx];
    }
    // if prefix is present as word, but there is no subtree below the last matching TrieNode
    if(isLastNode(curr)) {
        cout << query << endl;
        return -1;
    }
    suggestionsRec(curr, query);
    return 1;
}
int main() {
    struct TrieNode* root = new TrieNode();
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");
    
    int comp = printAutoSuggestions(root, "hel");
    
    if(comp == -1)
        cout << "No other strings found with this prefix\n";
    else if(comp == 0)
        cout << "No string found with this prefix\n";
        
    return 0;
}




/*

OUTPUT

hel
hell
hello
help
helping
helps


*/ 




