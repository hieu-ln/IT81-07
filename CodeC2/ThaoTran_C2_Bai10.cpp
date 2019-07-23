//bai 10 chuong 2
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *sp;

//10.2 
void init ()
{
	sp = NULL;
}

//10.3
int isEmpty ()
{
	if (sp == NULL)
		return 1;
	return 0;
}


//10.4
void Push (int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
//10.5
int Pop (int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//xuat stack
void Process_stack ()
{
	Node *p = sp;
	do{
		cout << p->info << " ";
		p = p->link;
	}while (p != NULL);
	cout << endl;
}

int main()
{
	int choice, x, i;
	system ("cls");
	cout << "--------BAI TAP 10, CHUONG 2, DANH SACH DAC---------" << endl;
	cout << "1. Khoi tao STACK rong" << endl;
	cout << "2. Them phan tu vao STACK" << endl;
	cout << "3.Lay phan tu ra khoi STACK" << endl;
	cout << "4. Xuat STACK" << endl;	
	cout << "5. Thoat" << endl; 
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
				Push(x);
				cout << "STACK sau khi them la: " << endl;
				Process_stack();
				break;
			case 3:
				Pop (x);
				cout << "Phan tu lay ra tu STACK la x= " << x;
				cout << "STACK sau khi lay ra la: " << endl;
				Process_stack();
				break;
			case 4: 
				cout << "STACK hien tai la: ";
				Process_stack();
				break;
			case 5: 
				cout << "Goodbye!" << endl;
				break;
			default:
				break;
		}
	}while(choice != 5);
	system("pause");
	return 0;
}