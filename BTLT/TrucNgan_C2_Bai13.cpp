#include <iostream>
using namespace std;
#define MAX 100

struct DT
{
	double heso[MAX];
	int bac[MAX];
	int pt;
};

void Nhap(DT* a)
{
	for (int i = 0; i < a->pt; i++)
	{
		cout << "Nhap he so, bac: " << endl;
		cout << "Don Thuc " << i + 1 << ": ";
		cin >> a->heso[i] >> a->bac[i];
	}
}

void check(double n)
{
	if (n >= 0)
		cout << "+" << n;
	else
		cout << n;
}

void Xuat(DT* a)
{
	for (int i = 0; i < a->pt - 1; i++)//Rut gon
	{
		for (int j = i + 1; j < a->pt; j++)
		{
			if (a->bac[i] == a->bac[j])
			{
				a->heso[i] = a->heso[i] + a->heso[j];
				for (int k = j; k < a->pt; k++)
				{
					a->heso[k] = a->heso[k + 1];
					a->bac[k] = a->bac[k + 1];
				}
				a->pt--;
				j--;
			}
		}
	}

	if (a->bac[0] == 0)//Xuat chu so dau tien
		cout << a->heso[0];
	else
	{
		if (a->bac[0] == 1)
			cout << a->heso[0] << "x";
		else
			cout << a->heso[0] << "x^" << a->bac[0];
	}

	for (int i = 1; i < a->pt; i++)//Xuat chu so o giua
	{
		if (a->bac[i] == 0)
			check(a->heso[i]);
		else
		{
			if (a->bac[i] == 1)
			{
				check(a->heso[i]);
				cout << "x";
			}
			else
			{
				check(a->heso[i]);
				cout << "x^" << a->bac[i];
			}
		}
	}
}

DT* cong(DT* a, DT* b)
{
	int i = 0;
	DT* c = new DT;

	for (i; i < a->pt; i++)
	{
		c->heso[i] = a->heso[i];
		c->bac[i] = a->bac[i];
	}
	for (int j = 0; j < b->pt; j++)
	{
		c->heso[i] = b->heso[j];
		c->bac[i] = b->bac[j];
		i++;
	}

	for (int t = 0; t < i - 1; t++)//Rút gọn đa thức
	{
		for (int j = t + 1; j < i; j++)
		{
			if (c->bac[t] == c->bac[j])
			{
				c->heso[t] = c->heso[t] + c->heso[j];
				for (int k = j; k < i; k++)
				{
					c->heso[k] = c->heso[k + 1];
					c->bac[k] = c->bac[k + 1];
				}
				i--;
				j--;
			}
		}
	}

	c->pt = i;

	return c;
}

DT* tru(DT* a, DT* b)
{
	int i = 0;
	DT* c = new DT;

	for (i; i < a->pt; i++)
	{
		c->heso[i] = a->heso[i];
		c->bac[i] = a->bac[i];
	}
	for (int j = 0; j < b->pt; j++)
	{
		c->heso[i] = -(b->heso[j]);
		c->bac[i] = b->bac[j];
		i++;
	}

	for (int t = 0; t < i - 1; t++)//Rút gọn đa thức
	{
		for (int j = t + 1; j < i; j++)
		{
			if (c->bac[t] == c->bac[j])
			{
				c->heso[t] = c->heso[t] + c->heso[j];
				for (int k = j; k < i; k++)
				{
					c->heso[k] = c->heso[k + 1];
					c->bac[k] = c->bac[k + 1];
				}
				i--;
				j--;
			}
		}
	}
	c->pt = i;

	return c;
}

DT* nhan(DT* a, DT* b)
{
	int n = 0;
	DT* c = new DT;

	for (int i = 0; i < a->pt; i++)
	{
		for (int j = 0; j < b->pt; j++)
		{
			c->heso[n] = a->heso[i] * b->heso[j];
			c->bac[n] = a->bac[i] + b->bac[j];
			n++;
		}
	}

	for (int t = 0; t < n - 1; t++)//Rút gọn đa thức
	{
		for (int j = t + 1; j < n; j++)
		{
			if (c->bac[t] == c->bac[j])
			{
				c->heso[t] = c->heso[t] + c->heso[j];
				for (int k = j; k < n; k++)
				{
					c->heso[k] = c->heso[k + 1];
					c->bac[k] = c->bac[k + 1];
				}
				n--;
				j--;
			}
		}
	}
	c->pt = n;

	return c;
}

DT* chia(DT* a, DT* b)
{
	DT* r = new DT, * q = new DT, * tam = new DT;
	int i = 0;
	q->pt = 0;

	while (a->bac[i] >= b->bac[0])//đk: bậc của số bị chia < số chia
	{
		q->heso[i] = a->heso[i] / b->heso[0];
		q->bac[i] = a->bac[i] - b->bac[0];
		q->pt++;
		cout << endl;
		/*cout << "q=";
		Xuat(q);
		cout << endl;*/
		tam = nhan(b, q);
		/*cout << "tam=";
		Xuat(tam);
		cout << endl;*/
		r = tru(a, tam);
		/*cout << "r=";
		Xuat(r);
		cout << endl;*/
		a = r;
		/*cout << endl << "a=";
		Xuat(a);
		cout << endl;*/
		i++;
	}

	return q;
}

int main()
{
	int choice = 0;
	DT* a = new DT, * b = new DT;

	cout << "---Bai 13, Chuong 2, DANH SACH DAC - DA THUC---" << endl;
	cout << "1.Nhap so luong don thuc cho 2 da thuc" << endl
		<< "2. Nhap he so, bac cho 2 da thuc" << endl
		<< "3. Tong 2 da thuc" << endl
		<< "4. Hieu 2 da thuc" << endl
		<< "5. Tich 2 da thuc" << endl
		<< "6. Thuong 2 da thuc" << endl
		<< "7. Xuat 2 da thuc" << endl
		<< "8. Thoat" << endl;

	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Vui long nhap so luong don thuc cho da thuc 1: ";
			cin >> a->pt;
			cout << "Vui long nhap so luong don thuc cho da thuc 2: ";
			cin >> b->pt;
			break;
		case 2:
			cout << "DA THUC 1:" << endl;
			Nhap(a);
			cout << "DA THUC 2:" << endl;
			Nhap(b);
			cout << "2 DA THUC VUA NHAP:" << endl;
			cout << "Da thuc 1: ";
			Xuat(a);
			cout << "\nDa thuc 2: ";
			Xuat(b);
			break;
		case 3:
			cout << "Tong 2 da thuc: ";
			Xuat(cong(a, b));
			break;
		case 4:
			cout << "Hieu 2 da thuc: ";
			Xuat(tru(a, b));
			break;
		case 5:
			cout << "Tich 2 da thuc: ";
			Xuat(nhan(a, b));
			break;
		case 6:
			cout << "Thuong 2 da thuc: ";
			Xuat(chia(a, b));
			break;
		case 7:
			cout << "Da thuc 1: ";
			Xuat(a);
			cout << "\nDa thuc 2: ";
			Xuat(b);
			break;
		case 8:
			cout << "Goodbye!";
			break;
		default:
			cout << "Loi nhap lieu!";
			break;
		}
	} while (choice != 8);

	cout << endl;
	system("pause");
	return 0;
}