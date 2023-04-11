#include <iostream>
#include <string>
using namespace std;

class Vector
{
    string *data;
    int capacity;
    int length;

public:
    // ������
    Vector(int n = 1);

    // �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
    void push_back(string s);

    // ������ ��ġ�� ���ҿ� �����Ѵ�.
    string operator[](int i);

    // x��° ��ġ�� ���Ҹ� �����Ѵ�.
    void remove(int x);

    // ���� ������ ũ�⸦ ���Ѵ�.
    int size();

    // �Ҹ���
    ~Vector();
};

void Vector::push_back(string s)
{
    if (capacity <= length) // ���� �뷮�� ���̺��� �۴ٸ�
    {
        string *temp = new string[capacity * 2]; // �ӽ� string�� �뷮�� 2�迡 �ش��ϴ�
        // ���̸� �Ҵ��ϰ�
        for (int i = 0; i < length; i++)
        {
            temp[i] = data[i]; // �ӽ� string�� ������ �Ȱ�
        }

        delete[] data; // ������ �����Ҵ��� �������ְ�
        data = temp;   // ������ ������ temp�� ���Կ���
        capacity *= 2; // capacity ��ü�� 2��� �÷�
    }

    data[length] = s; // �׷��� �ʰ� �뷮�� ���̺��� ũ�ٸ� �׳� ����ְ�
    length++;         // ���� ����
}

string Vector::operator[](int i) { return data[i]; } // �����ε�

void Vector::remove(int x)
{
    for (int i = x + 1; i < length; i++)
    {
        data[i - 1] = data[i];
    }
    length--;
}

int Vector::size() { return length; }

Vector::~Vector()
{
    if (data)
    {
        delete[] data;
    }
}
