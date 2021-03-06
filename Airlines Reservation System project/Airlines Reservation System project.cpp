﻿// Airline Reservation System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Database.h"
#include <Windows.h>
#include <iomanip>


using namespace std;
using namespace AirlineReservationSystem;

int Administrator(Database& db);
int displayMenu();
void doBooked(Database& db);
void RecordFlightDetail(Database& db);
void doCancelFlight(Database& db);
void doFlightDetail(Database& db);
void doDispayTicket(Database& db);

int main()

{
	SetConsoleTitle(L"AIRLINE RESERVATION");
	system("color black");
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t    WELCOME TO SELAM AIRLINE RESERVATION SYSTEM";
	Sleep(2500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t                     Presented by : Hayat";
	cout << "\n\t\                                     KAL Accadamy";
	cout << "\n\t\                                     Cohort 2-Group3";
	cout << "\n\t\                                     Sebtember 2018";
	Sleep(3000);
	system("cls");

	Database PassengerDB;
	Database FlightDB;

	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			FlightDB.displayAllFlight();
			break;
		case 2:
			doBooked(PassengerDB);
			break;
		case 3:
			PassengerDB.displayAllPassenger();
			break;
		case 4:
			doDispayTicket(PassengerDB);
		break;
		case 5:
			doFlightDetail(FlightDB);
			break;
		case 6:
			doCancelFlight(PassengerDB);
			break;
		case 9:
			Administrator(FlightDB);
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}
	return 0;
}

int displayMenu()
{
	int selection;
	cout << "\n\n\n\t\t\t\t\t\t\t\t9. FLIGHT ADMINISTRATOR LOGIN \n";

	cout << "\n\t\t*********************************************************************\n";
	cout << "\t\t................  Welcome to Selam Airline Services ............\n";
	cout << "\t\t....................Customer Airline Reservation ...............\n\n";
	cout << "\t\t*********************************************************************\n\n";
	cout << "\t\t\tPlease pick an option from the menu below. \n\n";
	cout << "\t\t\t\t1. Flight Schedule \n";
	cout << "\t\t\t\t2. Reserve Flight \n";
	cout << "\t\t\t\t3. Display passenger Information \n";
	cout << "\t\t\t\t4. Display user Ticket Information \n";
	cout << "\t\t\t\t5. Display flight details \n";
	cout << "\t\t\t\t6. Cancel reservation \n";
	cout << "\t\t\t\t0. Exit \n";
	cout << "\t\t \n\n";

	cout << endl;
	cout << "\t\t\t---> ";
	cin >> selection;
	return selection;
}

void RecordFlightDetail(Database& db)
{
	Database FlightDB;
	int FlightNumber;
	string departureTime;
	string arrivalTime;
	string startingFrom;
	string to;
	string FlightDate;
	double NewCost;
	string FlightName;

	cout << endl;
	cout << "\nEnter Flight Name: ";
	cin >> FlightName;
	cout << "\nEnter Flight Number: ";
	cin >> FlightNumber;
	cout << "\nEnter Departure Time: ";
	cin >> departureTime;
	cout << "\nEnter Arrival Time:  ";
	cin >> arrivalTime;
	cout << "\nEnter starting From:  ";
	cin >> startingFrom;
	cout << "\nEnter Destination:  ";
	cin >> to;
	cout << "\nEnter Flight Date (mm/dd/yyy) :  ";
	cin >> FlightDate;
	cout << "\nEnter Flight Cost  $: ";
	cin >> NewCost;

	db.addFlight(FlightNumber, departureTime, arrivalTime, startingFrom, to, FlightDate, FlightName, NewCost);

	system("CLS");

	cout << "\n\n\n\t\t ----- Data Added on Available Flight List. -------- ";
}

void doBooked(Database& db)

{
	string FirstName;
	string LastName;
	string PhoneNumber;
	int passportNumber;
	int FlightNumber;

	cout << "Enter your First Name?  ";
	cin >> FirstName;
	cout << "Enter Your Last Name?  ";
	cin >> LastName;
	cout << "Enter your Phone NUmber?  ";
	cin >> PhoneNumber;
	cout << "Enter Your Passport Number?  ";
	cin >> passportNumber;
	cout << "Enter Your Flight Number?  ";
	cin >> FlightNumber;

	cout << "\n\n\n\t\t Thank you for using our service  ";
	cout << "\n\t\t -----You are Booked!! -------- ";

	db.addPassenger(FirstName, LastName, PhoneNumber, passportNumber, FlightNumber);
}

