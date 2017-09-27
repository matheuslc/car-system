#include "Event.hpp"
#include <iostream>

bool Event::operator>(const Event& e) const {
	return time > e.time;
}

bool Event::operator<(const Event& e) const {
	return time < e.time;
}

bool Event::operator==(const Event& e) const {
	return time == e.time;
}

bool Event::operator!=(const Event& e) const {
	return time != e.time;
}

bool Event::operator>=(const Event& e) const {
	return time >= e.time;
}

bool Event::operator<=(const Event& e) const {
	return time <= e.time;
}

bool Event::operator>(int i) const {
	return time > i;
}

bool Event::operator<(int i) const {
	return time < i;
}

bool Event::operator==(int i) const {
	return time == i;
}

bool Event::operator!=(int i) const {
	return time != i;
}

bool Event::operator>=(int i) const {
	return time >= i;
}

bool Event::operator<=(int i) const {
	return time <= i;
}


