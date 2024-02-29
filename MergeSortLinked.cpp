#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

node *makenode(int x)
{
    node *tmp = new node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

void ThemDau(node *&head, int x)
{
    node *tmp = makenode(x);
    if (head == NULL)
        head = tmp;
    else
    {
        tmp->next = head;
        head = tmp;
    }
}

void ThemCuoi(node *&head, int x)
{
    node *tmp = makenode(x);
    if (head == NULL)
        head = tmp;
    else
    {
        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

void Themvitri(node *&head, int x, int k)
{
    node *tmp = makenode(x);
    if (head == NULL)
        head = tmp;
    else
    {
        node *p = head;
        for (int i = 1; i < k; i++)
        {
            p = p->next;
        }
        node *tmp = makenode(x);
        tmp->next = p->next;
        p->next = tmp;
    }
}

void Xoadau(node *&head)
{
    node *tmp = head;
    head = head->next;
    delete tmp;
}

void XoaCuoi(node *&head)

{
    node *p = head;
    node *sau = NULL;
    while (p->next = NULL)
    {
        sau = p;
        p = p->next;
    }
    sau->next = NULL;
    delete p;
}
void Xuat(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *merge(node *a, node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    node *tmp = NULL;
    if (a->data <= b->data)
    {
        tmp = a;
        tmp->next = merge(a->next, b);
    }
    else
    {
        tmp = b;
        tmp->next = merge(a, b->next);
    }
    return tmp;
}

void split(node *head, node *&a, node *&b)
{
    if (head == NULL || head->next == NULL)
    {
        a = head;
        b = NULL;
        return;
    }
    node *slow = head;
    node *fast = slow->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    a = head;
    b = slow->next;
    slow->next = NULL;
}

void merge_sort(node *&head)
{
    if (head == NULL || head->next == NULL)
        return;
    node *a;
    node *b ;
    split(head, a, b);
    merge_sort(a);
    merge_sort(b);
    head = merge(a, b);
}

int main()
{
    node *head = NULL;
    ThemDau(head, 3);       // 3
    ThemDau(head, 1);       // 1 3
    ThemCuoi(head, 0);      // 1 3 0
    ThemDau(head, 10);      // 10 1 3 0
    ThemDau(head, 9);       // 9 10 1 3 0
    Themvitri(head, -1, 3); // 9 10 1 -1 3 0
    Xuat(head);
    cout << "Sap xep\n";
    merge_sort(head);
    Xuat(head);
}