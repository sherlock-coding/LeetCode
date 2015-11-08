/*
 * 19 Remove Nth Node From End of List
 *
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *p = head, *q = head;
    while (n--)
        q = q-> next;

    if (!q) {
        q = p->next;
        delete p;
        return q;
    }        

    while (1) {
        q = q->next;
        if (!q) {
            q = p->next->next;
            delete p->next;
            p->next = q;
            return head;
        }
        else
            p = p->next;
    }

}

int main()
{

}
