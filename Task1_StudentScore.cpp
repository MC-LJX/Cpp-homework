#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string name;        // 姓名
    double chinese;     // 语文
    double math;        // 数学
    double english;     // 英语
    double average;     // 平均分
};

int main()
{
    int n;
    cin >> n;                                   // 输入学生人数

    Student* stu = new Student[n];              // 动态创建学生数组
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].name >> stu[i].chinese
            >> stu[i].math >> stu[i].english;   // 读入姓名与三科成绩
        stu[i].average = (stu[i].chinese + stu[i].math + stu[i].english) / 3.0;
    }

    cout << fixed << setprecision(2);           // 固定小数位、保留两位
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << stu[i].name // 姓名左对齐，占 10 列
             << setw(8) << stu[i].chinese
             << setw(8) << stu[i].math
             << setw(8) << stu[i].english
             << setw(8) << stu[i].average;
        if (stu[i].average >= 90.0)
            cout << " Excellent";               // 平均分≥90 标注 Excellent
        cout << endl;
    }

    delete[] stu;                               // 释放动态内存
    return 0;
}
