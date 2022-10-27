#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        unordered_map<Node *, Node *> hash_map;
        Node *retHead = new Node(head->val);
        Node *cur = head;
        Node *tmp = retHead;
        while (cur->next)
        {
            tmp->next = new Node(cur->next->val);
            tmp = tmp->next;
            cur = cur->next;
        }
        tmp = retHead;
        cur = head;
        while (cur)
        {
            hash_map[cur] = tmp;
            tmp = tmp->next;
            cur = cur->next;
        }
        tmp = retHead;
        cur = head;
        while (cur)
        {
            tmp->random = hash_map[cur->random];
            tmp = tmp->next;
            cur = cur->next;
        }

        return retHead;
    }
};