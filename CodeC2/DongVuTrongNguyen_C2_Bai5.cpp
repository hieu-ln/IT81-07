#include <iostream>
#include <conio.h>
using namespace std;

//5.1
#define MAX 100
int a[MAX];
int n;
//5.2
void init(int a[], int &n)
{
	n = -1;
}
//5.3
int isEmpty(int a[], int n)
{
	if (n == -1)
		return 0;
	return 1;
}
//5.4
int isFull(int a[], int n)
{
	if (n == MAX - 1)
		return 0;
	return 1;
}
//5.5
int insert(int a[], int &n, int x)
{
	if (n < MAX - 1)
	{
		a[++n] = x;
		return 1;
	}
	return 0;
}
//5.6
int deleteStack(int a[], int &n)
{
	if (n == -1)
	{
		n--;
		return 1;
	}
	return 0;
}
//lay ptu tu stack
int pop(int a[], int &n, int &x)
{
	if (n != -1)
	{
		x = a[n--];
		return x;
	}
	return 0;
}
//menu
void menu()
{
	cout << "----BAI 5 - BAI THUC HANH SO 3 - CHUONG 2-----" << endl;
	cout << "1. Khoi tao stack rong." << endl;
	cout << "2. Lay 1 ptu tu stack" << endl;
	cout << "3. Kiem tra stack rong." << endl;
	cout << "4. Kiem tra stack day." << endl;
	cout << "5. Them 1 phan tu." << endl;
	cout << "6. Xoa 1 phan tu." << endl;
	cout << "7. Thoat." << endl;
}
void main()
{
	int choice;
	int kq;
	int x;

	
	do{
		
		system("cls");
		menu();
		cout << "Vui long chon 1 so de thuc hien: ";
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			init(a, n);
			cout << "Khoi tao stack rong thanh cong" << endl;
			break;

		case 2:
			x = pop(a, n, x);
			if (x != 0)
			{
				cout << "Lay 1 ptu thanh cong!" << endl;
				cout << "ptu co gtri = " << x << endl;
			}
			else
				cout << "Lay ptu khong thanh cong!";
			break;
		case 3:
			kq = isEmpty(a, n);
			if (kq == 0)
				cout << "Kiem tra thanh cong! Stack hien tai dang rong." << endl;
			else
				cout << "Kiem tra khong thanh cong!" << endl;
			break;
		case 4:
			kq = isFull(a, n);
			if (kq == MAX - 1)
				cout << "Kiem tra thanh cong! Stack hien tai da day." << endl;
			else
				cout << "Kiem tra khong thanh cong!" << endl;
			break;
		case 5:
			cout << "Nhap gtri muon them: ";
			cin >> x;
			kq = insert(a, n, x);
			if (kq == 1)
				cout << "Chen 1 phan tu vao stack thanh cong!" << endl;
			else
				cout << "Chen khong thanh cong!" << endl;
			break;
		case 6:
			kq = deleteStack(a, n);
			if (kq == 1)
			{
				cout << "Xoa 1 phan tu vao stack thanh cong!" << endl;
				
				if (n == -1)
					cout << "Stack hien tai khong con phan tu nao!" << endl;
			}
			else
				cout << "Xoa khong thanh cong!" << endl;
			break;
		default:
			cout << "Chao tam biet!" << endl;
		}
		getch();
	} while(choice != 7);
}




