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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if (head == nullptr) {
            return head;
        }

        ListNode* p = head;
        while (p != nullptr && p->next != nullptr) {
            if(p->next->val == val){
                ListNode* temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else{
                p = p->next;
            }
        }

        return head;
    }
};