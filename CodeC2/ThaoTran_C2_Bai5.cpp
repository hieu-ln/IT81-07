//bai 5 chuong 2
#include <iostream>
using namespace std;

#define MAX 100

//5.2 
void init (int a[], int &sp)
{
	sp = -1;
}

//5.3
int isEmpty (int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

//5.4
int isFull (int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

//5.5
int Push (int ap[], int &sp, int &x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//5.6
int Pop (int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

//xuat stack
void Process_stack (int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << "\t";
	cout << endl;
}

int main()
{
	int a[MAX];
	int choice, sp, x, i;
	system ("cls");
	cout << "--------BAI TAP 5, CHUONG 2, DANH SACH DAC---------" << endl;
	cout << "1. Khoi tao STACK rong" << endl;
	cout << "2. Them phan tu vao STACK" << endl;
	cout << "3.Lay phan tu ra khoi STACK" << endl;
	cout << "4. Kiem tra STACK co rong hay khong" << endl;
	cout << "5. Kiem tra STACK co day hay khong" << endl;
	cout << "6. Xuat STACK" << endl;	
	cout << "7. Thoat" << endl; 
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init ();
				cout << "Ban vua khoi tao STACK thanh cong!" << endl;
				break;
			case 2:
				cout << "Vui long nhap gia tri x= " << endl;
				cin >> x;
				i = Push (a, sp, x);
				cout << "STACK sau khi them la: " << endl;
				Process_stack();
				break;
			case 3:
				i = Pop (a, sp, x);
				cout << "Phan tu lay ra tu STACK la x= " << x;
				cout << "STACK sau khi lay ra la: " << endl;
				Process_stack();
				break;
			case 4:
				i = isFull(a, sp);
				if (i == 0)
					cout << "STACK chua day" << x << endl;
				else
					cout << "STACK da day" << endl;
				break;
			case 5:
				i = isEmpty(a, sp);
				if(i == 0)
					cout << "STACK khong rong" << x << endl;
				else
					cout << "STACK rong" << endl;
				break;
			case 6: 
				cout << "STACK hien tai la: ";
				Process_stack(a, sp);
				break;
			case 7: 
				cout << "Goodbye!" << endl;
				break;
			default:
				break;
		}
	}while(choice != 7);
	system("pause");
	return 0;
}