/*
 * 21 Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    ListNode *head = NULL, *r = NULL;
    bool headflag = true;

    while (l1 && l2) {
        ListNode *q = NULL;
        if (l1->val < l2->val) {
            q = l1;
            l1 = l1->next;
        }
        else {
            q = l2;
            l2 = l2->next;
        }

        if (headflag) {
            head = q;
            r = q;
            headflag = false;
        }
        else {
            r->next = q;
            r = q;
        }
    }

    if (l1) 
        r->next = l1;
    if (l2)
        r->next = l2;

    return head;
}
