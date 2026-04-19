#include "cDaThuc.h"
#include <iostream>
#include <vector>
using namespace std;

cDaThuc::cDaThuc(int Bac) {
	iBac = Bac;
	aDSHeSo.resize(iBac + 1);
}

double cDaThuc::TinhGiaTri(const double& x) {
	double GiaTri = 0;
	for (int i = iBac; i >= 0; i--) {
		GiaTri += aDSHeSo[i] * pow(x, i);
	}
	return GiaTri;
}

void cDaThuc::Nhap() {
	int Bac;
	do {
		cout << "Nhap bac cua da thuc (bac >= 0): ";
		cin >> Bac;
	} while (Bac < 0);
	iBac = Bac;
	aDSHeSo.resize(iBac + 1);
	for (int i = Bac; i >= 0; i--) {
		double HeSo;
		cout << "Nhap he so bac " << i << " : ";
		cin >> HeSo;
		aDSHeSo[i] = HeSo;
	}
}

void cDaThuc::Xuat() {
	bool isEmpty = true;
	for (int i = iBac; i >= 0; i--) {
		if (aDSHeSo[i] == 0) continue; // Không cần hiện hệ số bằng 0
		isEmpty = false;
		cout << showpos << aDSHeSo[i]; // Hiện dấu của hệ số, biểu thị cho phép cộng hoặc trừ
		if (i != 0) { // Không cần hiện x^0
			if (i == 1) cout << "x"; // Hiện x thay vì x^1
			else cout << "x^" << noshowpos << i;
		}
	}
	if (isEmpty) cout << 0; // Xuất số 0 nếu tất cả hệ số đều bằng 0
	cout << noshowpos;
}

cDaThuc cDaThuc::Cong(cDaThuc& other) {
	cDaThuc KetQua(max(iBac, other.iBac));
	for (int i = KetQua.iBac; i >= 0; i--) {
		if (i <= iBac) KetQua.aDSHeSo[i] += aDSHeSo[i];
		if (i <= other.iBac) KetQua.aDSHeSo[i] += other.aDSHeSo[i];
	}
	return KetQua;
}

cDaThuc cDaThuc::Tru(cDaThuc& other) {
	cDaThuc KetQua(max(iBac, other.iBac));
	for (int i = KetQua.iBac; i >= 0; i--) {
		if (i <= iBac) KetQua.aDSHeSo[i] += aDSHeSo[i];
		if (i <= other.iBac) KetQua.aDSHeSo[i] -= other.aDSHeSo[i];
	}
	return KetQua;
}