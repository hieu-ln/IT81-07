//queue(Danh sach dac)
#include <iostream>
using namespace std;

#define MAX 100
//7.2Khoi tao queue rong
void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}
//7.3 kiem tra queue rong
int isEmpty(int a[], int front, int rear)
{
	if(front == rear)
		return 1;
	return 0;
}
//7.4 Kiem tra queue day
int isFull(int a[], int front, int rear)
{
	if(front == 0 && rear == MAX - 1 || front-rear == 1)
		return 1;
	return 0;
}
//7.5 them mot phan tu bang phuong phap vong
int Push(int a[], int &front, int &rear, int x)
{
	if(rear - front == MAX -1 || rear - front == -1)
		return 0;
	else
	{
		if(front == -1)
			front = 0;
		if(rear == MAX - 1)
			rear = -1;
		a[++rear] = x;
		return 1;
	}

}
//7.6 Xoa mot phan tu 
int Pop(int a[], int &front, int &rear, int &x)
{
	if(front != -1)
	{
		x = a[front];
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front++;
			if(front > MAX - 1)
				front = 0;
		}
		return 1;
	}
	return 0;
}
void Process(int a[], int front, int rear)
{
	for(int i = front; i <= rear; i++)
		cout << a[i] << "\t";
	cout << endl;
}

int main()
{
	int a[MAX];
	int front, rear;
	init(a, front, rear);
	int chon, i, x;
	cout << "Bai thuc hanh 3 - Chuong 2\n"
		<< "1.Khai bao\n"
		<< "2.Khoi tao queue\n"
		<< "3.Kiem tra queue rong\n"
		<< "4.Kiem tra queue day\n"
		<< "5.Them mot phan tu vao queue\n"
		<< "6.Xoa mot phan tu\n"
		<< "7.Thoat\n";
	do{
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			cout << "Khai bao queue thanh cong!\n";
			break;
		case 2:
			cout << "Khoi tao queue rong thanh cong!\n";
			break;
		case 3:
			i = isEmpty(a, front, rear);
			if(i == 1)
				cout << "Queue rong\n";
			else
				cout << "Queue khong rong\n";
			break;
		case 4:
			i = isFull(a, front, rear);
			if(i == 1)
				cout << "Queue day\n";

			else
				cout << "Queue khong day\n";
			break;
		case 5:
			cout << "Nhap phan tu muon them: ";
			cin >> x;
			i = Push(a, front, rear, x);
			if(i == 1)
			{
				cout << "Danh sach sau khi them la: ";
				Process(a, front, rear);
			}
			else
				cout << "Them khong thanh cong!\n";
			break;
		case 6:
			i = Pop(a, front, rear, x);
			cout << "Phan tu da xoa la: " << x << endl;
			cout << "Danh sach sau khi xoa la: ";
			Process(a, front, rear);
			break;
		default:
			cout << "Hen gap lai!\n";
		}
	}while(chon > 0 && chon < 8);
	return 0;
}