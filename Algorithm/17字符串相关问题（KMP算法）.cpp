1.字符串乘方 
//给定两个字符串 a 和 b，我们定义 a×b 为他们的连接。
//例如，如果 a=abc 而 b=def， 则 a×b=abcdef。
//如果我们将连接考虑成乘法，一个非负整数的乘方将用一种通常的方式定义：a0=``(空字符串)，a(n+1)=a×(an)。

//输入格式
//输入包含多组测试样例，每组测试样例占一行。
//每组样例包含一个字符串 s，s 的长度不超过 100。
//最后的测试样例后面将是一个点号作为一行。

//输出格式
//对于每一个 s，你需要输出最大的 n，使得存在一个字符串 a，让 s=an。

//输入样例：
//abcd
//aaaa
//ababab

//输出样例：
//1
//4
//3
 
#include <iostream>
using namespace std;
int main ()
{
    string s;
    while(cin >> s,s != ".")
    {
        int i,j,len = s.size();
        for (i=len;i;i--)
            if(len % i == 0)
            {
            	string ss;
                int k = len/i;
                for(j=0;j<i;j++) ss += s.substr(0,k);
                if(ss == s) cout << i << endl , break;
            }
    }
    return 0;
}



2.最长公共字符串后缀
//给出若干个字符串，输出这些字符串的最长公共后缀。

//输入格式
//由若干组输入组成。
//每组输入的第一行是一个整数 N。
//N 为 0 时表示输入结束，否则后面会继续有 N 行输入，每行是一个字符串（字符串内不含空白符）。
//每个字符串的长度不超过 200。

//输出格式
//共一行，为 N 个字符串的最长公共后缀（可能为空）。

//数据范围
//1≤N≤200

//输入样例：
//3
//baba
//aba
//cba
//2
//aa
//cc
//2
//aa
//a
//0

//输出样例：
//ba
//
//a

#include <iostream>
using namespace std;
int main ()
{
    int n;
    while(cin >> n,n)
    {
        string s;
        cin >> s;
        int len = s.size();
        
        int i,maxsuffix=1000;
        for(i=1;i<n;i++)
        {
            string a;
            cin >> a;
            int len1 = a.size();
            
            int j,cnt=0;
            for(j=0;j<len && j<len1;j++)                    //卡范围
            {
                if(s[len-j-1] == a[len1-j-1]) cnt++;        //做对比
                else break;
            }
            maxsuffix = min(maxsuffix,cnt);
        }
        if(maxsuffix) cout << s.substr(len-maxsuffix) << endl;
        else cout << endl;
    }
    return 0;
}



3.字符串移位包含问题 
//对于一个字符串来说，定义一次循环移位操作为：将字符串的第一个字符移动到末尾形成新的字符串。
//给定两个字符串 s1 和 s2，要求判定其中一个字符串是否是另一字符串通过若干次循环移位后的新字符串的子串。
//例如 CDAA 是由 AABCD 两次移位后产生的新串 BCDAA 的子串，而 ABCD 与 ACBD 则不能通过多次移位来得到其中一个字符串是新串的子串。

//输入格式
//共一行，包含两个字符串，中间由单个空格隔开。
//字符串只包含字母和数字，长度不超过 30。

//输出格式
//如果一个字符串是另一字符串通过若干次循环移位产生的新串的子串，则输出 true，否则输出 false。

//输入样例：AABCD CDAA

//输出样例：true

#include <iostream>
using namespace std;
int main ()
{
    string s,a;
    cin >> s >> a;
    if(s.size() < a.size())swap(s,a);
    
    int i,j,k;
    for(i=0;i<a.size();i++)
    {
        s = s.substr(1) + s[0];
        
        for(j=0;j+a.size() <= s.size();j++)					//找位置 
        {
            for(k=0;k<a.size();k++)							//卡范围 
            {
                if(s[k+j] != a[k])break;					//做对比 
            }
            if(k == a.size())
            {
                puts("true");
                return 0;
            }
        }
    }
    puts("false");
    return 0;
}



