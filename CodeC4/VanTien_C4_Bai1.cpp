#include<stdio.h>
#include<iostream>
using namespace std;

#define COUNT 10

//Cau 1.1
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//Cau 1.2
void Init()
{
	root=NULL;
}

//Cau 1.3
void insertNode(Node *&p, int x)
{
	if(p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else 
	{
		if(p->info==x)
			return;
		else if(p->info>x)
			return insertNode(p->left,x);
		else
			return insertNode(p->right,x);
	}
} 
//Cau 1.4
Node *search(Node *p, int x)
{
	if(p!=NULL)
	{
		if(p->info==x)
			return p;
		else
			if(x>p->info)
				return search(p->right,x);
			else
				return search(p->left,x);
	}
	return NULL;
}
//Cau 1.5
void searchstandfor(Node *&p, Node *&q)
{
	if(q->left==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
		
	}
	else
		searchstandfor(p,q->left);

}
int Delete(Node *&T, int x)
{
	if(T==NULL) return 0;
	if(T->info==x)
	{
		Node *p=T;
		if(T->left==NULL)
			T=T->right;
		else if(T->right==NULL)
			T=T->left;
		else
			searchstandfor(p,T->right);
		delete p;
		return 1;
	}
	if(T->info<x) return Delete (T->right,x);
	if(T->info>x) return Delete (T->left,x);

}

//cau 1.6
void duyetLNR(Node *p)
{
	if(p!=NULL)
	{
		duyetLNR(p->left);
		cout<<p->info<<" ";
		duyetLNR(p->right);
	}
}

//cau 1.7
void duyetNLR(Node *p)
{
	if(p!=NULL)
	{
		cout<<p->info<<" ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//cau 1.8
void duyetLRN(Node *p)
{
		duyetNLR(p->left);
		duyetNLR(p->right);
		cout<<p->info<<" ";
}
void print2DUtil(Node *p, int space)
{
	if(p==NULL)
		return;
	space+=COUNT;
	print2DUtil(p->right,space);
	cout<<endl;
	for(int i=COUNT;i<space;i++)
		cout<<" ";
	cout<<p->info<<"\n";
	print2DUtil(p->left,space);
}
void process_tree()
{
	print2DUtil(root,0);
}
int main()
{
	int choice=0;
	int x,i;
	Node *p;
	system("cls");
	cout<<"-------BAI TAP 1, CHUONG 4, CAY NPTK------"<<endl;
	cout<<"1.Khoi tao CAY NPTK"<<endl;
	cout<<"2.Them phan tu vao CAY NPTK"<<endl;
	cout<<"3.Tim phan tu co gia tri x trong CAY NPTK"<<endl;
	cout<<"4.Xoa phan tu co gia tri x trong CAY NPTK"<<endl;
	cout<<"5. Duyet CAY NPTK theo LNR"<<endl;
	cout<<"6. Duyet CAY NPTK theo NLR"<<endl;
	cout<<"7. Duyet CAY NPTK theo LRN"<<endl;
	cout<<"8.Xuat CAY NPTK"<<endl;
	cout<<"9.Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			Init();
			cout<<"Ban vua khoi tao CAY NPTK thanh cong!\n";
			break;
		case 2:
			cout<<"Vui long chon gia tri x can them";
			cin>>x;
			insertNode(root,x);
			cout<<"Cay NPTK sau khi them la: ";
			process_tree();
			break;
		case 3:
			cout<<"Vui long chon gia tri x can tim";
			cin>>x;
			p=search(root,x);
			if(p!=NULL)
				cout<<"Tim thay x="<<x<<"trong CAY NPTK"<<endl;
			break;
		case 4:
			cout<<"Vui long chon gia tri x can xoa";
			cin>>x;
			i=Delete(root,x);
			if(i==0)
				cout<<"Khong tim thay x="<<x<<"de xoa!"<<endl;
			else
			{
				cout<<"Da xoa thanh cong phan tu x="<<x<<"trong CAY NPTK"<<endl;
				cout<<"CAY NPTK sau khi xoa la: ";
				process_tree();
			}
			break;
		case 5:
			cout<<"CAY NPTK theo LNR la: "<<endl;
			duyetLNR(root);
			break;
		case 6:
			cout<<"CAY NPTK theo NLR la: "<<endl;
			duyetNLR(root);
			break;
		case 7:
			cout<<"CAY NPTK theo LRN la: "<<endl;
			duyetLRN(root);
			break;
		case 8:
			cout<<"CAY NPTK nhu sau: ";
			process_tree();
			break;
		case 9:
			cout<<"GOODBYE....!";
			break;
		default: 
			break;		
		}
	}while(choice!=9);
	system("pause");
	return 0;
	
}
