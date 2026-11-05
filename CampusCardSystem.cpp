#include <iostream>
#include <new>
#include <stdexcept>
#include "card_operations.h"
using namespace std;

int main()
{
    Card* cards = nullptr;
    try
    {
        card::title("==== Campus Card System ====");

        int n;
        cout << "请输入学生数量: ";
        cin >> n;

        cards = createCards(n);          // 可能抛出 bad_alloc

        bool ok = false;
        while (!ok)                      // 输入非法时提示并重新录入
        {
            try
            {
                inputCards(cards, n);    // 可能抛出 invalid_argument
                ok = true;
            }
            catch (const invalid_argument& e)
            {
                cerr << "输入错误: " << e.what() << " 请重新输入！" << endl;
                cin.clear();             // 清除错误状态
                cin.ignore(1000, '\n');  // 丢弃缓冲区残留
            }
        }

        deposit(cards[0], 100.0);        // 充值 100 元（默认手续费率 2%）
        if (!spend(cards[0], 8.5, "食堂午餐"))  // 消费 8.5 元（重载版本）
            throw runtime_error("消费失败：金额为负或余额不足！");

        showBalance(cards[0]);           // 常引用查询余额
        viewStudentID(&cards[0]);        // 指向常量的指针查询 ID
        cout << "换算为分：" << toCent(cards[0].balance) << endl;

        cout << endl;
        printReport(cards, n);           // 输出账户报表

        destroyCards(cards);             // 释放动态内存
        cards = nullptr;
    }
    catch (const bad_alloc& e)           // 内存分配失败
    {
        cerr << "内存分配失败: " << e.what() << endl;
        return -1;
    }
    catch (const invalid_argument& e)    // 其他输入数据非法
    {
        cerr << "输入错误: " << e.what() << endl;
        if (cards != nullptr) destroyCards(cards);
        return -1;
    }
    catch (const runtime_error& e)       // 消费异常
    {
        cerr << e.what() << endl;
        if (cards != nullptr) destroyCards(cards);
        return -1;
    }
    return 0;
}
