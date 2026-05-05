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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
        return head;
        if(head->next == nullptr)
        return head;
        ListNode* p1 = head;
        ListNode* p2;
        int n = 0;
        while(p1!=nullptr){
            n++;
            p1 = p1->next;
        }
        p1 = head->next;
        p2 = head;
        for(int i = 1;i<=k%n;i++){
            while(p1->next!=nullptr){
                p1 = p1->next;
                p2 = p2->next;
            }
            p1->next = head;
            p2->next = nullptr;
            head = p1;
            p1 = head->next;
            p2 = head;
        }
        return head;
    }
};