//Chuong 4 _ bai 2 _ bai lam them _ quan ly cay nhi phan
/*thưa thầy, duyệt theo stack và queue em không biết làm*/
#include <iostream>
using namespace std;
#include <stdio.h>

#define COUNT 10

//danh sach lien ket dung cho stack va queue
struct Node_SQ
{
	int info;
	Node_SQ *link;
};

// 2.1 khai bao cau truc cay nhi phan tim kiem
struct Node
{
	int info;
	Node *left;
	Node *right;
};

Node *root;
Node_SQ *sp;
Node_SQ *front, *rear;
void InitS ()
{
	sp = NULL;
}

void pushS (int x)
{
	Node_SQ *p = new Node_SQ;
	p->info = x;
	p->link = sp;
	sp = p;
}

int popS (int &x)
{
	if (sp != NULL)
	{
		Node_SQ *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
void InitQ ()
{
	front = NULL;
	rear = NULL;
}

void pushQ (int x)
{
	Node_SQ *p = new Node_SQ;
	p->info = x;
	p->link =NULL;
	if(rear == NULL)
		front = p;
	else 
		rear->link = p;
	rear = p;
}

int popQ (int &x)
{
	if(front != NULL)
	{
		Node_SQ *p = new Node_SQ;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}



// 2.2 khoi tao cay rong
void tree_Empty ()
{
	root = NULL;
}

// 2.3 them 1 phan tu vao cay - khong dung de quy
void insertNode (Node *&p, int x)
{
	if (p == NULL) // nếu node đó rỗng
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else
		{
			while (p != NULL)
			{
				if (x > p->info)
					p = p->right;
				if (x < p->info)
					p = p->left;
			}
			p->info = x;
			p->left = NULL;
			p->right = NULL;
		}
	}
}

// 2.4 tim mot phan tu trong cay - khong dung de quy
Node *search (Node *p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				p = p->right;
			else
				p = p->left;
	}
	return NULL;
}

// 2.5 xoa node trong cay - dung de quy
// tim node the mang
void searchStandFor(Node *&p, Node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
// xoa node trong cay
int Delete (Node *&T, int x)
{
	if(T == NULL)
		return 0;
	if (T-> info == x)
	{
		Node *p = T;
		if(T->left == NULL) // có 1 con phải
			T = T->right;
		else
			if(T->right == NULL) // có 1 con bên trái
				T = T->left;
			else
				searchStandFor(p, T->right); // có 2 con
		delete p;
		return 1;
	}
	if(T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
}


// 2.7 duyet lnr - dung stack
void duyetLNR (Node *p)
{
	if (p != NULL)
	{  
		duyetLNR(p->left);
		cout << p->info << "\t";
		duyetLNR (p->right);
	}
}
int n = 0; // duyet chi so
Node_SQ *q;
// 2.6 duyet nlr - dung stack
void duyetNLR (Node *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

// 2.8 duyet lrn - dung queue
void duyetLRN (Node *p)
{
	if (p != NULL)
	{
		duyetLNR (p->left);
		duyetLNR (p->right);
		cout << p->info << "\t";
	}
}

// xuat cay NPTK
void Print2DUtil (Node *p, int space)
{
	//base case
	if (p == NULL)
		return;
	//increase distance between levels
	space += COUNT;
		//process right child first
		Print2DUtil (p->right, space);
		//print current node after space 
		//count
		cout << endl;
		for (int i = COUNT; i< space; i++)
			cout << "\t";
		cout << p ->info << endl;
		//process left child
		Print2DUtil(p->left, space);
}

void Process_tree ()
{
	Print2DUtil(root, 0);
}

int main ()
{
	int choice = 0;
	int x, i;
	Node *p;
	system ("cls");
	cout << "------------BAI TAP 2 CHUONG 4----------------" << endl;
	cout << "1.Khoi tao cay NPTK rong" << endl;
	cout << "2.Them phan tu vao cay NPTK" << endl;
	cout << "3.Them phan tu co gia tri x vao cay NPTK" << endl;
	cout << "4.Xoa phan tu co gia tri x vao cay NPTK" << endl;
	cout << "5.Duyet cay NPTK theo LNR" << endl;
	cout << "6.Duyet cay NPTK theo NLR" << endl;
	cout << "7.Duyet cay NPTK theo LRN" << endl;
	cout << "8.Xuat cay NPTK" << endl;
	cout << "9.Thoat" << endl;
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
			case 1: 
				tree_Empty();
				cout << "Ban vua khoi tao cay thanh cong" << endl;
				break;
			case 2:
				cout << "Vui long nhap gia tri x can them: ";
				cin >> x;
				insertNode(root, x);
				cout << "Cay NPTK sau khi them la: " << endl;
				Process_tree();
				break;
			case 3: 
				cout << "Vui long nhap gia tri x can tim: ";
				cin >> x;
				p = search(root, x);
				if (p != NULL)
					cout << "Tim thay x= " << x << " trong cay NPTK" << endl;
				else
					cout << "Khong tim thay x = " << x << " trong cay nhi phan" << endl;
				break;
			case 4: 
				cout << "Vui long nhap gia tri x can xoa: ";
				cin >> x;
				i = Delete(root, x);
				if(i== 0)
					cout << "Khong tim thay x= " << x << " trong cay NPTK" << endl;
				else 
				{
					cout << "Da xoa thanh cong phan tu x = " << x << " trong cay NPTK" << endl;
					cout << "Cay NPTK sau khi xoa la: " << endl;
					Process_tree();
				}
				break;
			case 5:
				cout << "Cay NPTK duyet theo LNR la: " << endl;
				duyetLNR(root);
				break;
			case 6:
				cout << "Cay NPTK duyet theo NLR la: " << endl;
				duyetNLR(root);
				break;
			case 7: 
				cout << "Cay NPTK duyet theo LRN la: " << endl;
				duyetLRN(root);
				break;
			case 8:
				cout << "Cay NPTK nhu sau: "  << endl;
				break;
			case 9:
				cout << "Goodbye.......!!!" << endl;
				break;
			default: 
				break;
		}
	}while (choice != 9);
	system("pause");
	return 0;
}