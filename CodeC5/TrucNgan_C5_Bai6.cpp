#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];

struct Node
{
	int info;
	Node* link;
};
Node* sp;
Node* front, * rear;

//STACK
void InitS(int a[], int& sp)
{
	sp = -1;
}
int isEmptyS(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
int  PushS(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int PopS(int a[], int& sp, int x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

//QUEUE
void InitQ(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
int isEmptyQ(int a[], int front, int rear)
{
	if(front ==-1)
		return 1;
	if(rear==-1)
		return 1;
	return 0;
}
int PushQ(int a[], int& front, int& rear, int x)
{
	if(rear-front == MAX -1) 
			return 0;
	else
	{
		if (front == -1)
			front = 0; 	
		if (rear == MAX - 1) 
		{
			for(int i=front; i<=rear; i++)
				a[i-front]=a[i];
			rear=MAX-1-front;
			front =0;
		}
		a[++rear] = x; 
		return 1;
	}
}
int PopQ(int a[], int &front, int &rear, int &x)
{
	if(front==-1)
		return 0;
	else
	{
		x=a[front++];
		if(front>rear)
		{
			front=-1;
			rear=-1;
		}
		return 1;
	}
}
void InitGraph()
{
	n = 0;
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 9; j < n; j++)
				myfile >> A[i][j];
		}
	}

}
//cau 6.1
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}
//cau 6.2
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 9; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}
//Cau 6.3
int C[100]; // luu tru dinh chua xet.
// 1 la chua xet; 0 la da xet.
int bfs[100]; // luu danh sach phan tu da duyet.
int nbfs = 0; // luu chi so dinh da xet.

void InitC()
{
	for (int i = 0; i < n; i++) // Gan tat ca cac gia tri la 1.
		C[i] = 1;
}

void BFS(int v)
{
	int w, p,q;
	q.push(v);
	C[v] = 0;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				q.push(w);
				C[w] = 0;
			}
		}
	}
}
//Cau 6.4
int dfs[100];
int ndfs = 0;

void DFS(int s)
{
	PushS(a, s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			PopS(a, u);
		for (v = 0; v < n; v++)
			if (A[u][v] != 0 && C[v] == 1)
			{
				PushS(a, u);
				PushS(a, v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}
//cau 6.5
void search_by_bfs(int x, int v)
{
	InitC();
	int w, p;
	q.push(v);
	C[v] = 0;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (x == p)
		{
			cout << x << " ton tai" << endl;
			;
			return;
		}
		for (w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				q.push(w);
				C[w] = 0;
			}
		}
	}
	cout << x << " khong ton tai" << endl;
}
void input_graph_from_text()
{
	string line;
	ifstream myfile("matranke1.txt");

	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}
int main()
{
	int choice, x;
	system("cls");

	cout << "----------------------BAI 6 CHUONG 5-------------------\n"
		<< "1. Khoi tao MA TRAN KE rong.\n"
		<< "2. Nhap MA TRAN KE.\n"
		<< "3. Xuat MA TRAN KE.\n"
		<< "4. Duyet do thi theo chieu rong BFS - DSD.\n"
		<< "5. Duyet do thi theo chieu sau DFS - DSD\n"
		<< "6. Tim dinh co gia tri x theo BFS.\n"
		<< "7. Thoat." << endl;

	do
	{
		cout << "\nNhap vao so ban muon thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			InitGraph();
			cout << "\nBan  vua khoi tao MA TRAN KE rong thanh cong.\n";
			break;
		case 2:

			input_graph_from_text();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			InitC();
			cout << "\nNhap vao dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "\nThu tu dinh sau khi duyet BFS: " << endl;
			output(bfs, n);
			break;
		case 5:
			InitS();
			InitC();
			cout << "\nNhap vao dinh ban muon bat dau duyet: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "\nThu tu dinh sau khi duyet DFS: ";
			output(dfs, n);
			break;
		case 6:
			cout << "\nVui long nhap vao gia tri x can tim: ";
			cin >> x;
			search_by_bfs(x, 0);
			break;
		case 7:
			cout << "\nTam biet!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 7);
	return 0;
}