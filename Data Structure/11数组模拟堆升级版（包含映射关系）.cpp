//维护一个集合，初始时集合为空，支持如下几种操作：
//I x，插入一个数 x；
//PM，输出当前集合中的最小值；
//DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
//D k，删除第 k 个插入的数；
//C k x，修改第 k 个插入的数，将其变为 x；
//现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。

//输入格式
//第一行包含整数 N。
//接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。

//输出格式
//对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。
//每个结果占一行。

//数据范围
//1≤N≤105
//?109≤x≤109
//数据保证合法。

//输入样例：
//8
//I -10
//PM
//I -10
//D 1
//C 2 8
//I 6
//PM
//DM

//输出样例：
//-10
//6

//第一遍  2022/3/24
//第二遍  2022/4/2 
#include <iostream>
#include <algorithm>
#include <string.h>									//引入 strcmp 函数（比较字符串 a、b 相等返回 0 ， a > b 返回 1 ， a < b 返回 -1 
using namespace std;
const int N = 1e5+10;
int n,cnt;
int h[N],size;										//用一维数组存下一棵树，根节点为 1 ，左儿子节点为 2*n ， 右儿子节点为 2*n+1 
int hp[N],ph[N]; 									//相当于给每个节点发一个双向指针 ，hp 是堆指向节点，ph 是节点指向堆 

void heap_swap(int a,int b)							//不常用！！（复杂交换，存储映射关系） (使用时，输入的是两个元素的下标，不是值！！） 
{
    swap(ph[hp[a]],ph[hp[b]]);						//让指向堆的指针 ph 先互换
    swap(hp[a],hp[b]);								//再让指向 ph 的指针 hp 互换 
    swap(h[a],h[b]);								//交换堆中 a b 节点的值 
}

void down(int u)									//实现 down 操作 （生成大根堆，小数在上） 
{
    int t = u;										//用 t 做中间变量，存储下标 
    if(u*2<=size && h[u*2]<h[t]) t = u*2;			//如果左儿子存在，且值小于 u 节点，让 t 等于左儿子
    if(u*2+1<=size && h[u*2+1]<h[t]) t = u*2+1;		//如果右儿子存在，且值小于 u 节点，让 t 等于右儿子
    if(u!=t)										//如果最终下标 t 不等于当前下标 u  
    {
        heap_swap(u,t);								//交换 t 和 u 节点的值 
        down(t);									//递归处理，直到 u 节点的值小于左右儿子的值 
    }
}

void up(int u)										//实现 up 操作（生成大根堆，小数在上） 
{
	while(u/2 && h[u/2]>h[u])						//如果父节点存在，并且值大于左右儿子的值节点 
	{
		heap_swap(u/2,u);							//交换父节点与左/右儿子的值 
		u /= 2;										//让父节点的下标变为左/右儿子节点的下标
	}
}

int main()
{
	scanf("%d",&n);
	
	while(n--)
	{
		char op[5];
		int k,x;
		
		scanf("%s",op);
		if(!strcmp(op,"I"))									//111插入一个数 x
		{
			scanf("%d",&x);
			size++ , cnt++;									// size 记录堆长度 ，cnt记录是第 k 个数 
			ph[cnt]=size , hp[size]=cnt;					//第 k 个数映射堆的 size ，堆的 size 映射第 k 个数 
			h[size] = x;									//插入 x 
			up(size);										//重新生成堆 
		}
		else if(!strcmp(op,"PM")) printf("%d\n",h[1]);		//222输出当前集合中的最小值 
		else if(!strcmp(op,"DM"))							//333删除当前集合中的最小值 
		{
			heap_swap(1,size);								//让最后一个元素覆盖堆顶 
			size--;											//下标总数减 1 （ 实现堆元素的删除）
			down(1);										//将放在堆顶的元素 down，重新生成大根堆 
		}
		else if(!strcmp(op,"D"))							//444删除第 k 个插入的数 
		{
			scanf("%d",&k);
			k = ph[k];										//找到第 k 个数在堆中的实际位置 
			heap_swap(k,size);								//让最后一个元素覆盖第 k 个数 
			size--;											//下标总数减 1 （ 实现堆元素的删除） 
			down(k),up(k);									//由于插入的数字在中间，不确定向上还是向下，因此 down up ，但是，只会执行一个 
		}
		else												//555修改第 k 个插入的数，将其变为 x 
		{
			scanf("%d%d",&k,&x);
			k = ph[k];										//找到第 k 个数在堆中的实际位置 
			h[k] = x;										//让第 k 个数变为 x 
			down(k),up(k);									//由于插入的数字在中间，不确定向上还是向下，因此 down up ，但是，只会执行一个  
		}
	} 
	
	return 0;
}
