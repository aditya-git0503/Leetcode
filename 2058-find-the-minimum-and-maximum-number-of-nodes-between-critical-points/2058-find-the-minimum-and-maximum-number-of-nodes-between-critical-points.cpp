class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2, -1);
        vector<int> crit;

        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return res;
        }

        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r = head->next->next;

        int idx = 1;

        while(r != nullptr){
            if((q->val > p->val && q->val > r->val) ||
               (q->val < p->val && q->val < r->val)){
                crit.push_back(idx);
            }

            idx++;
            p = q;
            q = r;
            r = r->next;
        }

        int n = crit.size();

        if(n < 2){
            return res;
        }

        res[0] = INT_MAX;

        for(int i = 1; i < n; i++){
            res[0] = min(res[0], crit[i] - crit[i-1]);
        }

        res[1] = crit[n-1] - crit[0];

        return res;
    }
};