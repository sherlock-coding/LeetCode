/*
 * 61 Rotate List
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * rotateRight(ListNode * head, int k) 
{
    int n = 0;
    ListNode *p = head;
    while (p) {
        ++n;
        p = p->next;
    }

    if (n == 0 || n == 1 || k % n == 0)
        return head;
    k = k % n;
    int l = n - k;
    p = head;
    for (int i = 0; i < l - 1; ++i)
        p = p->next;

    ListNode *q = p->next;
    ListNode *nhead = q;
    p->next = NULL;
    while (q->next) 
        q = q->next;
    q->next = head;
    return nhead;
}

int main()
{
    
}
