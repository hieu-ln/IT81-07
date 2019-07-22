//Stack danh sach lien ket don
#include <iostream>
using namespace std;

//10.1 Khai bao stack
struct Node
{
	int info;
	Node *link;
};
Node *sp, *sp2;
//10.2 Khoi tao stack rong
void init()
{
	sp = NULL;
	sp2 = NULL;
}
//10.3 Kiem tra stack rong
int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}
//10.4 Them mot phan tu vao stack
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
//cho sp2
void Push2(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp2;
	sp2 = p;
}
//10.5 Xoa mot phan tu trong stack
int Pop(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p ->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//cho sp2
int Pop2(int &x)
{
	if(sp2 != NULL)
	{
		Node *p = sp2;
		x = p ->info;
		sp2 = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//Xuat
void Process()
{
	Node *p = sp;
	while(p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
//10.6 doi thap phan sang nhi phan
void toBinary(int x)
{
	int soDu, i;
	while(x != 0)
	{
		soDu = x % 2;
		Push2(soDu);
		x /= 2;
	}
	while(sp2 != NULL)
	{
		 i = Pop2(soDu);
		 cout << soDu;
	}
	cout << endl;
}

int main()
{
	int chon, x, i;
	cout << "1.Khai bao stack\n"
		<< "2.Khoi tao stack rong\n"
		<< "3.Kiem tra stack rong\n"
		<< "4. Them mot phan tu vao stack\n"
		<< "5. Xoa mot phan tu trong stack\n"
		<< "6. Chuyen mot so thap phan sang nhi phan\n"
		<< "7.Thoat\n";
	do{
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			cout << "Da khai bao\n";
			break;
		case 2:
			cout << "Khoi tao stack thanh cong!\n";
			break;
		case 3:
			i = isEmpty();
			if(i == 1)
				cout << "Stack rong\n";
			else
				cout << "Stack khong rong\n";
			break;
		case 4:
			cout << "Nhap phan tu muon them: ";
			cin >> x;
			Push(x);
			cout << "Danh sach sau khi them la: ";
			Process();
			break;
		case 5:
			i = Pop(x);
			cout << "Phan tu xoa la: " << x << endl;
			cout << "Danh sach sau khi xoa la: ";
			Process();
			break;
		case 6:
			cout << "Nhap so muon chuyen doi: ";
			cin >> x;
			toBinary(x);
			break;
		default:
			cout << "Hen gap lai!\n";
		}
	}while(chon > 0 && chon < 7);
	return 0;
}