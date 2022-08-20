//   https://www.youtube.com/watch?v=SK2S5lQegVg&ab_channel=CodeHelp-byBabbar

//   https://practice.geeksforgeeks.org/problems/phone-directory4628/1



class Solution{
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        TrieNode() {
            for(int i = 0; i < 26; i++) 
                child[i] = NULL;
                
            isEnd = false;
        }
    };
    class Trie {
        TrieNode* root;
        public:
        Trie() {
            root = new TrieNode();
        }
        void insert(string &s) {
            TrieNode* curr = root;
            for(int i = 0; i < s.length(); i++) {
                int idx = s[i] - 'a';
                if(curr->child[idx] == NULL) 
                    curr->child[idx] = new TrieNode();
                    
                curr = curr->child[idx];
            }
            curr->isEnd = true;
        }
        
        void dfs(string s, TrieNode* curr, vector<string>& vec) {
            if(curr->isEnd == true)
                vec.push_back(s);
            for(int i = 0; i < 26; i++) {
                if(curr->child[i] != NULL) {
                    s += ('a' + i);
                    dfs(s, curr->child[i], vec);
                    s.pop_back();
                }
            }
        }
        
        vector<string> printSuggestions(string pre) {
            TrieNode* curr = root;
            for(int i = 0; i < pre.length(); i++) {
                int idx = pre[i] - 'a';
                if(curr->child[idx] == NULL) 
                    return {"0"};
                else 
                    curr = curr->child[idx];
            }
            vector<string> vec;
            dfs(pre, curr, vec);
            return vec;
        }
    };
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        Trie trie;
        for(int i = 0; i < n; i++) 
            trie.insert(contact[i]);
            
        for(int i = 0; i < s.length(); i++)
            ans.push_back(trie.printSuggestions(s.substr(0, i + 1)));
            
        return ans;
    }
};
