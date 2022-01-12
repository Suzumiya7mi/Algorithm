#include <iostream>

double myPow(double x, int n) {      //快速幂思想，将x^n(偶数时)拆分成 x^(n/2) * x^(n/2)
    double result = 1;
    long int n1 = n;                  //防止负数取反、取余时发生的溢出
    if (x == 1 || n1 == 0) { return result; } //快速判断
    if (n1 == 1) return x;             //递归出口位置
    if (n1 > 1) {
        if (n1 % 2 == 0) return myPow(x, n1 / 2) * myPow(x, n1 / 2);             //偶数幂拆分成两个半分幂
        else return myPow(x, ((n1 - 1) / 2)) * myPow(x, ((n1 - 1) / 2)) * x;      //奇数幂拆分成比自己小1的偶数幂再乘底数
    }
    else {
        if (n1 % 2 == 0) { result = myPow(x, -n1 / 2) * myPow(x, -n1 / 2); return 1 / result; }             //偶数幂拆分成两个半分幂
        else { result = myPow(x, ((-n1 - 1) / 2)) * myPow(x, ((-n1 - 1) / 2)) * x; return 1 / result; }     //奇数幂拆分成比自己小1的偶数幂再乘底数
    }
}

int main() {
    double x;
    int n;
    printf("请输入底数x，和指数n:");
    std::cin >> x >> n;

    std::cout << "result= " << myPow(x, n) << std::endl;

}
