#include "EventLocation.h"

int EventLocation::seatsPerRow = 10;

EventLocation::EventLocation() : numZones(3) {
    maxSeats = new std::vector<int>;
    numRows = new std::vector<int>;
}

EventLocation::EventLocation(const std::vector<int>& seats, const std::vector<int>& rows)
    : numZones(3), maxSeats(new std::vector<int>(seats)), numRows(new std::vector<int>(rows)) {}

void EventLocation::setMaxSeats(const std::vector<int>& seats) {
    *maxSeats = seats;
}

void EventLocation::setNumRows(const std::vector<int>& rows) {
    *numRows = rows;
}

std::vector<int> EventLocation::getMaxSeats() const {
    return *maxSeats;
}

std::vector<int> EventLocation::getNumRows() const {
    return *numRows;
}

int EventLocation::calculateTotalSeats() const {
    int totalSeats = 0;
    for (size_t i = 0; i < maxSeats->size(); ++i) {
        totalSeats += (*maxSeats)[i] * (*numRows)[i];
    }
    return totalSeats;
}

void EventLocation::displayLocationDetails() const {
    std::cout << "Maximum Seats per Zone: " << *maxSeats << std::endl;
    std::cout << "Number of Rows per Zone: " << *numRows << std::endl;
}

std::ostream& operator<<(std::ostream& os, const EventLocation& location) {
    os << "Maximum Seats per Zone: " << *location.maxSeats << std::endl;
    os << "Number of Rows per Zone: " << *location.numRows << std::endl;
    return os;
}

EventLocation EventLocation::operator+(const EventLocation& other) const {
    EventLocation result;
    result.maxSeats = new std::vector<int>(*maxSeats);
    result.numRows = new std::vector<int>(*numRows);
    for (size_t i = 0; i < maxSeats->size(); ++i) {
        (*result.maxSeats)[i] += (*other.maxSeats)[i];
        (*result.numRows)[i] += (*other.numRows)[i];
    }
    return result;
}
