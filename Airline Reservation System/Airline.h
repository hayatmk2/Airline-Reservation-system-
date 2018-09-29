#pragma once
#include <string>
#include <time.h>
#include <ctime>


namespace  AirlineReservationSystem {
	 class Passenger 
	{
	

	public:
		//CONSTRACTOR
		Passenger() = default;
		Passenger(const std::string& firstName, const std::string& lastName, int passportNumber, int dateOfBirth);

		void display() const;
		//void book(); // book flight for each customer
		const std::string& getFirstName()const;
		void setFirstName(const std::string& firstName);

		const std::string& getLastName()const;
		void setLastName(const std::string& lastName);

		int getDateOfBirth() const;
		void setDateOfBirth(int dateOfBirth);

		int getPassportNumber() const;
		void setPassportNumber(int passportNumber);

		bool isBooked() const;

		/*int getPhoneNumber() const;
		void setPhoneNumber(int phoneNumber);*/


	private:
		std::string mFirstName;
		std::string mLastName;
		int mDateOfBirth;
		int mPassportNumber;
		int mPhoneNumber;
		bool mBooked;


	};
class Flight 
	{

	
	public:
		Flight() = default;
		Flight(const std::string& startingFrom, const std::string& to);

		int getFlightNumber() const;
		void setflightNumber(int flightNumber);
		int getDeparturTime();
		void setDeparturTime(int departureTime);
		int getArrivalTime();
		void setArrivalTime(int arrivalTime);
		const std::string& getStartingFrom() const;
		void setStartingFrom(const std::string& startingFrom);
		const std::string& getTo() const;
		void setTo(const std::string& to);
		void displayFlight() const;
		void addFlight();
		void cancleFlight();
		void resSeat();
		bool isFlightBooked() const;
	private:

		int mFlightNumber= -1;
		int  mSeats;
		std::string mStartingFrom;
		std::string mTo;
		int mDeparture = time(0);
		int mArrival;
		bool mFlightBooked=false;

	};	
	
}