#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct sinhvien {
	string hoten;
	int mssv;
	float diem;
	void xuat()
	{
		cout <<setw(2)<< hoten << setw(15)  << mssv << right << setw(20) << diem << endl;
	}
};
struct node {
	sinhvien data;
	node* next;
};
struct list {
	node* head;
	node* tail;
};
node* Getnode(sinhvien sv)
{
	node* p;
	p = new node;
	if (p == NULL)
	{
		cout << "Khong tao duoc o nho";
		exit(1);
	}
	p->data = sv;
	p->next = NULL;
	return p;
}
void InseachHead(list& l, sinhvien sv)
{
	node* p = Getnode(sv);
	if (p == NULL)
	{
		cout << "Khong tao duoc nut";
		exit(1);
	}
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
void InseachTail(list& l, sinhvien sv)
{
	node* p = Getnode(sv);
	if (p == NULL)
	{
		cout << "Khong tao duoc nut";
		exit(1);
	}
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void Nhap(list& l, sinhvien sv)
{
	l.head = l.tail = NULL;
	do {
		cin.ignore();
		cout << "Nhap ho ten sinh vien :"; getline(cin, sv.hoten);
		cout << "Nhap MSSV : "; cin >> sv.mssv;
		cout << "Nhap diem cua sinh vien : "; cin >> sv.diem;
		if ((sv.diem < 0) || (sv.diem > 10))
			break;
		InseachHead(l, sv);
	} while ((sv.diem >= 0) && (sv.diem <= 10));
}
void Xuat(list l)
{
	cout << "Hoten" <<  setw(15) << "mssv" << right << setw(20) << "diem" << endl;
	for (node* p = l.head; p != NULL; p = p->next)
	{
		p->data.xuat();
	}
}
void timsv(list l)
{
	string k;
	cin.ignore();
	cout << "Nhap ten sinh vien can tim " << endl;
	getline(cin,k);
	int dem = 0;
	for (node* p = l.head; p != NULL; p = p->next)
	{
		if (p->data.hoten == k)
		{
			p->data.xuat();
			dem++;
		}
	}
	if (dem == 0)
		cout << "Khong co sinh vien can tim" << endl;
}
void dtb_all(list l)
{
	int dem = 0;
	float tong = 0;
	for (node* p=l.head; p != NULL; p = p->next)
	{
		dem++;
		tong = tong + p->data.diem;
	}
	if (dem != 0)
	{
		cout << "diem trung binh tat ca sinh vien la : " << tong / dem<<endl;
	}
	else
		cout << "Khong co sinh vien nao " << endl;
}
void timmssv(list l)
{
	node* p;
	int k;
	cout << "Nhap mssv can tim: "; cin >> k;
	for (p = l.head; p != NULL; p = p->next)
	{
		if (p->data.mssv == k)
		{
			p->data.xuat();
			break;
		}
	}if (p == NULL)
		cout << "khong co sinh vien can tim" << endl;
}
void sapxep(list l)
{
	node* min;
	for (node* p = l.head; p != l.tail; p = p->next)
	{
		min = p;
		for (node* q = p->next; q != NULL; q = q->next)
		{
			if (min->data.diem > q->data.diem)
				min = q;
		}
		swap(min->data, p->data);
	}
	Xuat(l);
}
void xoadau(list & l)
{
	node* tam;
	if (l.head != NULL)
	{
		tam = l.head;
		l.head = l.head->next;
		delete tam;
		if (l.head == NULL)
			l.tail = NULL;
	}
}
void xoasau(list & l, node* q)
{
	node* p;
	if (q != NULL)
	{
		p = q->next;
		if (p != NULL)
		{
			if (p == l.tail)
			{
				l.tail = q;
			}
			q->next = p->next;
			delete p;
		}
	}
}
void huysv(list& l)
{
	node* p = l.head;
	while (p != NULL)
	{
		if (l.head->data.diem < 2)
		{
			xoadau(l);
			p = l.head;
		}
		else
		{
			if ((p->next != NULL) && (p->next->data.diem < 2))
			{
				xoasau(l, p);
			}
			else
			{
				p = p->next;
			}
		}
	}Xuat(l);
}
void huyvitri(list & l)
{
	int k;
	int dem = 1;
	cout << "Nhap vi tri : "; cin >> k;
	if (k == 1)
	{
		xoadau(l);
		return;
	}
	for (node* p = l.head; p != NULL; p = p->next)
	{
			if (dem + 1 == k)
			{
				xoasau(l, p);
				return;
			}
			dem++;
	}
}
void huyyeucau(list & l)
{
	int k;
	cout << "Nhap yeu cau can xoa cua ban :"; cin >> k;
	if (l.head->data.mssv == k)
	{
		xoadau(l);
		return;
	}
	for (node* p = l.head; p != NULL; p = p->next)
	{
			if ((p->next != NULL)&&(p->next->data.mssv == k))
			{
				xoasau(l, p);
				return;
			}
	}
}
void themgiua(list& l,node*p,node*q)
{
	q->next = p->next;
	p->next = q;
	if (p = l.tail)
		l.tail = q;
}
void themsv(list& l, sinhvien x)
{
	node* h = Getnode(x);
	if (l.head->data.diem >=h->data.diem)
	{
		InseachHead(l, h->data);
		return;
	}
	for (node* p = l.head; p != NULL; p = p->next)
	{
		if ((p->data.diem <= h->data.diem) && ((p->next != NULL) && (h->data.diem <= p->next->data.diem)))
		{
			
			themgiua(l, p, h);
			return;
		}
		else
			if ((p->next == NULL) && (p->data.diem < h->data.diem))
			{
				themgiua(l, p, h);
				return;
			}
	}
}
void main()
{
	sinhvien sv;
	list l;
	int select;
	do {
		cout << "\t\tDANH SACH SINH VIEN" << endl;
		cout << "==========================================" << endl;
		cout << "=\t\tNhap 1. Nhap \t\t=" << endl;
		cout << "=\t\tNhap 2. Xuat \t\t=" << endl;
		cout << "=\t\tNhap 3. Tim \t\t=" << endl;
		cout << "=\t\tNhap 4. dtbALL \t\t=" << endl;
		cout << "=\t\tNhap 5. tim mssv \t=" << endl;
		cout << "=\t\tNhap 6. sapxeptang \t=" << endl;
		cout << "=\t\tNhap 7. xoa \t\t=" << endl;
		cout << "=\t\tNhap 8. xoatheovitri \t=" << endl;
		cout << "=\t\tNhap 9. xoatheophantu \t=" << endl;
		cout << "=\t\tNhap 10. themvitri \t=" << endl;
		cout << "==========================================" << endl;
		cout << "SELECT : "; cin >> select;
		switch (select)
		{
		case 1:Nhap(l,sv);
			break;
		case 2:Xuat(l);
			break;
		case 3:timsv(l);
			break;
		case 4:dtb_all(l);
			break;
		case 5:timmssv(l);
			break;
		case 6:sapxep(l);
			break;
		case 7: {huysv(l);
		}
			break;
		case 8: {huyvitri(l); Xuat(l); }
			break;
		case 9: {huyyeucau(l); Xuat(l); }
			break;
		case 10: {sapxep(l);
			cin.ignore();
			sinhvien x;
			cout << "NHAP SINH VIEN MOI" << endl;
			cout << "Nhap ho ten can them :"; getline(cin, x.hoten);
			cout << "Nhap mssv :"; cin >> x.mssv;
			cout << "Nhap diem : "; cin >> x.diem;
			themsv(l,x);
			Xuat(l); }
			break;
		}
		cout << "\n\n";
	} while (select != 0);
}