4.字符串最大跨距
//有三个字符串 S,S1,S2，其中，S 长度不超过 300，S1 和 S2 的长度不超过 10。
//现在，我们想要检测 S1 和 S2 是否同时在 S 中出现，且 S1 位于 S2 的左边，并在 S 中互不交叉（即，S1 的右边界点在 S2 的左边界点的左侧）。
//计算满足上述条件的最大跨距（即，最大间隔距离：最右边的 S2 的起始点与最左边的 S1 的终止点之间的字符数目）。
//如果没有满足条件的 S1，S2 存在，则输出 ?1。
//例如，S= abcd123ab888efghij45ef67kl, S1= ab, S2= ef，其中，S1 在 S 中出现了 2 次，S2 也在 S 中出现了 2 次，最大跨距为：18。

//输入格式
//输入共一行，包含三个字符串 S,S1,S2，字符串之间用逗号隔开。
//数据保证三个字符串中不含空格和逗号。

//输出格式
//输出一个整数，表示最大跨距。
//如果没有满足条件的 S1 和 S2 存在，则输出 ?1。

//输入样例：
//abcd123ab888efghij45ef67kl,ab,ef

//输出样例：
//18

#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
    //输入字符串
	string s,s1,s2;
	getline (cin,s,',');
	getline (cin,s1,',');
	getline (cin,s2); 
    //检查字符串是否输入正确
    //cout << s << s1 << s2 <<endl; 
    
    
    //求左端位置
    int left=0,i,j;											//朴素字符串匹配三部曲 
    int len = s.size(),len1= s1.size(),len2 = s2.size();
    for(i=0;i<len;i++)										//找位置 
    {
        for(j=0;j<len1;j++)									//卡范围 
        {
            if (s[i+j] != s1[j])break;						//作对比 
        }
        if (j == len1)break;
    }
    left = i + len1;
    //检查左端位置是否求对
    //cout << left << endl;


    //求右端位置
    int right=0,o,k;
    for(o=len-len2;o>=0;o--)								//找位置 
    {
        for(k=0;k<len2;k++)									//卡范围 
        {
            if (s[o+k] != s2[k])break;						//做对比 
        }
        if(k == len2)break;
    }
    right = o;
    //检查右端位置是否求对
    //cout << right << endl;
    
    
    //输出最大跨距
    int max_distance = right - left;
    if(max_distance<0)cout << "-1" << endl;                 //确保s1与s2不交叉
    else cout << max_distance << endl;
    
    return 0;
} 



5.字符串匹配问题
//给定一个模式串 S，以及一个模板串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
//模板串 P 在模式串 S 中多次作为子串出现。
//求出模板串 P 在模式串 S 中所有出现的位置的起始下标。

//输入格式
//第一行输入整数 N，表示字符串 P 的长度。
//第二行输入字符串 P。
//第三行输入整数 M，表示字符串 S 的长度。
//第四行输入字符串 S。

//输出格式
//共一行，输出所有出现位置的起始下标（下标从 0 开始计数），整数之间用空格隔开。

//数据范围
//1≤N≤105
//1≤M≤106

//输入样例：
//3
//aba
//5
//ababa

//输出样例：
//0 2

#include <iostream>
using namespace std;
const int N = 1000010,M = 10000010;
int n,m,ne[N];
char p[N],s[M];
int main()
{
    cin >> n >> p+1 >> m >> s+1;
    
    //求next数组过程
    int i,j;
    for(i=2,j=0;i<=m;i++)							//由于 i 等于1时，只有一位，找不到前后缀相同，一定匹配不成，故 i 从 2 开始匹配 
    {
        while(j && p[i] != p[j+1]) j = ne[j];		//如果已经有 j 长度子串匹配成功，且从 j + 1 开始匹配失败，j 就后退一步（与当前尾缀子串相同的前缀子串的尾部） 
        if (p[i] == p[j+1]) j++;					//匹配 j 长度的子串 
        ne[i] = j;									//记录 ne 数组 （每一位长度时，前后缀的最大公共部分 ） 
    }
    
    
    //KMP匹配过程
    for (i=1,j=0;i<=m;i++)							//长串 s 从 1开始  子串 p 从0开始 
    {
        while(j && s[i] != p[j+1]) j = ne[j];		//如果已经有 j 长度子串匹配成功，且从 j + 1 开始匹配失败，j 就后退一步（与当前尾缀子串相同的前缀子串的尾部） 
        if(s[i] == p[j+1]) j++;						//匹配 j 长度的子串 
        if(j==n)
        {
            printf("%d ", i-n);						//输出每次匹配成功的开始位置 
            j = ne[j];                              //匹配成功后 j 也要往后退一步，因为题目要求找到所有匹配成功的子串 
        }
    }
    return 0;
}
