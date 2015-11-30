/*
 * 24 Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 **/

ListNode * swapPairs(ListNode * head)
{
    ListNode *p, *q, *r, *pre;
    ListNode * newHead;
    if (!head || head->next == NULL)
        return head;
    pre = NULL;
    p = head;
    newHead = p->next;
    while (p && p->next) {
        q = p->next;
        r = q->next;
        q->next = p;
        p->next = r;
        if (pre)
            pre->next = q;
        pre = p;
        p = r;
    }

    return newHead;
}
