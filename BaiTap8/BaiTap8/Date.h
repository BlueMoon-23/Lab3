#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int Ngay, Thang, Nam;
public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& ngay);
	void NhapDate();
	bool HopLe();
	void XuatDate();
	bool LonTuoiHon(const Date& other);
};

