#pragma once
#include <iostream>
#include <vector>
#include "Airline.h"

namespace AirlineReservationSystem {

	const int kFirstTicketNumber = 20180000;
	const int KfirstAvailableFlight = 1;
	class Database
	{
	public:

		Passenger& addPassenger(const std::string& FirstName,
			const std::string& LastName,
			const std::string& PhoneNumber,
			int passportNumber, int FlightNumber);
		Passenger& getPassenger(int PassportNumber, int FlightNumber);
		Passenger& getPassenger(const std::string& FirstName,
			const std::string& LastName,
			const std::string& PhoneNumber);

		Flight& addFlight(int FlightNumber, const std::string& departureTime, const std::string& arrivalTime,
			const std::string& startingFrom, const std::string& mto, const std::string& FlightDate, const std::string& FlightName, double NewCost);
		Flight& getFlight(int FlightNumber);
		Flight& getFlight(const std::string& startingFrom, const std::string& mto, const std::string& FlightDate);

		void displayAllPassenger() const;
		void Displaybooked() const;
		void flightcanceled() const;

		void DisplayFlight() const;
		void DeletedFlight() const;
		void displayAllFlight() const;


	private:
		std::vector<Passenger> mPassengers;
		std::vector<Flight> mFlights;
		int mNextTicketNumber = kFirstTicketNumber;
		int mNextAvailableFlight = KfirstAvailableFlight;


	};
}