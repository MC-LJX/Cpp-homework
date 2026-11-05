#include <iostream>
using namespace std;

// 统计字符串中元音字母（a、e、i、o、u）的个数
int countVowels(const char* p)
{
    int count = 0;
    while (*p != '\0')              // 遍历到字符串结束符
    {
        char ch = *p;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            count++;
        p++;                        // 指针后移；const 保证不能修改所指字符
    }
    return count;
}

int main()
{
    char str[200];
    cin.getline(str, 200);          // 读入含空格的一整行字符串
    cout << "Number of vowels: " << countVowels(str) << endl;
    return 0;
}
