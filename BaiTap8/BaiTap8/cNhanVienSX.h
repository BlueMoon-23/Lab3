#pragma once
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

class cNhanVienSX
{
private:
	string sMaNV, sHoTen;
	Date NgaySinh;
	int iSoSanPham;
	long long iGiaSanPham;
public:
	cNhanVienSX();
	cNhanVienSX(string MaNV, string Ten, Date ngaySinh, int SoLuong, long long gia);
	cNhanVienSX(const cNhanVienSX& NhanVien);
	void NhapNhanVien();
	void XuatNhanVien();
	long long TinhLuong();
	Date getNgaySinh();
	string getHoTen();
};

