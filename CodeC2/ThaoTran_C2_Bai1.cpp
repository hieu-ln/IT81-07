//bai 1 chuong 2
#include <iostream>
using namespace std;

//1.1 khai bao cau truc danh sach
#define MAX 100
int a[MAX];
int n;

//1.2 nhap danh sach
void input (int a[], int n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i + 1 << "] =";
		cin >> a[i];
	}
}

//1.3 xuat danh sach ra man hinh
void output (int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

//1.4 tìm mot phan tu trong danh sach
int search (int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}

//1.5 them mot phan tu vao cuoi danh sach
int insert_last (int a[], int &n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}

//1.6 xoa phan tu cuoi danh sach
int delete_last (int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}

//1.7 xoa phan tu tai vi tri thu i
int Delete (int a[], int &n, int i)
{
	if (i <n && i >= 0)
	{
		for (int j = 0; j < n; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}

//1.8 tim mot phan tu trong danh sach neu tim thay xoa phan tu do
int searchAndDelete (int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i;
	system ("cls");
	cout << "--------BAI TAP 1, CHUONG 2, DANH SACH DAC---------" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim phan tu co gia tri x trong danh sach" << endl;
	cout << "4. Them phan tu vao cuoi danh sach" << endl;
	cout << "5. Xoa phan tu cuoi danh sach" << endl;
	cout << "6. Xoa phan tu tai vi tri i" << endl;
	cout << "7. Tim phan tu voi gia tri x va xoa no neu co" << endl;
	cout << "8. Thoat" << endl;

	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				input (a, n);
				cout << "Ban vua nhap danh sach thanh cong!" << endl;
				break;
			case 2:
				cout << "Danh sach da nhap la: " << endl;
				output(a, n);
				break;
			case 3:
				cout << "Vui long nhap x can tim: ";
				cin >> x;
				i = search(a, n, x);
				if (i == -1)
					cout << "Tim khong thay phan tu co gia tri " << x << endl;
				else 
					cout << "Tim thay tai vi tri i= " << i << endl;
				break;
			case 4:
				cout << "Vui long nhap x can them vao cuoi danh sach: ";
				cin >> x;
				i = insert_last(a, n, x);
				if (i == 0)
					cout << "Danh sach da day, khong the them" << x << endl;
				else 
				{
					cout << "Da them phan tu x= " << i << " vao cuoi danh sach!" << endl;
					cout << "Danh sach sau khi them vao: " << endl;
					output(a, n);
				}
				break;
			case 5:
				i = delete_last (a, n);
				if (i > 0)
				{
					cout << "Xoa thanh cong!" << endl;
					cout << "Danh sach sau khi xoa phan tu cuoi la: " << endl;
					output(a, n);
				}
				else
					cout << "Danh sach dang rong, khong co phan tu nao!" << endl;
				break;
			case 6:
				cout << "Vui long nhap vi tri can xoa i= ";
				cin >> i;
				i = Delete (a, n, i);
				if (i == 1)
				{
					cout << "Xoa thanh cong" << endl;
					cout << "Danh sach sau khi xoa la: " << endl;
					output(a, n);
				}
				else 
					cout << "Khong co phan tu nao de xoa!" << endl;
				break;
			case 7:
				cout << "Vui long nhap gia tri can xoa x= ";
				cin >> x;
				i = searchAndDelete(a, n, x);
				if(i == 1)
				{
					cout << "Xoa thanh cong phan tu co gia tri x= " << x << endl;
					cout << "Danh sach sau khi xoa la: " << endl;
					output(a, n);
				}
				else 
					cout << "Khong co phan tu nao de xoa" << endl;
				break;
			case 8:
				cout << "Goodbye!" << endl;
				break;
			default:
				break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}