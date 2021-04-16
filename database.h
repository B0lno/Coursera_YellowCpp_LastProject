#pragma once

#include "date.h"

#include <string>
#include <set>
#include <map>
#include <sstream>

class Database {
public:
  void AddEvent(const Date& date, const std::string& event);
  bool DeleteEvent(const Date& date, const std::string& event);
  int DeleteDate(const Date& date);

  std::set<std::string> Find(const Date& date) const;

  void Print() const;

private:
  std::map<Date, std::set<std::string>> storage;
};