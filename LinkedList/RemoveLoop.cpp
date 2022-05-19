
// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#


#include<bits/stdc++.h>
class Solution
{
    public:
    // TC : 0(N) SC : O(N)
    void removeLoop1(Node* head)
    {
       if(!head) return;
       unordered_map<Node*, int> m;
       Node* prev = NULL, *curr = head;
       while(curr) {
           if(!m[curr]) {
               m[curr] = 1;
               prev = curr;
               curr = curr->next;
           }
           else {
               prev->next = NULL;
               break;
           }
       }
    }
    // TC : O(N) SC : O(1)
    void removeLoop(Node* head) {
        if(!head) return;
        Node* slow, *fast;
        slow = fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow == head) {
            while(fast->next != slow)
                fast = fast->next;
            fast->next = NULL;
        } else if(slow == fast){
            slow = head;
            while(slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
};
