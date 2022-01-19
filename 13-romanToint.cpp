// 13-romanToint.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class solution
{
private:
    unordered_map<char, int> res = {//无序哈希表
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };

public:
    int romanToint(string s) {
        int result = 0, n = s.length();//s.length()==strlen(s)
        for (int i = 0; i < n; i++) {
            int temp = res[s[i]];
            if (i < n - 1 && temp < res[s[i + 1]])//出现IV,IX,XL,XC,CD,CM特殊情况时减去左值
                result -= temp;
            else                                  //正常情况加上当前值即可
                result += temp;
        }
        return result;
    }
};


int main()
{
    string s;
    solution a;//主函数内类映射
    cin >> s;
    int r = a.romanToint(s);//类函数调用
    std::cout << r;
}

