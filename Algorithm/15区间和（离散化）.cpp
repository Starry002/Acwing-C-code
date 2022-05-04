//�ٶ���һ�����޳������ᣬ������ÿ�������ϵ������� 0��
//���ڣ��������Ƚ��� n �β�����ÿ�β�����ĳһλ�� x �ϵ����� c��
//������������ m ��ѯ�ʣ�ÿ��ѯ�ʰ����������� l �� r������Ҫ��������� [l,r] ֮����������ĺ͡�

//�����ʽ
//��һ�а����������� n �� m��
//������ n �У�ÿ�а����������� x �� c��
//�ٽ����� m �У�ÿ�а����������� l �� r��

//�����ʽ
//�� m �У�ÿ�����һ��ѯ������������������ֺ͡�

//���ݷ�Χ
//-109��x��109,
//1��n,m��105,
//-109��l��r��109,
//-10000��c��10000

//����������
//3 3
//1 2
//3 6
//7 5
//1 3
//4 6
//7 8

//���������
//8
//0
//5

//��һ��  2022/04/09
//�ڶ���  2022/04/27
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;					//ʹ�� pair ����˫Ԫ�� 
const int N = 3e5+10;
		
int n,m;									//��ɢ���ı��ʣ���ӳ�䣬������ܴ�ĵ㣬ӳ�䵽���ڵ�����Ԫ���С����ٶԿռ������Ҳ���ټ�������
int a[N],s[N];								// a[N] �洢ÿ������ �� s[N] �洢ǰ׺�� 
vector<int> alls;							//�洢������Ҫ ��ӺͲ�ѯ ���±� ������ӳ�䣨����ȥ�أ� 
vector<PII> add,query;						//����Ԫ������ vector ��¼ÿһ����ӺͲ�ѯ ��ӳ��ǰ�����֣� �����ڶ��ֲ��� 

int find(int x)								//���ֲ��ң�������ӳ�����±꣨���Ҷ��֣��ҵ����ڵ��� x �ĵ�һ���±꣩ 
{
    int l = 0 , r = alls.size()-1;			//������������ 
    while(l<r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l+1;								//���� l + 1 ����Ϊ�±�� 1 ��ʼ�ģ�������ǰ׺�ͣ� 
}

int main()
{
    cin >> n >> m;
    
    while(n--)
    {
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    sort(alls.begin(),alls.end());									//���� 
    alls.erase(unique(alls.begin(),alls.end()),alls.end());			//ȥ�� 
   
    for(auto item : add)											// c++ 11 ���� �������ᱨ�������� ��������� 
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    
    for(int i=1;i<=alls.size();i++) s[i] = s[i-1] + a[i];			//ǰ׺�� 
    
    for(auto item : query)											// c++ 11 ���� �������ᱨ�������� ��������� 
    {
        int l = find(item.first) , r = find(item.second);
        cout << s[r] - s[l-1] << endl;
    }
    
    return 0;
}

/* 
vector<int>::iterator unique(vector<int> &a)						//��д unique ��˫ָ���㷨�� 
{
    int j=0;
	for(int i=0;i<a.size();i++)										// a[0] ~~ a[j-1] ��¼ a �����в��ظ����� 
		if(!i || a[i] != a[i+1])									//ֻҪ a[i] �� ��һ�γ��� ���� ����һλ��ͬ 
			a[j++] = a[i];
	return a.begin() + j;											//�������һλ����ָ�� 
}
*/ 

