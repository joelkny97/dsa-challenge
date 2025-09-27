#include <cmath>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (l1 == nullptr && l2 == nullptr) return nullptr;

        stack<int> n1;
        stack<int> n2;
        
        while(l1 != nullptr) {
            n1.push(l1->val);
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            n2.push(l2->val);
            l2 = l2->next;
        }

        int carry=0;
        
        ListNode* dummy = new ListNode(-1);
        // ListNode* curr = dummy;


        while (!n1.empty() || !n2.empty() || carry!= 0) {
            int m1=0, m2=0;

            if(!n1.empty()){
                m1 = n1.top();
                n1.pop();
            }
            if(!n2.empty()){
                m2 = n2.top();
                n2.pop();
            }

            int sum = m1+m2+carry;
            
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;

            addToHead(dummy, newNode);

            // cout<<dummy->val;
        }

        return dummy->next;
        
    }

private:
    void addToHead(ListNode* head, ListNode* node ) {
        ListNode* temp = head->next;
        head->next = node;
        node->next = temp;
        
    }
};