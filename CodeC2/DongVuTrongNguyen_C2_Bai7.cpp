#include <iostream>
using namespace std;
//7.1
#define max 100
int a[max];
int front, rear;
//7.2
void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}
//7.3
bool isEmpty(int a[], int front, int rear)
{
	if (front == -1 && rear == -1)
		return true;
	return false;
}
//7.4
bool isFull(int a[], int front, int rear)
{
	if (rear - front == max - 1)
		return true;
	return false;
}
//7.5
bool push(int a[], int &front, int &rear, int x)
{
	if (rear - front == max - 1)
		return false;
	else
	{
		if (front == - 1)
			front = 0;
		if (rear == max - 1)
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = max - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return true;
	}
}
//7.6 
int pop(int a[], int &front, int &rear)
{
	if (rear >= front)
	{
		int tam = a[rear--];
		return tam;
	}
	return 0;

}
void menu()
{
	cout << "\t----- BAI 7 - CHUONG 2 ------" << endl;
	cout << "1. Khoi tao hang doi rong" << endl;
	cout << "2. Kiem tra rong" << endl;
	cout << "3. Kiem tra day" << endl;
	cout << "4. Chen 1 phan tu vao hang doi" << endl;
	cout << "5. Thoat" << endl;
}

void main()
{
	int x;
	int choice;
	bool kq;

	menu();
	do{
		cout << "Nhap so muon thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, front, rear);
			cout << "Khoi tao hang doi rong thanh cong" << endl;
			break;
		case 2:
			kq = isEmpty(a, front, rear);
			if (kq == true)
				cout << "Kiem tra thanh cong. Hang doi rong" << endl;
			else
				cout << "Kiem tra khong thanh cong" << endl;
			break;
		case 3:
			kq = isFull(a, front, rear);
			if (kq == true)
				cout << "Kiem tra thanh cong. Hang doi da day" << endl;
			else
				cout << "Kiem tra khong thanh cong" << endl;
			break;
		case 4:
			cout << "Nhap gtri muon chen: ";
			cin >> x;
			kq = push(a, front, rear, x);
			if (kq == true)
				cout << "Chen thanh cong" << endl;
			else
			cout << "Chen khong thanh cong" << endl;
			break;
		default:
			cout << "Goodbey" << endl;
		}
	} while(choice != 5);
}