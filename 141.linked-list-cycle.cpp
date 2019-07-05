/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;

        while (p != nullptr && q != nullptr) {
            ListNode *next;
            
            next = p->next;
            p = next;

            next = q->next;
            if (next != nullptr) {
                next = next->next;
            }
            q = next;

            if (p != nullptr && p == q) {
                return true;
            }
        }

        return false;
    }
};



bool hasCycle(ListNode *head) {
    ListNode *p = head;
    ListNode *q = head;

    while (p != nullptr && q != nullptr) {
        ListNode *next;
        
        next = p->next;
        p = next;

        next = q->next;
        if (next != nullptr) {
            next = next->next;
        }
        q = next;

        if (p != nullptr && p == q) {
            return true;
        }
    }

    return false;
}