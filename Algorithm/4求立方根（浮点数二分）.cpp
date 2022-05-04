//给定一个浮点数 n，求它的三次方根。

//输入格式
//共一行，包含一个浮点数 n。

//输出格式
//共一行，包含一个浮点数，表示问题的解。
//注意，结果保留 6 位小数。

//数据范围
//?10000≤n≤10000

//输入样例：
//1000.00

//输出样例：
//10.000000

//第一遍  2022/03/22
//第二遍  2022/04/08
//第三遍  2022/04/17 
#include <iostream>
using namespace std;
int main()
{
    double n;									//浮点数二分 ， 定义 变量 区间端点 都要用 浮点数类型！！！ 
    scanf("%lf",&n);
    											//定义左右区间 ， ***如果输入的是小于 1 的数 要注意区间范围 ，确保二分出来的值在区间内***  
    double l = -10000 , r = 10000;				//例如：0.001的立方根是0.1  但若区间取为（ 0 ， 0.001 ） 就不会有结果哦 ! ! 
    											//这里直接暴力求解了，区间给的足够大
												 
    while(r-l>1e-8)								//浮点数二分，当误差足够小时，我们就近似认为 该数 为所求数
    {
        double mid = (l+r)/2;
        if(mid * mid * mid >= n) r = mid;		//浮点数不需要考虑边界问题 ，很舒服！！ 
        else l = mid;							//浮点数不需要考虑边界问题 ，很舒服！！ 
    }
    
    printf("%.6lf\n",l);						//题目保留到小数点后六位 ，我们确保误差为小数点后八位，一般误差比题目在精确两位即可 （yxc经验之谈） 
    
    return 0;
}

