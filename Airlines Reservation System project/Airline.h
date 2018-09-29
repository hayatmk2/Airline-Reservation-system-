#pragma once
#include <string>
#include <time.h>


namespace  AirlineReservationSystem {
	class Passenger
	{

	public:
		//CONSTRACTOR
		Passenger() = default;
		Passenger(const std::string& FirstName, const std::string& LastName, const std::string& PhoneNumber, int passprtNumber, int FlightNumber);


		int getFlightNumber() const;
		void setflightNumber(int FlightNumber);

		int getTicketNumber() const;
		void setTicketNumber(int TicketNumber);

		const std::string& getFirstName() const;
		void setFirstName(const std::string& FirstName);

		const std::string& getLastName()const;
		void setLastName(const std::string& LastName);

		int getDateOfBirth() const;
		void setDateOfBirth(int dateOfBirth);

		const std::string& getAddress() const;
		void setAddress(const std::string& Address);

		int getPassportNumber() const;
		void setPassportNumber(int passportNumber);

		const std::string& getPhoneNumber() const;
		void setPhoneNumber(const std::string& PhoneNumber);

		bool isBooked() const;

		void booked();
		void CancelFlight();
		void display() const;

	private:
		int mTicketNumber;
		std::string mFirstName;
		std::string mLastName;
		int mDateOfBirth;
		std::string mAddress;
		int mPassportNumber;
		std::string mPhoneNumber;
		bool mBooked = true;
		int mFlightNumber;



	};


	class Flight
	{

	public:
		Flight() = default;
		Flight(int FlightNumber, const std::string& departureTime, const std::string& arrivalTime,
			const std::string& startingFrom, const std::string& to, const std::string& FlightDate, const std::string& FlightName, double NewCost);


		int getFlightAvailable() const;
		void setFlightAvailable(int FlightAvailable);

		int getFlightNumber() const;
		void setflightNumber(int FlightNumber);

		const std::string& getDeparturTime() const;
		void setDeparturTime(const std::string& departureTime);

		const std::string& getArrivalTime() const;
		void setArrivalTime(const std::string& arrivalTime);

		const std::string& getStartingFrom() const;
		void setStartingFrom(const std::string& startingFrom);

		const std::string& getFlightDate() const;
		void setFlightDate(const std::string& FlightDate);

		const std::string& getFlightName() const;
		void setFlightName(const std::string& FlightName);

		const std::string& getTo() const;
		void setTo(const std::string& to);

		double getCost() const;
		void setCost(double NewCost);

		void deleteRecord();
		void record();
		void FlightRecord() const;
		bool isrecorded() const;
	private:


		int mFlightNumber;
		std::string mStartingFrom;
		std::string mTo;
		std::string mDeparture;
		std::string mArrival;
		bool mrecorded = false;
		std::string mFlightDate;
		std::string mFlightName;
		double mCost;
		int mFlightAvailable = -1;



	};

}