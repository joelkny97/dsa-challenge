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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr) return nullptr;

        int count=0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* begin = dummy;
        ListNode* end = head;

        while (head!=nullptr) {
            
            count++;

            if (count % k == 0) {
                
                begin = reverse(begin, head->next);
                head = begin->next;
            }
            else {
                head = head->next;
            }
            
        }
        
        return dummy->next;
    }
private:
    ListNode* reverse(ListNode* begin, ListNode* end){

        // reverse using three pointer approach
        ListNode* prev = begin;
        ListNode* curr = begin->next;
        ListNode* fast; 
        ListNode* first = curr;

        while(curr!=end) {
            fast = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fast;
        }
        begin->next = prev;
        first->next = curr;
        return first;
    }
};