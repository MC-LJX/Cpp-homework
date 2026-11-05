#include <iostream>
using namespace std;

// 引用版：x、y 是实参的别名，函数内修改直接作用于实参
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// 重载：指针版，通过解引用交换指针所指向的内容
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x, y;
    cin >> x >> y;

    cout << "Before swap: x=" << x << ", y=" << y << endl;
    swap(x, y);                     // 调用引用版 swap
    cout << "After  swap: x=" << x << ", y=" << y << endl;

    swap(&x, &y);                   // 调用重载的指针版 swap（再次交换）
    cout << "Pointer swap: x=" << x << ", y=" << y << endl;
    return 0;
}
