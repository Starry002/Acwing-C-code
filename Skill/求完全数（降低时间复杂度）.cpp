//c++每秒最多算一亿次，否则会超时 


//一个整数，除了本身以外的其他所有约数的和如果等于该数，那么我们就称这个整数为完全数。
//例如，6 就是一个完全数，因为它的除了本身以外的其他约数的和为 1+2+3=6。
//现在，给定你 N 个整数，请你依次判断这些数是否是完全数。


//输入格式
//第一行包含整数 N，表示共有 N 个测试用例。
//接下来 N 行，每行包含一个需要你进行判断的整数 X。


//输出格式
//每个测试用例输出一个结果，每个结果占一行。
//如果测试数据是完全数，则输出 X is perfect，其中 X 是测试数据。
//如果测试数据不是完全数，则输出 X is not perfect，其中 X 是测试数据。


//数据范围
//1≤N≤100,
//1≤X≤108


//输入样例：
//3
//6
//5
//28


//输出样例：
//6 is perfect
//5 is not perfect
//28 is perfect


#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        
        int i,sum = 0;
        for (i=1;i*i<=x;i++)							//相当于只枚举到根号下x。注意结束条件是  i*i <= x		 
        {
            if(x%i==0)
            {
                if(i<x)sum += i;
                if(i != x/i && x/i < x)sum += x/i;       // 算出大的约数，并排除大小约数相等的情况 ，避免重复相加。 
            }											//相当于是把   大的约数（x除小的约数）   一并搞出来，降低时间复杂度，简化循环。
        }
        if(sum == x)
            cout << x << " is perfect" << endl;
        else
            cout << x << " is not perfect" << endl;
    }
    return 0;
}
