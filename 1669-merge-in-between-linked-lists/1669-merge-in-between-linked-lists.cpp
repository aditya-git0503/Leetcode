class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* prev = list1;

        for (int i = 0; i < a - 1; i++) {
            prev = prev->next;
        }

        ListNode* after = prev;

        for (int i = 0; i <= b - a + 1; i++)
            after = after->next;

        prev->next = list2;

        ListNode* tail = list2;
        while (tail->next)
            tail = tail->next;

        tail->next = after;

        return list1;
    }
};