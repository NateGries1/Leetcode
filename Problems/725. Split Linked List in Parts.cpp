
#include "../utils/Solution.hpp"

std::vector<ListNode*> Solution::splitListToParts(ListNode* head, int k) {
    int size = 0;
    auto cur = head;
    //O(n) loop to get size
    while (cur) {
        cur = cur->next;
        ++size;
    }

    //get quotient and remainder
    int div = size / k;
    int rem = size % k;
    
    cur = head;
    std::vector<ListNode*> res;
    
    for (int i = 0; i < rem; ++i) { // 'rem' items will have div+1 elements
        res.push_back(cur); //add cur pointer to vector
        for(int n = 0; n < div; ++n) { // iterate to the next critical element
            cur = cur->next;
        }
        //break off end of new list and move cur to the start of the next list
        auto temp = cur->next; 
        cur->next = nullptr;
        cur = temp;
    }

    for (int i = rem; i < k; ++i) { // k-rem lists will have div elements
        if (div == 0) { // if there are no more elements to be added, add nullptr to vector
            res.push_back(nullptr);
            continue;
        }
        
        res.push_back(cur); //add cur pointer to vector
        for(int n = 0; n < div-1; ++n) { // iterate to the next critical element
            cur = cur->next;
        }
        //break off end of new list and move cur to the start of the next list
        auto temp = cur->next;
        cur->next = nullptr;
        cur = temp;
    }
    return res;
}