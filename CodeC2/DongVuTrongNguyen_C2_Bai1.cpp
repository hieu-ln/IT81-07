//bai 1 chuong 2
#include <iostream>
using namespace std;

//1.1
#define MAX 100
int a[MAX];
int n;

//1.2
void nhap(int a[], int &n)
{
	cout << "Nhap sluong ptu: ";
	do{
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap lai n!";
	} while(n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
//1.3
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//1.4
int timKiem(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}
//1.5
void themCuoi(int a[], int &n, int x)
{
	a[n] = x;
	n++;
}
//1.6
void xoaCuoi(int a[], int &n)
{
	n--;
}
//1.7
void xoa(int a[], int &n, int i)
{
	if (i >= 0 && i < n)
		for (int j = i; j < n; j++)
			a[j] = a[j + 1];
	n--;
}
//1.8
int timVaXoa(int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			xoa(a, n, i);
		return 1;
	}
	return -1;
}
//menu
void menu()
{
	cout << "----BTH1-CHUONG2----" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim 1 ptu trong danh sach" << endl;
	cout << "4. Them 1 ptu vao cuoi danh sach" << endl;
	cout << "5. Xoa 1 ptu cuoi danh sach" << endl;
	cout << "6. Xoa ptu tai vi tri i trong danh sach" << endl;
	cout << "7. Tim va xoa 1 ptu (neu tim thay) trong danh sach" << endl;
	cout << "8. Thoat" << endl;
}

void main()
{
	int chon = 0;
	int x;
	int kq;

	menu();
	do{
		cout << "Chon so de thuc hien: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			{
				nhap(a, n);
				break;
			}
		case 2:
			{
				cout << "Danh sach la: ";
				if (n != 0)
					xuat(a, n);
				else
					cout << "Dach sach khong con ptu nao!" << endl;
				break;
			}
		case 3:
			{
				cout << "Nhap gtri can tim: ";
				cin >> x;
				kq = timKiem(a, n, x);
				if (kq != -1)
					cout << "Gtri x = " << x << " co trong danh sach tai vi tri i = " << kq << endl;
				else
					cout << "Gtri x = " << x << " khong co trong danh sach" << endl;
				break;
			}
		case 4:
			{
				cout << "Nhap gtri muon them: ";
				cin >> x;
				cout << "Danh sach sau khi them cuoi la: ";
				xuat(a, n);
				break;
			}
		case 5:
			{
				xoaCuoi(a, n);
				if (n != 0)
				{
					cout << "Danh sach sau khi xoa cuoi la: ";
					xuat(a, n);
				}
				else
					cout << "Dach sach khong con ptu nao!" << endl;
				break;
			}
		case 6:
			{
				cout << "Nhap vi tri muon xoa: ";
				cin >> x;
				xoa(a, n, x);
				if (n != 0)
				{
					cout << "Danh sach sau khi xoa tai vi tri " << x << " la: ";
					xuat(a, n);
				}
				else
					cout << "Dach sach khong con ptu nao!" << endl;
				break;
			}
		case 7:
			{
				cout << "Nhap ptu muon tim kiem va xoa: ";
				cin >> x;
				kq = timVaXoa(a, n, x);
				if (kq != -1 && n != 0)
				{
					cout << "Danh sach sau khi xoa la: ";
					xuat(a, n);
				}
				else
					cout << "Khong co gtri " << x << " trong danh sach" << endl;
				break;
			}
		default:
			cout << "Goodbye!!!!!!!!" << endl;
		}
	} while(chon != 8);
}