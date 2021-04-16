#include "database.h"
#include "date.h"
#include "event.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

int main() {
  try {
    Database db;

    
    for (string line; getline(cin, line); ) {

    	istringstream is(line);

      string command;
      is >> command;
      if (command == "Add") {

      	const auto date  = ParseDate(is);
      	const auto event = ParseEvent(is); 
        db.AddEvent(date, event);

      } else if (command == "Del") {

        string event;
        if (!is.eof()) {
          is >> event;
        }
        const Date date = ParseDate(is);
        if (event.empty()) {
          const int count = db.DeleteDate(date);
          cout << "Deleted " << count << " events" << endl;
        } else {
          if (db.DeleteEvent(date, event)) {
            cout << "Deleted successfully" << endl;
          } else {
            cout << "Event not found" << endl;
          }
        }

      } else if (command == "Find") {

        const Date date = ParseDate(is);
        for (const string& event : db.Find(date)) {
          cout << event << endl;
        }

      } else if (command == "Last") {

      	cout << db.Last(ParseDate(is)) << endl;

      } else if (command == "Print") {

        db.Print();

      } else if (!command.empty()) {

        throw logic_error("Unknown command: " + command);

      }
    }
  } catch (const exception& e) {
    cout << e.what() << endl;
  }

	return 0;
}