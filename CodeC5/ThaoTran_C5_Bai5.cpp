//danh sach ke
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#define MAX 20

//khai bao
struct Node
{
	int info;
	Node *link;
};
Node *first[MAX];
int n;
char vertex[MAX];

Node *sp;
Node *front, *rear;

//stack
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
//Khoi tao do thi rong
void initGraph(int n)
{
	for(int i = 0; i < n; i++)
		first[i]= NULL;
	n = 0;
}
void InsertLast(Node *&f, Node *p)
{
	if(f == NULL)
		f = p;
	else
	{
		Node *q = f;
		while(q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
//5.1 Nhap ma tran
//Nhap tu tep
void inputFromGraphText()
{
	string line;
	ifstream dataFile ("danhsachke1.txt");
	if(dataFile.is_open())
	{
		dataFile >> n;
		for(int i = 0; i < n; i++)
			dataFile >> vertex[i];
		string str;
		int i = 0;
		while(getline(dataFile, str))
		{
			istringstream ss(str);
			int u;
			while(ss >> u)
			{
				//dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(first[i-1], p);
			}
			i++;
		}
	}
}
//Nhap tu ban phim
void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i];
	for(int i = 0; i < n + 1; i++)
	{
		if(i > 0)
			cout << "Nhap danh sach cua dinh thu" << i - 1 << "( " << vertex[i -1] << ") : ";
		int u;
		string str;
		while(getline(cin, str))
		{
			istringstream ss(str);
			while(ss >> u)
			{
				//dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(first[i-1], p);
			}
			break;
		}
	}
}
//5.2 Xuat do thi
void output(int b[], int nb)
{
	for(int i = 0; i < n; i++)
		cout << vertex[b[i]] << "  ";
}
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " ( " << vertex[i] << ") : ";
		Node *p = first[i];
		while(p != NULL)
		{
			cout << p->info << "  ";
			p = p->link;
		}
		cout << endl;
	}
}
//5.3 BFS: duyet theo chieu rong
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for(int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)//v la dinh bat dau
{
	int p;
	Node *w;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = first[p];
		nbfs++;
		while(w != NULL)
		{
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}
//5.4 Duyet do thi theo chieu sau
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0; 
	int u = s;
	Node *v = NULL;
	while(isEmptyS() == 0)
	{
		if(v == NULL)
			PopS(u);
		v = first[u];
		while(v != NULL)
		{
			if(C[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
		
	}
}
//5.5 Tim kiem dinh dua tren BFS
void search_By_BFS(int x, int v)//v la dinh bat dau
{
	int p;
	Node *w;
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
		w = first[p];
		while(w !=NULL)
		{
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}


int main()
{
	int  chon,i;
	cout << "--------Bai thuc hanh 4 - Chuong 5-----" << endl;
	cout << "1.Khoi tao ma tran" << endl;
	cout << "2.Nhap danh sach ke tu file" << endl;
	cout << "3.Xuat danh sach ke" << endl;
	cout << "4.Duyet do thi theo chieu rong" << endl;
	cout << "5.Duyet do thi theo chieu sau" << endl;
	cout << "6.Tim mot dinh trong do thi" << endl;
	cout << "7.Thoat" << endl;
	do{
		cout << "Vui long chon so: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			n = 10;
			initGraph(n);
			cout << "Khai bao thanh cong!" << endl;
			break;
		case 2:
			inputFromGraphText();
			cout << "Ban vua nhap ma tran ke tu file: " << endl;
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
			cout << "Thu tu dinh sau khi duyet BFS la: " << endl;
			output(bfs, n);
			break;
		case 5:
			initStack();
			initC();
			ndfs = 0;
			cout << "Duyet tu dinh thu: ";
			cin >> i;
			DFS(i);
			cout << "Thu tu dinh sau khi duyet DFS la: " << endl;
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
		case 7: 
			cout << "Goodbye....!";
			break;
		default:
			break;
		}
	}while(chon != 7);
	return 0;
}