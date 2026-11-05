#ifndef CARD_OPERATIONS_H
#define CARD_OPERATIONS_H

#include <string>
using namespace std;

const double FEE_RATE = 0.02;        // 充值手续费率
const double WARNING_BALANCE = 10.0; // 低余额警戒值

// 账户数据结构
struct Card
{
    int id;              // 学号
    string name;         // 姓名
    double balance;      // 余额
    int transactions;    // 交易次数
};

// 辅助工具模块：命名空间封装格式化输出函数
namespace card
{
    void printLine(char c = '-', int len = 60);  // 分隔线（默认参数）
    void title(const string& s);                 // 打印标题
}

// 动态内存管理与账户录入
Card* createCards(int n);
void destroyCards(Card* p);
void inputCards(Card* arr, int n);

// 账户操作（充值、消费、查询）
void deposit(Card& c, double amount, double fee = FEE_RATE);
bool spend(Card& c, double cost);
bool spend(Card& c, double cost, const string& item);
void showBalance(const Card& c);      // 常引用：只读查询余额
void viewStudentID(const Card* p);    // 指向常量的指针：只读查询 ID

// 类型转换与报表
int toCent(double amount);
void printReport(const Card* arr, int n);

#endif
