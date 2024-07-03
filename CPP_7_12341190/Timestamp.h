#pragma once
#include <iostream>
using namespace std; 

class Timestamp {
public:
	enum Selector {MONTH,DAY,YEAR,HOUR,MINUTE,SECOND};
	Selector selector;
	unsigned int year, month, day, hour, minute, second;
	
	Timestamp(int year = 1900, int month = 1, int day = 1,int hour = 0, int minute = 0, int second = 0);
	Timestamp& operator++();
	Timestamp& operator++(int);
	Timestamp operator--();
	Timestamp operator--(int);
	friend ostream& operator<<(ostream& o, const Timestamp& timestamp);
	friend int main();
	void select(Selector selector);
	friend Timestamp operator-(const Timestamp& timestamp1, const Timestamp& timestamp2);
	void validacionHora();
	void validacionDias(int month);
};