#include <iostream>
using namespace std;

struct Node // 3.1 khai báo cấu trúc
{
	int info;
	struct Node *link;
};
Node *first;
void init() // 3.2 khởi tạo danh sách rỗng 
{
	first = NULL;
}

void khoitao() // 3.3 Duyệt danh sá	ch
{
	Node *p;
	p = first;
	while (p!=NULL)
	{
		cout << p -> info << endl;
		p = p -> link;
	}
} 
NODE *khoitaoNode(int x) {
	NODE *p = new NODE;
	if (p == NULL) {
		return p;
	}
	p->info = x;
	p->link = NULL;
	return p;
}
Node *tim(int x) // 3.4 tìm x
{
	Node *p = first;
	while ((p!=NULL) && (p -> info !=x))
		p = p -> link;
	return p;
}

void themdau(int x) // 3.5 thêm đầu
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = first;
	first = p;
}

int xoadau() // 3.6 xóa đầu
{
	if (first != NULL)
	{
		Node *p = first;
		first = first -> link;
		delete p;
		return 1;
	}
	return 0;
}
void themcuoi(int x) // 3.7 thêm cuối
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q -> link != NULL)
			q = q -> link;
		q -> link = p;
	}
}

int xoacuoi() // 3.8 xóa cuối
{
	if (first != NULL)
	{
		Node *p = first, *q = NULL;
		if(p!=NULL)
			while (p -> link != NULL)
			{
				q = p;
				p = p -> link;
			}
			if (p!=first)
				q -> link = NULL;
			else
				first = NULL;
			delete p;
			return 1;
	}
	return 0;
}
void xuatDS()
{	
	for (Node *k = first; k != NULL, k = k ->link)
	{
		cout << k ->info << " ";
	}
}


int main ()
{
	LIST(l);
	int n,x;

	cout <<"Nhap so luong Node: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "Nhap gia tri so nguyen: ";
		cin >> x;
		Node *p = khoitaoNode(x);
		themcuoi(l, p);
	}
	xuatDS();
	return 0;
}


