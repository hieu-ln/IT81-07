//bai 3 chuong 2
#include <iostream>
using namespace std;

//3.1 khai bao cau truc danh sach
struct Node
{
	int info;
	Node *link;
};

Node *first;

//3.2 khoi tao danh sach rong
void Init()
{
	first = NULL;
}

//3.3 xuat cac phan tu trong danh 
void Process_list ()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

//3.4 tim mot phan tu trong danh sach
Node *search (int x)
{
	Node *p = first;
	while (p != NULL && p->info != x)
		p = p->link;
	return p;
}

//3.5 them phan tu vao dau danh sach
void Insert_first (int x)
{
	Node *p;
	p = new Node;
	p ->info = x;
	p ->link = first;
	first = p;
}

//3.6 xoa phan tu dau danh sach
int Delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first ->link;
		delete p;
		return 1;
	}
	return 0;
}

//3.7 them phan tu vao cuoi danh sach
void Insert_last (int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p ->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node *q =first;
		while (q->link != NULL)
			q = q->link;
		q ->link = p;
	}
}

//3.8 xoa phan tu cuoi danh sach
int Delete_last()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
			q->link = NULL;
		else 
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

// 3.9 tim phan tu trong danh sach roi xoa phan tu do neu co
int searchAndDelete (int x)
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p-> link != NULL)
		{
			// phan tu giua  ds
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
			if (p == first)
			{
				// phan tu dau ds
				first = p->link;
				delete p;
				return 1;
			}
			else
				if (p->link == NULL && p->info == x)
				{
					// phan tu cuoi ds
					q->link = NULL;
					delete p;
					return 1;
				}
				else
					return 0;
	}
	return 0;
}

//hoan doi 2 thanh phan
void swap (Node *a, Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

//3.10 sap xep ds co thu tu tang dan // selection sort
void sort ()
{
	Node *p, *q, *min;
	//di chuyen ranh gioi cua mang da sap xep va chua sap xep
	p = first;
	while (p != NULL)
	{
		// tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
					min = q;
			q = q->link;
		}
		//doi cho phan tu nho nhat voi phan tu dau tien
		swap(min, p);
		p = p->link;
	}
}

//3.10b sap xep danh sach co thu tu giam dan
void sortDesc()
{
	Node *p, *q, *min;
	//di chuyen ranh gioi cua mang da sap xep cua chua sap xep
	p = first;
	while (p != NULL)
	{
		// tim phan tu nho nhat trong mang chua sap xep 
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q != NULL)
				min = q;
			q = q->link;
		}
		//?oi cho phan tu nho nhat voi phan tu dau tien
		swap (min, p);
		p = p-> link;
	}
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system ("cls");
	cout << "--------BAI TAP 3, CHUONG 2, DANH SACH DAC---------" << endl;
	cout << "1. Khoi tao DSLK DON rong" << endl;
	cout << "2. Them phan tu vao dau DSLK DON" << endl;
	cout << "3. Them phan tu vao cuoi DSLK DON" << endl;
	cout << "4. Xoa phan tu vao dau DSLK DON" << endl;
	cout << "5. Xoa phan tu vao cuoi DSLK DON" << endl;
	cout << "6. Xuat DSLK DON" << endl;
	cout << "7. Tim phan tu voi gia tri x trong DSLK DON" << endl;
	cout << "8. Tim phan tu voi gia tri x va xoa no neu co" << endl;
	cout << "9. Sap xep DSLK DON tang dan" << endl;
	cout << "10. Sap xep DSLK DON giam dan" << endl;	
	cout << "11. Thoat" << endl; 
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Init ();
				cout << "Ban vua khoi tao DSLK DON thanh cong!" << endl;
				break;
			case 2:
				cout << "Vui long nhap gia tri x= " << endl;
				cin >> x;
				Insert_first (x);
				cout << "Danh sach sau khi them la: " << endl;
				Process_list();
				break;
			case 3:
				cout << "Vui long nhap gia tri x= ";
				cin >> x;
				Insert_last(x);
				cout << "Danh sach sau khi them la: " << endl;
				Process_list();
				break;
			case 4:
				i = Delete_first();
				if (i == 0)
					cout << "Danh sach rong, khong the xoa " << x << endl;
				else 
				{
					cout << "Da xoa thanh cong phan tu dau DSLK DON" << endl;
					cout << "Danh sach sau khi xoa: " << endl;
					Process_list();
				}
				break;
			case 5:
				i = Delete_last ();
				if (i == 0)
					cout << "Danh sach rong, khong the xoa " << x << endl;
				else
				{
					cout << "Danh sach dang rong, khong co phan tu nao!" << endl;
					cout << "Da xoa thanh cong phan tu cuoi cua DSLK DON" << endl;
					Process_list();
				}
				break;
			case 6:
				cout << "Danh sach hien tai la: ";
				Process_list();
				break;
			case 7:
				cout << "Vui long nhap gia tri can xoa x= ";
				cin >> x;
				p = search(x);
				if(p != NULL)
					cout << "Tim thay phan tu co gia tri x= " << x << endl;
				else 
					cout << "Khong co phan tu nao de xoa" << endl;
				break;
			case 8:
				cout << "Vui long nhap gia tri can tim x= ";
				cin >> x;
				i = searchAndDelete(x);
				if(i == 1)
				{
					cout << "Tim thay x= " << x << " va sa xoa thanh cong" << endl;
					cout << "Danh sach sau khi xoa la: " << endl;
					Process_list();
				}
				else
					cout << "Khong tim thay phan tu co gia tri x= " << x << endl;
				break;
			case 9:
				sort();
				cout << "Danh sach sau khi sap xep tang dan la: " << endl;
				Process_list();
				break;
			case 10:
				sortDesc();
				cout << "Danh sach sau khi sap xep giam dan la: "<< endl;
				Process_list();
				break;
			case 11: 
				cout << "Goodbye!" << endl;
				break;
			default:
				break;
		}
	}while(choice != 11);
	system("pause");
	return 0;
}