void doCancelFlight(Database& db)
{
	int PassportNumber;
	int FlightNumber;

	cout << "Enter your Passport Number ";
	cin >> PassportNumber;
	cout << "Enter your Flight Number ";
	cin >> FlightNumber;
	try {
		Passenger& pas = db.getPassenger(PassportNumber, FlightNumber);
		pas.CancelFlight();
		cout << endl;
		cout << "your flight with PassportNumber " << PassportNumber << " and FlightNumber " << FlightNumber << " has been cancled." << endl;
		
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to cancel Flight: " << exception.what() << endl;
	}

}
void doFlightDetail(Database& db)
{
	string startingFrom;
	string	to;
	string	FlightDate;


	cout << "\n\n\t\t\tFrom  : ";
	cin >> startingFrom;
	cout << "\n\t\t\tWhere to  : ";
	cin >> to;
	cout << "\n\t\tFlight Date (mm/dd/yyyy)  : ";
	cin >> FlightDate;

	try {
		Flight& Fly = db.getFlight(startingFrom, to, FlightDate);
		Fly.FlightRecord();

	}
	catch (const std::logic_error& exception) {
		cerr << "\n\n\t\tSorry on the given Date : " << exception.what() << endl;
	}

}
void doDispayTicket(Database& db)
{
	int PassportNumber;
	int FlightNumber;

	cout << "Passport Number? ";
	cin >> PassportNumber;
	cout << "Flight Number? ";
	cin >> FlightNumber;

	try {
		Passenger& pas = db.getPassenger(PassportNumber,FlightNumber);
		pas.display();
		cout << "This is the Pasenger Ticket information for:";
		cout << "\n\t\t\t For Paspart Number " << PassportNumber << " and." << endl;
		cout << "\n\t\t\t Flight Number " << FlightNumber << "." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "\n\t\t\t Search Complited  : " << exception.what() << endl;
	}
}

int Administrator(Database& db)
{
	Database FlightDB;

	string username = "";
	int	password;
	bool loginSuccess = false;
	cout << "\t\t\t\t\t************************************* \n";
	cout << "\t\t\t\t\t Administrator Login \n";
	cout << "\t\t\t\t\t************************************* \n";
	do {
		cout << "\t\t\t\t\t hit UserName:- admin  Password:- 1234\n";
		cout << "\t\t\t\t\t\t Username   : ";
		cin >> username;
		cout << "\t\t\t\t\t\t Password   : ";
		cin >> password;

		cout << "\t\t\t\t\t************************************* \n\n";
		system("cls");
		if (username == "admin" && password == 1234) {
			Database FlightDB;

			int FlightNumber;
			string departureTime;
			string arrivalTime;
			string startingFrom;
			string to;
			string FlightDate;
			double NewCost;
			string FlightName;

			cout << endl;
			cout << "\n=== Enter Flight status and information === \n\n";

			int f;
			cout << "\n\t\t*********************************************************************\n";
			cout << "THESE ARE THE CURRENT AVAILABLE FLIGHTS" << endl << endl;
			cout << "\t\t\t 1)Alaska Airlines" << endl;
			cout << "\t\t\t 2)Delta Airlines" << endl;
			cout << "\t\t\t 3)Frontier Airlines" << endl;
			cout << "\t\t\t 4)JetBlue Airlines" << endl;
			cout << endl;
			cout << " Enter your choice to continue" << endl;
			cin >> f;
		
			switch (f)
			{
			case 1:
				if (f == 1)
					cout << setw(40) << "\n\n\n                                Create Alaska Air Lines Flight Detail" << endl;
				break;
			case 2:
				if (f == 2)
					cout << setw(40) << "\n\n\n                                Create Delta Air Lines Flight Detail" << endl;
				break;
			case 3:
				if (f == 3)
					cout << setw(40) << "\n\n\n                                Create Frontier Airlines Flight Detail" << endl;
				break;
			case 4:
				if (f == 4)
					cout << setw(40) << "\n\n\n                                Record JetBlue Flight Detail" << endl;
				break;
			}

			cout << "\nEnter Flight Name: ";
			cin >> FlightName;
			cout << "\nEnter Flight Number: ";
			cin >> FlightNumber;
			cout << "\nEnter Departure Time: ";
			cin >> departureTime;
			cout << "\nEnter Arrival Time:  ";
			cin >> arrivalTime;
			cout << "\nEnter starting From:  ";
			cin >> startingFrom;
			cout << "\nEnter Destination:  ";
			cin >> to;
			cout << "\nEnter Flight Date:  ";
			cin >> FlightDate;
			cout << "\nEnter Flight Cost:  ";
			cin >> NewCost;

			db.addFlight(FlightNumber, departureTime, arrivalTime, startingFrom, to, FlightDate, FlightName, NewCost);

			cout << "\n\n\n\t\t ----- Data Added on Available Flight List. -------- ";
		}
		else {
			cout << "Incorrect username and password";
		}
	} while (loginSuccess = false);
	return 0;
}


