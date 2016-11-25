#include<iostream>
using namespace std;
int Max(double a[], int n){
	double max = a[0];
	int maxi = 0;
	for (int i = 0; i < n; i++){
		if (a[i]>max){
			max = a[i];
			maxi = i;
		}
	}
	return maxi;

}
int Min(double a[], int n){
	double min = a[0];
	int mini = 0;
	for (int i = 0; i < n; i++){
		if (a[i] < min){
			min = a[i];
			mini = i;
		}
	}
	return mini;
}

bool isbest(double A[], int n){
	for (int i = 0; i < n; i++){ if (A[i]>0) return false; }
}
int main(){

	double A[30][30];
	int m, n,w;

	int huanru = 0;
	int huanchu = 0;

	cout << "------------------对偶单纯形法---------------------" << endl << endl;

	cout << "请输入增广矩阵的行数 ：   ";
	cin >> m;
	cout << "请输入增广矩阵的列数：     ";
	cin >> n;

	double *jianyanshu = new double[n - 1];
	double *xishu = new double[n - 1];
	for (int i = 0; i < n - 1; i++){
		jianyanshu[i] = 0;
	}
	double *jianyanshu2 = new double[m];

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			A[i][j] = 0;
		}
	}
	cout << "请输入目标函数的系数:" << endl;
	for (int i = 1; i < n; i++){ cout << "x" << i << "  "; }
	cout << endl;
	
	for (int i = 0; i < n - 1; i++){
		cin >> jianyanshu[i];
		xishu[i]=jianyanshu[i];
		
	}
	cout << "求最大值还是求最小值， 最大值为1，最小值为-1：      " << endl;
	cin >> w;

	cout << "请输入该增广矩阵" << endl;
	for (int i = 1; i < n; i++){ cout << "x" << i << "     "<<"  b"; }
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	int  *jilu = new int[m];
	double *b=new double [m];//专门记录b列的数字
	

	for (int i = 0; i<m; i++){
		jilu[i] = n - 1 - m + i;
	}//这是在记录基变量的下标
	//计算过程
	for (int i = 0; i<m; i++){
		while (A[i][n-1]<0){
for(int i=0;i<m;i++){
		b[i]=A[i][n-1];}
			huanchu = Min(b,m);//huanchu为换出元素的下标
			//确定换出变量，选取b中最小的
			int tempi=0;
			for(int i=0;i<n-1;i++){
				if(A[huanchu][i]>0){
					tempi++;}}
			if(tempi==n-1){
				cout<<"无可行解"<<endl;
				return 0;}
			

			for (int i = 0; i < n-1; i++){
				if(A[huanchu][i]!=0  &&  jianyanshu[i] / A[huanchu][i]<0)

				{
					jianyanshu[i] = jianyanshu[i] / A[huanchu][i];}
				else{
	
					jianyanshu[i] = 1000;}
				

			}
			huanru=Min(jianyanshu,n-1);
				

			const double x = A[huanchu][huanru];//A【huanchu】【换入】改变了，得不到正确结果
			for (int i = 0; i < n; i++){
				A[huanchu][i] = (A[huanchu][i] / x);
			}
			double temp[3];

			for (int i = 0; i < m; i++){
				temp[i] = A[i][huanru];
			}
			for (int i = 0; i < huanchu; i++){//行
				for (int j = 0; j < n; j++){//列
					A[i][j] = (A[i][j] - A[huanchu][j] * temp[i]);
				}
			}
			for (int i = huanchu + 1; i < m; i++){//行
				for (int j = 0; j < n; j++){//列
					A[i][j] = (A[i][j] - A[huanchu][j] * temp[i]);
				}
			}
			const double y = jianyanshu[huanru];

			for (int i = 0; i < n - 1; i++){
				jianyanshu[i] = jianyanshu[i] - y * A[huanchu][i];
			}
			//记录下此时基变量和非基变量
			jilu[huanchu] = huanru + 1;}}

	cout << "最终表为" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
	double s = 0;
	cout << "基变量分别为" << endl;
	
	for (int i = 0; i<m; i++){

		
		cout <<"x"<<jilu[i] << endl;

	}
	
	



	system("pause");
}
