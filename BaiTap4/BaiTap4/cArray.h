#pragma once
#include <iostream>
#include <vector>
using namespace std;
class cArray
{
private:
	int iSoPhanTu;
	vector<int> aDSSoNguyen;
public:
	void MangNgauNhien(const int& n);
	void Xuat();
	int SoLanXuatHien(const int& x);
	bool KiemTraTangDan();
	int PhanTuLeNhoNhat();
	int SoNguyenToLonNhat();
	void SapXepTangDan();
};

