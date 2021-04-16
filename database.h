#pragma once

#include "date.h"
#include "event.h"

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
  std::string Last(const Date& date) const;

private:
  std::map<Date, std::set<Event>> storage;
  size_t add_event_count;
};

