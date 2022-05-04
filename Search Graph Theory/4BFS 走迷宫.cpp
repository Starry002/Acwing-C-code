//����һ�� n��m �Ķ�ά�������飬������ʾһ���Թ���������ֻ���� 0 �� 1������ 0 ��ʾ�����ߵ�·��1 ��ʾ����ͨ����ǽ�ڡ�
//�������һ����λ�����Ͻ� (1,1) ������֪����ÿ�ο������ϡ��¡���������һ�������ƶ�һ��λ�á�
//���ʣ����˴����Ͻ��ƶ������½� (n,m) ����������Ҫ�ƶ����ٴΡ�
//���ݱ�֤ (1,1) ���� (n,m) ��������Ϊ 0����һ�����ٴ���һ��ͨ·��

//�����ʽ
//��һ�а����������� n �� m��
//������ n �У�ÿ�а��� m ��������0 �� 1������ʾ�����Ķ�ά�����Թ���

//�����ʽ
//���һ����������ʾ�����Ͻ��ƶ������½ǵ������ƶ�������

//���ݷ�Χ
//1��n,m��100

//����������
//5 5
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0

//���������
//8

//��һ��  2022/3/29 
#include <cstring>
#include <iostream>
using namespace std;
const int N = 110;
typedef pair<int ,int> PII;
int n,m;
PII load[N][N];																			//�洢·�� 
int g[N][N];																			// g �洢��ͼ 
int d[N][N];																			// d �洢ÿ���㵽 0��0  �ľ��� 
PII q[N * N];																			// q �洢��ǰ���ѡ�ķ������ö����Ƚ��ȳ�������������·���� 

int bfs()																				//����������� 
{
	int hh=0,tt=0;																		//�����ͷ����β 
	q[0] = {0,0};																		//������� 
	
	memset(d,-1,sizeof d);																//��ʼ�� d �е�ÿ���� �����Ϊ -1 ��δ�߹��� 
	d[0][0] = 0;																		//���һ�����߹��ģ� 
	
	int dx[4] = {-1,0,1,0} , dy[4] = {0,1,0,-1};										//����������ƫ��������ʾÿ�������һ���� 
	
	while(hh<=tt)																		//���������չ����һ�㣨��֤�Ȱ���ΧһȦ����������һ�㣩 
	{
		PII t = q[hh++];																//ȡ����ͷԪ�أ��Ƚ��ȳ��������±� ���� 
		
		for(int i=0;i<4;i++)															//ö���������ĸ����� 
		{
			int x = t.first + dx[i] , y = t.second + dy[i];								//����������ƫ��������ʾÿ�������һ���� 
			if(x>=0 && x<n && y>=0 && y<m && g[x][y] == 0 && d[x][y] == -1)				//�����һ���� x��y ������ �������� ����û�߹�����֤�����·���� 
			{
				load[x][y] = t;
				d[x][y] = d[t.first][t.second] + 1;										//��һ����ľ���Ϊ��ǰ��ľ���� 1  
				q[++tt] = {x,y};														//�Ȱ���һ���� x��y �洢�� q �� ���ٿ�����һ��λ�� 
			}
		}
	}
	
	int x = n - 1, y = m - 1;															//��ӡ·�� ������ 
	while(x || y)
	{
		cout << x << ' ' << y << endl;
		PII t = load[x][y];
		x = t.first , y = t.second;	
	} 
	
	return d[n-1][m-1];																	//���ض��� q �����һ����ľ��� 
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)															//д���ͼ 
			cin >> g[i][j];
			
	cout << bfs() << endl;
	
	return 0;
}


/*
C++ queueд���� 
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int n, m;
int g[N][N], d[N][N];

int bfs()
{
    queue< pair<int, int> > q;

    q.push({0, 0});

    memset(d, -1, sizeof(d));

    d[0][0] = 0;


    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())//���в�Ϊ��
    {
        PII t = q.front();//ȡ��ͷԪ��

        q.pop();//����

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;//��ǰ�㵽���ľ���
                q.push({x, y});//�����������
            }
        }
    }

    return d[n - 1][m -1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}

*/
