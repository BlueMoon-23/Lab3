#include "DSNhanVien.h"
#include <iostream>
#include <vector>
using namespace std;

// Phương thức thiết lập mặc định
DSNhanVien::DSNhanVien() {
	iSoNhanVien = 0;
}
// Phương thức thiết lập có truyền tham số
DSNhanVien::DSNhanVien(int SoLuong) {
	iSoNhanVien = SoLuong;
}
// Phương thức thiết lập sao chép
DSNhanVien::DSNhanVien(const DSNhanVien& DS) {
	iSoNhanVien = DS.iSoNhanVien;
	DanhSach = DS.DanhSach;
}
// Hàm nhập danh sách nhân viên
void DSNhanVien::NhapDanhSach() {
	do {
		cout << "Nhap so luong nhan vien (lon hon 0): ";
		cin >> iSoNhanVien;
	} while (iSoNhanVien < 0);
	for (int i = 0; i < iSoNhanVien; i++) {
		cNhanVienSX NhanVien;
		NhanVien.NhapNhanVien();
		DanhSach.push_back(NhanVien);
	}
}
// Hàm xuất danh sách nhân viên
void DSNhanVien::XuatDanhSach() {
	cout << "DANH SACH NHAN VIEN";
	for (int i = 0; i < iSoNhanVien; i++) {
		cout << "\n--------------------------------------\n";
		DanhSach[i].XuatNhanVien();
	}
}
// Trả về nhân viên có lương thấp nhất
cNhanVienSX DSNhanVien::NVLuongThapNhat() {
	int min_index = 0;
	long long LuongthapNhat = DanhSach[0].TinhLuong();
	for (int i = 1; i < iSoNhanVien; i++) {
		if (DanhSach[i].TinhLuong() < LuongthapNhat) {
			LuongthapNhat = DanhSach[i].TinhLuong();
			min_index = i;
		}
	}
	return DanhSach[min_index];
}
// Trả về tổng lương mà công ty phải trả cho các nhân viên sản xuất
long long DSNhanVien::TongLuong() {
	long long Tong = 0;
	for (int i = 0; i < iSoNhanVien; i++) {
		Tong += DanhSach[i].TinhLuong();
	}
	return Tong;
}
// Trả về nhân viên có tuổi cao nhất
cNhanVienSX DSNhanVien::NVTuoiCaoNhat() {
	int max_index = 0;
	for (int i = 1; i < iSoNhanVien; i++) {
		if (DanhSach[i].getNgaySinh().LonTuoiHon(DanhSach[max_index].getNgaySinh())) {
			max_index = i;
		}
	}
	return DanhSach[max_index];
}
// Hàm sắp xếp danh sách nhân viên tăng dần theo lương bằng giải thuật Quick Sort
void QuickSort(vector<cNhanVienSX>& DanhSach, int left, int right) {
	if (left >= right) return;
	int i = left;
	int j = right;
	long long mid = DanhSach[(i + j) / 2].TinhLuong();
	while (i < j) {
		while (DanhSach[i].TinhLuong() < mid) i++;
		while (DanhSach[j].TinhLuong() > mid) j--;
		if (i <= j) {
			swap(DanhSach[i], DanhSach[j]);
			i++;
			j--;
		}
	}
	QuickSort(DanhSach, left, j);
	QuickSort(DanhSach, i, right);
}
// Hàm gọi hàm sắp xếp danh sách nhân viên tăng dần theo lương 
void DSNhanVien::SapXepTangDan() {
	QuickSort(DanhSach, 0, iSoNhanVien - 1);
}

