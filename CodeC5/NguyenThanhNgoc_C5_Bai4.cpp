#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX];	// mang 2 chieu
int n;				// so dinh cua do thi
char vertex[MAX];	// ten dinh

// DSLK su dung cho STACK va QUEUE
struct Node {
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

//STACK

void initStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp = NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p = new Node;
	p ->info = x;
	p ->link = sp;
	sp = p;
}
int PopS(int &x)
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
// end STACK

// QUEUE
void initQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node *p = new Node;
	p ->info = x;
	p ->link = NULL;
	if (rear = NULL)
		front = p;
	else
		rear ->link = p;
	rear = p;
}
int PopQ (int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p ->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
// end QUEUE

void initGraph()
{
	n = 0;
}
void inputGraphFromText()
{
	string line;
	ifstream myfile ("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
		}
	}
}

// Cau 4.1: Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao dong thu " << i + 1 <<": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

// Cau 4.2: Xuat ma tran ke cua do thi
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}
// Cau 4.3 : Duyet do thi theo chieu rong BFS(Dung QUEUE va ds lkdon)
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n; i++) // n la so dinh cua do thi
		C[i] = 1;
}
void BFS (int v) // v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if(C[w] && a[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}
// Cau 4.4: Duyet do thi theo chieu sau DFS(Dung STACK va ds lkdon)
int dfs[100];
int ndfs = 0;
void DFS (int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v= -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
			if (a[u][v]!=0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}
// 4.5: Dung BFS tim x tren do thi
void Search_by_BFS(int x, int v) // v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout <<"Tim thay x=" << x << endl;
		}
		for (w =0; w < n; w++)
			if (C[w] && a[p][w]== 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}
int main ()
{

	int choice, x, i;
	system("cls");
	cout << "-------  BAI TAP 4, CHUONG 5, DO THI -------" << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file text" << endl;
	cout << "3. Nhap MA TRAN KE" << endl;
	cout << "4. Xuat MA TRAN KE" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "6. Duyet do thi theo chieu sau DFS - DSLK" << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	
	do { 
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				initGraph();
				cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
				break;
			case 2:
				inputGraphFromText();
				cout << "Ban vua nhap MA TRAN KE tu file: \n";
				outputGraph();
				break;
			case 3:
				inputGraph();
				break;
			case 4: 
				outputGraph();
				break;
			case 5:
				initQueue();
				initC();
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				nbfs = 0;
				BFS(x);
				cout << "Thu tu dinh sau khi duyet BFS: " << endl;
				output(bfs, n);
				break;
			case 6:
				initStack();
				initC();
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				ndfs = 0;
				DFS(x);
				cout << "Thu tu dinh sau khi duyet BFS: " << endl;
				output(dfs, n);
				break;
			case 7:
				initQueue();
				initC();
				nbfs = 0;
				cout << "Vui long nhap gia tri x can tim: ";
				cin >> x;
				Search_by_BFS(x,0);
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