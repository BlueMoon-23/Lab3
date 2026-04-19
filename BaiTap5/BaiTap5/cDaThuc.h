#pragma once
#include <iostream>
#include <vector>
using namespace std;

class cDaThuc
{
private:
	int iBac;
	vector<double> aDSHeSo;
public:
	cDaThuc(int Bac = 0);
	double TinhGiaTri(const double& x);
	void Nhap();
	void Xuat();
	cDaThuc Cong(cDaThuc& other);
	cDaThuc Tru(cDaThuc& other);
};

