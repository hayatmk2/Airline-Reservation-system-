#include "pch.h"
#include <iostream>
#include <stdexcept>
#include "Database.h"
#include "Airline.h"

using namespace std;


namespace AirlineReservationSystem {
	Flight& DatatbaseFlight::addFlight(const std::string& startingFrom, const std::string& to)
	{
		Flight theFlight(startingFrom, to);
		theFlight.setflightNumber(mNextFlightNumber++);
		theFlight.isFlightBooked();
		mFlight.push_back(theFlight);
		return mFlight[mFlight.size() - 1];
	}
	Flight& DatatbaseFlight::getFlight(int flightNumber) {
		for (auto& flight : mFlight) {
			if (flight.getFlightNumber() == flightNumber) {
				return flight;
			}
		}
		throw logic_error("No flight found.");

	}
	Flight& DatatbaseFlight::getFlight(const string& startingFrom, const string& mto) {
		for (auto& flight : mFlight) {
			if (flight.getStartingFrom() == startingFrom && flight.getTo() == mto) {
				return flight;
			}
		}
		throw logic_error("No flight found.");
	}
	/*Flight& Database::resSeat(int mSeats) {
		for()
	}*/
	void DatatbaseFlight::displayAllFlight() const
	{
		for (const auto& flight : mFlight) {
			flight.displayFlight();
		}
	}
	void DatatbaseFlight::displayCurrentFlight() const
	{
		for (const auto& flight : mFlight)
		{
			if (flight.isFlightBooked())
				flight.displayFlight();
		}
	}
	void DatatbaseFlight::displayFormerFlight()const {
		for (const auto& flight : mFlight) {
			if (!flight.isFlightBooked())
				flight.displayFlight();
		}
	}

	Passenger& Database::addPassenger(const string& firstName,
		const string& lastName, int passportNumber, int dateOfBirth)
	{
		Passenger thePassenger(firstName, lastName, passportNumber, dateOfBirth);
		thePassenger.isBooked();

		mPassenger.push_back(thePassenger);

		return mPassenger[mPassenger.size() - 1];
	}

	Passenger& Database::getPassenger(int PassportNumber) {

		for (auto& passenger : mPassenger) {
			if (passenger.getPassportNumber() == PassportNumber) {
				return passenger;
			}
		}
		throw logic_error("No passenger found.");
	}
	Passenger& Database::getPassenger(const string& firstName, const string& lastName) {
		for (auto& passenger : mPassenger) {
			if (passenger.getFirstName() == firstName && passenger.getLastName() == lastName) {
				return passenger;
			}
		}
		throw logic_error("No Passenger found.");
	}
	void Database::displayAll() const
	{
		for (const auto& passenger : mPassenger) {
			passenger.display();
		}
	}
	void Database::displayCurrent() const
	{
		for (const auto& passenger : mPassenger) {
			if (passenger.isBooked())
				passenger.display();
		}
	}

	void Database::displayFormer() const
	{
		for (const auto& passenger : mPassenger) {
			if (!passenger.isBooked())
				passenger.display();
		}
	}

	
}
	