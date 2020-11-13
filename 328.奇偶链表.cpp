/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* odd_head = head;
        ListNode* even_head = head->next;

        ListNode* odd_node = head;
        ListNode* even_node = head->next;
        while (even_node != nullptr && even_node->next != nullptr) {
            odd_node->next = even_node->next;
            even_node->next = odd_node->next ? odd_node->next->next : nullptr;

            odd_node = odd_node->next;
            even_node = even_node->next;
        }
        odd_node->next = even_head;
        return head;
    }
};
// @lc code=end

