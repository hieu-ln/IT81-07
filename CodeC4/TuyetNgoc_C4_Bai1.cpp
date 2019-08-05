#include <iostream>
#include <stdio.h>
using namespace std; 

#define COUNT 10
//1.1 Khai bao
struct Node
{
	int info;
	Node *left, *right;
};
Node *root;
//1.2 Khoi tao rong
void tree_empty()
{
	root = NULL;
}
//1.3 Them mot phan tu
//su dung dia chi con tro
void InsertNode(Node *&p, int x)
{
	if(p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
		if(p->info == x)
			return;
		else
			if(p->info > x)
				return InsertNode(p->left, x);
			else
				return InsertNode(p->right, x);
}
//them ko su dung dia chi con tro
int Insert_Node_Recursive(Node *q, int x)
{
	if(q->info == x)
		return 0;
	else
		if(q->info > x)
		{
			if(q->left == NULL)
			{
				Node *p = new Node;
				p->info = x;
				p->left = NULL;
				p->right = NULL;
				p->left = p;
				return 1;
			}
			else
				Insert_Node_Recursive(q->left, x);
		}
		else
			if(q ->right == NULL)
			{
				Node *p = new Node;
				p->info = x;
				p->left = NULL;
				p->right = NULL;
				p->right = p;
				return 1;
			}
			else
				Insert_Node_Recursive(q->right, x);
}
//1.4 Tim kiem mot phan tu
Node *search(Node *p, int x)
{
	if(p != NULL)
		if(p->info == x)
			return p;
		else
			if(p->info > x)
				return search(p->left, x);
			else
				return search(p->right, x);
	return NULL;
}
//1.5 Xoa mot node
//Tim phan tu the mang
void searchStandFor(Node *&p, Node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete(Node *&T, int x)
{
	if(T->info == NULL)
		return 0;
	if(T->info == x)
	{
		Node *p = T;
		if(T->left == NULL)
			T = T->right;
		else
			if(T->right == NULL)
				T = T->left;
			else
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info > x)
		return Delete(T->left, x);
	if(T->info < x)
		return Delete(T ->right, x);
}
//1.6 Duyet NLR
void DuyetNLR(Node *p)
{
	if(p != NULL)
	{
		cout << p->info << "\t";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}
//1.7 Duyet LNR
void DuyetLNR(Node *p)
{
	if(p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << "\t";
		DuyetLNR(p->right);
	}
}
//1.8 Duyet LRN
void DuyetLRN(Node *p)
{
	if(p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << "\t";
	}
}
void print2DUtil(Node *p, int space)
{
	//basic case
	if(p == NULL)
		return;
	// Increase distance betwen level
	space += COUNT;
	//Process right child first
	print2DUtil(p->right, space);
	//Print current node after space
	//count
	cout << endl;
	for(int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	//Process left chid
	print2DUtil(p->left, space);
}
//Wrapper over print2DUtil()
void Process_Tree()
{
	//Pass initial space count as 0
	print2DUtil(root, 0);
}

int main()
{
	int chon, i, x;
	Node *a;
	system("clc");
	cout << "--------Bai thuc hanh 1 - Chuong 4---------" << endl;
	cout << "1.Khai bao\n2.Khoi tao cay\n3.Them mot phan tu\n4.Tim mot phan tu\n5.Xoa mot phan tu\n6.Duyet theo NLR\n"
		<< "7.Duyet theo thu tu LNR\n8.Duyet theo thu tu LRN\n";
	tree_empty();
	do{
		cout << "\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			cout << "Khai bao thanh cong!\n";
			break;
		case 2:
			cout << "Da khoi tao cay rong!\n";
			break;
		case 3:
			cout << "Nhap phan tu muon them: ";
			cin >> x;
			InsertNode(root, x);
			Process_Tree();
			break;
		case 4:
			cout << "Nhap phan tu muon tim: ";
			cin >> x;
			a = search(root, x);
			if(a > 0)
				cout << "Phan tu can tim xuat hien tai vi tri: " << int(a) << endl;
			else
				cout << "Khong tim thay\n";
			break;
		case 5:
			cout << "Nhap phan tu muon xoa: ";
			cin >> x;
			i = Delete(root, x);
			if(i == 1)
				Process_Tree();
			else
				cout << "Khong the xoa\n";
			break;
		case 6:
			cout << "Duyet theo NLR\n";
			DuyetNLR(root);
			break;
		case 7:
			cout << "Duyet theo LNR\n";
			DuyetLNR(root);
			break;
		case 8:
			cout << "Duyet theo LRN\n";
			DuyetLRN(root);
			break;
		default:
			cout << "Chao tam biet!\n";
		}
	}while(chon > 0 && chon < 9);
	return 0;
}