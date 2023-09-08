#include "../utils/Solution.hpp"

ListNode* Solution::removeElements(ListNode* head, int val) {
    while(head != nullptr && head->val == val) {
        head = head->next;
    }
    auto cur = head;

    while (cur != nullptr) {
        if (cur->next != nullptr && cur->next->val == val) {
            cur->next = cur->next->next;
        } else cur = cur->next;
    }
    return head;
}