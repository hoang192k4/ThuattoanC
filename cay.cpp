#include<iostream>
#include<ctime>
using namespace std;
typedef struct node {
	int key;
	node* left, * right;
};
typedef node* Tree;
int Intersert(Tree& t, int x)
{
	if (t != NULL)
	{
		if (t->key == x) return 0;
		else if (t->key > x) return Intersert(t->left, x);
		else return Intersert(t->right, x);
	}
	t = new node;
	if (t == NULL)
		return -1;
	t->key = x;
	t->left = t->right = NULL;
	return 1;
}
void nhap(Tree& t, int & x)
{
	cout << "Nhap gia tri cay, Nhap 0 de dung :";
	cin >> x;
	while (x != 0)
	{
		Intersert(t, x);
		cout << "Nhap gia tri cay, Nhap 0 de dung :";
		cin >> x;
	}
}
void Nhapramdom(Tree& t, int& n)
{
	srand(time(0));
	int a;
	for (int i = 0; i < n; i++)
	{
		a = rand() % 100 + 1;
		Intersert(t, a);
	}
}
void NLR(Tree t)
{
	if (t != NULL)
	{
		cout << t->key << " ";
		NLR(t->left);
		NLR(t->right);
	}
}
node* seach(Tree t, int x)
{
	if (t != NULL)
	{
		if (t->key == x) return t;
		else if (t->key > x) return seach(t->left, x);
		else  return seach(t->right, x);
	}
	return NULL;
}
void seachstanfor(Tree & p, Tree & q)
{
	if (q->left) seachstanfor(p, q->left);
	else {
		p->key = q->key;
		p = q;
		q = q->right;
	}
}
int  huy(Tree& t, int x)
{
	if (t == NULL) return 0;
	if (t->key > x) return huy(t->left, x);
	else
	if (t->key < x) return huy(t->right, x);
	else {
		node* p = t;
		if (t->left ==NULL) t = t->right;
			else if (t->right == NULL) t = t->left;
				else
				seachstanfor(p, t->right);
			delete p;
			}return 1;
}
bool ktsnt(int x)
{
	if (x == 1) return false;
	if ((x == 2) || (x == 3)) return true;
	for (int i = 2; i <= x/2; i++)
	{
		if (x % i == 0)
			return false;
	}return true;
}
void minnt(Tree t, int & min)
{
	if (t != NULL)
	{
		if (min == 0)
		{	if (ktsnt(t->key) == true)
		
			min = t->key;
		}
		if (min != 0)
			{
				if ((ktsnt(t->key) == true) && (t->key < min))
					min = t->key;
			}
		/*
		if ((ktsnt(t->key) == true) && ((t->key < min) || (min == 0)))
		{
			min = t->key;
		}*/
	
		minnt(t->left, min);
		minnt(t->right, min);
	}


}
void seach(Tree& p, Tree& q)
{
	if (q->left ) seach(p, q->left);
	else
	{
		p->key = q->key;
		p = q;
		q = q->right;
	}
}
int dddd(Tree t, int data)
{
	if (t == NULL) return 0;
	if (t->key > data) return dddd(t->left, data);
	else
		if (t->key < data) return dddd(t->right, data);
		else
		{
			node* p = t;
			if (t->left == NULL) t = t->right;
			else
				if (t->right == NULL) t = t->left;
				else
					seach(p, t -> right);
			delete p;
 		}
	return 1;
}
void main()
{
	Tree t = NULL;
	int x;
	int select;
	do {
		cout << "\n\t\tMENU" << endl;
		cout << "Nhap 1 de nhap tay hoac ramdom " << endl;
		cout << "Nhap 2 de xuat " << endl;
		cout << "Nhap 3 de tim kiem " << endl;
		cout << "Nhap 4 de huy sv " << endl;
		cout << "Nhap 5 de tim snt nho nhat " << endl;
		cout << "SELECT : "; cin >> select;
		switch (select)
		{
		case 1: {
			int k;
				cout << "Nhap 9 de nhap tay hoac 10 de nhap ramdom " << endl;
				cin >> k;
				switch (k)
				{
					case 9: {
						nhap(t, x);
					}break;
					case 10: {int n;
						cout << "Nhap so luong phan tu ramdom "; cin >> n;
						Nhapramdom(t, n); 
					}break;
				}
			}break;
		case 2:NLR(t);
			break;
		case 3: {
			int k;
			cout << "Nhap so can tim "; cin >> k;
			node* p = seach(t, k);
			if (p != NULL)
			{
				cout << "\nso can tim la " << p->key;
			}
			else
				cout << "\nKhong co so can tim ";
		}break;
		case 4: {
			int k;
			cout << "Nhap gia tri can xoa tren cay "; cin >> k;
			if (huy(t, k) == 1)
			{
				cout << "cay sau khi xoa xong la " << endl;
				NLR(t);
			}
			else
				cout << "Khong co gia tri can xoa ";
		}break;
		case 5: {
			int min = 0;
			minnt(t, min);
			if (min == 0)
			{
				cout << "khong co so nguyen to ";
			}
			else
				cout << "so nguyen to nho nhat la " << min;

		}break;


		}
		cout << "\n";
	} while (select != 0);
}