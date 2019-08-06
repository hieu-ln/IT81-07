#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100
int a[MAX];
int n;
int sp;

void init (int a[], int &sp)
{
	sp = -1;
}
void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a["<<i<<"] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i = sp; i >= 0; i--)
		cout << a[i] << endl;
}
int stackRong(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
int stackDay(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}
int Push(int a[], int &sp, int x)
{
	if (sp < MAX -1)
	{
		a[++sp] = x;
		return 1;
	}                        
	return 0;
}
int Pop(int a[], int &sp, int &x)
{
	if (sp != -1) 
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
int Convert(int so)
{
	init(a, sp);
	int np = 0;
	while (so != 0)
	{
		int du = so % 2;
		if (Push(a, sp, du))
			so /= 2;
		else 
			break;
	}
	while (!stackRong(a, sp))
	{
		int x;
		if (Pop(a, sp, x))
			np = np * 10 + x;
		else 
			break;
	}
	return np;
}
int main ()
{
	char tt;
	int chon;
	do {
		cout << "1. Khoi tao\n2. Kiem tra rong\n3. Kiem tra day\n4. Them 1 phan tu\n5. Xoa 1 phan tu\n6. Xuat Stack\n7. Doi tp sang np\nMoi ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init(a, sp);
			cout << "Khoi tao stack thanh cong\n";
			break;
		case 2:
			if (stackRong(a, sp))
				cout << "Stack rong\n";
			else
				cout << "Stack khong rong\n";
			break;
		case 3:
			if (stackDay(a, sp))
				cout << "Stack day\n";
			else
				cout << "Stack chua day\n";
			break;
		case 4:
			int x;
			cout <<" Nhap gia tri can them vao stack: ";
			cin >> x;
			if (Push(a, sp, x))
				cout << "Them thanh cong\n";
			else
				cout << "Them khong thanh cong\n";
			break;
		case 5:
			int y;
			if (Pop(a, sp, y))
				cout << "Xoa thanh cong. Phan tu xoa duoc la " << y << endl;
			else 
				cout << "Xoa khong thanh cong\n";
			break;
		case 6:
			cout << "Stack hien tai: " << endl;
			output(a, sp);
			break;
		case 7:
			int tp;
			cout << "Nhap gia tri he thap phan can chuyen: ";
			cin >> tp;
			cout << "Gia tri nhi phan tuong ung la: " << Convert(tp) << endl;
			break;
		}
		cout << "Ban co muon tiep tuc hay khong(y/n): ";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
return 0;
}
