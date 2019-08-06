#include <iostream>
using namespace std;
#define MAX 100 
int a[MAX];
int front, rear;

void init(int a[], int &front, int &rear) // khởi tạo rỗng
{
	front = -1; 
	rear = -1;
}
int isEmpty(int a[], int &front, int &rear)
{
	if(front == -1)
		return 1;
	return 0;
}
int isFull(int a[], int &front, int &rear)
{
	if (rear - front == MAX - 1)
		return 1;
	return 0;
}
int Push(int a[], int &front, int &rear, int x)
{
	if (rear - front == MAX - 1) // hang đợi đầy
		return 0;
	else
	{
		if (front == -1) // hang đợi rỗng
			front = 0;
		if (rear == MAX - 1) // hang đợi tràn
		{
			for (int i = front; i <= rear; i++)
				a[i-front] = a[i];
			rear = MAX - 1- front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}
int Pop(int a[], int &front, int &rear, int &x)
{
	if (front == -1)
		return 0;
	else 
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}
int main ()
{
	{
	char tt;
	int chon;
	do {
		cout << "1. Khoi tao\n2. Kiem tra rong\n3. Kiem tra day\n4. Them 1 phan tu\n5. Xoa 1 phan tu\nMoi ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init(a, front, rear);
			cout << "Khoi tao stack thanh cong\n";
			break;
		case 2:
			if (isEmpty(a, front, rear))
				cout << "Stack rong\n";
			else
				cout << "Stack khong rong\n";
			break;
		case 3:
			if (isFull(a, front, rear))
				cout << "Stack day\n";
			else
				cout << "Stack chua day\n";
			break;
		case 4:
			int x;
			cout <<" Nhap gia tri can them vao stack: ";
			cin >> x;
			if (Push(a, front, rear, x))
				cout << "Them thanh cong\n";
			else
				cout << "Them khong thanh cong\n";
			break;
		case 5:
			int y;
			if (Pop(a, front, rear, y))
				cout << "Xoa thanh cong. Phan tu xoa duoc la " << y << endl;
			else 
				cout << "Xoa khong thanh cong\n";
			break;
		}
		cout << "Ban co muon tiep tuc hay khong(y/n): ";
		cin >> tt;
		} while (tt == 'y' || tt == 'Y');
	}
return 0;
}