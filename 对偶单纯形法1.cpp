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

	cout << "------------------��ż�����η�---------------------" << endl << endl;

	cout << "������������������ ��   ";
	cin >> m;
	cout << "��������������������     ";
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
	cout << "������Ŀ�꺯����ϵ��:" << endl;
	for (int i = 1; i < n; i++){ cout << "x" << i << "  "; }
	cout << endl;
	
	for (int i = 0; i < n - 1; i++){
		cin >> jianyanshu[i];
		xishu[i]=jianyanshu[i];
		
	}
	cout << "�����ֵ��������Сֵ�� ���ֵΪ1����СֵΪ-1��      " << endl;
	cin >> w;

	cout << "��������������" << endl;
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
	double *b=new double [m];//ר�ż�¼b�е�����
	

	for (int i = 0; i<m; i++){
		jilu[i] = n - 1 - m + i;
	}//�����ڼ�¼���������±�
	//�������
	for (int i = 0; i<m; i++){
		while (A[i][n-1]<0){
for(int i=0;i<m;i++){
		b[i]=A[i][n-1];}
			huanchu = Min(b,m);//huanchuΪ����Ԫ�ص��±�
			//ȷ������������ѡȡb����С��
			int tempi=0;
			for(int i=0;i<n-1;i++){
				if(A[huanchu][i]>0){
					tempi++;}}
			if(tempi==n-1){
				cout<<"�޿��н�"<<endl;
				return 0;}
			

			for (int i = 0; i < n-1; i++){
				if(A[huanchu][i]!=0  &&  jianyanshu[i] / A[huanchu][i]<0)

				{
					jianyanshu[i] = jianyanshu[i] / A[huanchu][i];}
				else{
	
					jianyanshu[i] = 1000;}
				

			}
			huanru=Min(jianyanshu,n-1);
				

			const double x = A[huanchu][huanru];//A��huanchu�������롿�ı��ˣ��ò�����ȷ���
			for (int i = 0; i < n; i++){
				A[huanchu][i] = (A[huanchu][i] / x);
			}
			double temp[3];

			for (int i = 0; i < m; i++){
				temp[i] = A[i][huanru];
			}
			for (int i = 0; i < huanchu; i++){//��
				for (int j = 0; j < n; j++){//��
					A[i][j] = (A[i][j] - A[huanchu][j] * temp[i]);
				}
			}
			for (int i = huanchu + 1; i < m; i++){//��
				for (int j = 0; j < n; j++){//��
					A[i][j] = (A[i][j] - A[huanchu][j] * temp[i]);
				}
			}
			const double y = jianyanshu[huanru];

			for (int i = 0; i < n - 1; i++){
				jianyanshu[i] = jianyanshu[i] - y * A[huanchu][i];
			}
			//��¼�´�ʱ�������ͷǻ�����
			jilu[huanchu] = huanru + 1;}}

	cout << "���ձ�Ϊ" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
	double s = 0;
	cout << "�������ֱ�Ϊ" << endl;
	
	for (int i = 0; i<m; i++){

		
		cout <<"x"<<jilu[i] << endl;

	}
	
	



	system("pause");
}