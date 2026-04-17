#pragma once
#include <iostream>
#include <vector>
#include "Diem.h"
using namespace std;

class cDaGiac
{
private:
	int iSoDinh;
	vector<Diem> aDSDiem;
public:
	cDaGiac();
	cDaGiac(int SoDinh);
	cDaGiac(const cDaGiac& A);
	void Nhap();
	void Xuat();
	void KiemTra();
	double ChuVi();
	double DienTich();
	void TinhTien(const Diem& Vector);
	void Quay(const double& GocQuay);
	void PhongTo(const double& TyLe);
	void ThuNho(const double& TyLe);
};

