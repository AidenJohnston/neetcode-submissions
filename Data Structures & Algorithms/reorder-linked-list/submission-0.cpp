/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        //using fast and slow pointers to figure out the midpoint
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //one pointer at the start, one at the midpoint
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;

        //reverse the second half of the linkedlist
        ListNode* prev = nullptr;
        ListNode* curr = l2;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        l2 = prev; // l2 now points to the head of the second half

        //merge both the lists
        while (l1 != nullptr && l2 != nullptr) {
            //save next nodes
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;

            l1->next = l2; //connect l1 to l2
            l2->next = next1; //connect l2 to l1's original next

            l1 = next1; //move pointers forward
            l2 = next2; 
        }

    }
};
