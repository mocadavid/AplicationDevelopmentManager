#include "Subject.h"

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::registerObserver(Observer* observer) {
	this->observers.push_back(observer);
}

void Subject::unregisterObserver(Observer* observer) {
	this->observers.erase(find(this->observers.begin(), this->observers.end(), observer));
}

void Subject::notify() {
	for (auto observer : this->observers) {
		observer->update();
	}
}