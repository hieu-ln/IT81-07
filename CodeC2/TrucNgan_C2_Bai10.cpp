#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *sp;

void init()
{
	sp=NULL;
}

int isEmpty()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void push(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}

int pop(int &x)
{
	if(sp!=NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
	return 0;
}
void output()
{
	Node *p=new Node;
	p=sp;
	while(p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->link;
	}
	cout<<endl;
}
int convert( int tp)
{
	init();
	while(tp!=0)
	{
		int d= tp%2;
		push(d);
		tp/=2;
	}
	int np=0;
	while (!isEmpty ())
	{
		int so;
		if(pop(so))
			np=np*10+so;
	}
	return np;
}
int main()
{
	int choice=0;
	system("cls");
	cout<<"1.Khoi tao\n";
	cout<<"2.Kiem tra rong\n";
	cout<<"3.Them mot phan tu\n";
	cout<<"4.Xoa mot phan tu\n";
	cout<<"5.Doi mot so thap phan sang so nhi phan\n";
	cout<<"6.Xuat danh sach\n";
	cout<<"7.Thoat\n";	
	do{
		cout<<" Vui long chon so de thuc hien: ";
		cin>>choice;
		switch (choice)
		{
		case 1:
			init();
			cout<<"Ban vua khoi tao danh sach thanh cong!\n";
			break;
		case 2:
			if(isEmpty())
				cout<<"Stack rong\n";
			else
				cout<<"Stack khong rong\n";
			break;
		case 3:
			int x;
			cout<<"Nhap gia tri muon them:";
			cin>>x;
			push(x);
			break;
		case 4:
			int y;
			cout<<"Nhap phan tu muon xoa: ";
			cin>>y;
			if(pop(y))
				cout<<"Xoa phan tu thanh cong\n";
			else
				cout<<"Xoa phan tu khong thanh cong\n";
			break;
		case 5:
			int tp;
			cout<<"Nhap gia tri he thap phan can chuyen: ";
			cin>>tp;
			cout<<"Gia tri nhi phan tuong ung la: "<<convert(tp)<<endl;
			break;
		case 6:
			cout<<"Stack hien tai: "<<endl;
			output();
			break;
		case 7:
			cout<<"Thoat! "<<endl;
			break;
		default:
			break;
		}
	}while(choice !=9);
	system("Pause");
	return 0;
}



