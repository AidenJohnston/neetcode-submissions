/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        std::unordered_map<Node*, Node*> mp;

        mp[nullptr] = nullptr;
        
        Node* curr = head;
        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr) {
            Node* copyNode = mp[curr];
            copyNode->next = mp[curr->next];
            copyNode->random = mp[curr->random];
            curr = curr->next;
        }


        return mp[head];
    }
};
