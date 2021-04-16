#include "event.h"

std::string Event::GetEventName() const {
	return event_name;
}

size_t Event::GetEventNum() const {
	return event_num;
}

bool operator<(const Event& lhs, const Event& rhs) {
	return lhs.GetEventNum() < rhs.GetEventNum();
}

bool operator==(const Event& lhs, const Event& rhs) {
	return lhs.GetEventName() == rhs.GetEventName();
}

std::ostream& operator<<(std::ostream& stream, const Event& event) {
	stream << event.GetEventName();

	return stream;
}

Event::Event(const std::string name, const size_t num) :
	event_name(name),
	event_num(num)
{}

Event::Event(const std::string name) :
	event_name(name),
	event_num(0)
{}

Event::Event() :
	event_name(""),
	event_num(0)
{}
