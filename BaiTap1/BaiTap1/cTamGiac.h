#pragma once
#include "Diem.h"

class cTamGiac
{
private:
	Diem DiemA, DiemB, DiemC;
public:
	cTamGiac();
	cTamGiac(Diem a, Diem b, Diem c);
	cTamGiac(const cTamGiac& A);
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

