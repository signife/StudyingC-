#include <iostream>
#include <string>
using namespace std;

class Vector
{
    string *data;
    int capacity;
    int length;

public:
    // 생성자
    Vector(int n = 1);

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(string s);

    // 임의의 위치에 원소에 접근한다.
    string operator[](int i);

    // x번째 위치한 원소를 제거한다.
    void remove(int x);

    // 현재 벡터의 크기를 구한다.
    int size();

    // 소멸자
    ~Vector();
};

void Vector::push_back(string s)
{
    if (capacity <= length) // 만약 용량이 길이보다 작다면
    {
        string *temp = new string[capacity * 2]; // 임시 string에 용량의 2배에 해당하는
        // 길이를 할당하고
        for (int i = 0; i < length; i++)
        {
            temp[i] = data[i]; // 임시 string에 원본을 옴겨
        }

        delete[] data; // 원본은 동적할당을 해제해주고
        data = temp;   // 새로이 원본에 temp를 대입연산
        capacity *= 2; // capacity 자체는 2배로 늘려
    }

    data[length] = s; // 그렇지 않고 용량이 길이보다 크다면 그냥 집어넣고
    length++;         // 길이 증가
}

string Vector::operator[](int i) { return data[i]; } // 오버로딩

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
