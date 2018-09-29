#include "pch.h"
#include <iostream>
#include <string>
#include "Airline.h"
#include <time.h>
#include <ctime>

using namespace std;

namespace AirlineReservationSystem {

	Passenger::Passenger(const std::string& firstName, const std::string& lastName, int passportNumber, int dateOfBirth) :
		mFirstName(firstName), mLastName(lastName), mPassportNumber(passportNumber), mDateOfBirth(dateOfBirth) {

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
	void Passenger::setDateOfBirth(int dateOfBirth) {
		mDateOfBirth = dateOfBirth;
	}
	int Passenger::getPassportNumber() const {
		return mPassportNumber;
	}
	void Passenger::setPassportNumber(int passportNumber) {
		mPassportNumber = passportNumber;
	}
	bool Passenger::isBooked()const {
		return mBooked;
	}
	void Passenger::display() const
	{
		cout << "Passenger Information" << endl;
		cout << "-------------------------" << endl;
		cout << "Passenger: " << getLastName() << ", " << getFirstName() << endl;
		cout << (isBooked() ? "Currently booked Passenger" : "Not Booked passenger ") << endl;
		cout << "Passport Number: " << getPassportNumber() << endl;
		cout << "Date Of Birth: " << getDateOfBirth() << endl;
		cout << endl;
	}

	Flight::Flight(const std::string& to, const std::string& startingFrom):
		mTo(to), mStartingFrom(startingFrom) {

	}

	int Flight::getFlightNumber() const {
		return mFlightNumber;
	}
	void Flight::setflightNumber(int flightNumber) {
		mFlightNumber = flightNumber;
	}
	int Flight::getDeparturTime(){
		//time_t now = time(0);
		//char* dt = ctime(&now);
		return mDeparture;
	}
	void Flight::setDeparturTime(int departureTime) {
		mDeparture = departureTime;
	}
	int Flight::getArrivalTime() {
		//time_t now = time(0);
		//char* ar = ctime(&now);
		return mArrival;
	}
	void Flight::setArrivalTime(int arrivalTime) {
		mArrival= arrivalTime;
	}
	const std::string& Flight::getStartingFrom() const {
		return mStartingFrom;
	}
	void Flight::setStartingFrom(const string& startingFrom) {
		mStartingFrom = startingFrom;
	}
	const std::string& Flight::getTo()const {
		return mTo;
	}
	void Flight::setTo(const string& mto) {
		mTo = mto;
	}
	void Flight::addFlight() {

	}
	void Flight::cancleFlight() {

	}
	void Flight::resSeat() {

	}
	bool Flight::isFlightBooked()const {
		return mFlightBooked;
	}
	void Flight::displayFlight() const
	{
		cout << "Flight Information" << endl;
		cout << "-------------------------" << endl;
		cout << "Flight Number: " << getFlightNumber() <<"," << endl;
		cout << "Locations: starting from " << getStartingFrom() << "To:" << getTo() << endl;
		cout << (isFlightBooked() ? "Currently booked flight" : "Not Booked flight ") << endl;
		cout << "Departure Time: " << mDeparture <<  "Arrival Time: " << mArrival << endl;
		cout << endl;
		

	}
}
