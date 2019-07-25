//Danh sach co thu tu
#include <iostream>
using namespace std;

//2.1 Khai bao
#define Max 100
int a[Max];
int n;
//Nhap danh sach
void input(int a[], int &n)
{
	do{
		cout << "Nhap so phan tu: ";
		cin >> n;
		if(n <= 0 || n > Max)
			cout << "Vui long nhap lai!\n";
	}while(n <= 0  || n > Max);
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
//2.2 Them mot phan tu
int insert_i(int a[], int &n, int x, int i)
{
	if(i <= n && i >= 0)
	{
		for(int j = n; j > i; j--)
			a[j] = a[j -1];
		a[i] = x;
		n++;
		return 1;
	}
	return 0;
}
//2.3 Xuat danh sach
void output(int a[], int n)
{
	cout << "Danh sach cac phan tu la: \n";
	for(int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
//2.4 Tim kiem tuan tu
int search(int a[], int n, int x)
{
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			return i;
	return -1;
}
//hoan doi
void swap(int &a, int &b)
{
	int tam = a;
	a = b; 
	b = tam;
}
//Sap xep danh sach theo selection sort
void selectionSort(int a[], int n)
{
	int min, i, j;
	for(i = 0; i < n; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
}
//2.6 Tim kiem theo phuong phap nhi phan
int Binarysearch(int a[], int n, int x)
{
	selectionSort(a, n);
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(x == a[mid])
			return mid;
		if(x < a[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
//2.7 Tim va xoa
int SearchAndDelete(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
		if(a[i] == x)
		{
			a[i] = a[i + 1];
			n--;
			return 1;
		}
	return 0;
}

int main()
{
	int x, i, b;
	int chon;
	input(a, n);
	cout << "----Bai thuc hanh chuong 2_bai 2---"
		<< "1.Khai bao cau truc danh sach\n"
		<< "2.Them mot phan tu vao danh sach\n"
		<< "3.Xuat cac phan tu\n"
		<< "4.Tim mot phan tu(tim kiem tuan tu)\n"
		<< "5.Tim mot phan tu(Tim kiem cay nhi phan)\n"
		<< "6.Tim va xoa\n"
		<< "7.Thoat\n";
	do{
		cout << "Ban muon chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			cout << "Khai bao thanh cong!\n";
			break;
		case 2:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			cout << "Ban muon them tai vi tri: ";
			cin >> i;
			if(i >= 0 || i < Max)
			{
				b = insert_i(a, n, x, i);
				if(b == 1)
				{
					cout << "Them thanh cong!\n";
					output(a, n);
				}
				else
					cout << "Them khong thanh cong!\n";
			}
			else
				cout << "Vi tri khong hop le!\n";
			break;
		case 3:
			output(a, n);
			break;
		case 4:
			 cout << "Nhap gia can tim: ";
			 cin >> x;
			 output(a, n);
			 i = search(a, n, x);
			 if(i == -1)
				 cout << "Khong tim thay!\n";
			 else
				 cout << "Gia tri can tim tai vi tri " << i << endl;
			 break;
		case 5:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			i = Binarysearch(a, n, x);
			output(a, n);
			if(i == -1)
				cout << "Khong tim thay!\n";
			else
				cout << "Gia tri can tim tai vi tri " << i << endl;
			break;
		case 6:
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			i = SearchAndDelete(a, n, x);
			if(i == 1)
			{
				cout << "Xoa thanh cong!\n";
				output(a, n);
			}
			else
				cout << "Khong tim thay gia tri can xoa\n";
			break;
		default:
			cout << "Tam biet. Hen gap lai!\n";
		}
	}while(chon > 0 && chon < 7);

	return 0;
}