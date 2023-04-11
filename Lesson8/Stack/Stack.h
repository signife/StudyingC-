#include <iostream>
#include <string>
using namespace std;

class Stack
{
    struct Node
    {
        Node *prev;
        string s;

        Node(Node *prev, string s) : prev(prev), s(s) {}
    };

    Node *current;
    Node start;

public:
    Stack();

    // �ֻ�ܿ� ���ο� ���Ҹ� �߰��Ѵ�.
    void push(string s);

    // �ֻ���� ���Ҹ� �����ϰ� ��ȯ�Ѵ�.
    string pop();

    // �ֻ���� ���Ҹ� ��ȯ�Ѵ�.(���� x)
    string peek();

    // ������ ����ִ����� ������ ��ȯ�Ѵ�.
    bool is_empty();

    ~Stack();
};

Stack::Stack() : start(NULL, "") { current = &start; }

void Stack::push(string s)
{
    Node *n = new Node(current, s);
    current = n;
}

string Stack::pop()
{
    if (current == &start)
        return "";

    string s = current->s;
    Node *prev = current;
    current = current->prev;

    // Delete popped node
    delete prev;
    return s;
}

string Stack::peek() { return current->s; }

bool Stack::is_empty()
{
    if (current == &start)
        return true;
    return false;
}

Stack::~Stack()
{
    while (current != &start)
    {
        Node *prev = current;
        current = current->prev;
        delete prev;
    }
}
