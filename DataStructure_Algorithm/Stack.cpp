#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000005;
int dat[MAX];
int pos = 0;

void push(int x)
{
    dat[pos++] = x;
}
void pop()
{
    pos--;
}

int top() // peek
{
    return dat[pos - 1];
}
void test()
{
}
int main(void)
{
    test();
}