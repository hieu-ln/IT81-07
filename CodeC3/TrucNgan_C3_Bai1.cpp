//Bai 1, chuong 3 : XEP THU TU, TIEM KIEM
#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

//Cau 1.1 Khai bao
#define MAX 5000
int a[MAX];
int n;

//Cau 1.2 NHAP DANH SACH TU DONG, NGAU NHIEN
void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++){
		a[i]= rand() % 10000 +1;
	}
	cout << "Danh sach da duong nhap ngau nhien la: " << endl;
	for (int i = 0; i < n; i++){
		cout << a[i] << "  ";
	}
	cout << endl;
}
//1.2 NHAP DANH SACH
void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;;
	for(int i = 0; i < n; i++){
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
//1.3 XUAT DANH SACH
void output(int a[], int &n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void CopyArray(int a[], int b[], int n)
{
	for(int i = 0; i< n; i++)
		b[i] = a[i];
}
//Cau1.4 Insertion Sort
void InsertionSort(int a[], int n)
{
    int i, key, j;
	for(int i = 1; i < n; i++)
	{
		key = a[i]; // biến x lưu giá trị a[i]
		j = i - 1;
		/*Di chuyển các phần tử có giá trị lớn hơn giá trị key về sau một vị trí so với vị trí ban đầu */
		while(0 <= j && key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1 ]= key;
	}
}
//ham doi cho hai so nguyen
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
//Cau 1.5 Selection Sort
void SelectionSort(int a[], int n)
{
	int  min_idx, i, j;
	//Di chuyển ranh giới giưa các mảng chưa sắp xếp và đã sắp xếp
	for(i=0; i<n-1; i++)
	{
		//Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min_idx= i;
		for (j=i+1;j<n;j++)
			if (a[j]<a[min_idx])
				min_idx=j; 
		// min_idx là vị trí chứa giá tri hiện nhỏ nhất
		swap(a[min_idx], a[i]);
	}
}
//Cau 1.6 InterchangeSort
void InterchangeSort(int a[], int n)
{
for(int i=0; i<n-1; i++)
	for (int j=i+1;j<n;j++)
		if (a[i]>a[j])
			swap(a[i], a[j]); // đổi chỗ  a[i] và a[j]
}

//Cau 1.7 Bubble sort
void BubbleSort(int arr[], int n)
{
	int i, j;
	bool haveSwap = false;
	for(int i= 0; i < n-1; i++){
		//i phan tử cuối cùng đã đc sắp xếp
		haveSwap = false;
		for(int j= 0; j < n - i - 1; j++)
			if(arr[j] > arr[j+1]) {// xét điều kiện phần tử sau nhỏ hơn phần tử trước
				swap(a[j],a[j+1]); // hoán vị a[j] với a[j-1]
				haveSwap = true;//kiểm tra lần lặp này có swap không
		}
	
		//nếu không có wap nào đc thực hiện => mảng đá sắp xếp
		if (haveSwap == false)
		{
			break;
		}
	}
}
//Cau 1.8
void QuickSort(int a[], int left, int right)
{
	int x = a[(left+right)/2];
	int i=left;
	int j=right;
	while(i<j) 
	{
		while(a[i]<x) 
			i++;
		while(a[j]>x) 
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++; 
			j--;
		}
	}
	if(left<j) 
		QuickSort(a,left,j);
	if(i<right) 
		QuickSort(a,i,right);
}
//Cau 1.9 Heap sort
void shift(int a[], int i, int n)
{
	int j = 2*i+1;
	if (j>=n) // nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
		return;
	if (j+1 <n) // nếu tồn tại vị trí j+1 trong danh sách đang xét thì thoát khỏi chương trình
		if ( a[j]<a[j+1] ) // nếu vị trí j không tồn tại  phần tử a[j] <a[j+1]
			j++;

	if (a[i] >= a[j] ) 
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n/2;
	while (i >=0) // tạo heap ban đầu
	{	
		shift(a, i, n-1);	i--;
	}
	int right=n-1; // right là vị trí cuối Heap đang xét
	while (right>0)
	{	
		swap(a[0], a[right]); // hoán vị phần tử a[0] cho phần tử cuối Heap đang xét
		right--; // giới hạn lại phần tử cuối đang xét
		if (right > 0) // Kiểm tra dãy đang xét còn nhiều hơn 1 phần tử
			shift(a, 0, right); // tạo Heap lại tại vị trí 0
	}

}
//Cau 1.10 Tiem kiem tuan tu
int Search(int a[], int n, int X)
{
	int i=0;
	while(i<n && a[i]!=X)
		i++;
	if(i < n)
		return i; // x trong danh sách a, và nằm ở vị trí i
	return -1; // không tìm thấy x trong danh sách a;
}
//Cau1.11 Tiem kiem nhi phan
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(a [mid] == x)
			return mid;
		if(x > a[mid]) 
			left = mid + 1;
		else right = mid-1;
	}
	return -1; // không tìm thấy x trong danh sách a;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << " --------- BAI TAP 1 , CHUONG 3 , XEP THU TU VA TIEM KIEM --------- " << endl;
	cout << "0. Khoi tao danh sach ngau nhien: " << endl;
	cout << "1. Nhap danh sach: " << endl;
	cout << "2. Xuat danh sach: " << endl;
	cout << "3. Xep thu tu danh sach SELECTION SORT: " << endl;
	cout << "4. Xep thu tu danh sach INSERTION SORT: " << endl;
	cout << "5. Xep thu tu danh sach BUBBLE SOTR: " << endl;
	cout << "6. Xep thu tu danh sach INTERCHANGE SORT: " << endl;
	cout << "7. Xep thu tu danh sach QUICK SORT: " << endl;
	cout << "8. Xep thu tu danh sach HEAP SORT: " << endl;
	cout << "9. Tiem kiem phan tu x bang TIEM KIEM TUAN TU: " << endl;
	cout << "10. Tiem kiem phan tu x bang TIEM KIEM NHI PHAN: " << endl;
	cout << "11. Thoat " << endl;
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;		
		case 2:
			cout << "Danh sach la: ";
			output(a, n);
			break;
		case 3:
			CopyArray(a,b,n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi SelectionSort la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian SelectionSort: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 4:
			CopyArray(a,b,n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi InsertionSort la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian InsertionSort: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 5:
			CopyArray(a,b,n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi BubbleSort la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian IBubbleSort: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 6:
			CopyArray(a,b,n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi InterchangeSort la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian InterchangeSort: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 7:
			CopyArray(a,b,n);
			start = clock();
			QuickSort(b, 0, n -1);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi QuickSort la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian QuickSort: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 8:
			CopyArray(a,b,n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi HeapSort la: " << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian InterchangeSort: " << duration * 1000000 << " Microseconds" << endl;
			break;		
		case 9:			
			start = clock();
			cout<<"Nhap x: ";
			cin >> x;
			i = Search(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(i == - 1)
				cout << "Khong tim thay x= " << x << " trong day!" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl; 
			if(duration > 0)
				cout << "Thoi gian tim kiem tuan tu: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 10:
			start = clock();
			cout << "Nhap x: ";
			cin >> x;
			i = BinarySearch(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(i == - 1)
				cout << "Khong tim thay x= " << x << " trong day!" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl; 
			if(duration > 0)
				cout << "Thoi gian tim kiem nhi phan: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 11:
			cout << "Good bye!";
			break;
		default:
			break;
		}
	}while(choice != 11);
	return 0;
}