/*
 * 203 Remove Linked List Elements
 * Remove all elements from a linked list of integers that have value val.
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val)
{
    ListNode *p, *q;
    p = NULL;
    q = head;
    while (q) {
        if (q->val == val) {
            if (p == NULL) {
                p = q->next;
                delete q;
                q = p;
                head = q;
                p = NULL;
            } else {
                p->next = q->next;
                delete q;
                q = p->next;
            }
        } else {
            p = q;
            q = q->next;
        }
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode *newhead = removeElements(head,2);
}
