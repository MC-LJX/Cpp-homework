#include "card_operations.h"
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
using namespace std;

// ---------------- 命名空间：格式化输出 ----------------
namespace card
{
    void printLine(char c, int len)
    {
        for (int i = 0; i < len; i++)
            cout << c;
        cout << endl;
    }

    void title(const string& s)
    {
        cout << s << endl;
    }
}

// ---------------- 动态内存管理与账户录入 ----------------
Card* createCards(int n)
{
    Card* arr = new (nothrow) Card[n];  // 分配失败返回 nullptr
    if (arr == nullptr)
        throw bad_alloc();              // 抛出内存分配异常
    return arr;
}

void destroyCards(Card* p)
{
    delete[] p;                         // 与 new[] 成对释放
}

void inputCards(Card* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "请输入第 " << i + 1 << " 个账户的学号、姓名、初始余额: ";
        cin >> arr[i].id >> arr[i].name >> arr[i].balance;
        if (cin.fail() || arr[i].balance < 0)   // 输入校验
            throw invalid_argument("余额为负数或输入数据非法！");
        arr[i].transactions = 0;        // 交易次数初始化为 0
    }
}

// ---------------- 账户操作 ----------------
void deposit(Card& c, double amount, double fee)
{
    c.balance += amount * (1.0 - fee);  // 扣除手续费后入账
    c.transactions++;                   // 累加交易次数
}

bool spend(Card& c, double cost)
{
    if (cost < 0 || cost > c.balance)
        return false;                   // 金额非法或余额不足
    c.balance -= cost;
    c.transactions++;
    return true;
}

bool spend(Card& c, double cost, const string& item)  // 重载版本
{
    cout << "消费项目：" << item << endl;
    return spend(c, cost);              // 调用上一版本完成扣款
}

void showBalance(const Card& c)         // 常引用：只读显示余额
{
    cout << c.name << " 当前余额为：" << fixed << setprecision(2)
         << c.balance << endl;
}

void viewStudentID(const Card* p)       // 指向常量的指针：只读显示 ID
{
    cout << "账户ID为：" << p->id << endl;
}

// ---------------- 类型转换与报表 ----------------
int toCent(double amount)
{
    return static_cast<int>(amount * 100 + 0.5);  // 元 → 分（四舍五入）
}

void printReport(const Card* arr, int n)
{
    card::printLine('=', 60);
    cout << left << setw(8) << "ID"
         << setw(16) << "Name"
         << setw(12) << "Balance"
         << "Transactions" << endl;
    card::printLine('-', 60);
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(8) << arr[i].id
             << setw(16) << arr[i].name
             << setw(12) << arr[i].balance
             << arr[i].transactions << endl;
    }
    card::printLine('=', 60);
}
