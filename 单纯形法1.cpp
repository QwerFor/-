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


	



int main(){

	double A[30][30];
	int m, n, w;

	int huanru = 0;
	int huanchu = 0;

	cout << "------------------�����η�---------------------" << endl << endl;

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
		xishu[i] = jianyanshu[i];
	}
	cout << "�����ֵ��������Сֵ�� ���ֵΪ1����СֵΪ-1��      " << endl;
	cin >> w;

	cout << "��������������" << endl;
	for (int i = 1; i < n; i++){ cout << "x" << i ; }
	cout << " b";
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	int  *jilu = new int[m];
	for (int i = 0; i < m; i++){
		jilu[i] = n - 1 - m + i;
	}
	int *xxishu = new int[n - 1];
	//�������
	for (int i = 0; i<n - 1; i++){
		while (jianyanshu[i]>0
			){
			for (int i = 0; i < n - 1; i++){
				xxishu[i] = i + 1;

				huanru = Max(jianyanshu, n);//huanrulile

				///����m ����n

				for (int i = 0; i < m; i++){

					if (A[i][huanru]>0)
					{

						jianyanshu2[i] = A[i][n - 1] / A[i][huanru];
					}
					else
					{
						jianyanshu2[i] = 100001;
					}

				}


				//�����У�������
				huanchu = Min(jianyanshu2, m);
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
				//�õ��¾��󣬼����¼�����
				const double y = jianyanshu[huanru];

				for (int i = 0; i < n - 1; i++){
					jianyanshu[i] = jianyanshu[i] - y * A[huanchu][i];
				}
				//��¼�´�ʱ�������ͷǻ�����
				jilu[huanchu] = huanru + 1;

			}
		}
		//�ж��Ƿ�Ϊ���Ž⻹���޽�⻹����������Ž�
		for (int i = 0; i < n - 1; i++){
			for (int j = 0; j < m; j++){
				if (xxishu[i] = jilu[j]){ xxishu[i] = 0; }
			}
		}
		int *feiji = new int[n - 1 - m];
		for (int i = 0; i < n - 1 - m; i++){
			feiji[i] = 0;
		}
		for (int i = 0; i < n - 1; i++){
			if (xxishu[i] != 0){
				int j = 0;
				feiji[j] = xxishu[i]; j++;
			}
		}
		for (int i = 0; i < n; i++){
			if (jianyanshu[i]>0){
				for (int i = 0; i < m; i++){
					int flag = 0;
					for (int j = 0; j < m; j++){
						if (A[i][jilu[j]] < 0){
							flag += 1;
						}
						if (flag == m){
							cout << "�޽��";
							break;
						}
					}

				}
			}

		}
		for (int i = 0; i < n - 1 - m; i++){
			if (jianyanshu[feiji[i]-1] == 0){
				cout << "��������Ž�" << endl;
				break;
			}
		}

		cout << "���ձ�Ϊ" << endl;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cout << A[i][j] << "  ";
			}
			cout << endl;
		}
		double s = 0;
		cout << "�����������ֱ�Ϊ" << endl;

		for (int i = 0; i < m; i++){


			cout << "x" << jilu[i] << endl;

			s += xishu[jilu[i] - 1] * A[i][n - 1];


		}
		cout << "�������Ž�Ϊ��" << endl;
		cout << s << endl;
		system("pause");
	}
}