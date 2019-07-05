/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *tailA = headA;
        while (tailA->next != nullptr) {
            tailA = tailA->next;
        }
        tailA->next = headA;

        ListNode *intersection = detectCycle(headB);
        tailA->next = nullptr;

        return intersection;
    }

private:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *cross = nullptr;

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
                cross = p;
                break;
            }
        }

        if (cross == nullptr) {
            return nullptr;
        }

        while (head != cross) {
            head = head->next;
            cross = cross->next;
        }

        return head;
    }
};
