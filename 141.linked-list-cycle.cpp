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
        shared_ptr<ListNode> guard = make_shared<ListNode>(0);

        ListNode *node = head;
        while (node != nullptr) {
            if (node->next == guard.get()) {
                return true;
            }

            ListNode *next = node->next;
            node->next = guard.get();
            node = next;
        }

        return false;
    }
};

