#include <iostream>

int reverse(int x) {
    unsigned int temp = 0, n;   //由于规定最长存储为32位整数,所以用无符号数储存来节省符号位.
    int signal;
    if (x > 0) signal = 1;      //将符号位分离成signal位.
    else if (x == 0) return 0;
    else signal = -1;
    n = abs(x);

    //int i = 0;
    do {
        if (signal == 1 && temp > (INT_MAX - n % 10) /10) return 0;             //正数溢出判断
        else if (signal == -1 && temp > (INT_MIN - n % 10) /10) return 0;       //负数溢出判断
        temp = temp * 10 + n % 10;     /*核心代码就这一行 将数字反向: 将低位取出变为高位*/
        n /= 10;
        //std::cout << "round=" << i << ", temp=" << temp<<'\n';
        //i++;
    } while (n);

    return signal * temp;       //最后结果再乘上signal

}

int main()
{
    int x;
    std::cin >> x;
    std::cout << reverse(x);
}

