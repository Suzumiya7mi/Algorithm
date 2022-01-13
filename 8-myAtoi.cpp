// myAtoi.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int myAtoi(string s) {
    int i = 0, signal, arr[128] = { 0 }, MAX = pow(2, 31) - 1, MIN = -pow(2, 31);//设定上下限值，不超过 signed int范围
    long long num = 0;      //防止按位累加时溢出
    while (s[i] == ' ') i++;//前置的空格字符跳过   
    switch (s[i]) {         //判断符号位
    case '+': {signal = 1; i++; break; }        //如果有符号位则判断后跳过此位
    case '-': {signal = -1; i++; break; }       
    default: {signal = 1; break; }              //如果无符号位则直接默认为'+'并且不跳过当前位
    }

    int j = 0;
    while (s[i] >= '0' && s[i] <= '9') {        //输入为数字则转换
        arr[j++] = (int)s[i++] - 48;
    }

    int temp = j - 1;   //temp是次方数
    if (arr[0] != 0 && j > 11 && signal == 1) return MAX;           //防止num溢出的提前判断
    else if (arr[0] != 0 && j > 11 && signal == -1) return MIN;     
    for (int i = 0; i <= j; i++) {
        num += arr[i] * pow(10, temp);
        temp--;
    }

    num = signal * num;
    if (num >= MAX)return MAX;
    else if (num <= MIN)return MIN;
    else return num;


}


int main()
{
    string s;
    cin >> s;
    cout << myAtoi(s);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
