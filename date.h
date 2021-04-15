#pragma once

#include <string>

class Date {
public: 

	Date(std::string new_date) :
		date(new_date)
	{}

private:
	std::string date;
};