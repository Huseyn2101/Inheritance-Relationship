#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "class.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	TransPortDepo depo;

	string carModels[] = { "Model S", "Mustang", "Civic", "Corolla", "A4", "Camry", "Mazda 3", "Golf", "Elantra", "Accord", "Tesla X", "BMW M3", "Audi Q5", "Ford Focus", "Lexus IS" };
	string shipModels[] = { "Titanic", "Aurora", "Poseidon", "Odyssey", "Neptune", "Mariner", "Seabreeze", "Voyager", "Atlantis", "Oasis", "Harmony", "Liberty", "Queen Mary", "Sea Cloud", "Wind Surf" };
	string airplaneModels[] = { "Boeing 737", "Airbus A320", "Cessna 172", "Concorde", "Gulfstream G650", "Bombardier CRJ", "Embraer E190", "Boeing 747", "Airbus A380", "Piper PA-28", "Learjet 75", "Antonov An-225", "McDonnell Douglas MD-80", "Sukhoi Superjet", "Tupolev Tu-154" };

	string vendors[] = { "Toyota", "Ford", "Honda", "Chevrolet", "BMW", "Mercedes", "Volkswagen", "Nissan", "Hyundai", "Kia", "Lamborghini", "Ferrari", "Rolls-Royce", "Mazda", "Peugeot" };

	string companies[] = { "Honda Motors", "Ford Co.", "Toyota Inc.", "BMW AG", "Hyundai Group", "GE Aviation", "Rolls-Royce", "Pratt & Whitney", "Safran", "MTU Aero Engines", "CFM International", "Lycoming Engines", "Honeywell Aerospace", "Avco Corporation", "Turbomeca" };

	float volumes[] = { 1.6f, 2.0f, 2.2f, 2.5f, 3.0f, 1.4f, 3.2f, 2.8f, 1.8f, 2.6f, 2.3f, 3.6f, 4.0f, 1.2f, 1.9f };

	for (int i = 0; i < 7; ++i) {
		Car car(carModels[i], vendors[i], companies[i], volumes[i], i % 2 == 0);
		depo.addCar(car);
	}

	for (int i = 0; i < 7; ++i) {
		Ship ship(shipModels[i], vendors[i], companies[i], volumes[i], i % 2 == 1);
		depo.addShip(ship);
	}

	for (int i = 0; i < 7; ++i) {
		int engineCount = (i % 4) + 1;
		int passengerCapacity = 50 + (i * 10 % 200);
		Airplane plane(airplaneModels[i], vendors[i], companies[i], volumes[i], engineCount, passengerCapacity);
		depo.addAirplane(plane);
	}


	cout << "All vehicles in the depot: \v" << endl;
	depo.showAll();


	return 0;
}

