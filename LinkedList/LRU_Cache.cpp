// https://practice.geeksforgeeks.org/problems/lru-cache/1#


class Node {
    public:
    int key;
    int val;
    Node* next, *prev;
    Node(int newkey, int newval){
        key = newkey;
        val = newval;
    }
};
class LRUCache
{
    public:
    

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;
    LRUCache(int c)
    {
        cap = c;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(Node* newnode){
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deletenode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delnext->prev = delprev;
        delprev->next = delnext;
        
    }
    int get(int key)
    {
        if(m.find(key) != m.end()) {
            Node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    void set(int key, int value)
    {
        if(m.find(key) != m.end()){
            Node *existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        } 
        if(m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key, value));
        m[key] = head->next;
    }
};


/***********************************************************************************************************************************************************/
/***********************************************************************************************************************************************************/


//  https://leetcode.com/problems/lru-cache/submissions/


class LRUCache {
public:
    size_t m_capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;   // m_map_iter->first : key;  m_map_iter->second: list iterator
    list<pair<int, int>> m_list;    // m_list_iter->first : key   m_list_iter->second : value
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        auto found_iter = m_map.find(key);
        if(found_iter == m_map.end()) // key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second);  // move the node corresponding to key to front
        return found_iter->second->second;  // return value of the node
    }
    
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if(found_iter != m_map.end()) {
            m_list.splice(m_list.begin(), m_list, found_iter->second);
            found_iter->second->second = value;
            return;
        }
        if(m_map.size() == m_capacity)  // reached capacity
        {
            int key_to_del = m_list.back().first;
            m_list.pop_back();          // remove node in list
            m_map.erase(key_to_del);    // remove key in map
        }
        m_list.emplace_front(key, value);   // create a new node in list
        m_map[key] = m_list.begin();  
    }
};

// https://www.youtube.com/watch?v=xDEuM5qa0zg
// https://www.youtube.com/watch?v=akFRa58Svug
// https://leetcode.com/problems/lru-cache/discuss/45912/Clean-Short-Standard-C%2B%2B-solution-NOT-writing-C-in-C%2B%2B-like-all-other-lengthy-ones
