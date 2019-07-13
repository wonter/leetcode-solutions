/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (36.03%)
 * Likes:    1739
 * Dislikes: 255
 * Total Accepted:    273.7K
 * Total Submissions: 750.7K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
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
    bool isPalindrome(ListNode* head) {
        ListNode *tail = head;
        while (tail && tail->next) {
            tail = tail->next;
        }

        ListNode *p = head;     // slow pointer
        ListNode *q = head;     // fast poinnter

        while (p && q && q->next) {
            p = p->next;
            q = q->next->next;
        }

        reverseList(p);
 
        while (head && tail && head != tail) {
            if (head->val != tail->val) {
                return false;
            }
            head = head->next;
            if (head != tail) {
                tail = tail->next;
            }
        }

        return true;
    }

private:
    void reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode *first = head;
        ListNode *second = first->next;
        head->next = nullptr;
        while (first != nullptr && second != nullptr) {
            ListNode *third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
    }
};

