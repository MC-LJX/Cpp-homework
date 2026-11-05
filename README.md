# 第2章 C++ 对 C 的改进和扩展 —— 实验源代码

本文件夹包含本次实验（实验任务 2-1 + 实验任务 2-2）的全部源程序，共 7 个文件。

## 一、实验任务 2-1：C++ 对 C 的改进和扩展基础实验（4 个独立单文件程序）

| 文件 | 对应任务 | 考察知识点 |
| --- | --- | --- |
| Task1_StudentScore.cpp | 任务一：学生成绩统计与输出 | 输入输出流控制、fixed/setprecision/setw 格式对齐 |
| Task2_CountVowels.cpp | 任务二：统计字符串中的元音字母 | 指向常量的指针 const char* |
| Task3_Calculator.cpp | 任务三：简易多功能计算器 | 内联函数、默认参数、函数重载 |
| Task4_Swap.cpp | 任务四：交换两个整数 | 引用传参、函数重载（引用版/指针版） |

## 二、实验任务 2-2：校园一卡通消费管理系统设计与实现（多文件工程）

| 文件 | 说明 |
| --- | --- |
| card_operations.h | 头文件：常量、账户结构体 Card、函数声明（#ifndef 宏保护） |
| card_operations.cpp | 功能实现：namespace card、动态内存、充值/消费、类型转换、报表 |
| CampusCardSystem.cpp | 主程序：流程集成、异常处理（try/throw/catch） |

## 三、编译与运行

- 推荐环境：Visual Studio（新建控制台应用 C++ 项目，编译标准 C++11/C++14）
- 实验任务 2-1：每个 .cpp 文件各自新建一个控制台项目，或直接编译单个文件运行
- 实验任务 2-2：在同一项目中添加 card_operations.h、card_operations.cpp、CampusCardSystem.cpp 三个文件后编译
- MSVC 命令行方式（以任务 2-2 为例）：
  cl /EHsc /std:c++14 /utf-8 CampusCardSystem.cpp card_operations.cpp

## 四、源码托管

请将本文件夹上传至 gitee / github 等平台的代码仓库，并把仓库地址填入实验报告附录
"本实验代码托管地址"处。
