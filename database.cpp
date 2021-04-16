#include "database.h"
#include "date.h"

#include <iostream>
#include <algorithm>

using namespace std;

void Database::AddEvent(const Date& date, const string& event) {
  storage[date].insert(Event(event, add_event_count));
  add_event_count++;
}

bool Database::DeleteEvent(const Date& date, const string& event) {
  if (storage.count(date) > 0 && storage[date].count(Event(event)) > 0) {
    storage[date].erase(Event(event));
    return true;
  }
  return false;
}

int Database::DeleteDate(const Date& date) {
  if (storage.count(date) == 0) {
    return 0;
  } else {
    const int event_count = storage[date].size();
    storage.erase(date);
    return event_count;
  }
}

set<string> Database::Find(const Date& date) const {
  if (storage.count(date) > 0) {
    set<string> ret;

    for (auto it : storage.at(date))
      ret.insert(it.GetEventName());
    return ret;
  } else {
    return {};
  }
}

void Database::Print() const {
  for (const auto& item : storage) {
    for (const Event& event : item.second) {
      cout << item.first << " " << event << endl;
    }
  }
}

void Database::Last(const Date& date) const {
  auto last_event_it = storage.upper_bound(date);

  if (storage.size() == 0 || (last_event_it == storage.begin()))
    cout << "No entries" << endl;
  else {
    --last_event_it;
    cout << last_event_it->first << " " << *last_event_it->second.rbegin() << endl;
  }
}
