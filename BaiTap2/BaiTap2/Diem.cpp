#include <iostream>
#include <math.h>
#include "Diem.h"
#include <iomanip>
using namespace std;

// Phương thức thiết lập mặc định
Diem::Diem() {
	x = 0;
	y = 0;
}

// Phương thức thiết lập có truyền tham số
Diem::Diem(double a, double b) {
	x = a;
	y = b;
}

// Phương thức thiết lập sao chép
Diem::Diem(const Diem& A) {
	x = A.x;
	y = A.y;
}

// Nhập 1 điểm
void Diem::Nhap() {
	cin >> x >> y;
}

// Xuất 1 điểm (làm tròn đến 2 chữ số thập phân)
void Diem::Xuat() {
	cout << fixed << setprecision(2);
	cout << '(' << x << ", " << y << ')';
}

// Hàm getter trả về tọa độ x
double Diem::ToaDoX() {
	return x;
}

// Hàm getter trả về tọa độ y
double Diem::ToaDoY() {
	return y;
}

// Trả về độ dài từ điểm này đến điểm other
double Diem::DoDai(const Diem& other) {
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

// Tịnh tiến điểm này theo tọa độ vector
void Diem::TinhTien(const Diem& vector) {
	x += vector.x;
	y += vector.y;
}

// Quay điểm này quanh gốc tọa độ theo góc quay GocQuay đơn vị độ
void Diem::Quay(const double& GocQuay) {
	double pi = acos(-1.0);
	double newX = x * cos(GocQuay * pi / 180) - y * sin(GocQuay * pi / 180);
	double newY = y * cos(GocQuay * pi / 180) + x * sin(GocQuay * pi / 180);
	x = newX;
	y = newY;
}

// Phóng to điểm này theo gốc là điểm Tam với tỷ lệ TyLe
void Diem::PhongTo(const Diem& Tam, const double& TyLe) {
	x = Tam.x + (x - Tam.x) * TyLe;
	y = Tam.y + (y - Tam.y) * TyLe;
}

// Thu nhỏ điểm này theo gốc là điểm Tam với tỷ lệ TyLe
void Diem::ThuNho(const Diem& Tam, const double& TyLe) {
	x = Tam.x + (x - Tam.x) * (1 / TyLe);
	y = Tam.y + (y - Tam.y) * (1 / TyLe);
}
