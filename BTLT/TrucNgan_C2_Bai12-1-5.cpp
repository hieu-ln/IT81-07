#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node *next, *previous;
};
Node *first, *last;
void init()
{
	first=NULL;
	last=NULL;
}
void Process_list()
{
	Node *p;
	p=first;
	while(p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->next;
	}
}
void Insert_first(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=first;
	p->previous=NULL;
	if(first!=NULL)
		first->previous=p;
	else
		last=p;
	first=p;
}
void Insert_last(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=NULL;
	p->previous=last;
	if(last!=NULL)
		last->next=p;
	else
		first=p;
	last=p;
}
int main()
{
	int choice =0;
	int x, i;
	system("cls");
	cout<<"-------------BAI TAP 12, CHUONG 2, DANH SACH LIEN KET KEP-------------";
	cout<<"1.Khoi tao DSLK kep"<<endl;
	cout<<"2.Them 1 phan tu vao dau danh sach"<<endl;
	cout<<"3.Them 1 phan tu vao cuoi danh sach"<<endl;
	cout<<"4.Xuat danh sach"<<endl;
	cout<<"5.Thoat"<<endl;

	do
	{
		cout<<"Vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"Khoi tao DSLK kep thanh cong!\n";
			break;
		case 2:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			Insert_first(x);
			cout<<"Danh sach sau khi them la: ";
			Process_list();
			break;
		case 3:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			Insert_last(x);
			cout<<"Danh sach sau khi them la: ";
			Process_list();
			break;
		case 4:
			Process_list();
			break;
		case 5:
			cout<<"Thoat!"<<endl;
			break;
		default:
			break;		
		}
	}while(choice!=6);
	system("Pause");
	return 0;
}
