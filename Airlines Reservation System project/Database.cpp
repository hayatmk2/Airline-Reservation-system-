#include "pch.h"
#include "Database.h"
#include <iostream>
#include <stdexcept>


using namespace std;

namespace AirlineReservationSystem {

	Passenger& Database::addPassenger(const std::string& FirstName,
		const std::string& LastName, const std::string& PhoneNumber, int passportNumber, int FlightNumber)

	{
		Passenger thePassenger(FirstName, LastName, PhoneNumber, passportNumber, FlightNumber);
		thePassenger.setTicketNumber(mNextTicketNumber++);
		thePassenger.isBooked();
		mPassengers.push_back(thePassenger);

		return mPassengers[mPassengers.size() - 1];
	}

	Passenger& Database::getPassenger(int passportNumber,int flightNumber)
	{
		for (auto& passenger : mPassengers) {
			if (passenger.getPassportNumber() == passportNumber && passenger.getFlightNumber() == flightNumber) {
				return passenger;
			}
		}
		throw logic_error("No passenger Found");
	}
	Passenger& Database::getPassenger(const std::string& FirstName,
		const std::string& LastName,
		const std::string& PhoneNumber)
	{
		for (auto& passenger : mPassengers) {
			if (passenger.getFirstName() == FirstName &&
				passenger.getLastName() == LastName &&
				passenger.getPhoneNumber() == PhoneNumber) {
				return passenger;
			}
		}
		throw logic_error("No passenger Found");
	}
	void Database::displayAllPassenger() const {
		for (auto& passenger : mPassengers) {
			passenger.display();
		}
	}

	void Database::Displaybooked() const {
		for (auto& passenger : mPassengers) {
			if (passenger.isBooked())
				passenger.display();
		}
	}

	void Database::flightcanceled() const {
		for (const auto& passenger : mPassengers) {
			if (!passenger.isBooked())
				passenger.display();
		}
	}

	Flight& Database::addFlight(int FlightNumber, const std::string& departureTime, const std::string& arrivalTime,
		const string& startingFrom, const std::string& to, const std::string& FlightDate, const std::string& FlightName, double NewCost)
	{
		Flight theFlght(FlightNumber, departureTime, arrivalTime, startingFrom, to, FlightDate, FlightName, NewCost);
		theFlght.setFlightAvailable(mNextAvailableFlight++);
		theFlght.record();
		mFlights.push_back(theFlght);

		return mFlights[mFlights.size() - 1];
	}

	Flight& Database::getFlight(int FlightNumber) {

		for (auto& flight : mFlights) {
			if (flight.getFlightNumber() == FlightNumber) {
				return flight;
			}
		}
		throw logic_error("No Flight Found");

	}

	void Database::displayAllFlight() const {
		for (auto& flight : mFlights) {
			flight.FlightRecord();
		}

	}
	void Database::DisplayFlight() const
	{
		for (auto& flight : mFlights) {
			if (flight.isrecorded())
				flight.FlightRecord();
		}
	}
	void Database::DeletedFlight() const
	{
		for (auto& flight : mFlights) {
			if (!flight.isrecorded())
				flight.FlightRecord();
		}
	}
	Flight& Database::getFlight(const std::string& startingFrom, const std::string& mto, const std::string& FlightDate)
	{
		for (auto& flight : mFlights) {
			if (flight.getStartingFrom() == startingFrom &&
				flight.getTo() == mto &&
				flight.getFlightDate() == FlightDate) {
				return flight;
			}
		}
		throw logic_error(" No Flight Found!!");
	}

}