#include <iostream>
#include <iomanip>
using namespace std;

// 1. 内联函数：计算平方
inline double square(double x)
{
    return x * x;
}

// 2. 带默认参数值的函数：计算乘幂，exponent 缺省为 2（平方）
double power(double base, int exponent = 2)
{
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

// 3. 重载函数：double 版本
double calc(double a, double b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)                       // 除零保护
            {
                cout << "Error: divide by zero" << endl;
                return 0.0;
            }
            return a / b;
        default:  return 0.0;
    }
}

// 3. 重载函数：int 版本
double calc(int a, int b, char op)
{
    return calc(static_cast<double>(a), static_cast<double>(b), op);
}

int main()
{
    int a, b;
    char op;
    cin >> a >> b >> op;            // 读入两个操作数和一个运算符

    cout << "square(" << a << ") = "
         << fixed << setprecision(2) << square(a) << endl;
    cout << "power(" << a << ",3) = "
         << fixed << setprecision(2) << power(a, 3) << endl;

    if (op == '/' && b == 0)
        calc(a, b, op);             // 除数为 0：函数内部已输出错误提示
    else
        cout << a << " " << op << " " << b << " = "
             << fixed << setprecision(2) << calc(a, b, op) << endl;
    return 0;
}
