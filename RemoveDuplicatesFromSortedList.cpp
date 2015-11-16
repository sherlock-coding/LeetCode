/*
 * 83 Remove Duplicates from Sorted List
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    if (!head)
        return NULL;
    ListNode *p = head;
    ListNode *q = head->next;

    while (q) {
        if (p->val == q->val) {
            ListNode *tmp = q->next;
            delete q;
            q = tmp;
            p->next = q;
            continue;
        }
        else {
            p = q;
            q = q->next;
        }
    }

    return head;
}

int main()
{

}
