#include <iostream>
#include "cTamGiac.h"
using namespace std;

// Phương thức thiết lập mặc định
cTamGiac::cTamGiac() {
	DiemA = Diem(0, 0);
	DiemB = Diem(0, 0);
	DiemC = Diem(0, 0);
}

// Phương thức thiết lập có truyền tham số
cTamGiac::cTamGiac(Diem a, Diem b, Diem c) {
	DiemA = a;
	DiemB = b;
	DiemC = c;
}

// Phương thức thiết lập sao chép
cTamGiac::cTamGiac(const cTamGiac& A) {
	DiemA = A.DiemA;
	DiemB = A.DiemB;
	DiemC = A.DiemC;
}

// Nhập tam giác
void cTamGiac::Nhap() {
	cout << "Nhap diem A: ";
	DiemA.Nhap();
	cout << "Nhap diem B: ";
	DiemB.Nhap();
	cout << "Nhap diem C: ";
	DiemC.Nhap();
}

// Hàm nhận 3 đỉnh của 1 tam giác , tính độ dài các cạnh và truyền kết quả vào lại các tham số
void DoDaiCacCanh(Diem DiemA, Diem DiemB, Diem DiemC, double& canhA, double& canhB, double& canhC) {
	canhA = DiemB.DoDai(DiemC);
	canhB = DiemA.DoDai(DiemC);
	canhC = DiemA.DoDai(DiemB);
}

// Xuất tam giác
void cTamGiac::Xuat() {
	cout << "Tam giac:";
	cout << " A: ";
	DiemA.Xuat();
	cout << " B: ";
	DiemB.Xuat();
	cout << " C: ";
	DiemC.Xuat();
}

// Kiểm tra tam giác là tam giác đều, cân, vuông, thường, hay không phải tam giác
void cTamGiac::KiemTra() {
	double canhA, canhB, canhC;
	DoDaiCacCanh(DiemA, DiemB, DiemC, canhA, canhB, canhC);
	if (DienTich() == 0) {
		cout << "3 diem thang hang, khong phai tam giac";
		return;
	}
	if (canhA == canhB && canhA == canhC) {
		cout << "Tam giac deu";
		return;
	}
	if (canhA == canhB || canhA == canhC || canhB == canhC) {
		cout << "Tam giac can";
		return;
	}
	if (canhA * canhA + canhB * canhB == canhC * canhC || canhC * canhC + canhB * canhB == canhA * canhA || canhA * canhA + canhC * canhC == canhB * canhB) {
		cout << "Tam giac vuong";
		return;
	}
	cout << "Tam giac thuong";
}

// Trả về chu vi của tam giác
double cTamGiac::ChuVi() {
	double canhA, canhB, canhC;
	DoDaiCacCanh(DiemA, DiemB, DiemC, canhA, canhB, canhC);
	return canhA + canhB + canhC;
}

// Trả về diện tích của tam giác
double cTamGiac::DienTich() {
	double canhA, canhB, canhC;
	DoDaiCacCanh(DiemA, DiemB, DiemC, canhA, canhB, canhC);
	double nuaChuVi = ChuVi() / 2;
	return sqrt(nuaChuVi * (nuaChuVi - canhA) * (nuaChuVi - canhB) * (nuaChuVi - canhC));
}

// Tịnh tiến tam giác theo tọa độ vector
void cTamGiac::TinhTien(const Diem& Vector) {
	DiemA.TinhTien(Vector);
	DiemB.TinhTien(Vector);
	DiemC.TinhTien(Vector);
}

// Quay tam giác quanh gốc tọa độ theo góc quay GocQuay đơn vị độ
void cTamGiac::Quay(const double& GocQuay) {
	DiemA.Quay(GocQuay);
	DiemB.Quay(GocQuay);
	DiemC.Quay(GocQuay);
}

// Phóng to điểm này theo gốc là trọng tâm của tam giác với tỷ lệ TyLe
void cTamGiac::PhongTo(const double& TyLe) {
	Diem TrongTam = Diem((DiemA.ToaDoX() + DiemB.ToaDoX() + DiemC.ToaDoX()) / 3, (DiemA.ToaDoY() + DiemB.ToaDoY() + DiemC.ToaDoY()) / 3);
	DiemA.PhongTo(TrongTam, TyLe);
	DiemB.PhongTo(TrongTam, TyLe);
	DiemC.PhongTo(TrongTam, TyLe);
}

// Thu nhỏ điểm này theo gốc là trọng tâm của tam giác với tỷ lệ TyLe
void cTamGiac::ThuNho(const double& TyLe) {
	Diem TrongTam = Diem((DiemA.ToaDoX() + DiemB.ToaDoX() + DiemC.ToaDoX()) / 3, (DiemA.ToaDoY() + DiemB.ToaDoY() + DiemC.ToaDoY()) / 3);
	DiemA.ThuNho(TrongTam, TyLe);
	DiemB.ThuNho(TrongTam, TyLe);
	DiemC.ThuNho(TrongTam, TyLe);
}
