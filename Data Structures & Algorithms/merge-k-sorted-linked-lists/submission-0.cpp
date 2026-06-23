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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a dummy node to easily build the result list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (true) {
            int minIdx = -1;
            int lowest = INT_MAX;
            
            // Loop through the head of every list to find the minimum
            for (int i = 0; i < lists.size(); i++) {
                // Only look at lists that aren't fully traversed yet
                if (lists[i] != nullptr) {
                    if (lists[i]->val < lowest) {
                        lowest = lists[i]->val;
                        minIdx = i; // Keep track of WHICH list had the min value
                    }
                }
            }
            
            // If minIdx is still -1, it means all lists are completely empty/exhausted
            if (minIdx == -1) {
                break;
            }
            
            // Append the node with the lowest value to our result list
            tail->next = lists[minIdx];
            tail = tail->next;
            
            // Advance the pointer of the list we just took a node from
            lists[minIdx] = lists[minIdx]->next;
        }
        
        // The actual head is right after the dummy node
        return dummy.next;
    }
};
