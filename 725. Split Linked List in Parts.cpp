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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        auto cur = head;
        while (cur) {
            cur = cur->next;
            ++size;
        }
        int div = size / k;
        int rem = size % k;
        
        cur = head;
        vector<ListNode*> res;
        
        for (int i = 0; i < rem; ++i) {
            //cout << cur->val << "-->" << cur->next->val;
            res.push_back(cur);
            for(int n = 0; n < div; ++n) {
                cur = cur->next;
            }
            auto temp = cur->next;
            cur->next = nullptr;
            cur = temp;
        }

        for (int i = rem; i < k; ++i) {
            if (div == 0) {
                res.push_back(nullptr);
                continue;
            }
            //cout << cur->val << "-->" << cur->next->val;
            res.push_back(cur);
            for(int n = 0; n < div-1; ++n) {
                cur = cur->next;
            }
            auto temp = cur->next;
            cur->next = nullptr;
            cur = temp;
        }
        //cout << res[0]->val << "-->" << res[0]->next->val;
        return res;
    }
};