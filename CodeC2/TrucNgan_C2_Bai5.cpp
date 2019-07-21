#include<iostream>
using namespace std;
#define MAX 100

int a[MAX];
int sp;

//5.1
void init(int a[], int &sp)
{
	sp=-1;
}

//5.2
int isEmpty(int a[], int sp)
{
	if(sp==-1)
		return 1;
	return 0;
}

//5.3
int isFull(int a[], int sp)
{
	if(sp==MAX -1)
		return 1;
	return 0;
}

//5.4
int push(int a[], int &sp, int x)
{
	if(sp <=MAX-1)
	{
		a[++sp]=x;
		return 1;
	}
	return 0;
}

//5.5
int pop(int a[], int &sp, int &x)
{
	if(sp!=-1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}

//5.6
void Xuat(int a[], int sp )
{
	for(int i=sp; i>0; i--)
		cout<<a[i]<<endl;
}

int main()
{
	int choice=0;
	int x, i;
	system("cls");
	cout<<"1.Khoi tao\n";
	cout<<"2.Kiem tra rong\n";
	cout<<"3.Kiem tra day\n";
	cout<<"4.Them mot phan tu\n";
	cout<<"5.Xoa mot phan tu\n";
	cout<<"6.Xuat danh sach\n";
	cout<<"7.Thoat\n";	
	do{
		cout<<" Vui long chon so de thuc hien: ";
		cin>>choice;
		switch (choice)
		{
		case 1:
			init(a,sp);
			cout<<"Ban vua khoi tao danh sach thanh cong!\n";
			break;
		case 2:
			if(isEmpty(a,sp))
				cout<<"Stack rong\n";
			else
				cout<<"Stack khong rong\n";
			break;
		case 3:
			if(isFull(a,sp))
				cout<<"Stack day\n";
			else
				cout<<"Stack chua day\n";
			break;
		case 4:
			int x;
			cout<<"Nhap gia tri muon them:";
			cin>>x;
			if(push(a,sp,x))
				cout<<"Them phan tu thanh cong\n";
			else
				cout<<"Them phan tu khong thanh cong\n";
			break;
		case 5:
			int y;
			if(pop(a,sp, y))
				cout<<"Xoa phan tu thanh cong\n";
			else
				cout<<"Xoa phan tu khong thanh cong\n";
			break;
		case 6:
			cout<<"Stack hien tai: "<<endl;
			Xuat(a, sp);
			break;
		case 7:
			cout<<"Thoat! "<<endl;
			break;
		default:
			break;
		}
	}while(choice !=8);
	system("Pause");
	return 0;
}

