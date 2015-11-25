/*
 * 234 Palindrome Linked List
 * Given a singly linked list, determine if it is a palindrome.
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode * head)
{
    vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }

    for (int i = 0, j = v.size() - 1; i < j; ++i, --j) {
        if (v[i] != v[j])
            return false;
    }

    return true;
}

// 优化
ListNode * reverseList(ListNode * head, ListNode * newhead)
{
    if (!head)
        return newhead;
    ListNode * p = head->next;
    head->next = newhead;
    return reverseList(p, head);
}

bool isPalindromeOpt(ListNode * head)
{
    if (!head)
        return true;

    ListNode *p = head;
    ListNode *q = head;
    while (q->next != NULL && q->next->next != NULL) {
        p = p->next;
        q = q->next->next;
    }

    ListNode * newhead = reverseList(p->next, NULL);

    while (newhead) {
        if (head->val != newhead->val)
            return false;
        head = head->next;
        newhead = newhead->next;
    }

    return true;
}

int main()
{

}
