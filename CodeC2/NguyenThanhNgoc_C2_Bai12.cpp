#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *next, *previous;
};
Node *first, *last;
void init()
{
	first = NULL;
	last = NULL;
}
void Process_list()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p ->next;
	}
}
void output ()
{
	Node *p = first;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
}
void insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
		first->previous = p;
	else
		last = p;
	first = p;
}
void insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	last->next = p;
	last = p;
}
Node * Search(int x)
{
	Node * p;
	p = first;
	while ((p != NULL) && (p->info != x))
		p = p->next;
	return p;
}
int Delete_first()
{
	if (first != NULL)
	{
		Node *p;
		p = first;
		first = first->next;
		if (first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		return 1;
		delete p;
	}
	return 0;
}
int Delete_last()
{
	if (last != NULL)
	{
		Node *p;
		p = last;
		last = last->previous;
		if (last != NULL)
			last->next = NULL;
		else
			first = NULL;
		return 1;
		delete p;
	}
	return 0;
}
int Search_del (int x)
{
	Node *p= Search(x);
	if (p != NULL)
	{
		if (p == first)
		{
			if (Delete_first())
				return 1;
			else 
				return 0;
		}
		else if (p == last)
		{
			if (Delete_last())
				return 1;
			else 
				return 0;
		}
		else
		{
			Node *q, *r;
			q = p->previous;
			q->next = p->next;
			r = p->next;
			r->previous = q;
			delete p;
			return 1;
		}
	}
}
int main ()
{
	char tt;
	int x,y;
	int chon;
	do {
		system("cls");
		cout << "MENU\n";
		cout << "1. Khoi tao\n2. Xuat danh sach\n3. Them 1 phan tu vao dau ds\n4. Them 1 phan tu vao cuoi ds\n5. Xoa 1 phan tu dau ds\n6. Xoa 1 phan tu cuoi ds\n7. Tim 1 phan tu trong ds r xoa\nMoi ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
			cout << "Khoi tao ds thanh cong\n";
			break;
		case 2:
			cout << "Danh sach hien tai: " << endl;
			output();
			break;
		case 3:
			cout << "Nhap gia tri can them vao dau ds: ";
			cin >> x;
			insert_first(x);
			cout << "Them thanh cong\n";
			break;
		case 4:
			cout << " Nhap gia tri can them vao cuoi ds: ";
			cin >> y;
			insert_last(y);
			cout << "Them thanh cong\n";
			break; 
		case 5:
			cout << "Nhap gia tri can xoa dau ds: ";
			cin >> x;
			if (Delete_first())
				cout << "Xoa thanh cong. Phan tu xoa duoc la " << x <<endl;
			else 
				cout << "Xoa khong thanh cong\n";
			break;
		case 6:
			cout << "Nhap gia tri can xoa cuoi ds: ";
			cin >> y;
			if (Delete_last())
				cout << "Xoa thanh cong. Phan tu xoa duoc la " << y <<endl;
			else 
				cout << "Xoa khong thanh cong\n";
			break;
		case 7:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			if (Search_del(x))
				cout << "Xoa thanh cong";
			else
				cout << "Xoa khong thanh cong";
			break;
		}
		cout << "Ban co muon tiep tuc hay khong(y/n): ";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
return 0;
}