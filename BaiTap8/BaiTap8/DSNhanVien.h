#pragma once
#include "cNhanVienSX.h"
#include <iostream>
#include <vector>
using namespace std;

class DSNhanVien
{
private:
	int iSoNhanVien;
	vector<cNhanVienSX> DanhSach;
public:
	DSNhanVien();
	DSNhanVien(int SoLuong);
	DSNhanVien(const DSNhanVien& DS);
	void NhapDanhSach();
	void XuatDanhSach();
	cNhanVienSX NVLuongThapNhat();
	long long TongLuong();
	cNhanVienSX NVTuoiCaoNhat();
	void SapXepTangDan();
};

