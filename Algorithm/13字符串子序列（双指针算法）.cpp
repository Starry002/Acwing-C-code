//***最长不连续子序列*** 

//给定一个长度为 n 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。

//输入格式
//第一行包含整数 n。
//第二行包含 n 个整数（均在 0～105 范围内），表示整数序列。

//输出格式
//共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。

//数据范围
//1≤n≤105

//输入样例：
//5
//1 2 2 3 5

//输出样例：
//3

//第一遍  2022/04/07
//第二遍  2022/04/27 
#include <iostream>
using namespace std;
const int N = 1e5+10;
int n,a[N],s[N];							// a[N] 存储输入的数字 ，s[N] 存储当前区间中每个数出现的次数 
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    
    int res = 0;
    for(int i=0,j=0;i<n;i++)
    {
        s[a[i]]++;							//记录 j~~i 区间内每个数出现的次数 
        while(s[a[i]]>1)					//当有一个数出现第二次时， j 就前进一格，并将区间外的数字清除记录，直到无重复数字为止 
        {
            s[a[j]]--;
            j++;
        }
        res = max(res,i-j+1);				//记录最大的 j~~i 区间长度 
    }
    
    cout << res <<endl;
    
    return 0;
}


//***最长连续子序列***

//求一个字符串中最长的连续出现的字符，输出该字符及其出现次数，字符串中无空白字符（空格、回车和 tab），如果这样的字符不止一个，则输出第一个。

//输入格式
//第一行输入整数 N，表示测试数据的组数。
//每组数据占一行，包含一个不含空白字符的字符串，字符串长度不超过 200。

//输出格式
//共一行，输出最长的连续出现的字符及其出现次数，中间用空格隔开。

//输入样例：
//2
//aaaaabbbbbcccccccdddddddddd
//abcdefghigk

//输出样例：
//d 10
//a 1

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        string str;
        cin >> str;

        int cnt = 0;
        char c;

        for (int i = 0; i < str.size(); i ++ )
        {
            int j = i;												//第一类双指针算法 
            while (j < str.size() && str[j] == str[i]) j ++ ;		//只要后面还有字符和连续字符 
            if (j - i > cnt) cnt = j - i, c = str[i];				 
            i = j - 1;												//因为不管怎样第一个字符 i j 指的是一样的 j都会加 1 ，因此 i 要等于 j 的前一位 
        }

        cout << c << ' ' << cnt << endl;
    }

    return 0;
} 
