#include <iostream>
using namespace std;

struct Node 
{
	int info;
	Node *link;
};
Node *sp;
void init ()
{
	sp = NULL;
}
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node *p;
	p = new Node;
	p ->info = x;
	p ->link = sp;
	sp = p;
}
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p ->info;
		sp = p ->link;
		delete p;
		return 1;
	}
	return 0;
}
int Convert(int so)
{
	init();
	int np = 0;
	while (so != 0)
	{
		int x;
		int du = so % 2;
		(Push(du));
		so /= 2;
	}
	while (!isEmpty())
	{
		int x;
		if (Pop(x))
			np = np * 10 + x;
		else 
			break;
	}
	return np;
}
int main ()
{
	{
	int choice;
	int x;


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
			Push(x);
			cout << "Them gtri vao danh sach thanh cong" << endl;
			break;
		case 4:
			x = Pop(x);
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
}

	