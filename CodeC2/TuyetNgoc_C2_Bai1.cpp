//Danh sach dac
#include <iostream>
using namespace std;

#define Max 100
	int a[Max];
	int n;

void input(int a[], int &n)
{
	cout << "Nhap so phan tu can thuc hien: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] =";
		cin >> a[i];
	}
}
void output(int a[], int &n)
{
	cout << "Danh sach cac phan tu la: \n";
	for(int i = 0; i < n; i++)
		cout << a[i] << endl;
}
int search(int a[], int n,int x)
{
	int i = 0;
	while(i < n && a[i] != x)
	{
		i++;
	}
	if(i == n)
		return -1;
	return i;
}
void swap(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}
int insert_last(int a[], int &n, int x)
{
	if(n < Max)
	{
		a[n] = x;
		n++;
		return 1;
	}

	return 0;
}
int Delete_last(int a[], int &n)
{
	if(n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
int Delete_i(int a[], int &n, int b)
{
	if(b >= 0 && b < n)
	{
		for(int i = b; i < n - 1; i++)
			a[i] = a[i + 1];
		n--;
		return 1;
	}
	return 0;
}
int searchAndDelete(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
		if(a[i] == x)
		{
			Delete_i(a, n, i);
			return 1;
		}
	return 0;
}
	

int main()
{
	int i, chon = 0, x;
	system("cls");
	cout << "Bai thuc hanh 1_Chuong 2" << endl;
	cout << "1.Nhap danh sach\n"
		<< "2.Xuat danh sach\n"
		<< "3.Tim mot phan tu trong danh sach\n"
		<< "4.Them mot phan tu vao cuoi danh sach\n"
		<< "5.Xoa mot phan tu cuoi danh sach\n"
		<< "6.Xoa phan tu tai vi tri bat ki\n"
		<< "7. Tim mot phan tu va xoa\n"
		<< "8.Thoat\n";
	do{
		cout << "Ban muon chon thuc hien so may: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			input(a, n);
			cout << "Ban vua nhap thanh cong!\n";
			break;
		case 2:
			output(a, n);
			break;
		case 3:
			cout << "Ban muon tim gia tri: ";
			cin >> x;
			i = search(a, n, x);
			if(i == -1)
				cout << "Khong tim thay\n";
			else
				cout << x << "xuat hien tai vi tri a[" << i << "]";
			break;
		case 4:
			cout << "Ban muon them gia tri: ";
			cin >> x;
			i = insert_last(a, n, x);
			output(a, n);
			break;
		case 5:
			i = Delete_last(a, n);
			output(a, n);
			break;
		case 6:
			cout << "Ban muon xoa tai vi tri: ";
			cin >> x;
			i = Delete_i(a, n, x);
			if(i == 1)
				output(a, n);
			else
				cout << "Khong the xoa!\n";
			break;
		case 7:
			cout << "Ban muon xoa gia tri: ";
			cin >> x;
			i = searchAndDelete(a, n, x);
			if(i == 1)
				output(a,n);
			else
				cout << "Khong tim thay de xoa!\n";
				break;
		default:
			cout << "Tam biet!\n";
		}
	}while(chon >=1 && chon < 8);
	return 0;
}


