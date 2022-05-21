//  https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1#


class Node {
  public:
    bool isWord;
    Node *child[26];   // or use unordered_map<char, Node*> m;
    Node () {
        isWord = false;
        memset(child, 0, sizeof(child));
    }
};

int countDistinctSubstring(string s)
{
    Node* head = new Node();
    int count = 1;
    
    for(int i = 0; i < s.length(); i++) {
        Node* temp = head;
        for(int j = i; j < s.length(); j++) {
            if(temp->child[s[j] - 'a'] == NULL) {
                temp->child[s[j] - 'a'] = new Node();
                temp->isWord = true;
                count++;
            }
            temp = temp->child[s[j] - 'a'];
        }
    }
    return count;
}


// https://www.youtube.com/watch?v=RV0QeTyHZxo
