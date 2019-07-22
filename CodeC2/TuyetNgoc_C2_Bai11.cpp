//queue danh sach lien ket don
#include < iostream>
using namespace std;

// 11.1Khai bao
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;
//11.2 Khoi tao rong
void inti()
{
	front = NULL;
	rear = NULL;
}
//11.3 Kiem tra queue rong
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
//11.4 Them mot phan tu vao queue
void Push(int x)
{
	Node *p = new Node;
	p ->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear ->link = p;
	rear = p;
}
//11.5 Xoa mot phan tu trong queue
int Pop(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		x = p ->info;
		front = front ->link;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//xuat
void Process()
{
	Node *p = front;
	while(p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

int main()
{
	int chon, x, i;
	cout << "1.Khai bao cau truc queue\n"
		<< "2.Khoi tao queue rong\n"
		<< "3.Kiem tra queue rong\n"
		<< "4.Them mot phan tu vao queue\n"
		<< "5. Xoa mot phan tu trong queue\n"
		<< "6.Thoat\n";
	do{
		cout << "Ban chon: ";
		cin >> chon;
		 switch(chon)
		 {
		 case 1:
			 cout << "Khai bao thanh cong!\n";
			 break;
		 case 2:
			cout << "Khoi tao queue rong thanh cong!\n";
			break;
		 case 3:
			 i = isEmpty();
			 if(i == 1)
				 cout << "Queue rong\n";
			 else
				 cout << "Queue khong rong\n";
			 break;
		 case 4:
			 cout << "Nhap phan tu muon them: ";
			 cin >> x;
			 Push(x);
			 cout << "Danh sach sau khi them la: ";
			 Process();
			 break;
		 case 5:
			 i = Pop(x);
			 cout << "Phan tu da xoa la: " << x << endl;
			 if(i == 1)
			 {
				 cout << "Danh sach sau khi xoa la: ";
				 Process();
			 }
			 else
				 cout << "Xoa khong thanh cong!\n";
			 break;
		 default:
			 cout << "Hen gap lai!\n";
		 }
	}while(chon > 0 && chon < 6);
	return 0;
}