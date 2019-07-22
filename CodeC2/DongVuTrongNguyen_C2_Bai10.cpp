#include <iostream>
using namespace std;

//10.1
struct node
{
	int info;
	node *link;
};
node *sp;
//10.2
void init()
{
	sp = NULL;
}
//10.3
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
//10.4
void push(int x)
{
	node *p = new node;
	p ->info = x;
	p ->link = sp;
	sp = p;
}
//10.5
int pop(int &x)
{
	if (sp != NULL)
	{
		node *p = sp;
		x = p ->info;
		sp = sp ->link;
		delete p;
		return x;
	}
	return 0;
}
//menu
void menu()
{
	cout << "\t-----BAI 10 - CHUONG 2-----" << endl;
	cout << "1. Tao danh sach rong" << endl;
	cout << "2. Kiem tra danh sach rong" << endl;
	cout << "3. Chen 1 phan tu vao danh sach" << endl;
	cout << "4. Xoa 1 phan tu ra khoi danh sach" << endl;
	cout << "5. Thoat" << endl;
}

void main()
{
	int choice;
	int x;

	menu();
	do{
		cout << "Chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			init();
			cout << "Tao danh sach rong thanh cong" << endl;
			break;
		case 2:
			x = isEmpty();
			if (x == 1)
				cout << "Kiem tra thanh cong. Danh sach dang rong" << endl;
			else
				cout << "Kiem tra khong thanh cong." << endl;
			break;
		case 3:
			cout << "Nhap gtri muon them: ";
			cin >> x;
			push(x);
			cout << "Them gtri vao danh sach thanh cong" << endl;
			break;
		case 4:
			x = pop(x);
			if (x != 0)
			{
				cout << "Xoa 1 phan tu thanh cong" << endl;
				cout << "Ptu co gtri la: " << x << endl;
			}
			else
				cout << "Xoa khong thanh cong" << endl;
			break;
		default:
			cout << "Goodbey" << endl;
		}
	} while(choice != 5);
}