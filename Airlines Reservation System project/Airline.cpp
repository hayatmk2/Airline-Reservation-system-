#include "pch.h"
#include <iostream>
#include <string>
#include "Airline.h"

using namespace std;

namespace AirlineReservationSystem {

	Passenger::Passenger(const std::string& FirstName, const std::string& LastName, const std::string& PhoneNumber, int passprtNumber, int FlightNumber) :
		mFirstName(FirstName), mLastName(LastName), mPassportNumber(passprtNumber), mPhoneNumber(PhoneNumber), mFlightNumber(FlightNumber) {

	}
	int Passenger::getFlightNumber() const {
		return mFlightNumber;
	}
	void Passenger::setflightNumber(int FlightNumber) {
		mFlightNumber = FlightNumber;
	}


	int Passenger::getTicketNumber() const {
		return mTicketNumber;
	}
	void Passenger::setTicketNumber(int TicketNumber) {
		mTicketNumber = TicketNumber;
	}
	const std::string& Passenger::getFirstName() const {
		return mFirstName;
	}
	void Passenger::setFirstName(const string& firstName) {
		mFirstName = firstName;
	}
	const std::string& Passenger::getLastName() const {
		return mLastName;
	}
	void Passenger::setLastName(const string& lastName) {
		mFirstName = lastName;
	}
	int Passenger::getDateOfBirth() const {
		return mDateOfBirth;
	}
	const std::string& Passenger::getAddress() const {
		return mAddress;

	}
	void Passenger::setAddress(const std::string& Address) {
		mAddress = Address;
	}
	void Passenger::setDateOfBirth(int dateOfBirth) {
		mDateOfBirth = dateOfBirth;
	}
	int Passenger::getPassportNumber() const {
		return mPassportNumber;
	}
	void Passenger::setPassportNumber(int passportNumber) {
		mPassportNumber = passportNumber;
	}
	const std::string& Passenger::getPhoneNumber() const {
		return mPhoneNumber;

	}
	void Passenger::setPhoneNumber(const std::string& PhoneNumber) {
		mPhoneNumber = PhoneNumber;
	}
	bool Passenger::isBooked()const {
		return mBooked;
	}
	void Passenger::booked()
	{
		mBooked = true;
	}
	void Passenger::CancelFlight()
	{
		mBooked = false;
	}

	void Passenger::display() const {

		cout << "-----------------Selam Airline Services---------------" << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "\nPassenger  : " << getFirstName() << ", " << getLastName() << "            " << "ticket : " << getTicketNumber() << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "Flight Number" << getFlightNumber() << endl;
		//	cout << "date of Flight" << getDateOfFlight << endl;
		//	cout << "From" << getorginalLocation() << endl;
		//	cout << "To" << getdestination() << endl;
		//	cout << "Departure Time" << getDeparturetime << endl;
		//	cout << "Arival Time" << getArivalTime() << endl;

		cout << (isBooked() ? "Booked" : "Canceled") << endl;
		cout << "Passport Number: " << getPassportNumber() << endl;
		cout << "Flight Number: " << getFlightNumber() << endl;
		cout << "=======================================================" << endl;
		cout << "--------- Thank you for using our service -------------" << endl;
		cout << "=======================================================" << endl;
		cout << endl;


	};


	Flight::Flight(int FlightNumber, const std::string& departureTime, const std::string& arrivalTime,
		const std::string& startingFrom, const std::string& to, const std::string& FlightDate, const std::string& FlightName, double NewCost) :
		mFlightNumber(FlightNumber), mDeparture(departureTime), mArrival(arrivalTime), mStartingFrom(startingFrom), mTo(to), mFlightDate(FlightDate), mFlightName(FlightName), mCost(NewCost) {

	}
	int Flight::getFlightAvailable() const {
		return mFlightAvailable;
	}
	void Flight::setFlightAvailable(int FlightAvailable) {
		mFlightAvailable = FlightAvailable;
	}

	int Flight::getFlightNumber() const {
		return mFlightNumber;
	}
	void Flight::setflightNumber(int FlightNumber) {
		mFlightNumber = FlightNumber;
	}
	const std::string& Flight::getDeparturTime() const {
		return mDeparture;
	}
	void Flight::setDeparturTime(const std::string& departureTime) {
		mDeparture = departureTime;
	}
	const std::string& Flight::getArrivalTime() const {
		return mArrival;
	}
	void Flight::setArrivalTime(const std::string& arrivalTime) {
		mArrival = arrivalTime;
	}
	const std::string& Flight::getStartingFrom() const {
		return mStartingFrom;
	}
	void Flight::setStartingFrom(const string& startingFrom) {
		mStartingFrom = startingFrom;
	}
	const std::string& Flight::getFlightDate() const {
		return mFlightDate;
	}
	void Flight::setFlightDate(const string& FlightDate) {
		mFlightDate = FlightDate;
	}
	const std::string& Flight::getFlightName() const {
		return mFlightName;
	}
	void Flight::setFlightName(const string& FlightName) {
		mFlightName = FlightName;
	}
	const std::string& Flight::getTo()const {
		return mTo;
	}
	void Flight::setTo(const string& to) {
		mTo = to;
	}
	double Flight::getCost() const {
		return mCost;
	}
	void Flight::setCost(double NewCost) {
		mCost = NewCost;
	}

	void Flight::deleteRecord() {
		mrecorded = false;

	}
	void Flight::record() {
		mrecorded = true;


	}

	bool Flight::isrecorded()const {
		return mrecorded;
	}
	void Flight::FlightRecord() const {

		cout << "===========================================================================================\n" << endl;
		cout << "==========================  Available Flight  : " << getFlightAvailable() << "  ========================================\n" << endl;


		cout << " Flight Name : " << getFlightName() << "    " << " Flight Number : " << getFlightNumber() << "    " << " Departur Time : " << getDeparturTime() << "   " << " Arrival Time  : " << getArrivalTime() << "    " << endl;
		cout << endl;
		cout << " Starting From  : " << getStartingFrom() << "    " << "  To  : " << getTo() << "    " << " Flight Date  : " << getFlightDate() << "    " << "Cost  : " << getCost() << endl;



		cout << endl;


	};
}