#include <iostream>
#include<stdio.h>
using namespace std;

struct Node 
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void tree_empty()	
{
	root = NULL;
}
Node *p = root;
void init()
{
	root = NULL;
}
void print(Node *p, int space)
{
	int COUNT = 10;
	if (p == NULL)
		return;
	space += COUNT;
	print(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	print (p->left, space);
}
void Process_print()
{
	print(root, 0);
}
Node *search (Node *p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info > x)
				return  search(p->right, x);
			else
				return  search(p->left, x);
	}
	return NULL;
}
void insertNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p =  new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else 
			if(p->info > x)
				return insertNode(p->left, x);
			else 
				return insertNode(p->right, x);
	}
}
void DuyetLNR(Node *p)
{
	if (p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << " ";
		DuyetLNR(p->right);
	}
}
void DuyetLRN(Node *p)
{
	if (p != NULL)
	{
		DuyetLNR(p->left);
		DuyetLNR(p->right);
		cout << p->info << " ";
	}
}
void DuyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		DuyetLNR(p->left);
		DuyetLNR(p->right);
	}
}
void searchStandFor(Node *&p, Node *&q)
{
	if (q-> left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete (Node *&t, int x)
{
	if (t == NULL)
		return 0;
	{
		Node *p = t;
		if (t->left == NULL)
			t = t-> right;
		else 
			if (t->right == NULL)
				t = t-> left;
			else
				searchStandFor(p, t->right);
		delete p;
		return 1;
	}
	if (t->info < x) 
		return Delete(t->right, x);
	if (t->info > x) 
		return Delete(t->left, x);
}
int main ()
{
	int x;
	int choice;
	system("cls");
	cout << "MENU:\n"
		<< "---------BAI TAP 1-----------CHUONG 4---------CNP---------\n"
		<< "1. Khoi tao cay rong\n"
		<< "2. Them 1 node vao cay\n"
		<< "3. Tim 1 phan tu trong cay\n"
		<< "4. Xoa 1 phan tu trong cay\n"
		<< "5. Duyet NLR\n"
		<< "6. Duyet LNR\n"
		<< "7. Duyet LRN\n"
		<< "8. Thoat\n";
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			cout << "Nhap phan tu can them: ";
			cin >> x;
			insertNode(root, x);
			cout << "Phan tu nhi phan sau khi them:\n";
			Process_print();
			break;
		case 3:
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			if(search(root, x))
				cout << "Tim thay x " << x << " trong cay nhi phan" << endl;
			else
				cout << "Ko tim thay x trong cay nhi phan" << endl;
			break;
		case 4:
			cout << "Nhap phan tu can xoa: ";
			cin >> x;
			if (Delete(root, x))
			{
				cout << "Xoa thanh cong. Phan tu sau khi xoa:\n";
				Process_print();
			}
			else 
				cout << "Xoa khong thanh cong " << endl;
			break;
		case 5:
			cout << "Ket qua duyet NLR: ";
			DuyetNLR(root);
			break;
		case 6:
			cout << "Ket qua duyet LNR: ";
			DuyetLNR(root);
			break;
		case 7:
			cout << "Ket qua duyet LRN: ";
			DuyetLRN(root);
			break;
		case 8:
				cout << "Goodbye ....!" << endl;
				break;
		default:
				break;
		}
	} while (choice != 8);
	system("pause");
	return 0;
}