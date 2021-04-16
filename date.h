#pragma once 

#include <ostream>
#include <istream>
#include <string>

class Date {
public:
  // конструктор выбрасывает исключение, если его аргументы некорректны
  Date(int new_year, int new_month, int new_day);
  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;

private:
  int year;
  int month;
  int day;
};

// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

// даты будут по умолчанию выводиться в нужном формате
std::ostream& operator<<(std::ostream& stream, const Date& date);

Date ParseDate(std::istream& is);


std::string to_string(const Date& date);