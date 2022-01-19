// 14-longestCommonPrefix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//二维变长字符串数组,不定字符串数,也不定单个字符串中字符个数
        int strNum = strs.size(),flag=0;
        if (strNum == 0)return "";
        char ch;
        string res="";
        int minlen = strs[0].size();
        for (int i = 0; i < strNum; i++) {
            if (strs[i].size() < minlen) minlen = strs[i].size();//获取最短字符串长度
        }

        for (int i = 0; i < minlen; i++) {//以最短字符串当做前缀,一位一位对应
            ch = strs[0][i];
            for (int j = 0; j < strNum; j++) {//每个字符串按位比较
                if (strs[j][i] != ch) flag = 1;
            }
            if (flag == 0)res += ch;
            else if (flag == 1)break;
        }
        return res;
    }
};
int main()
{
    vector<vector<string> > strs;
    std::cout << "Hello World!\n";
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
