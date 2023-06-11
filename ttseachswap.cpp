#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
using namespace std;
struct sinhvien {
	string hoten;
	int  mssv;
	float dlt, dth;
	void nhap()
	{
		cout << "Nhap ho va ten :";
		cin.ignore();
		getline(cin, hoten);
		cout << "Nhap mssv :";
		cin >> mssv;
		cout << "Nhap diem ly thuyet:";
		cin >> dlt;
		cout << "Nhap diem thuc hanh:";
		cin >> dth;
	}
	void xuat()
	{
		cout << left << setw(25) << hoten << setw(10) << mssv << right << setw(20) << dlt << setw(20) << dth << endl;
	}
};
void quicksort(int n,sinhvien A[], int l, int r);
void nhapds(int& n, sinhvien A[]);
void xuatds(int n, sinhvien A[]);
void sapxepmssv(int n, sinhvien A[]);
void sapxepdlt(int n, sinhvien A[]);
void chepmang(int n, sinhvien A[], sinhvien B[]);
int timtuyentinh(int n, sinhvien A[],string x);
int timnhiphan(int n, sinhvien A[], int x);

void main()
{
	sinhvien A[100],B[100];
	int  x;
	int n;
	int select;
	do {
		cout << "\t\tMENU" << endl;
		cout << "1.Nhap danh sach sinh vien " << endl;
		cout << "2. Xuat danh sach sinh vien " << endl;
		cout << "3.sap xep thep mssv " << endl;
		cout << "4.Sap xep theo thu tu tang dan diem trung binh " << endl;
		cout << "5.sap xep theo thu tu tang dan dth" << endl;
		cout << "6.tim kiem ho ten bang cach tim kim  tuyen tinh  " << endl;
		cout << "7.tim kim mssv theo kieu tim kiem nhi phan " << endl;
		cin >> select;
		switch (select)
			{
		case 1: nhapds(n, A);
			break;
		case 2:xuatds(n, A);
			break;
		case 3: {cout << "Sinh vien sap sep theo mssv tang dan"<<endl;
			chepmang(n, A, B);
			sapxepmssv(n, B);
			xuatds(n, B); }
			  break;
		case 4: {cout << "sinh vien sap xep diem trung binh tang dan" << endl;
			chepmang(n, A, B);
			sapxepdlt(n, B);
			xuatds(n, B); }
		break;
		case 5: {
			cout << "Sap xep theo quicksort diem thuc hanh tang dan "<<endl;
			chepmang(n, A, B);
			quicksort(n,B,0, n - 1);
			xuatds(n, B);
		}
			  break;
		case 6: {
			string x;
			cout << "nhap hoten can tim ";
			cin.ignore();
			getline(cin, x);
			chepmang(n, A, B);
			int c = timtuyentinh(n, B,x);
			if (timtuyentinh(n, B,x) == -1)
				cout << "Khong co ho ten can tim " << endl;
			else
			{
				cout << "ho ten sinh vien can tim la " << endl;
				cout << left << setw(25) << "Ho ten" << setw(10) << "MSSV" << right << setw(25) << "diem ly thuyet" << setw(25) << right << "diem thuc hanh " << endl;
				B[c].xuat();
			}
		}break;
		case 7: {
			chepmang(n, A, B);
			int x;
			cout << "Nhap mssv can tim ";
			cin >> x;
			int k = timnhiphan(n, B, x);
			if (timnhiphan(n, B, x) == -1)
				cout << "Khong co mssv can tim ";
			else
			{
				cout << "Mssv can tim la "<<endl;
				cout << left << setw(25) << "Ho ten" << setw(10) << "MSSV" << right << setw(25) << "diem ly thuyet" << setw(25) << right << "diem thuc hanh " << endl;
				B[k].xuat();
			}
		}

			}

			cout << "\n\n";
			  cout << "Nhan ESC de ket thuc va nhan bat ki de tiep tuc  \n";
		} while (_getch() != 27);

}
	void nhapds(int& n, sinhvien A[])
	{
		cout << "Nhap so luong sinh vien ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			A[i].nhap();
		}
	}
	void xuatds(int n, sinhvien A[])
	{
		cout << left << setw(25) << "Ho ten" << setw(10) << "MSSV" << right << setw(25) << "diem ly thuyet" << setw(25) << right << "diem thuc hanh " << endl;
		for (int i = 0; i < n; i++)
			A[i].xuat();
	}
	void chepmang(int n, sinhvien A[], sinhvien B[])
	{
		for (int i = 0; i < n; i++)
			B[i] = A[i];
	}

	void sapxepmssv(int n, sinhvien A[])
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (A[i].mssv > A[j].mssv)
					swap(A[i], A[j]);
			}
		}

	}
	void sapxepdlt(int n, sinhvien A[])
	{
		int min;
		for (int i = 0; i < n - 1; i++)
		{
			min = i;
			for (int j = i + 1; j < n; j++)
			{
				if ((A[min].dlt +A[min].dth)> (A[j].dlt+A[j].dth))
					min = j;
			}
			swap(A[min], A[i]);
		}
	}
	void quicksort(int n, sinhvien A[],int l, int r)
	{
		int i, j;
		i = l;
		j = r;
		int x;
		x= A[(l + r) / 2].dth;
		do {

			while (A[i].dth <x)i++;
			while (A[j].dth> x)j--;
			if (i <= j)
			{
				swap(A[i], A[j]);
				i++;
				j--;
			}
		} while(i <= j);
		if (l < j)quicksort(n, A, l, j);
		if (i < r)quicksort(n, A, i, r);
	}
	int timtuyentinh(int n, sinhvien A[], string x)
	{
		
		int i = 0;
		while ((i < n) && (A[i].hoten != x))
			i++;
		if (i == n)
			return -1;
		return i;
	}
	int timnhiphan(int n, sinhvien A[], int x)
	{
		sapxepmssv(n, A);
		int l = 0, r = n - 1;
		int i = 0;
		int m;
		do {
			 m = (l + r) / 2;
			 if(A[m].mssv==x)
				 return m;
			 if (A[m].mssv < x)
				 l = m + 1;
			 else
				 r = m - 1;

		} while (l<=r);
		return -1;
	}