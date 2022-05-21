// https://practice.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1/#


class Node {
    public:
        int freq;
        Node* child[26];
        bool isWord;
       
        Node() {
            memset(child, 0, sizeof(child));
            isWord = false;
            freq = 0;
        }
};
class Solution
{
    public:
    void insert(Node* root, string arr[], int n) {
        for(int i = 0; i < n; i++) {
            Node* curr = root;
            for(int j = 0; j < arr[i].size(); j++) {
                int idx = arr[i][j] - 'a';
                if(curr->child[idx] == NULL)
                    curr->child[idx] = new Node();
                curr = curr->child[idx];
                curr->freq++;
            }
        }
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        Node* head = new Node();
        insert(head, arr, n);
        vector<string> r;
        
        for(int i = 0; i < n; i++) {
            Node* curr = head;
            for(int j = 0; j < arr[i].size(); j++) {
                int idx = arr[i][j] - 'a';
                if(curr->child[idx]->freq == 1) {
                    string p = arr[i].substr(0, j+1);
                    r.push_back(p);
                    break;
                }
                curr = curr->child[idx];
            }
        }
        return r;
     }
    
};
