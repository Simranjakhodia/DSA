// https://leetcode.com/problems/implement-trie-prefix-tree/


class Trie {
    struct TrieNode {
        TrieNode *child[26];
        int word_cnt;
        int prefix_cnt;
        TrieNode(){
            memset(child, 0, sizeof(child));
            word_cnt = 0;
            prefix_cnt = 0;
        }
    };
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* tmp = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(tmp->child[idx] == NULL){
                tmp->child[idx] = new TrieNode();
            }
            tmp = tmp->child[idx];
            tmp->prefix_cnt++;
        }
        tmp->word_cnt++;
    }
    int countWordsEqualTo(string word) {
        TrieNode* tmp = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(tmp->child[idx] == NULL)
                return 0;
            tmp = tmp->child[idx];
        }
        return tmp->word_cnt;
    }
    int countWordsStartingWith(string prefix) {
        TrieNode* tmp = root;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(tmp->child[idx] == NULL)
                return 0;
            tmp = tmp->child[idx];
        }
        return tmp->prefix_cnt;
    }
    void erase(string word) {
        TrieNode* tmp = root;
        TrieNode* to_be_deleted = NULL;
        for(char ch : word) {
            int idx = ch - 'a';
            TrieNode* parent = tmp;
            tmp = tmp->child[idx];
            if(to_be_deleted != NULL) {
                delete to_be_deleted;
            }
            if(tmp->prefix_cnt == 0) {
                if(to_be_deleted == NULL) {
                    parent->child[idx] = NULL;
                }
                to_be_deleted = tmp;
            }
        }
        tmp->word_cnt--;
        if(to_be_deleted != NULL)
            delete to_be_deleted;
    }
};

// https://www.youtube.com/watch?v=_3ReIHJeTT4
// https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-1804-implement-trie-ii-prefix-tree
