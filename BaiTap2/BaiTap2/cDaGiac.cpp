#include "cDaGiac.h"
#include <iostream>
#include <math.h>
using namespace std;

// Phương thức thiết lập mặc định
cDaGiac::cDaGiac() {
	iSoDinh = 0;
}

// Phương thức thiết lập có truyền tham số
cDaGiac::cDaGiac(int SoDinh) {
	iSoDinh = SoDinh;
}

// Phương thức thiết lập sao chép
cDaGiac::cDaGiac(const cDaGiac& A) {
	iSoDinh = A.iSoDinh;
	aDSDiem = A.aDSDiem;
}

// Nhập tam giác
void cDaGiac::Nhap() {
	cout << "Nhap so dinh cua da giac: ";
	cin >> iSoDinh;
	for (int i = 0; i < iSoDinh; i++) {
		cout << "Nhap toa do: ";
		Diem X;
		X.Nhap();
		aDSDiem.push_back(X);
	}
}

// Xuất tam giác
void cDaGiac::Xuat() {
	for (int i = 0; i < iSoDinh; i++) {
		cout << "Danh sach diem: ";
		aDSDiem[i].Xuat();
		cout << ", ";
	}
}

// Hàm nhận đầu vào là danh sách điểm của 1 đa giác và trả về tọa độ trọng tâm
Diem ToaDoTam(vector<Diem> DSDiem) {
	double TamX = 0, TamY = 0;
	for (int i = 0; i < DSDiem.size(); i++) {
		TamX += DSDiem[i].ToaDoX();
		TamY += DSDiem[i].ToaDoY();
	}
	return Diem(TamX / DSDiem.size(), TamY / DSDiem.size());
}

// Kiểm tra tam giác là tam giác đều, cân, vuông, thường, hay không phải tam giác
void cDaGiac::KiemTra() {
	// Kiểm tra độ dài các cạnh, nếu có 1 cạnh khác cạnh ban đầu thì đa giác đó là đa giác thường
	double KetQuaDauTien = aDSDiem[0].DoDai(aDSDiem[1]);;
	for (int i = 1; i < iSoDinh; i++) {
		int j = (i + 1) % iSoDinh;
		double DoDai = aDSDiem[i].DoDai(aDSDiem[j]);
		if (KetQuaDauTien != DoDai) {
			cout << "Da giac thuong";
			return;
		}
	}
	// Kiểm tra khoảng cách từ tâm đến các đỉnh, nếu có 1 khoảng cách khác khoảng cách ban đầu thì đa giác đó là đa giác thường
	Diem Tam = ToaDoTam(aDSDiem);
	KetQuaDauTien = Tam.DoDai(aDSDiem[0]);
	for (int i = 1; i < iSoDinh; i++) {
		double KhoangCach = Tam.DoDai(aDSDiem[i]);
		if (KetQuaDauTien != KhoangCach) {
			cout << "Da giac thuong";
			return;
		}
	}
	cout << "Da giac deu";
}

// Trả về chu vi của tam giác
double cDaGiac::ChuVi() {
	double ChuVi = 0;
	for (int i = 0; i < iSoDinh; i++) {
		int j = (i + 1) % iSoDinh;
		ChuVi += aDSDiem[i].DoDai(aDSDiem[j]);
	}
	return ChuVi;
}

// Trả về diện tích của tam giác
double cDaGiac::DienTich() {
	double DienTich = 0;
	for (int i = 0; i < iSoDinh; i++) {
		int j = (i + 1) % iSoDinh;
		DienTich += aDSDiem[i].ToaDoX() * aDSDiem[j].ToaDoY();
		DienTich -= aDSDiem[j].ToaDoX() * aDSDiem[i].ToaDoY();
	}
	return abs(DienTich) / 2;
}

// Tịnh tiến tam giác theo tọa độ vector
void cDaGiac::TinhTien(const Diem& Vector) {
	for (int i = 0; i < iSoDinh; i++) {
		aDSDiem[i].TinhTien(Vector);
	}
}

// Quay tam giác quanh gốc tọa độ theo góc quay GocQuay đơn vị độ
void cDaGiac::Quay(const double& GocQuay) {
	for (int i = 0; i < iSoDinh; i++) {
		aDSDiem[i].Quay(GocQuay);
	}
}

// Phóng to điểm này theo gốc là trọng tâm của tam giác với tỷ lệ TyLe
void cDaGiac::PhongTo(const double& TyLe) {
	Diem Tam = ToaDoTam(aDSDiem);
	for (int i = 0; i < iSoDinh; i++) {
		aDSDiem[i].PhongTo(Tam, TyLe);
	}
}

// Thu nhỏ điểm này theo gốc là trọng tâm của tam giác với tỷ lệ TyLe
void cDaGiac::ThuNho(const double& TyLe) {
	Diem Tam = ToaDoTam(aDSDiem);
	for (int i = 0; i < iSoDinh; i++) {
		aDSDiem[i].ThuNho(Tam, TyLe);
	}
}
