#include "Timestamp.h"
#include <iostream>
#include <iomanip>
using namespace std; 

Timestamp::Timestamp(int year,int month, int day, int hour, int minute, int second) {
	selector = DAY;
	this->month = month;
	this->day = day; 
	this->year = year;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

void Timestamp::select(Selector selector) {
	this->selector = selector;
}

ostream &operator<<(ostream& o, const Timestamp& timestamp) {
	o << (timestamp.year >= 10 ? "" : "0") << timestamp.year << "-" << (timestamp.month >= 10 ? "" : "0") << timestamp.month << "-" << 
		(timestamp.day >= 10 ? "" : "0") << timestamp.day << " " <<
		(timestamp.hour >= 10 ? "" : "0") <<timestamp.hour << ":" << (timestamp.minute >= 10 ? "" : "0") << timestamp.minute << ":" << 
		(timestamp.second >= 10 ? "" : "0")<< timestamp.second;
	return o; 
}

Timestamp& Timestamp::operator++() {
	switch (selector) {
		case 0:
			month++;
			break;

		case 1:
			day++;
			break;

		case 2:
			year++;
			break;
		

		case 3:
			hour++;
			break;

		case 4:
			minute++;
			break;

		case 5:
			second++;
			break;
	}
	validacionHora();
	validacionDias(this->month);
	return *this;
}

Timestamp Timestamp::operator--() {
	switch (selector) {
		case 0:
			month--;
			break;

		case 1:
			day--;
			break;

		case 2:
			year--;
			break;


		case 3:
			hour--;
			break;

		case 4:
			minute--;
			break;

		case 5:
			second--;
			break;
	}
	validacionHora();
	validacionDias(this->month);
	return *this;
}

Timestamp Timestamp::operator--(int) {
	switch (selector) {
		case 0:
			--month;
			break;

		case 1:
			--day;
			break;

		case 2:
			--year;
			break;

		case 3:
			--hour;
			break;

		case 4:
			--minute;
			break;

		case 5:
			--second;
			break;
	}
	validacionHora();
	validacionDias(this->month);
	return *this;
}

Timestamp& Timestamp::operator++(int) {
	switch (selector) {
		case 0:
			++month;
			break;

		case 1:
			++day;
			break;

		case 2:
			++year;
			break;


		case 3:
			++hour;
			break;

		case 4:
			++minute;
			break;

		case 5:
			++second;
			break;
	}
	validacionHora();
	validacionDias(this->month); 
	return *this;
}

Timestamp operator-(const Timestamp& timestamp1, const Timestamp& timestamp2) {
	int days, months, years, hours, minutes, seconds; 
	days = timestamp1.day - timestamp2.day;
	months = timestamp1.month - timestamp2.month;
	hours = timestamp1.hour - timestamp2.hour;
	minutes = timestamp1.minute - timestamp2.minute;
	seconds = timestamp1.second - timestamp2.second;

	if (timestamp1.year > timestamp2.year) {
		years = timestamp1.year - timestamp2.year;
	}
	else {
		years = timestamp2.year - timestamp1.year;
	}
	
	if (seconds < 0) {
		minutes--;
		seconds = 59;
	}

	 if (minutes < 0) {
		 hours--;
		minutes = 59;
	}

	 if (hours < 0) {
		 days--;
		hours = 24;
	}
	Timestamp timestamp3(years, months, days, hours, minutes, seconds);
	return timestamp3;

}

void Timestamp::validacionHora() {
	if (hour > 24) {
		hour = 0;
		day++;
		
	}
	else if (hour < 1) {
		hour = 24;
		day--; 
	}
	else if (minute >= 59) {
		minute = 0;
		hour++;
	}
	else if (second >= 59) {
		second = 0;
		minute++;
	}
}

void Timestamp::validacionDias(int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10, month == 12) {
		if (day >= 31) {
			day = 1; 
		}
		else if (day < 1 ) {
			day = 31;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day >= 30) {
			day = 1;
		}
		else if (day < 1) {
			day = 30;
		}
	}
	else if (month == 2) {
		if (day >= 28) {
			day = 1;
		}
		else if (day < 1) {
			day = 28;
		}
	}
}