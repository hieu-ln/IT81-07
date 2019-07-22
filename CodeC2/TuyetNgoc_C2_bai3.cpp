//Danh sach lien ket don
#include <iostream>
using namespace std;

//3.1 Cau truc
struct Node
{
	int info;
	Node *link;
};
	Node *first;
//3.2 Khoi tao
void init()
{
	first = NULL;
}
//3.3 Xuat
void Process_list()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
//3.4 Tim kiem
Node *search(int x)
{
	Node *p = first;
	while(p != NULL && p->info != x)
	{
		p = p ->link;
	}
	return p;
}
//3.5 Them vao dau danh sach
void insert_first(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
// 3.6 Xoa dau danh sach
int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first ->link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7 them cuoi danh sach
void insert_last(int x)
{
	Node *p = new Node;
	p ->info = x;
	p ->link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while(q->link != NULL)
			 q = q ->link;
		q ->link = p;
	}
}
//3.8 Xoa cuoi danh sach
int Delete_last()
{
	Node *p, *q;
	p = first;
	q = NULL;
	if(p != NULL)
	{
		while(p ->link != NULL)
		{
			q = p;
			p = p ->link;
		}
		if(p != first)
			q ->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//3.9 tim va xoa
int searchAndDelete(int x)
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while(p ->info != x && p ->link != NULL)
		{
			q = p;
			p = p ->link;
		}
		if(p != first && p->link != NULL)
		{
			//giua danh sach
			if(p ->link != NULL)
				q ->link = p ->link;
			else
				q ->link = NULL;
			delete p;
			return 1;
		}
		else
			if(p == first)
			{
				//dau ds
				first = p->link;
				delete p;
				return 1;
			}
			else
				if(p->link == NULL && p->info == x)
				{
					//cuoi ds
					q->link == NULL;
					delete p; 
					return 1;
				}
				else
					return 0;
	}
	return 0;
}
void swap(Node *a, Node *b)
{
	int t = a->info;
	a ->info = b -> info;
	b->info = t;
}
//3.10 Dung selection sort sx tang dan
void Sort()
{
	Node *p, *q, *min;
	//Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	p = first;
	while(p != NULL)
	{
		//Tim phan tu nho nhat trong mang chua sx
		min = p;
		q = p->link;
		while(q != NULL)
		{
			if(q -> info < min->info)
				min = q;
			q = q->link;
		}
		//Doi cho phan tu nho nhat vs phan tu dau tien
		swap(min, p);
		p = p->link;
	}
}
//sx giam dan
void SortDesc()
{
	Node *p, *q, *min;
	//Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	p = first;
	while(p != NULL)
	{
		//Tim phan tu nho nhat trong mang chua sx
		min = p;
		q = p->link;
		while(q != NULL)
		{
			if(q -> info > min->info)
				min = q;
			q = q->link;
		}
		//Doi cho phan tu nho nhat vs phan tu dau tien
		swap(min, p);
		p = p->link;
	}
}

int main()
{
	int x, i;
	int chon;
	cout << "Bai thuc hanh 2_Chuong 2\n"
		<< "1.Khoi tao danh sach\n"
		<< "2.Xuat danh sach\n"
		<< "3.Tim mot phan tu\n"
		<< "4.Them phan tu vao dau danh sach\n"
		<< "5.Xoa phan tu dau danh sach\n"
		<< "6.Them phan tu cuoi danh sach\n"
		<< "7.Xoa phan tu cuoi danh sach\n"
		<< "8.Tim phan tu trong danh sach va xoa\n"
		<< "9.Danh sach tang\n"
		<< "10.Danh sach giam\n"
		<< "11.Thoat\n";
	do{
		cout << "Chon so muon thuc hien: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
			cout << "Khoi tao ds rong thanh cong!\n";
			break;
		case 2:
			Process_list();
			break;
		case 3:
			cout << "Nhap phan tu muon tim: ";
			cin >> x;
			i = int(search(x));
			cout << "Phan tu co dia chi: " << i << endl;
			break;
		case 4:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			insert_first(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 5:
			i = Delete_first();
			if(i == 1)
			{
				cout << "Danh sach sau khi them la: ";
				Process_list();
			}
			else
				cout << "Khong the xoa!\n";
			break;
		case 6:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			insert_last(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 7:
			i = Delete_last();
			if(i == 1)
			{
				cout << "Danh sach sau khi them la: ";
				Process_list();
			}
			else
				cout << "Khong the xoa\n";
			break;
		case 8:
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			i = searchAndDelete(x);
			if(i == 1)
			{
				cout << "Danh sach sau khi them la: ";
				Process_list();
			}
			else
				cout << "Khong tim thay!\n";
			break;
		case 9:
			Sort();
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 10:
			SortDesc();
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		default:
			cout << "Tam biet!\n";
		}
	}while(chon < 11);
	return 0;
}