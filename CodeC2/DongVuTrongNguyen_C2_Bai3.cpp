#include <iostream>
using namespace std;

//3.1
struct node
{
	int info;
	node *link;
};
node *first;
//3.2
void init()
{
	first = NULL;
}
//3.3
void output()
{
	node *p;
	p = first;
	while(p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
	cout << endl;
}
//3.4
node *search(int x)
{
	node *p = first;
	while (p->info != x && p->link != NULL)
		p = p->link;
	return p;
}
//3.5
void insertFirst(int x)
{
	node *p = new node;
	p->info = x;
	p->link = first;
	first = p;
}
//3.6
int deleteFirst()
{
	if (first != NULL)
	{
		node *p = first;
		first = first->link;
		return 1;
	}
	return -1;
}
//3.7
void insertLast(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
//3.8
int deleteLast()
{
	if (first != NULL)
	{
		node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
			p->link = NULL;
		else
			first = NULL;
		return 1;
	}
	return -1;
}
//3.9
int searchAndDelete(int x)
{
	if (first != NULL)
	{
		node *p, *q;
		p = first;
		q = first;
		
		while (p->info != x && p->info != NULL)
		{
			p = q;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			if (p->link != NULL)
				p->link = q->link;
			else
				p->link =NULL;
			delete p;
			return 1;
		}
		else 
			if (p == first)
			{
				first = p->link;
				delete p;
				return 1;
			}
			else
				if (p->link == NULL && p->info == x)
				{
					p->link = NULL;
					delete p;
					return 1;
				}
				else
					return -1;
	}
	return -1;

}
//3.10
	//hoan doi 2 ptu
void swap(node *a, node *b)
{
	int tam = a->info;
	a->info = b->info;
	b->info = tam;
}
	//sap xep tang dan su dung SelectionSort
void sort()
{
	node *p, * q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}
	//sap xep giam dan su dung SelectionSort
void sortDesc()
{
	node *p, * q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info > min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}
void main()
{
	int choice = 0;
	int x, i;
	node *p;
	cout << "----BAI TAP 3, CHUONG 2, DANG LIEN KET DON-----" << endl;
	cout << "1. Khoi tao DSLK don rong" << endl;
	cout << "2. Them ptu vao dau DSLK Don" << endl;
	cout << "3. Them ptu vao cuoi DSLK Don" << endl;
	cout << "4. Xoa ptu dau DSLK Don" << endl;
	cout << "5. Xoa ptu cuoi DSLK Don" << endl;
	cout << "6. Xuat DSLK Don" << endl;
	cout << "7. Tim gtri x trong DSLK Don" << endl;
	cout << "8. Tim gtri x va xoa no neu co" << endl;
	cout << "9. Sap xep DSLK Don tang dan" << endl;
	cout << "10. Sap xep DSLK Don giam dan" << endl;
	cout << "11. Thoat" << endl;

	do{
		cout << "Chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao thanh cong!" << endl;
			break;
		case 2:
			cout << "Nhap gtri x: ";
			cin >> x;
			insertFirst(x);
			cout << "DS sau khi them dau la: ";
			output();
			break;
		case 3:
			cout << "Nhap gtri x la: ";
			cin >> x;
			insertLast(x);
			cout << "DS sau khi them cuoi la: ";
			output();
			break;
		case 4:
			i = deleteFirst();
			if (i == 0)
				cout << "DS rong khong the xoa!" << endl;
			else
			{
				cout << "Da xoa thanh cong ptu dau cua DS" << endl;
				cout << "DS sau khi xoa la: ";
				output();
			}
			break;
		case 5:
			i = deleteLast();
			if (i == 0)
				cout << "DS rong khong the xoa" << endl;
			else
			{
				cout << "Da xoa thanh cong ptu cuoi" << endl;
				cout << "DS sau khi xoa la: ";
				output();
			}
			break;
		case 6:
			cout << "DS hien tai la: ";
			output();
			break;
		case 7:
			cout << "Nhap gtri can tim: ";
			cin >> x;
			p = search(x);
			if (p != NULL)
				cout << "Da tim thay gtri x = " << x << endl;
			else
				cout << "Khong tim thay gtri x = " << x << endl;
			break;
		case 8:
			cout << "Nhap gtri can tim: ";
			cin >> x;
			i = searchAndDelete(x);
			if (i == 1)
			{
				cout << "Tim thay grti x = " << x << " va da xoa thanh cong" << endl;
				cout << "DS sau khi xoa la: ";
				output();
			}
			else
				cout << "Khong tim thay gtri x = " << x << endl;
			break;
		case 9:
			sort();
			cout << "DS sau khi sap xep tang la: ";
			output();
			break;
		case 10:
			sortDesc();
			cout << "DS sau khi sap xep giam dan la: ";
			output();
			break;
		default:
			cout << "GoodBye!";
		}
	} while(choice != 11);
}