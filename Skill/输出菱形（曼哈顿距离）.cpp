#include <iostream>
#include <cstdio>
#include <cmath>									//sqrt（）平方根     abs（）绝对值 
using namespace std;
int main()
{
    int n;											//题目规定输入必须为奇数 
    cin >> n;
    int i,j;
    int x = n/2 , y = n/2;							//设置中心点 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           if(abs(i - x) + abs(j - y) <= n/2)       //观察n阶菱形规律得，该点到中心的曼哈顿距离小于  n/2 即可 输出菱形 
                cout << "*";
           else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
