//���� N ����Ԫ�� (x,y,z)������ x ��������y �Ǹ�������z ���ַ�����
//���㰴�� x ��С�����˳����Щ��Ԫ���ӡ������
//���ݱ�֤��ͬ��Ԫ��� x ֵ������ͬ��

//�����ʽ
//��һ�а������� N��
//������ N �У�ÿ�а���һ������ x��һ�������� y��һ���ַ��� z����ʾһ����Ԫ�飬����֮���ÿո������

//�����ʽ
//�� N �У����� x ��С�����˳��ÿ�����һ����Ԫ�顣
//ע�⣬�������������ĸ����� y ��������λС����

//���ݷ�Χ
//1��N��10000,
//1��x,y��105,
//�ַ����ܳ��Ȳ����� 105��

//����������
//5
//32 1.36 nsyiupnnhc
//18 4.53 fmofzwrah
//33 4.86 wzuymbm
//1 3.93 gtnrwcebt
//31 4.53 gcllxioc

//���������
//1 3.93 gtnrwcebt
//18 4.53 fmofzwrah
//31 4.53 gcllxioc
//32 1.36 nsyiupnnhc
//33 4.86 wzuymbm

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

#define x first
#define y second

using namespace std;

typedef pair<int, pair<double, string > > PII;
vector<PII> ans;

int n, a;
double b;
string s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        cin >> a >> b >> s;
        ans.push_back({a, {b, s}});
    }

    sort(ans.begin(), ans.end());

    for (auto i: ans)
        printf("%d %.2lf %s\n",i.x, i.y.x, i.y.y.c_str());   

    return 0;
}
