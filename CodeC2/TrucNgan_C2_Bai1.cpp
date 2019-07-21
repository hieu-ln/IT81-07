//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//#define MAX 100
////cau 1.1
//int a[MAX];
//int n;
////cau 1.2
//void input(int a[], int &n)
//{
//	cout<<"Nhap vao so luong phan tu cua danh sach: ";
//	cin>>n;
//	cout<<"Nhap vao cac phan tu cua danh sach: "<<endl;
//	for(int i=0; i<n; i++)
//	{
//		cout<<"a["<<i<<"]=";
//		cin>>a[i];
//	}
//}
////cau 1.3
//void Output(int a[], int n)
//{
//	for(int i=0; i<n; i++)
//		cout<<a[i]<<endl;
//
//}
////cau 1.4
//int search(int a[], int n, int x)
//{
//	int i=0;
//	while(i<n&& a[i]!=x)
//	{
//		i++;
//		if(i==n)
//			return -1;
//	}
//	return i;
//}
////cau 1.5
//int insert_last(int a[], int &n, int x)
//{
//	if(n<MAX)
//	{
//		a[n]=x;
//		n++;
//		return 1;
//	}
//	else
//		return 0;
//}
////cau 1.6
//int Delete_last(int a[], int &n)
//{
//	if(n>0)
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
////cau 1.7
//int Delete(int a[], int &n, int i)
//{
//	if(i>=0&&i<n)
//	{
//		for(int j=i; j<n-1; j++)
//		{
//			a[j]=a[j+1];
//		}
//		n--;
//		return 1;
//	}
//	return 0;
//}
////cau 1.8
//int searchanddelelte( int a[], int &n,int x)
//{
//	for(int i=0; i<n;i++)
//	{
//		if(a[i]==x)
//		{
//			Delete(a,n,i);
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int choice =0;
//	int i,x;
//	system("cls");
//	cout<<"------------BAI TAP 1, CHUONG 1, DANH SACH DAC----------"<<endl;
//	cout<<"1. Nhap danh sach"<<endl;
//	cout<<"2. Xuat danh sach"<<endl;
//	cout<<"3. Tim phan tu co gia tri x trong danh sach"<<endl;
//	cout<<"4. Them phan tu vao cuoi danh sach"<<endl;
//	cout<<"5. Xoa phan tu cuoi danh sach"<<endl;
//	cout<<"6. Xoa phan tu tai vi tri i"<<endl;
//	cout<<"7. Tim phan tu voi gia tri x va xoa no neu co"<<endl;
//	cout<<"8. Thoat"<<endl;
//	do
//	{
//		cout<<"Vui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			input(a,n);
//			cout<<"Ban vua nhap danh sach thanh cong!\n";
//			break;
//		case 2:
//			cout<<"Danh sach da nhap la: \n";
//			Output(a,n);
//			break;
//		case 3:
//			cout<<"Vui long nhap x can tim: \n";
//			cin>>x;
//		case 4:
//			cout<<"Vui long nhap x can them vao cuoi DS: \n";
//			cin>>x;
//			i= insert_last(a,n,x);
//			if(i==0)
//				cout<<"Danh sach da day, khong the them!"<<x<<endl;
//			else
//			{
//				cout<<"Da them phan tu x="<<i<<" vao cuoi danh sach!\n";
//				cout<<"Danh sach sau khi them la: ";
//				Output(a,n);
//			}
//			break;
//		case 5:
//			i= Delete_last(a,n);
//			if(i>0)
//			{
//				cout<<"Xoa thanh cong!"<<endl;
//				cout<<"Danh sach sau khi xoa phan tu cuoi la: \n";
//				Output(a,n);
//			}
//			else
//				cout<<"Danh sach dang rong, khong co phan tu nao!"<<endl;
//			break;
//		case 6:
//			cout<<"Vui long nhap vi tri can xoa i=";
//			cin>>i;
//			i=Delete(a,n,i);
//			if (i==1)
//			{
//				cout<<"Xoa thanh cong! "<<endl;
//				cout<<"Danh sach sau khi xoa la: \n";
//				Output(a,n);
//			}
//			else 
//				cout<<"Khong co phan tu nao de xoa! "<<endl;
//			break;
//		case 7:
//			cout<<"Vui long nhap gia tri can xoa x=";
//			cin>>x;
//			i =searchanddelelte(a,n,x);
//			if(i==1)
//			{
//				cout<<"Xoa thanh cong!"<<endl;
//				cout<<"Danh sach sau khi xoa la: \n";
//				Output(a,n);
//			}
//			else
//				cout<<"Khong co phan tu nao de xoa! "<<endl;
//			break;
//		case 8:
//			cout<<"Goodbye!";
//			break;
//		default:
//			break;
//
//		}
//	}
//	while(choice!=8);
//	system("Pause");
//	return 0;
//}
//
