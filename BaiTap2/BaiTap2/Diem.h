#pragma once
class Diem
{
private:
	double x;
	double y;
public:
	Diem();
	Diem(double a, double b);
	Diem(const Diem& A);
	void Nhap();
	void Xuat();
	double ToaDoX();
	double ToaDoY();
	double DoDai(const Diem& other);
	void TinhTien(const Diem& vector);
	void Quay(const double& GocQuay);
	void PhongTo(const Diem& Tam, const double& TyLe);
	void ThuNho(const Diem& Tam, const double& TyLe);
};

