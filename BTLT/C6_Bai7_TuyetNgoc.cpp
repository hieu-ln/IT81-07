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
void taoE()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
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
//hoan doi
void swap(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}
//sap xep dua tren Interchange Sort
void SapXepE()
{
	for(int i = 0; i < nE - 1; i++)
		for(int j = i + 1; j < nE; j++)
			if(wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
}
//Kruskal
void Kruskal()
{
	for(int i = 0; i< nE; i++)
	{
		if(TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if(TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if(nT == n-1)
			break;
	}
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

int main()
{
	int chon, x, i;
	cout << "-----------------BAI TAP 6, CHUONG 6------------------------" << endl;
	cout << "1. Khoi tao ma tran\n2. Nhap ma tran tu file\n 3. Nhap ma tran bang tay\n4. Xuat ma tran\n5.Tao E\n6.Sap xep truoc khi tim\n7. Tim cay khung toi tieu bang kruskal\n8.Tim cay khung bang prim\n9. Thoat\n";
	do{
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			initGraph();
			cout << "Khoi tao ma tran thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Nhap ma tran thanh cong!\n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			cout << "Ma tran sau khi nhap la: \n";
			outputGraph();
			break;
		case 4:
			cout << "Ma tran la: \n";
			outputGraph();
			break;
		case 5:
			taoE();
			cout << "Tao E thanh cong!\n";
			break;
		case 6:
			SapXepE();
			cout << "Sap xep thanh cong!\n";
			break;
		case 7:
			Kruskal();
			cout << "Cay khung toi thieu voi kruskal: \n";
			output();
			break;
		case 8:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			Prim(x);
			cout << "Cay khung toi thieu voi prim: \n";
			output();
			break;
		default:
			cout << "Tam biet. Hen gap lai!\n";
		}
	}while(chon > 0 && chon < 9);
	return 0;
}

