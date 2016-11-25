#include<iostream>
#define maxsize 100
#define maxsize_n 100
using namespace std;
typedef struct node
{
	int x;
	int y;
	int pre;                                                     //pre��ʾָ������ǰһ��� 
	int flag;                                                    //flag��ʾ�����У����У���״̬��ȡֵΪ0��1,����1��ʾ��������0��ʾ�������� 
}sqtype;
sqtype sq[maxsize];                                  
int circle[maxsize_n][maxsize_n];
void printall(sqtype sq[], int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("(%d,%d),%d,%d\n", sq[i].x, sq[i].y, sq[i].pre, sq[i].flag);
	}
}
void printpath(sqtype sq[], int n)                                   //���·��
{
	int i;
	i = n;
	do{
		cout << "(" << sq[i].x << "," << sq[i].y << ")" << endl;
		i = sq[i].pre;                                            //��ǰһ����� 
	} while (i != 0);                                                  //i=0Ϊ���
}
int path_search(int circle[maxsize_n][maxsize_n], int m, int n, int m1, int n1)           //m,n��ʾ����Ĺ�ģ��m1,n1��ʾ��ʼ��� 
//�ҳ�����֪�㿪ʼ�ıջ�·
{
	int i, j, front, rear, x, y;
	sq[1].x = m1; sq[1].y = n1; sq[1].pre = 0; sq[1].flag = 1;                  //��ʼ��� 
	front = 1; rear = 1;
	while (front <= rear)												//���зǿ�
	{
		x = sq[front].x; y = sq[front].y;                  //��ʼ���
		if (sq[front].flag == 1)                        //��ʾ���������� 
		{
			i = x;
			for (j = 0; j < n; j++)
			{

				if (circle[i][j] > 0)
				{
					rear++;
					sq[rear].x = i;//��¼����
					sq[rear].y = j;
					sq[rear].pre = front;//��¼ǰһ���ڵ�
					if (sq[rear].y == n1)
					{
						cout << "�ջ�·Ϊ��" << endl;
						printpath(sq, rear);

						printall(sq, rear);
						return rear;
					}
					sq[rear].flag = 0;   //��־Ϊ�´ν��������� 
					circle[i][j] = -1;   //���(i,j)�Ѿ��ﵽ����ֹ���ظ�
				}
			}
		}
		else                                          //��ʾ���������� 
		{
			j = y;
			for (i = 0; i < m; i++)
			{
				if (circle[i][j] >0)
				{
					rear++;
					sq[rear].x = i;
					sq[rear].y = j;
					sq[rear].pre = front;
					sq[rear].flag = 1;   //��־Ϊ�´ν��������� 
					circle[i][j] = -1;   //���(i,j)�Ѿ��ﵽ����ֹ���ظ�
				}

			}
		}
		front++;
	}
}
int Max(int a[], int n){
	int max = a[0];
	int maxi = 0;
	for (int i = 0; i < n; i++){
		if (a[i]>max){
			max = a[i];
			maxi = i;
		}
	}
	return maxi;

}
int Min(int a[], int n){
	int min = a[0];
	int mini = 0;
	for (int i = 0; i < n; i++){
		if (a[i] < min){
			min = a[i];
			mini = i;
		}
	}
	return mini;
}
int Min(int a, int b){
	if (a>b)
		return b;
	else
		return a;
}

