//da thuc danh sach lien ket kep
#include <iostream>
#include <string>
using namespace std;

//14.1 Khai bao cau truc phan tu ds lk kep
struct Node
{
	int c, power;
	Node *prev, *next;
};
Node *first, *last;
// Khoi tao
void init()
{
	first = NULL;
	last = NULL;
}
// Them phan tu vao ds
int insert(Node *p)
{
	if(first == NULL)
	{
		first = p;
		last = p;
		return 1;
	}
	else
	{
		Node *q = first;
		while(q != NULL)
		{
			if(q->power == p ->power)
				break;
			q = q->next;
		}
		if(q != NULL)
		{
			q->c = q->c + p->c;
		}
		else
		{
			Node *l = last;
			l ->next = p;
			p->prev = l;
			p->next = NULL;
			last = p;
			return 1;
		}
	}
	return 0;
}
// xuat
void output()
{
	if(first == NULL)
	{
		cout << "Da thuc rong\n";
		return;
	}
	Node *p = first;
	cout << "P(x) = " ;
	while(p!= NULL)
	{
		if(p->power == 0)
			cout << " + " << p->c;
		else
			if(p->power == 1)
				cout << " + " << p->c << "x" ;
			else
				if(p->c > 0)
					cout << " + " << p->c << "x^(" << p->power << ")";
				else
					cout << " " << p->c << "x^(" << p->power << ")";
		p = p->next;
	}
}

int main()
{
	int chon, i;
	int c, power;
	Node *p = new Node;
	cout << "1.Khoi tao\n 2. Them phan tu\n 3. Xuat\n";
	do{
		cout << "\n Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			cout << "Khoi tao thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap c va power: ";
			cin >> c >> power;
			p->c= c;
			p->power = power;
			p ->prev = NULL;
			p->next = NULL;
			insert(p);
			output();
			break;
		case 3:
			break;
		}
	}while(chon > 0 && chon < 3);
}