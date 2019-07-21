//#include<iostream>
//#define MAX 100
//using namespace std;
//
//int a[MAX];
//int front;
//int rear;
//
//void init(int a[], int &front, int &rear)
//{
//	front =-1;
//	rear=-1;
//}
//int isEmpty(int a[], int front, int rear)
//{
//	if(front ==-1)
//		return 1;
//	if(rear==-1)
//		return 1;
//	return 0;
//}
//
//int isFull(int a[], int front, int rear)
//{
//	if(rear-front==MAX-1)
//		return 1;
//	return 0;
//}
//int push(int a[], int &front, int &rear, int x)
//{
//	if(rear-front == MAX -1) 
//			return 0;
//	else
//	{
//		if (front == -1)
//			front = 0; 	
//		if (rear == MAX - 1) 
//		{
//			for(int i=front; i<=rear; i++)
//				a[i-front]=a[i];
//			rear=MAX-1-front;
//			front =0;
//		}
//		a[++rear] = x; 
//		return 1;
//	}
//}
//int pop(int a[], int &front, int &rear, int &x)
//{
//	if(front==-1)
//		return 0;
//	else
//	{
//		x=a[front++];
//		if(front>rear)
//		{
//			front=-1;
//			rear=-1;
//		}
//		return 1;
//	}
//}
//
//int main()
//{
//	int choice=0;
//	system("cls");
//	cout<<"1.Khoi tao\n";
//	cout<<"2.Kiem tra rong\n";
//	cout<<"3.Kiem tra day\n";
//	cout<<"4.Them mot phan tu\n";
//	cout<<"5.Xoa mot phan tu\n";
//	cout<<"6.Thoat\n";	
//	do{
//		cout<<" Vui long chon so de thuc hien: ";
//		cin>>choice;
//		switch (choice)
//		{
//		case 1:
//			init(a, front, rear);
//			cout<<"Ban vua khoi tao danh sach thanh cong!\n";
//			break;
//		case 2:
//			if(isEmpty(a,front, rear))
//				cout<<"Queue rong\n";
//			else
//				cout<<"Queue khong rong\n";
//			break;
//		case 3:
//			if(isFull(a,front, rear))
//				cout<<"Queue day\n";
//			else
//				cout<<"Queue chua day\n";
//			break;
//		case 4:
//			int x;
//			cout<<"Nhap gia tri muon them:";
//			cin>>x;
//			if(push(a,front, rear,x))
//				cout<<"Them phan tu thanh cong\n";
//			else
//				cout<<"Them phan tu khong thanh cong\n";
//			break;
//		case 5:
//			int y;
//			if(pop(a,front, rear, y))
//				cout<<"Xoa phan tu thanh cong\n";
//			else
//				cout<<"Xoa phan tu khong thanh cong\n";
//			break;
//		case 6:
//			cout<<"Thoat! "<<endl;
//			break;
//		default:
//			break;
//		}
//	}while(choice !=7);
//	system("Pause");
//	return 0;
//
//
//}
