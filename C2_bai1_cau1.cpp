//Danh sach dac
#include <iostream>
using namespace std;

void input(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] =";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	cout << "Danh sach cac phan tu la: ";
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
void insert(int a[], int &n, int x)
{
	a[n] = x;
	n++;
}
void Delete(int a[], int &n)
{
	n--;
}
void Delete_i(int a[], int &n, int b)
{
	for(int i = b - 1; i < n; i++)
		a[i] = a[i + 1];
	n--;
}
void menu(int a[], int n, int x, int y, int z)
{
	int chon, i;
	
int main()
{
	const int Max = 100;
	int a[Max];
	int n;
	int x, y, z;
	do{
		cout << "Nhap so luong phan tu thuc te: ";
		cin >> n;
		if(n < 0 || n > Max)
			cout << "Nhap sai. Vui long nhap lai!"
	}while(n < 0 || n > Max);
	do{
		cout << "1.Khai bao cau truc danh sach\n2.Thu tuc nhap danh sach\n3.Thu tuc xuat danh sach ra man hinh\n"
			<< "4.Tim mot phan tu trong danh sach\n5.Them phan tu vao cuoi danh sach\n6.Xoa phan tu cuoi danh sach\n"
			<< "7.Xoa phan tu tai vi tri thu i\n8.Tim phan tu va xoa\n9.Thoat\n Ban chon: ";
		cin >> chon;
		if(chon < 0 || chon > 10)
			cout << "Khong tim thay yeu cau. Vui long chon lai!";
	}while(chon < 0 || chon > 10);
	while(chon >= 1 || chon <= 9)
	{
		switch(chon)
		{
		case 1:
			cout << "Da khai bao thanh cong!\n";
				break;
		case 2:
			input(a, n);
			break;
		case 3:
			output(a, n);
			break;
		case 4:
			{
				cout << "Ban muon tim gia tri: ";
				cin >> x;
				cout << "Phan tu co tai vi tri: ";
				i = search(a, n, x);
				break;
			}
		case 5:
			{
				cout << "Ban muon chen gia tri: ";
				cin >> y;
				insert(a, n, y);
				break;
			}
		case 6:
			Delete(a, n);
		case 7:
			{

			}
		}
	}
	return 0;
}


