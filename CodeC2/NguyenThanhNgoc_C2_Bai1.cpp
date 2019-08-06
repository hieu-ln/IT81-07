#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100
int a[MAX];
int n;
void input (int a[], int n)
{
	cout << "Nhap phan tu cho danh sach dac: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cout << endl;
	}
}
void output (int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
int search (int a[], int n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	if (i == n)
		return -1;
	return i;
}
int insert_last (int a[], int &n, int x)
{
	if (n >= 0 && n < MAX - 1)
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;
	
}
int delete_last (int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
	
}
int delete_vtri (int a[], int n, int vtri)
{
	if (vtri >= 0 && vtri< n)
	{
		for (int j = vtri; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}
int search_delete (int a[], int &n, int x)
{
	if (search(a, n, x) == -1)
		return 0;
	if (delete_vtri(a, n, x))
		return 1;
}
int main ()
{
	int x;
	do {
		cout << "Nhap phan tu cho danh sac dac: ";
		cin >> n;
		if (!(n >= 0 && n < MAX))
			cout << "Nhap lai\n";
	} while (!(n >= 0 && n < MAX));
	input (a, n);
	cout << "Danh sach dang luu tru la: ";
	output (a, n);
	cout << "Nhap gia tri can tim: ";
	cin >> x;
	if (search(a, n, x) == -1)
		cout << x << "Khong ton tai trong danh sach" << endl;
	else
		cout << x << " co trong danh sach tai vi tri " << search (a, n, x) + 1 << endl;
	if (insert_last(a, n, x))
	{
		cout << "Danh sach sau khi them vao phan tu cuoi: ";
		output (a, n);
	}
	else
		cout <<"Khong the them vao danh sach\n";
return 0;
}