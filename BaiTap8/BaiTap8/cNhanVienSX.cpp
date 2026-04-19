#include "cNhanVienSX.h"
#include <iostream>
#include <string>
using namespace std;

// Phương thức thiết lập mặc định
cNhanVienSX::cNhanVienSX() {
	sMaNV = "";
	sHoTen = "";
	NgaySinh = Date();
	iSoSanPham = 0;
	iGiaSanPham = 0;
}
// Phương thức thiết lập có truyền tham số
cNhanVienSX::cNhanVienSX(string MaNV, string Ten, Date ngaySinh, int SoLuong, long long gia) {
	sMaNV = MaNV;
	sHoTen = Ten;
	NgaySinh = Date(ngaySinh);
	iSoSanPham = SoLuong;
	iGiaSanPham = gia;
}
// Phương thức thiết lập sao chép
cNhanVienSX::cNhanVienSX(const cNhanVienSX& NhanVien) {
	sMaNV = NhanVien.sMaNV;
	sHoTen = NhanVien.sHoTen;
	NgaySinh = Date(NhanVien.NgaySinh);
	iSoSanPham = NhanVien.iSoSanPham;
	iGiaSanPham = NhanVien.iGiaSanPham;
}
// Hàm nhập nhân viên
void cNhanVienSX::NhapNhanVien() {
	cout << "Nhap ma nhan vien: ";
	cin >> sMaNV;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nhap ho ten nhan vien: ";
	getline(cin, sHoTen);
	cout << "Nhap ngay sinh nhan vien: ";
	NgaySinh.NhapDate();
	cout << "Nhap so san pham da gia cong: ";
	cin >> iSoSanPham;
	cout << "Nhap don gia mot san pham: ";
	cin >> iGiaSanPham;
}
// Hàm xuất nhân viên
void cNhanVienSX::XuatNhanVien() {
	cout << "Ma nhan vien: " << sMaNV;
	cout << "\nHo ten nhan vien: " << sHoTen;
	cout << "\nNgay sinh: ";
	NgaySinh.XuatDate();
	cout << "\nSo san pham da gia cong: " << iSoSanPham;
	cout << "\nDon gia mot san pham: " << iGiaSanPham;
	cout << "\nLuong: " << TinhLuong();
}
// Trả về lương của nhân viên
long long cNhanVienSX::TinhLuong() {
	return iSoSanPham * iGiaSanPham;
}
// Hàm get trả về ngày sinh của nhân viên
Date cNhanVienSX::getNgaySinh() {
	return NgaySinh;
}
// Hàm get trả về họ tên của nhân viên
string cNhanVienSX::getHoTen() {
	return sHoTen;
}