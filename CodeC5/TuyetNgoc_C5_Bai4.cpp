#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Khai bao ma tran
#define MAX 20
int a[MAX][MAX]; // mang 2 chieu
int n; // so dinh cua do thi
char vertex[MAX]; //ten dinh
//Khai bao dslk su dung queue va stack
struct Node
{
	int info;
	Node *link;
};
Node *sp;
Node *front, *rear;
//Stack
void initStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if(sp == NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int PopS(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//Queue
void initQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(front == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		x = p->info;
		front = front->link;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void initGraph()
{
	n = 0;
}
void inputGraphFromText()
{
	string line;
	ifstream datafile("matranke1.txt");
	if(datafile.is_open())
	{
		datafile >> n;
		for(int i = 0; i < n; i++)
			datafile >> vertex[i];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				datafile >> a[i][j];
		}
		datafile.close();
	}
}

//4.1 Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
//4.2 Xuat ma tran ke cua do thi
void output(int b[], int nb)
{
	for(int i = 0; i < n; i++)
		cout << vertex[b[i]] << "  ";
}
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
//4.3 Duyet do thi theo chieu rong 
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for(int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)//v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
			if(C[w] && a[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}
//4.4 Duyet do thi theo chieu sau
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0; 
	int v = -1, u = s;
	while(!isEmptyS())
	{
		if(v == n)
			PopS(u);
		for(v = 0; v < n; v++)
			if(a[u][v] != 0 && C[v] == 1)
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
//4.5 Tim kiem dinh dua tren BFS
void search_By_BFS(int x, int v)//v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "Tim thay x =" << x << endl;
			return;
		}
		for(w = 0; w < n; w++)
		{
			if(C[w] && a[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
		}
	}
}


int main()
{
	int  chon,i;
	cout << "--------Bai thuc hanh 4 - Chuong 5-----" << endl;
	cout << "1.Khoi tao ma tran\n2.Nhap ma tran ke tu file\n3.Xuat ma tran ke\n4.Duyet do thi theo chieu rong\n5.Duyet do thi theo chieu sau\n6.Tim mot dinh trong do thi\n7.Thoat\n";
	do{
		cout << "\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			cout << "Khai bao thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap ma tran ke tu file: \n";
			outputGraph();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			initQueue();
			initC();
			cout << "Duyet tu dinh thu: ";
			cin >> i;
			nbfs = 0;
			BFS(i);
			cout << "Thu tu dinh sau khi duyet BFS la: \n";
			output(bfs, n);
			break;
		case 5:
			initStack();
			initC();
			ndfs = 0;
			cout << "Duyet tu dinh thu: ";
			cin >> i;
			DFS(i);
			cout << "Thu tu dinh sau khi duyet DFS la: \n";
			output(dfs, n);
			break;
		case 6:
			initQueue();
			initC();
			cout << "Vui long nhap dinh can tim la: ";
			cin >> i;
			nbfs = 0;
			search_By_BFS(i, 0);
			break;
		default:
			cout << "Tam biet!\n";
		}
	}while(chon > 0 && chon < 8);
	return 0;
}