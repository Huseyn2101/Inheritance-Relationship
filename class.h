#pragma once

template<typename T, int MAX = 7>
class Stack
{
	T _container[MAX]{};
	int _top = -1;

public:
	Stack() = default;

	void push(T element)
	{
		if (isFull())
			throw "Stack overflow";

		_container[++_top] = element;
	}
	void pop()
	{
		if (isEmpty())
			throw "Stack underflow";

		_top--;
	}
	T peek() const
	{
		if (isEmpty())
			throw "Stack is Empty";

		return _container[_top];
	}

	void display() const
	{
		if (isEmpty())
			throw "Stack is Empty";

		for (int i = _top; i >= 0; --i)
			static_cast<T>(_container[i]).display();
		cout << endl;
	}

	bool isEmpty() const { return _top == -1; }
	bool isFull() const { return _top + 1 == MAX; }
	int size() const { return _top + 1; }

	const T* getContainer() const
	{
		if (isEmpty())
			throw "Stack is Empty";
		return _container;
	}
};


class Engine {
private:
	string _engineNo;
	string _company;
	float _volume;

	string generateEngineNumber() {
		string engineNo;
		for (size_t i = 0; i < 3; ++i)
		{
			engineNo += 'A' + rand() % 26;
		}
		engineNo += '-';
		for (size_t i = 0; i < 6; i++)
		{
			engineNo += '0' + rand() % 10;
		}
		return engineNo;
	}

public:

	Engine() : _engineNo(generateEngineNumber()), _company("Default Company"), _volume((rand() % 40 + 10) / 10.0f) {}
	Engine(string engineNo, string company, float volume) : _engineNo(engineNo), _company(company), _volume(volume) {}
	Engine(string company, float volume) : _engineNo(generateEngineNumber()), _company(company), _volume(volume) {}
	Engine(string engineNo, string company) : _engineNo(engineNo), _company(company), _volume((rand() % 40 + 10) / 10.0f) {}


	string getEngineNo() const { return _engineNo; }
	string getCompany() const { return _company; }
	float getVolume() const { return _volume; }

	virtual void display() {
		cout << "\vEngine number: " << getEngineNo() << endl;
		cout << "Company: " << getCompany() << endl;
		cout << "Volume: " << getVolume() << endl;
	}

};

class Transportation :public Engine {
private:
	size_t _id;
	string _model;
	string _vendor;
	Engine _engine;

	static size_t generateID() {
		static size_t id = 291;
		return id += 29;
	}

public:

	Transportation() : _id(generateID()), _model("Default Model"), _vendor("Default Vendor"), _engine() {}
	Transportation(string model, string vendor, string engineNo, string company, float volume)
		: _id(generateID()), _model(model), _vendor(vendor), _engine(engineNo, company, volume) {
	}
	Transportation(string model, string vendor, string company, float volume)
		: _id(generateID()), _model(model), _vendor(vendor), _engine(company, volume) {
	}
	Transportation(string model, string vendor)
		: _id(generateID()), _model(model), _vendor(vendor), _engine() {
	}

	string getModel() const { return _model; }
	string getVendor() const { return _vendor; }
	size_t getID() const { return _id; }

	void display() override {
		cout << "\v~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		Engine::display();
		cout << "ID: " << _id << endl;
		cout << "Model: " << _model << endl;
		cout << "Vendor: " << _vendor << endl;
	}

};

class Car :public Transportation {
private:
	bool _hasSpoiler;

public:

	Car() : Transportation(), _hasSpoiler(false) {}
	Car(string model, string vendor, bool hasSpoiler)
		: Transportation(model, vendor), _hasSpoiler(hasSpoiler) {
	}
	Car(string model, string vendor, string engineNo, string company, float volume, bool hasSpoiler)
		: Transportation(model, vendor, engineNo, company, volume), _hasSpoiler(hasSpoiler) {
	}
	Car(string model, string vendor, string company, float volume, bool hasSpoiler)
		: Transportation(model, vendor, company, volume), _hasSpoiler(hasSpoiler) {
	}

	bool getHasSpoiler() const { return _hasSpoiler; }

	void display() override {
		Transportation::display();
		cout << "Has spoiler: " << (_hasSpoiler ? "Yes" : "No") << endl;
		cout << "\v~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}


};


class Ship :public Transportation {
private:
	bool _hasSail;

public:

	Ship() : Transportation(), _hasSail(false) {}

	Ship(string model, string vendor, bool hasSail)
		: Transportation(model, vendor), _hasSail(hasSail) {
	}
	Ship(string model, string vendor, string engineNo, string company, float volume, bool hasSail)
		: Transportation(model, vendor, engineNo, company, volume), _hasSail(hasSail) {
	}
	Ship(string model, string vendor, string company, float volume, bool hasSail)
		: Transportation(model, vendor, company, volume), _hasSail(hasSail) {
	}

	void display() override {
		Transportation::display();
		cout << "Has sail: " << (_hasSail ? "Yes" : "No") << endl;
		cout << "\v~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}

	bool getHasSail() const { return _hasSail; }

};

class Airplane :public Transportation {
private:
	int _engineCount;
	int _passengerCapacity;

	int generateEngineCount() {
		return rand() % 4 + 1;
	}

	int generatePassengerCapacity() {
		return rand() % 200 + 50;
	}

public:

	Airplane() : Transportation(), _engineCount(generateEngineCount()), _passengerCapacity(generatePassengerCapacity()) {}
	Airplane(string model, string vendor, int engineCount, int passengerCapacity)
		: Transportation(model, vendor), _engineCount(engineCount), _passengerCapacity(passengerCapacity) {
	}
	Airplane(string model, string vendor, string engineNo, string company, float volume, int engineCount, int passengerCapacity)
		: Transportation(model, vendor, engineNo, company, volume), _engineCount(engineCount), _passengerCapacity(passengerCapacity) {
	}
	Airplane(string model, string vendor, string company, float volume, int engineCount, int passengerCapacity)
		: Transportation(model, vendor, company, volume), _engineCount(engineCount), _passengerCapacity(passengerCapacity) {
	}

	void display() override {
		Transportation::display();
		cout << "Engine count: " << getEngineCount() << endl;
		cout << "Passenger capacity: " << getPassengerCapacity() << endl;
		cout << "\v~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}

	int getEngineCount() const { return _engineCount; }

	int getPassengerCapacity() const { return _passengerCapacity; }

};


class TransPortDepo {
private:
	Stack<Car> _carStack;
	Stack<Ship> _shipStack;
	Stack<Airplane> _airplaneStack;

public:

	void addCar(const Car& car) { _carStack.push(car); }
	void addShip(const Ship& ship) { _shipStack.push(ship); }
	void addAirplane(const Airplane& airplane) { _airplaneStack.push(airplane); }

	void displayCars() const {
		cout << "=== Cars ===\n";
		_carStack.display();
	}
	void displayShips() const {
		cout << "=== Ships ===\n";
		_shipStack.display();
	}
	void displayAirplanes() const {
		cout << "=== Airplanes ===\n";
		_airplaneStack.display();
	}

	void showAll() const {
		displayCars();
		displayShips();
		displayAirplanes();
	}

};