#include<iostream>
#define maxsize 100
#define maxsize_n 100
using namespace std;
typedef struct node
{
	int x;
	int y;
	int pre;                                                     //pre表示指向它的前一结点 
	int flag;                                                    //flag表示搜索行（或列）的状态，取值为0、1,其中1表示行搜索，0表示列搜索。 
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
void printpath(sqtype sq[], int n)                                   //输出路径
{
	int i;
	i = n;
	do{
		cout << "(" << sq[i].x << "," << sq[i].y << ")" << endl;
		i = sq[i].pre;                                            //找前一个结点 
	} while (i != 0);                                                  //i=0为入口
}
int path_search(int circle[maxsize_n][maxsize_n], int m, int n, int m1, int n1)           //m,n表示矩阵的规模，m1,n1表示开始结点 
//找出从已知点开始的闭回路
{
	int i, j, front, rear, x, y;
	sq[1].x = m1; sq[1].y = n1; sq[1].pre = 0; sq[1].flag = 1;                  //开始结点 
	front = 1; rear = 1;
	while (front <= rear)												//队列非空
	{
		x = sq[front].x; y = sq[front].y;                  //开始结点
		if (sq[front].flag == 1)                        //表示进行行搜索 
		{
			i = x;
			for (j = 0; j < n; j++)
			{

				if (circle[i][j] > 0)
				{
					rear++;
					sq[rear].x = i;//记录数据
					sq[rear].y = j;
					sq[rear].pre = front;//记录前一个节点
					if (sq[rear].y == n1)
					{
						cout << "闭回路为：" << endl;
						printpath(sq, rear);

						printall(sq, rear);
						return rear;
					}
					sq[rear].flag = 0;   //标志为下次进行列搜索 
					circle[i][j] = -1;   //标记(i,j)已经达到，防止在重复
				}
			}
		}
		else                                          //表示进行列搜索 
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
					sq[rear].flag = 1;   //标志为下次进行行搜索 
					circle[i][j] = -1;   //标记(i,j)已经达到，防止在重复
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
	//最小元素法求初始基可行解
	int m, n;
	cout << "请输入运价表的行数和列数：" << endl;
	cin >> m >> n;
	int minforall;
	int diaoruliang;
	int price;
	int c;//这是记录节点个数用的
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
	cout << "请输入运价表" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){

			cin >> yunjiabiao[i][j];
			yunjiabiaofuben[i][j] = yunjiabiao[i][j];
		}
	}
	cout << "请输入各地的销量:" << endl;
	for (int i = 0; i < n; i++){
		cin >> xiaoliangbiao[i];
		xiaoliangbiaofuben[i] = xiaoliangbiao[i];
	}
	cout << "请输入各地的产量:" << endl;
	for (int i = 0; i < m; i++){
		cin >> chanliangbiao[i];
		chanliangbiaofuben[i] = chanliangbiao[i];
	}
	int flag = 0;

	while (flag != m){
		for (int i = 0; i < m; i++){
			minforlineindex[i] = Min(yunjiabiao[i], n);//记录各行最小元素的下标；
		}
		for (int i = 0; i < m; i++){
			zuixiao[i] = yunjiabiao[i][minforlineindex[i]];//各行最小元素,存入一个数组;然后利用Min可获得纵向坐标
		}
		minforallindex = Min(zuixiao, m);//minforall=zuixiao[minforallindex]
		minforall = yunjiabiao[minforallindex][minforlineindex[minforallindex]];//行index即为minforallindex,列index即为minforlineinde[minforallindex]
		yunshubiao[minforallindex][minforlineindex[minforallindex]] = Min(xiaoliangbiao[minforlineindex[minforallindex]], chanliangbiao[minforallindex]);
		if (xiaoliangbiao[minforlineindex[minforallindex]]>chanliangbiao[minforallindex]){
			xiaoliangbiao[minforlineindex[minforallindex]] = xiaoliangbiao[minforlineindex[minforallindex]] - chanliangbiao[minforallindex];
			chanliangbiao[minforallindex] = 0;
			for (int i = 0; i < n; i++)
				yunjiabiao[minforallindex][i] = 10000;//若销量第i大于产量第j，则运价最小那一行行划去；
		}
		else{
			chanliangbiao[minforallindex] = chanliangbiao[minforallindex] - xiaoliangbiao[minforlineindex[minforallindex]];
			xiaoliangbiao[minforlineindex[minforallindex]] = 0;
			for (int i = 0; i < m; i++){
				yunjiabiao[i][minforlineindex[minforallindex]] = 10000;//否则最小那一列划去；
			}
		}
		flag = 0;
		for (int i = 0; i < m; i++){
			if (chanliangbiao[i] == 0){ flag++; }
		}
	}

	cout << "初始运价表为:" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << yunshubiao[i][j] << " ";
		}
		cout << endl;
	}
	//求得初始单纯形表后用位势法求检验数//
	int flagjianyanshu = 1;//先假设不是最优解才能进入循环

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
		//由此计算出全部的ui vj
		for (int i = 0; i < m; i++)
			cout << u[i] << endl;
		for (int j = 0; j < n; j++){
			cout << v[j] << endl;
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (yunjiabiao[i][j] == 0){ yunjiabiao[i][j] = yunjiabiaofuben[i][j] - u[i] - v[j]; }
				else{ yunjiabiao[i][j] = 0; }
				jianyanshu[i][j] = yunjiabiao[i][j];//即基变量检验数为0
			}
		}
		cout << "检验数为：" << endl;
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
			cout << "检验数均大于等于0,已得到最优解";
			break;
		}
		//求得检验数之后用闭回路法调
		//二维数组存储数据位

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
		cout << "bihuilu为";
		do{
			bihuilu[ii] = yunshubiao[sq[ic].x][sq[ic].y];
			cout << bihuilu[ii] << " ";
			ii++; ic = sq[ic].pre;
		} while (ic != 0);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//把所有节点存到一个数组中//不应该按下标访问，而是应该按pre访问!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		int minjiedian;
		minjiedian = bihuilu[0];
		for (int i = 0; i < ii; i++){
			if (i % 2 == 0){
				if (bihuilu[i] < minjiedian){
					minjiedian = bihuilu[i];//此即调入量,第0个实际上是末节点，所以%2==0
				}
			}
		}
		cout << "最小节点即调入量为：" << minjiedian;

		for (int i = 0; i <= ii; i++){
			if (i % 2 == 0){
				bihuilu[i] -= minjiedian;
			}
			if (i % 2 == 1){
				bihuilu[i] += minjiedian;
			}
		}//然后再把改变后的bihuilu【i】赋值给yunshubiao【i】【j】

		ic = c; ii = 0; do{ yunshubiao[sq[ic].x][sq[ic].y] = bihuilu[ii]; ii++; ic = sq[ic].pre; } while (ic != 0);
		cout << "改变后的运输表为：" << endl;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cout << yunshubiao[i][j] << " ";
			}
			cout << endl;
		}//得到新运输表；

	}
	while (flagjianyanshu != 0);
	price = 0;
	for (int i = 0; i < m; i++){ 
		for (int j = 0; j < n; j++){
			price += yunjiabiaofuben[i][j] * yunshubiao[i][j];
		}
	}
	cout << "总价为：" << price;
	system("pause");
}