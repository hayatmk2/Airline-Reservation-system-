#pragma once
#include <iostream>
#include <vector>
#include "Airline.h"

namespace AirlineReservationSystem {
	const int KFlightNumber = 1000;

	class Database
	{
	public:
		Passenger& addPassenger(const std::string& firstName,
			const std::string& lastName, int passportNumber, int dateOfBirth);
		Passenger& getPassenger(int passportNumber);
		Passenger& getPassenger(const std::string& firstName,
			const std::string& lastName);

		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

	private:
		std::vector<Passenger> mPassenger;

	};

	class DatatbaseFlight
	{
	public:
		Flight& addFlight(const std::string& startingFrom, const std::string& to);
		Flight& getFlight(int flightNumber);
		Flight& getFlight(const std::string& startingFrom, const std::string& mto);
		//Flight& resSeat(int mSeat);


		void displayAllFlight() const;
		void displayCurrentFlight() const;
		void displayFormerFlight()const;

	private:

		std::vector<Flight> mFlight;
		int mNextFlightNumber = KFlightNumber;

	};
	

}


