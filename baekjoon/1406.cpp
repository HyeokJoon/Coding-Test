#include <iostream>
#include <vector>
#include <algorithm>
#include "1406.h"
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    char val;
};

class LinkedList
{
public:
    Node *root;
    Node *last;
    Node *cur;
    int size;
};

// vector<char> arr;
// char arr[600001];
int n, iter, arr_size;
char oper, operand;
LinkedList ll;

void newNode(char c)
{
    Node *node = new Node;
    node->next = NULL;
    node->val = c;

    Node *prevNode = ll.cur;
    prevNode->next->prev = node;
    node->next = prevNode->next;
    prevNode->next = node;
    node->prev = prevNode;

    ll.cur = node;
    if (ll.last == prevNode)
        ll.last = node;
    ll.size++;
}

void init(std::__1::string &s)
{
    // Node *cur = ll.root;
    for (int i = 0; i < s.size(); i++)
    {
        newNode(s[i]);
        // arr[iter++] = s[i];
        // arr_size++;
    }
    cin >> n;
    ll.cur = ll.last;
}

void deleteNode()
{
    if (ll.cur != NULL && ll.cur->prev != NULL)
        ll.cur->prev->next = ll.cur->next;
}

void edit()
{
    cin >> oper;
    switch (oper)
    {
    case 'L':
    {
        // iter = max(iter - 1, 0);
        if (ll.cur->prev != NULL)
            ll.cur = ll.cur->prev;
        break;
    }
    case 'D':
    {
        // iter++;
        if (ll.cur->next != NULL)
            ll.cur = ll.cur->next;
        break;
    }
    case 'B':
    {
        deleteNode();
        // arr[--iter] = 0;
    }
    case 'P':
    {
        cin >> operand;
        newNode(operand);
        // arr[iter++] = operand;
        // arr_size++;
    }
    break;
    }
}

void show()
{
    Node *cur = ll.root;
    while (cur != NULL)
    {
        cout << cur->val;
        cur = cur->next;
    }
}

int main()
{
    string s;
    cin >> s;
    init(s);
    for (int i = 0; i < n; i++)
    {
        edit();
    }
    show();
}