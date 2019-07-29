//Danh sach dac
#include <stdio.h>
#include <iostream>
using namespace std;

//1.1 Khai bao 
#define MAX 1000
int a[MAX];
int b[MAX];
int n;
//1.2 Nhap danh sach
void input(int a[], int &n)
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
//1.3 Xuat danh sach
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
//Nhap tu dong
void auTo(int a[], int &n)
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	for(int i = 0; i < n; i++)
		a[i] = rand() % 1000;
	output(a, n);
}
//Doi cho
void swap(int &a, int &b)
{
	int tam = a; 
	a = b;
	b = tam;
}
// sao chep mang, de giu lai mang goc
void copyArry(int a[], int b[], int n)
{
	for(int i = 0; i < n; i++)
		b[i] = a[i];
}
//1.4 Sap xep tang dan bang thuat toan InsertionSort
void insertionSort(int a[], int n)
{
	int key, i, j;
	for(i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
//1.5 Sap xep thu tu tang dan theo SelectionSort
void selectionSort(int a[], int n)
{
	int min, i, j;
	for(i = 0; i < n - 1; i++)
	{
		min  = i;
		for(j = i+1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
}
//1.6 Sap xep tang dan theo InterchangeSort
void interchangeSort(int a[], int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}
//1.7 Sap xep tang dan theo BubbleSort
void BubbleSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = n - 1; j > i; j--)
			if(a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
//
void bubbleSort(int a[], int n)
{
	int i, j;
	bool haveSwap = false;
	for(i = 0; i < n - 1; i++)
	{
		haveSwap = false;
		for(j = 0; j < n - i - 1; j++)
			if(a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				haveSwap = true;
			}
		if(haveSwap == false)
			break;
	}
}
//1.8 Sap xep tang dan theo QuickSort
void quickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left; 
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
		{
			i++;
		}
		while(a[j] > x)
		{
			j--;
		}
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j)
		quickSort(a, left, j);
	if(i < right)
		quickSort(a, i, right);
}
//tao thuat giai cho Heap
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if(j >= n)
		return;
	if(j + 1 < n)
		if(a[j] < a[j + 1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		swap(a[i], a[j]);
		shift(a, j, n);
	}
}
//1.9 Sap xep tang dan theo HeapSort
void heapSort(int a[], int n)
{
	int i = n / 2 - 1;
	while(i >= 0)
	{
		shift(a, i, n);
		i--;
	}
	int right = n - 1;
	while(right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if(right > 0)
			shift(a, 0, right);
	}
}
//1.10 Tim kiem tuan tu
int search(int a[], int n, int x)
{
	int i;
	for(i = 0; i < n; i++)
		if(a[i] == x)
			return i;
	return -1;
}
//1.11 Tim kiem nhi phan
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid = (left + right)/2;
		if(a[mid] == x)
			return mid;
		if(x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	int chon, x, i;
	cout << "Bai thuc hanh 1 - Chuong 3\n"
		<< "1.Khai bao cau truc danh sach\n"
		<< "2.Nhap danh sach auto\n"
		<< "3. Nhap danh sach thuong\n"
		<< "4. Xuat danh sach\n"
		<< "5.Sap xep theo InsertionSort\n"
		<< "6.Sap xep theo SelectionSort\n"
		<< "7.Sap xep theo InterchangeSort\n"
		<< "8. Sap xep theo BubbleSort \n"// khong sap xep
		<< "9. Sap xep theo QuickSort \n"
		<< "10.Sap xep theo HeapSort \n"
		<< "11. Tim kiem tuan tu\n"
		<< "12. Tim kiem nhi phan\n"// phai chay thu tu sap xep truoc
		<< "13. Thoat\n";
	do{
		cout << "Ban chon: ";
		cin >> chon ;
		switch(chon)
		{
		case 1: 
			cout << "Khai bao cau truc thanh cong!\n";
			break;
		case 2:
			auTo(a, n);
			break;
		case 3:
			input(a, n);
			break;
		case 4:
			output(a, n);
			break;
		case 5:
			copyArry(a, b, n);
			insertionSort(b, n);
			output(b, n);
			break;
		case 6:
			copyArry(a, b, n);
			selectionSort(b, n);
			output(b, n);
			break;
		case 7:
			copyArry(a, b, n);
			interchangeSort(b,n);
			output(b, n);
			break;
		case 8:
			copyArry(a, b, n);
			bubbleSort(b, n);
			output(a, n);
			break;
		case 9:
			copyArry(a, b, n);
			quickSort(b, 0, n-1);
			output(b, n);
			break;
		case 10:
			copyArry(a, b, n);
			heapSort(b, n);
			output(b, n);
			break;
		case 11:
			cout << "Nhap phan tu muon tim: ";
			cin >> x;
			i = search(a, n, x);
			if(i >= 0)
				cout << "Phan tu " << x << " xuat hien tai vi tri " << i << endl;
			else
				cout << "Khong tim thay!\n";
			break;
		case 12:
			interchangeSort(b, n);
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			i = BinarySearch(b, n, x);
			if(i >= 0)
				cout << "Phan tu " << x << " xuat hien tai vi tri " << i << endl;
			else
				cout << "Khong tim thay!\n";
			break;
		default:
			cout << "Hen gap lai!\n";
		}
	}while(chon > 0 && chon < 13);
	return 0;
}