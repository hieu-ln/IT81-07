//Giai thuat Prim
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX 20
//Khai bao mang 2 chieu
int a[MAX][MAX];
int n;
char vertex[MAX];
//Khoi tao 
void initGraph()
{
	n = 0;
}
//nhap tu file
void inputGraphFromText()
{
	string line;
	ifstream datafile("matrantrongso1.txt");
	if(datafile.is_open())
	{
		datafile >> n;
		for(int i = 0; i < n; i++)
			datafile >> vertex[i];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				datafile >> a[i][j];
		}
		datafile.close();
	}
}
//nhap bang tay
void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i];
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
void outputGraph()
{
	cout << setw(6) << left;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}

//Khai bao tapE
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
//Khai bao tapT
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;
//ton tai
int TonTai(int d, int D[], int nD)
{
	for(int i = 0; i < nD; i++)
		if(D[i] == d)
			return 1;
	return 0;
}
//Xoa vi tri
void XoaViTri(int i)
{
	for(int j = 0; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}
//xoa canh
void XoaCanhE(int u, int v)
{
	for(int i = 0; i < nE; i++)
		if(E1[i] == u && E2[i] == v)
		{
			XoaViTri(i);
			break;
		}
}
//thuat giai prim
void Prim(int s)
{
	int u = s, min, i, d1, d2;
	while(nT < n - 1)
	{
		for(int v = 0; v < n; v++)
			if(a[u][v] != 0)
				if(TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
		for(i = 0; i < nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		for(i = 0; i < nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
				if(min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}
//xuat
void output()
{
	int tong = 0;
	for(int i = 0; i < nT; i++)
	{
		cout << endl << "(" << T1[i] << ", " << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong =" << tong;
	cout << endl;
}

int main()
{
	int chon, x, i;
	cout << "-----------------BAI TAP 4, CHUONG 6------------------------" << endl;
	cout << "1. Khoi tao ma tran" << endl;
	cout << "2. Nhap ma tran tu file" << endl;
	cout << "3. Nhap ma tran bang tay" << endl;
	cout << "4. Xuat ma tran" << endl;
	cout << "5. Tim cay khung toi tieu" << endl;
	cout << "6. Thoat" << endl;
	do{
		cout << "Vui long chon so: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			initGraph();
			cout << "Khoi tao ma tran thanh cong!" << endl;
			break;
		case 2:
			inputGraphFromText();
			cout << "Nhap ma tran thanh cong!" << endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			cout << "Ma tran sau khi nhap la: " << endl;
			outputGraph();
			break;
		case 4:
			cout << "Ma tran la: " << endl;
			outputGraph();
			break;
		case 5:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			Prim(x);
			cout << "Cay khung toi thieu voi prim: " << endl;
			output();
			break;
		case 6:
			cout << "Tam biet. Hen gap lai!" << endl;
			break;
		default:
			break;
		}
	}while(chon != 6);
	return 0;
}