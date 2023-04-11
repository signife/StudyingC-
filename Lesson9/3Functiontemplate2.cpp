#include <iostream>

template <typename T>
class Vector
{
    T *data;
    int capacity;
    int length;

public:
    // � Ÿ���� �����ϴ���
    typedef T value_type;

    // ������
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
    void push_back(int s)
    {
        if (capacity <= length)
        {
            int *temp = new T[capacity * 2];
            for (int i = 0; i < length; i++)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // ������ ��ġ�� ���ҿ� �����Ѵ�.
    T operator[](int i) { return data[i]; }

    // x ��° ��ġ�� ���Ҹ� �����Ѵ�.
    void remove(int x)
    {
        for (int i = x + 1; i < length; i++)
        {
            data[i - 1] = data[i];
        }
        length--;
    }

    // ���� ������ ũ�⸦ ���Ѵ�.
    int size() { return length; }

    // i ��° ���ҿ� j ��° ���� ��ġ�� �ٲ۴�.
    void swap(int i, int j)
    {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    ~Vector()
    {
        if (data)
        {
            delete[] data;
        }
    }
};

template <typename C>
void bubble_sort(C &c)
{
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = i + 1; j < c.size(); j++)
        {
            if (c[i] > c[j])
            {
                c.swap(i, j);
            }
        }
    }
}

int main()
{
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(8);
    int_vec.push_back(5);
    int_vec.push_back(3);

    std::cout << "before sorting" << std::endl;
    for (int i = 0; i < int_vec.size(); i++)
    {
        std::cout << int_vec[i] << " ";
    }

    std::cout << "after sorting" << std::endl;
    bubble_sort(int_vec);
    for (int i = 0; i < int_vec.size(); i++)
    {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
