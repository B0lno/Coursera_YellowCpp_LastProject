#include "event.h"

using namespace std;

string Event::GetEventName() const {
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

ostream& operator<<(ostream& stream, const Event& event) {
	stream << event.GetEventName();

	return stream;
}

Event::Event(const string name, const size_t num) :
	event_name(name),
	event_num(num)
{}

Event::Event(const string name) :
	event_name(name),
	event_num(0)
{}

Event::Event() :
	event_name(""),
	event_num(0)
{}

string ParseEvent(istream& stream) {
	string ret;

	stream.ignore(1);
	getline(stream, ret);

	return ret;
}