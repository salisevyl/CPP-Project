#pragma once
#include <iostream>
#include <vector>

class EventLocation {
private:
    std::vector<int>* maxSeats;
    std::vector<int>* numRows;
    const int numZones;
    static int seatsPerRow;

public:
    EventLocation();
    EventLocation(const std::vector<int>& seats, const std::vector<int>& rows);

    void setMaxSeats(const std::vector<int>& seats);
    void setNumRows(const std::vector<int>& rows);
    std::vector<int> getMaxSeats() const;
    std::vector<int> getNumRows() const;

    int calculateTotalSeats() const;
    void displayLocationDetails() const;

    friend std::ostream& operator<<(std::ostream& os, const EventLocation& location);
    EventLocation operator+(const EventLocation& other) const;

};


