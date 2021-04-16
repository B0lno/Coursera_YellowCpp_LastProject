#pragma once

#include <string>
#include <ostream>
#include <istream>

class Event {
public:
	std::string GetEventName() const;
	size_t GetEventNum() const;

	Event(const std::string name, const size_t num);
	Event(const std::string name);
	Event();

private:
	std::string event_name;
	size_t event_num;
};

bool operator<(const Event& lhs, const Event& rhs);
bool operator==(const Event& lhs, const Event& rhs);

std::ostream& operator<<(std::ostream& stream, const Event& event);

std::string ParseEvent(std::istream& stream);