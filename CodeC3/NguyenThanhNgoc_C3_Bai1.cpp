#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];

void swap (int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void SeletionSort(int a[], int n)
{
	int min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap (a[min_pos], a[i]);
	}
}
void InsertionSort(int a[], int n)
{
	int x, i ,j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] =a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}
void InterchangeSort(int a[], int n)
{
	for (int i =0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[i])
				swap(a[i], a[j]);      
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x) 
			i++;
		while (a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
				i++;
				j--;
		}
	}
	QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2*i + 1;
		if (j > n)
			return;
		if (j + 1 < n)
			if (a[j] < a[j + 1])
				j++;
		if (a[i] >= a[j])
			return;
		else 
		{
			int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
		}
}
void HeapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		swap(a[0], a[right]);
		right;
		if (right > 0)
			shift(a, 0, right);
	}
}
int Search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] == x)
			return mid;
		if(x > a[mid]) 
			left = mid + 1; 
		else right = mid - 1;
	}
	return -1;
}   
void NhapMang(int a[], int n)
 {
    for(int i = 0; i < n; i++)
	{
        printf("\nNhap a[%d] = ",i);
        scanf("%d", &a[i]);
    }
}
void XuatMang(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%5d", a[i]);
}
int main ()
{	
	int a[100];
	int n, x;
	int left, right;
	char tt;
	int chon;
    
	do{
        cout << "Nhap so luong phan tu n: ";
		cin >> n;
        if(n <= 0)
           cout << "Nhap lai." << endl;
		} while(n <= 0);
	do {
		system("cls");
		cout << "MENU\n";
		cout << "1. Khai bao\n2. InsertionSort\n3. SelectionSort\n4. InterchangeSort\n5. BubbleSort\n6. QuickSort\n7. HeapSort\n8. Tim kim tuan tu\n9. Tim kim nhi phan\n.Moi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Khai bao thanh cong " << endl;
			break;
		case 2:
			cout << "Mang sap xep tang dan la: " << endl;
			InsertionSort(a, n);
			break;
		case 3:
			cout << "Mang sap xep tang dan la: " << endl;
			SeletionSort(a, n);
			break;
		case 4:
			cout << "Mang sap xep tang dan la: " << endl;
			BubbleSort(a, n);
			break;
		case 5:
			cout << "Mang sap xep tang dan la: " << endl;
			QuickSort(a, left, right);
			break;
		case 6:
			cout << "Mang sap xep tang dan la: " << endl;
			HeapSort(a, n);
			break;
		case 7:
			cout << "Nhap phan tu can tim trong mang: " << endl;
			cin >> n;
			Search(a, n, x);
			break;
		case 8:
			cout << "Nhap phan tu can tim trong mang: " << endl;
			cin >> n;
			BinarySearch(a, n, x);
			break;
		} 
		cout << "Ban co muon tiep tuc hay khong(y/n): ";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
	return 0;
}