int main(){
	//��СԪ�ط����ʼ�����н�
	int m, n;
	cout << "�������˼۱��������������" << endl;
	cin >> m >> n;
	int minforall;
	int diaoruliang;
	int price;
	int c;//���Ǽ�¼�ڵ�����õ�
	int minforallindex;
	int bihuilu[50];
	int *zuixiao = new int[m]; for (int i = 0; i < m; i++){ zuixiao[i] = 0; }
	int *minforlineindex = new int[m]; for (int i = 0; i < m; i++){ minforlineindex[i] = 0; }
	int *maxforlineindex = new int[m]; for (int i = 0; i < m; i++){ maxforlineindex[i] = 0; }
	int yunjiabiao[50][50]; for (int i = 0; i < m; i++){ for (int j = 0; j < n; j++) { yunjiabiao[i][j] = 0; } }
	int yunjiabiaofuben[50][50]; for (int i = 0; i < m; i++){ for (int j = 0; j < n; j++) { yunjiabiaofuben[i][j] = 0; } }
	int yunshubiao[50][50]; for (int i = 0; i < m; i++){ for (int j = 0; j < n; j++) { yunshubiao[i][j] = 0; } }
	int jianyanshu[50][50]; for (int i = 0; i < m; i++){ for (int j = 0; j < n; j++) { jianyanshu[i][j] = 0; } }
	int *xiaoliangbiao = new int[n]; for (int i = 0; i < n; i++){ xiaoliangbiao[i] = 0; }
	int *xiaoliangbiaofuben = new int[n]; for (int i = 0; i < n; i++){ xiaoliangbiaofuben[i] = 0; }
	int *chanliangbiao = new int[m]; for (int i = 0; i < m; i++){ chanliangbiao[i] = 0; }
	int *chanliangbiaofuben = new int[m]; for (int i = 0; i < m; i++){ chanliangbiaofuben[i] = 0; }
	cout << "�������˼۱�" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){

			cin >> yunjiabiao[i][j];
			yunjiabiaofuben[i][j] = yunjiabiao[i][j];
		}
	}
	cout << "��������ص�����:" << endl;
	for (int i = 0; i < n; i++){
		cin >> xiaoliangbiao[i];
		xiaoliangbiaofuben[i] = xiaoliangbiao[i];
	}
	cout << "��������صĲ���:" << endl;
	for (int i = 0; i < m; i++){
		cin >> chanliangbiao[i];
		chanliangbiaofuben[i] = chanliangbiao[i];
	}
	int flag = 0;

	while (flag != m){
		for (int i = 0; i < m; i++){
			minforlineindex[i] = Min(yunjiabiao[i], n);//��¼������СԪ�ص��±ꣻ
		}
		for (int i = 0; i < m; i++){
			zuixiao[i] = yunjiabiao[i][minforlineindex[i]];//������СԪ��,����һ������;Ȼ������Min�ɻ����������
		}
		minforallindex = Min(zuixiao, m);//minforall=zuixiao[minforallindex]
		minforall = yunjiabiao[minforallindex][minforlineindex[minforallindex]];//��index��Ϊminforallindex,��index��Ϊminforlineinde[minforallindex]
		yunshubiao[minforallindex][minforlineindex[minforallindex]] = Min(xiaoliangbiao[minforlineindex[minforallindex]], chanliangbiao[minforallindex]);
		if (xiaoliangbiao[minforlineindex[minforallindex]]>chanliangbiao[minforallindex]){
			xiaoliangbiao[minforlineindex[minforallindex]] = xiaoliangbiao[minforlineindex[minforallindex]] - chanliangbiao[minforallindex];
			chanliangbiao[minforallindex] = 0;
			for (int i = 0; i < n; i++)
				yunjiabiao[minforallindex][i] = 10000;//��������i���ڲ�����j�����˼���С��һ���л�ȥ��
		}
		else{
			chanliangbiao[minforallindex] = chanliangbiao[minforallindex] - xiaoliangbiao[minforlineindex[minforallindex]];
			xiaoliangbiao[minforlineindex[minforallindex]] = 0;
			for (int i = 0; i < m; i++){
				yunjiabiao[i][minforlineindex[minforallindex]] = 10000;//������С��һ�л�ȥ��
			}
		}
		flag = 0;
		for (int i = 0; i < m; i++){
			if (chanliangbiao[i] == 0){ flag++; }
		}
	}

	cout << "��ʼ�˼۱�Ϊ:" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << yunshubiao[i][j] << " ";
		}
		cout << endl;
	}
	//��ó�ʼ�����α����λ�Ʒ��������//
	int flagjianyanshu = 1;//�ȼ��費�����Ž���ܽ���ѭ��

	do{
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				yunjiabiao[i][j] = 0;
				if (yunshubiao[i][j] != 0)yunjiabiao[i][j] = yunjiabiaofuben[i][j];
			}
		}


		int *u = new int[m]; for (int i = 0; i < m; i++){ u[i] = 0; }
		int *v = new int[n]; for (int i = 0; i < n; i++){ v[i] = 0; }
		u[1] = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (yunjiabiao[i][j] != 0) {
					v[j] = yunjiabiao[i][j] - u[i];
					for (int i = 0; i < m; i++){
						if (yunjiabiao[i][j] != 0){ u[i] = yunjiabiao[i][j] - v[j]; }
					}
				}
			}
		}
		//�ɴ˼����ȫ����ui vj
		for (int i = 0; i < m; i++)
			cout << u[i] << endl;
		for (int j = 0; j < n; j++){
			cout << v[j] << endl;
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (yunjiabiao[i][j] == 0){ yunjiabiao[i][j] = yunjiabiaofuben[i][j] - u[i] - v[j]; }
				else{ yunjiabiao[i][j] = 0; }
				jianyanshu[i][j] = yunjiabiao[i][j];//��������������Ϊ0
			}
		}
		cout << "������Ϊ��" << endl;
		for (int i = 0; i < m; i++){ for (int j = 0; j < n; j++){ cout << jianyanshu[i][j] << " "; } cout << endl; }
		flagjianyanshu = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (jianyanshu[i][j] < 0){
					flagjianyanshu++;
				}
			}
		}
		int flagjianyanshu = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (jianyanshu[i][j] < 0){
					flagjianyanshu++;
				}
			}
		}
		if (flagjianyanshu == 0){
			cout << "�����������ڵ���0,�ѵõ����Ž�";
			break;
		}
		//��ü�����֮���ñջ�·����
		//��ά����洢����λ

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				circle[i][j] = yunshubiao[i][j];
			}
		}

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (jianyanshu[i][j] < 0)
					c = path_search(circle, m, n, i, j);
			}
		}

		int ic = c;
		int ii = 0;
		cout << "bihuiluΪ";
		do{
			bihuilu[ii] = yunshubiao[sq[ic].x][sq[ic].y];
			cout << bihuilu[ii] << " ";
			ii++; ic = sq[ic].pre;
		} while (ic != 0);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//�����нڵ�浽һ��������//��Ӧ�ð��±���ʣ�����Ӧ�ð�pre����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		int minjiedian;
		minjiedian = bihuilu[0];
		for (int i = 0; i < ii; i++){
			if (i % 2 == 0){
				if (bihuilu[i] < minjiedian){
					minjiedian = bihuilu[i];//�˼�������,��0��ʵ������ĩ�ڵ㣬����%2==0
				}
			}
		}
		cout << "��С�ڵ㼴������Ϊ��" << minjiedian;

		for (int i = 0; i <= ii; i++){
			if (i % 2 == 0){
				bihuilu[i] -= minjiedian;
			}
			if (i % 2 == 1){
				bihuilu[i] += minjiedian;
			}
		}//Ȼ���ٰѸı���bihuilu��i����ֵ��yunshubiao��i����j��

		ic = c; ii = 0; do{ yunshubiao[sq[ic].x][sq[ic].y] = bihuilu[ii]; ii++; ic = sq[ic].pre; } while (ic != 0);
		cout << "�ı��������Ϊ��" << endl;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cout << yunshubiao[i][j] << " ";
			}
			cout << endl;
		}//�õ��������

	}
	while (flagjianyanshu != 0);
	price = 0;
	for (int i = 0; i < m; i++){ 
		for (int j = 0; j < n; j++){
			price += yunjiabiaofuben[i][j] * yunshubiao[i][j];
		}
	}
	cout << "�ܼ�Ϊ��" << price;
	system("pause");
}