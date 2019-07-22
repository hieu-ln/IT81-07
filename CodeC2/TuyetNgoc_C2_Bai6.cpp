//Stack (Danh sach dac)
#include <iostream>
using namespace std;

//5.1 Khai bao cau truc stack theo ds dac
#define MAX 100
int a[MAX];
int sp;
//xuat
void output(int a[], int sp)
{
	for(int i = 0; i <= sp; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
//5.2 Khoi tao stack rong
void init(int a[], int &sp)
{
	sp = -1;
}
//5.4 Kiem tra stack day
int isFull(int a[], int sp)
{
	if(sp == MAX - 1)
		return 1;
	return 0;
}
//5.3 Kiem tra stack rong
int isEmpty(int a[], int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}
//5.5 Them 1 phan tu vao stack
int Push(int a[], int &sp, int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//5.6 Lay mot phan tu trong stack
int Pop(int a[], int &sp, int &x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
//6 chuyen thap phan sang nhi phan
void toBinary(int b[], int sp2, int x)
{
	int sodu, i, ii;
	while(x != 0)
	{
		sodu = x % 2;
		ii = Push(b, sp2, sodu);
		x /= 2;
	}
	while(sp2 >= 0)
	{
		i = Pop(b, sp2, sodu);
		cout << sodu;
	}
	cout << endl;
}

int main()
{
	int chon, i, x, y;
	int b[MAX], sp2;
	init(b, sp2);
	cout << "---Bai thuc hanh 3_Chuong 2---\n"
		<< "1.Khai bao stack theo ds dac\n"
		<< "2.Khoi tao stack rong\n"
		<< "3.Kiem tra stack rong\n"
		<< "4.Kiem tra stack day\n"
		<< "5.Them mot phan tu\n"
		<< "6.Xoa mot phan tu\n"
		<< "7.Chuyen thap phan sang nhi phan\n"
		<< "8.Thoat\n";
	do{
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			cout << "Khai bao thanh cong!\n";
			break;
		case 2:
			init(a, sp);
			cout << "Khoi tao stack rong thanh cong!\n";
			break;
		case 3:
			i = isEmpty(a, sp);
			if(i == 0)
				cout << "Stack khong rong!\n";
			else
				cout << "Stack rong!\n";
			break;
		case 4: 
			i = isFull(a, sp);
			if(i == 1)
				cout << "Stack da day!\n";
			else
				cout << "Stack van con trong!\n";
			break;
		case 5:
			cout << "Nhap phan tu muon them: ";
			cin >> x;
			i = Push(a, sp, x);
			if(i == 1)
			{
				cout << "Danh sach sau khi them la: ";
				output(a, sp);
			}
			break;
		case 6:
			i = Pop(a, sp, x);
			cout << "Phan tu lay ra la: " << x << endl;
			cout << "Danh sach sau khi xoa la: ";
			output(a, sp);
			break;
		case 7:
			cout << "Nhap so thap phan: ";
			cin >> y;
			toBinary(b, sp2, y);
			break;
		default:
			cout << "Hen gap lai!\n";
		}
	}while(chon >= 1 && chon < 8);
	return 0;
}