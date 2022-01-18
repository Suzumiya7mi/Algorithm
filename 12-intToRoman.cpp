
#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {//  字符串操作算法
    int arr[4] = { 0 }, i = 3;
    do {
        arr[i] = num % 10;
        num /= 10;
        i--;
    } while (num);
    string str;
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 4) {
            if (i == 1) { str += "CD"; continue; }
            else if (i == 2) { str += "XL"; continue; }
            else if (i == 3) { str += "IV"; continue; }
        }
        else if (arr[i] == 9) {
            if (i == 1) { str += "CM"; continue; }
            else if (i == 2) { str += "XC"; continue; }
            else if (i == 3) { str += "IX"; continue; }
        }
        else if (arr[i] < 4)
            for (int j = 0; j < arr[i]; j++) {
                if (i == 0)str += 'M';
                else if (i == 1)str += 'C';
                else if (i == 2)str += 'X';
                else if (i == 3)str += 'I';
            }
        else {
            if (i == 1)str += 'D';
            else if (i == 2)str += 'L';
            else if (i == 3)str += 'V';
            for (int j = 0; j < arr[i] - 5; j++) {
                if (i == 1)str += 'C';
                else if (i == 2)str += 'X';
                else if (i == 3)str += 'I';
            }

        }

    }
    return str;
}

string INTtoRoman(int num) {//hash map
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string reps[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    string res;
    for (int i = 0; i < 13; i++)  //这里不使用图里的count了，一遍一遍来就行了
            while (num >= values[i])
            {
                num -= values[i];
                res += reps[i];
            }
    return res;


}

int main()
{
    int num;
    std::cin >> num;
    std::cout << intToRoman(num)<<'\n';
    std::cout << INTtoRoman(num);
}

