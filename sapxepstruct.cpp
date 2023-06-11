#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
using namespace std;
struct baihat {
	string ten;
	int namph;
	int luotview;
	void nhap()
	{
		cout << "NHap ten bai hat : ";
		cin.ignore();
		getline(cin, ten);
		cout << "nhap nam phat hanh : ";
		cin >> namph;
		cout << "Nhap luot view : ";
		cin >> luotview;
	}
	void xuat()
	{
		cout << left << setw(20) << ten << setw(25) << namph << right << setw(10) << luotview << endl;
	}
};

void nhapds(int & n, baihat A[]);
void xuatds(int n, baihat A[]);
void chepmang(int n, baihat A[], baihat B[]);
int timmax(int n, baihat A[]);
int timmin(int n, baihat A[]);
int timten(int n, baihat A[], string x);
void tangdantheonam(int n, baihat A[]);
void giamdantheonam(int n, baihat A[]);
int timnam(int n, baihat A[], int x);
void quicksort(int n, baihat A[], int l, int r);

void main()
{
	baihat A[100], B[100];
	int n;
	int select;
	do {
		cout << "\t\t MENU" << endl;
		cout << "1 nhap ds bai hat " << endl;
		cout << "2.xuat ds bai hat " << endl;
		cout << "3 tim bai hat co luong view cao nhat " << endl;
		cout << "4 tim bai hat co luong view thap  nhat " << endl;
		cout << "5. Tim bai hat co ten nhap vao " << endl;
		cout << "6. Sap xep tang dan theo nam phat hanh " << endl;
		cout << "7. Sap xep giam dan theo so view " << endl;
		cout << "8. tim nam phat hanh " << endl;
		cout << "9.tim quicksort luot view" << endl;
		cin >> select;
		switch (select)
		{
		case 1: 
			nhapds(n,A);
		break;
		case 2: {
			chepmang(n, A, B);
			xuatds(n, B);
		}break;
		case 3:
		{
			chepmang(n, A, B);
			int c = timmax(n, B);
			cout << "Danh sanh co luot view cao nhat la " << endl;
			cout << "Ten bai hat " << setw(20) << " Nam phat hanh " << right << setw(28) << "So luot view " << endl;
			B[c].xuat();
		}break;
		case 4: {
			chepmang(n, A, B);
			int c = timmin(n, B);
			cout << "Bai hat co luot view thap nhat la " << endl;
			cout << "Ten bai hat " << setw(20) << " Nam phat hanh " << right << setw(28) << "So luot view " << endl;
			B[c].xuat(); 
		}break;
		case 5:
		{
			chepmang(n, A, B);
			string x;
			cout << "Nhap ten bai hat can tim " << endl;
			cin.ignore();
			getline(cin, x);
			int c = timten(n, B, x);
			if (timten(n, B, x) == -1)
				cout << "Khong co ten can tim " << endl;
			else
			{
				cout << "ten bai hat can tim " << endl;
				cout << "Ten bai hat " << setw(20) << " Nam phat hanh " << right << setw(28) << "So luot view " << endl;
				B[c].xuat();
			}

		}break;
		case 6: {
			chepmang(n, A, B);
			tangdantheonam(n, B);
			cout << "tang dan theo nam " << endl;
			xuatds(n, B);
			
		}break;
		case 7: {
			chepmang(n, A, B);
			giamdantheonam(n, B);
			
		}break;
		case 8:
		{
			chepmang(n, A, B);
			int x;
			cout << "Nhap nam " << endl;
			cin >> x;
			int c = timnam(n, B, x);
			if (timnam(n, B, x) == -1)
				cout << "Khong co nam can tim " << endl;
			else {
				cout << "Nam can tim la " << endl;
				cout << "Ten bai hat " << setw(20) << " Nam phat hanh " << right << setw(28) << "So luot view " << endl;
				B[c].xuat();
			}
		}break;
		case 9: {
			chepmang(n, A, B);
			quicksort(n, B, 0, n - 1);
			xuatds(n, B);
		}break;



		}
		cout << "\n\nNhan ESC de ket thuc hoac nhan phim bat ki de dung lai " << endl;
	} while (_getch() != 27);
}
void nhapds(int& n, baihat A[])
{
	cout << "Nhap so luong bai hat " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
		A[i].nhap();
}
void xuatds(int n, baihat A[])
{
	cout << "Ten bai hat " << setw(20) << " Nam phat hanh " << right << setw(28) << "So luot view " << endl;
	for (int i = 0; i < n; i++)
		A[i].xuat();
}
void chepmang(int n, baihat A[], baihat B[])
{
	for (int i = 0; i < n; i++)
		B[i] = A[i];
}
int timmax(int n, baihat A[]) {
	int max = 0;
	for (int i = 0; i < n; i++)
		if (A[max].luotview < A[i].luotview)
			max = i;
	return max;
}
int timmin(int n, baihat A[]) {
	int min = 0;
	for (int i = 0; i < n; i++)
		if (A[min].luotview > A[i].luotview)
			min = i;
	return min;
}
void tangdantheonam(int n, baihat A[])
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (A[i].namph > A[j].namph)
				swap(A[i], A[j]);
	
}
void giamdantheonam(int n, baihat A[])
{
	int max;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
			if (A[max].namph < A[j].namph)
				max = j;
		swap(A[max], A[i]);
	}
	cout << "Giam dan theo nam " << endl;
	xuatds(n, A);
}
int timten(int n, baihat A[],string x)
{
	int i = 0;
	while ((i < n) && (A[i].ten != x))
		i++;
	if (i == n)
		return -1;
	return i;
}
int timnam(int n, baihat A[], int x)
{
	tangdantheonam(n, A);
	int l = 0;
	int r = n - 1;
	int m;
	do {
		m = (l + r) / 2;
		if (A[m].namph == x)
			return m;
		if (A[m].namph < x)
			l = m + 1;
		else
			r = m - 1;

	} while (l <= r);
	return -1;
}
void quicksort(int n, baihat A[], int l, int r)
{
	int i = l, j = r;
	int x = A[(l + r) / 2].luotview;
	do {
		while (A[i].luotview < x)i++;
		while (A[j].luotview > x)j--;
		if (i <= j)
		{
			swap(A[i], A[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)quicksort(n, A, l, j);
	if (i < r)quicksort(n, A, i, r);
}