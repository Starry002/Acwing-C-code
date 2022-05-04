//Acwing 656. 钞票和硬币

//读取一个带有两个小数位的浮点数，这代表货币价值。
//在此之后，将该值分解为多种钞票与硬币的和，每种面值的钞票和硬币使用数量不限，要求使用的钞票和硬币的数量尽可能少。
//钞票的面值是 100,50,20,10,5,2。
//硬币的面值是 1,0.50,0.25,0.10,0.05 和 0.01。

//输入格式： 输入一个浮点数 N。
//输出格式： 参照输出样例，输出每种面值的钞票和硬币的需求数量。
//数据范围：0≤N≤1000000.00

//输入样例：
//576.73
//输出样例：
//NOTAS:
//5 nota(s) de R$ 100.00
//1 nota(s) de R$ 50.00
//1 nota(s) de R$ 20.00
//0 nota(s) de R$ 10.00
//1 nota(s) de R$ 5.00
//0 nota(s) de R$ 2.00
//MOEDAS:
//1 moeda(s) de R$ 1.00
//1 moeda(s) de R$ 0.50
//0 moeda(s) de R$ 0.25
//2 moeda(s) de R$ 0.10
//0 moeda(s) de R$ 0.05
//3 moeda(s) de R$ 0.01

//*******带有小数的问题一般转换为整数，why？，因为容易被精度坑******* 
//*******带有小数的问题一般转换为整数，why？，因为容易被精度坑******* 
//*******带有小数的问题一般转换为整数，why？，因为容易被精度坑******* 

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double n;
    cin >> n;
    int m = (n * 100);
    double a[12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    int ans[12] = {};

    for (int i = 0; i < 12; i++)
    {
        int cnt = 0;
        while (m >= a[i])
        {
            m -= a[i];
            cnt++;
        }
        ans[i] = cnt;
    }

    puts("NOTAS:");
    for (int i = 0; i < 6; i++)
        printf("%d nota(s) de R$ %.2lf\n", ans[i], (double)a[i] / 100);
    puts("MOEDAS:");
    for (int i = 6; i < 12; i++)
        printf("%d moeda(s) de R$ %.2lf\n", ans[i], (double)a[i] / 100);

    return 0;
}
