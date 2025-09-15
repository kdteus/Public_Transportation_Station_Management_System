#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ================== Driver Class ===================
class Driver {
    string name;
    int id;
    string licenseType; 
public:
    Driver(string n, int i, string lt) : name(n), id(i), licenseType(lt) {}

    string getName() const { return name; }
    int getId() const { return id; }
    string getLicenseType() const { return licenseType; }

    string getDriver() const {
        return "Driver: " + name + " (ID: " + to_string(id) +
               ", License: " + licenseType + ")";
    }
    void displayInfo() const {
        cout << getDriver() << endl;
    }
};


// ================== Base Class Vehicle ==================
class Vehicle {
protected:
    string route;
    int capacity;
    int bookedSeats;
    bool status; 
    double speed;  
    string fuelType;
    int year;
    Driver* driver; 
public:
    Vehicle(string r, int c, double s, string f, int y)
        : route(r), capacity(c), bookedSeats(0), status(true), 
          speed(s), fuelType(f), year(y), driver(nullptr) {}

    void assignDriver(Driver* d) { driver = d; }

    virtual double calculateTravelTime(double distance) {
        if (speed <= 0) return 0;
        return distance / speed;
    }

    bool bookSeat() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    void toggleStatus() { status = !status; }
    string getRoute() const { return route; }
    string getStatus() const { return status ? "On time" : "Delayed"; }
    int getCapacity() const { return capacity; }
    int getBookedSeats() const { return bookedSeats; }
    string getFuelType() const { return fuelType; }
    int getYear() const { return year; }

    string getDriver() const {
        if (driver) return driver->getDriver();
        return "";
    }

    virtual void displayInfo() {
        cout << "[Vehicle] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Status: " << (status ? "On time" : "Delayed")
             << " | Speed: " << speed << " km/h"
             << " | Fuel: " << fuelType
             << " | Year: " << year << endl;
        if (driver) driver->displayInfo();
    }
    virtual string getName() const { return "Vehicle"; }
};

// ================== Derived Classes ==================
class Bus : public Vehicle {
public:
    Bus(string r, int c, double s, string f, int y) : Vehicle(r, c, s, f, y) {}
    void displayInfo() override {
        cout << "[Bus] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Status: " << (status ? "On time" : "Delayed")
             << " | Speed: " << speed << " km/h"
             << " | Fuel: " << fuelType
             << " | Year: " << year << endl;
        if (driver) driver->displayInfo();
    }
    string getName() const override { return "Bus"; }
};

class Train : public Vehicle {
public:
    Train(string r, int c, double s, string f, int y) : Vehicle(r, c, s, f, y) {}
    void displayInfo() override {
        cout << "[Train] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Status: " << (status ? "On time" : "Delayed")
             << " | Speed: " << speed << " km/h"
             << " | Fuel: " << fuelType
             << " | Year: " << year << endl;
        if (driver) driver->displayInfo();
    }
    string getName() const override { return "Train"; }
};

class ExpressBus : public Vehicle {
public:
    ExpressBus(string r, int c, double s, string f, int y) : Vehicle(r, c, s, f, y) {}
    double calculateTravelTime(double distance) override {
        return (distance / speed) * 0.8;
    }
    void displayInfo() override {
        cout << "[ExpressBus] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Status: " << (status ? "On time" : "Delayed")
             << " | Speed: " << speed << " km/h (20% faster)"
             << " | Fuel: " << fuelType
             << " | Year: " << year << endl;
        if (driver) driver->displayInfo();
    }
    string getName() const override { return "ExpressBus"; }
};

class Airplane : public Vehicle {
public:
    Airplane(string r, int c, double s, string f, int y) : Vehicle(r, c, s, f, y) {}
    void displayInfo() override {
        cout << "[Airplane] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Status: " << (status ? "On time" : "Delayed")
             << " | Speed: " << speed << " km/h (Flying)"
             << " | Fuel: " << fuelType
             << " | Year: " << year << endl;
        if (driver) driver->displayInfo();
    }
    string getName() const override { return "Airplane"; }
};

class Ship : public Vehicle {
public:
    Ship(string r, int c, double s, string f, int y) : Vehicle(r, c, s, f, y) {}
    void displayInfo() override {
        cout << "[Ship] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Status: " << (status ? "On time" : "Delayed")
             << " | Speed: " << speed << " km/h (Sailing)"
             << " | Fuel: " << fuelType
             << " | Year: " << year << endl;
        if (driver) driver->displayInfo();
    }
    string getName() const override { return "Ship"; }
};

class Motorbike : public Vehicle {
public:
    Motorbike(string r, int c, double s, string f, int y) : Vehicle(r, c, s, f, y) {}
    void displayInfo() override {
        cout << "[Motorbike] Route: " << route
             << " | Amount: " << capacity  
             << " | Booked: " << bookedSeats
             << " | Status: " << (status ? "On time" : "Delayed")
             << " | Speed: " << speed << " km/h (Two-wheeler)"
             << " | Fuel: " << fuelType
             << " | Year: " << year << endl;
        if (driver) driver->displayInfo();
    }
    string getName() const override { return "Motorbike"; }
};

class Taxi : public Vehicle {
public:
    Taxi(string r, int c, double s, string f, int y) : Vehicle(r, c, s, f, y) {}
    void displayInfo() override {
        cout << "[Taxi] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Status: " << (status ? "On time" : "Delayed")
             << " | Speed: " << speed << " km/h (Private Car)"
             << " | Fuel: " << fuelType
             << " | Year: " << year << endl;
        if (driver) driver->displayInfo();
    }
    string getName() const override { return "Taxi"; }
};

// ================== Passenger Class ==================
class Passenger {
    string name;
    int id;
    vector<Vehicle*> tickets;
public:
    Passenger(string n, int i) : name(n), id(i) {}
    void bookRide(Vehicle* v) {
        if (v->bookSeat()) {
            tickets.push_back(v);
            cout << name << " booked a seat for " 
                 << v->getName() << " successfully." << endl;
        } else {
            cout << "Booking failed for " << name 
                 << ": " << v->getName() << " is full." << endl;
        }
    }
    void displayInfo() {
        cout << "Passenger " << name << " (ID: " << id << ") booked " 
             << tickets.size() << " rides." << endl;
    }
};

void viewAllDrivers(const vector<Vehicle*>& vehicles) {
    cout << "\n--- DRIVER LIST ---" << endl;
    if (vehicles.empty()) {
        cout << "No vehicles available.\n";
        return;
    }

    for (int i = 0; i < (int)vehicles.size(); i++) {
        cout << i << ". Vehicle: " << vehicles[i]->getName()
             << " (" << vehicles[i]->getRoute() << ")\n";

        if (vehicles[i]->getDriver().empty()) {
            cout << "   Driver: None\n";
        } else {
            cout << "   " << vehicles[i]->getDriver() << "\n";
        }
    }
}

int main() {
    vector<Vehicle*> vehicles;
        // === Passenger Testcases ===
    Passenger p1("Alice", 101);
    Passenger p2("Bob", 102);
    Passenger p3("Charlie", 103);

    vehicles.push_back(new Bus("A", 40, 50, "Diesel", 2015));
    vehicles.push_back(new Train("T1", 200, 80, "Electric", 2020));
    vehicles.push_back(new ExpressBus("E1", 30, 60, "Gasoline", 2018));
    vehicles.push_back(new Airplane("F1", 150, 600, "Jet fuel", 2021));
    vehicles.push_back(new Ship("S1", 500, 40, "Diesel", 2010));
    vehicles.push_back(new Motorbike("M1", 5, 100, "Gasoline", 2019));
    vehicles.push_back(new Taxi("T2", 4, 70, "Gasoline", 2017));

    const string adminPassword = "1234"; 


    // === Example Passenger Bookings ===
    cout << "\n--- PASSENGER TESTCASES ---" << endl;
    p1.bookRide(vehicles[0]);  // Alice books a Bus
    p1.bookRide(vehicles[3]);  // Alice books an Airplane

    p2.bookRide(vehicles[1]);  // Bob books a Train
    p2.bookRide(vehicles[6]);  // Bob books a Taxi

    p3.bookRide(vehicles[2]);  // Charlie books an ExpressBus
    p3.bookRide(vehicles[5]);  // Charlie books a Motorbike
    p3.bookRide(vehicles[4]);  // Charlie books a Ship

    p1.displayInfo();
    p2.displayInfo();
    p3.displayInfo();

    int mainChoice;
    while (true) {
        cout << "\n===== TRANSPORT MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Passenger Menu" << endl;
        cout << "2. Admin Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        if (mainChoice == 0) break;
        else if (mainChoice == 1) {
            int choice;
            while (true) {
                cout << "\n--- PASSENGER MENU ---" << endl;
                cout << "1. Book a seat" << endl;
                cout << "2. View all vehicle routes" << endl;
                cout << "3. View status of all vehicles" << endl;
                cout << "4. View capacity of all vehicles" << endl;
                cout << "5. View all drivers" << endl;
                cout << "0. Back" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 0) break;
                else if (choice == 1) {
                    cout << "\nAvailable Vehicles:\n";
                    for (int i = 0; i < (int)vehicles.size(); i++) {
                        cout << i << ". ";
                        vehicles[i]->displayInfo();
                    }
                    cout << "Enter vehicle index to book: ";
                    int i; cin >> i;
                    if (i >= 0 && i < (int)vehicles.size())
                        p1.bookRide(vehicles[i]);
                    else 
                        cout << "Invalid vehicle!\n";
                }
                else if (choice == 2) {
                    for (int i = 0; i < (int)vehicles.size(); i++)
                        cout << i << ". " << vehicles[i]->getName()
                             << " Route: " << vehicles[i]->getRoute() << endl;
                }
                else if (choice == 3) {
                    for (int i = 0; i < (int)vehicles.size(); i++)
                        cout << i << ". " << vehicles[i]->getName()
                             << " Status: " << vehicles[i]->getStatus() << endl;
                }
                else if (choice == 4) {
                    for (int i = 0; i < (int)vehicles.size(); i++)
                        cout << i << ". " << vehicles[i]->getName()
                             << " | Capacity: " << vehicles[i]->getCapacity()
                             << " | Booked: " << vehicles[i]->getBookedSeats() << endl;
                }
                else if (choice == 5) {
                    viewAllDrivers(vehicles);
                }
            }
        }
        else if (mainChoice == 2) {
            string inputPass;
            cout << "Enter Admin Password: ";
            cin >> inputPass;
            if (inputPass != adminPassword) {
                cout << "Wrong password! Returning to main menu.\n";
                continue;
            }

            int choice;
            while (true) {
                cout << "\n--- ADMIN MENU ---" << endl;
                cout << "1. View all vehicle info" << endl;
                cout << "2. Add new vehicle" << endl;
                cout << "3. Change vehicle status" << endl;
                cout << "4. Assign driver to vehicle" << endl;
                cout << "5. Calculate travel time" << endl;
                cout << "6. Search vehicle by route" << endl;
                cout << "7. View all drivers" << endl;
                cout << "0. Back" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 0) break;
                else if (choice == 1) {
                    for (int i = 0; i < (int)vehicles.size(); i++) {
                        cout << i << ": ";
                        vehicles[i]->displayInfo();
                    }
                }
                else if (choice == 2) {
                    cout << "Choose vehicle type (1=Bus, 2=Train, 3=ExpressBus, 4=Airplane, 5=Ship, 6=Motorbike, 7=Taxi): ";
                    int type; cin >> type;
                    string r,f; int c,y; double s;
                    cout << "Enter route: "; cin >> r;
                    cout << "Enter capacity: "; cin >> c;
                    cout << "Enter speed: "; cin >> s;
                    cout << "Enter fuel type: "; cin >> f;
                    cout << "Enter year: "; cin >> y;
                    if (type == 1) vehicles.push_back(new Bus(r,c,s,f,y));
                    else if (type == 2) vehicles.push_back(new Train(r,c,s,f,y));
                    else if (type == 3) vehicles.push_back(new ExpressBus(r,c,s,f,y));
                    else if (type == 4) vehicles.push_back(new Airplane(r,c,s,f,y));
                    else if (type == 5) vehicles.push_back(new Ship(r,c,s,f,y));
                    else if (type == 6) vehicles.push_back(new Motorbike(r,c,s,f,y));
                    else if (type == 7) vehicles.push_back(new Taxi(r,c,s,f,y));
                    cout << "Vehicle added successfully!\n";
                }
                else if (choice == 3) {
                    cout << "\nChoose vehicle to toggle status:\n";
                    for (int i = 0; i < (int)vehicles.size(); i++) {
                        cout << i << ". " << vehicles[i]->getName()
                             << " (" << vehicles[i]->getRoute()
                             << ") Current: " << vehicles[i]->getStatus() << endl;
                    }
                    int i; cin >> i;
                    if (i >= 0 && i < (int)vehicles.size()) {
                        vehicles[i]->toggleStatus();
                        cout << "Status updated!\n";
                    } else cout << "Invalid vehicle!\n";
                }
                else if (choice == 4) {
                    cout << "Enter driver name, id, licenseType: ";
                    string n, lt; int id;
                    cin >> n >> id >> lt;
                    Driver* d = new Driver(n,id,lt);
                    cout << "Choose vehicle index: ";
                    int i; cin >> i;
                    if (i>=0 && i<(int)vehicles.size()) {
                        vehicles[i]->assignDriver(d);
                        cout << "Driver assigned!\n";
                    } else cout << "Invalid vehicle!\n";
                }
                else if (choice == 5) {
                    cout << "Enter vehicle index and distance: ";
                    int i; double dist;
                    cin >> i >> dist;
                    if (i>=0 && i<(int)vehicles.size()) {
                        cout << "Estimated time: " << vehicles[i]->calculateTravelTime(dist) << " hours\n";
                    } else cout << "Invalid vehicle!\n";
                }
                else if (choice == 6) {
                    cout << "Enter route to search: ";
                    string r; cin >> r;
                    bool found = false;
                    for (auto v: vehicles) {
                        if (v->getRoute() == r) {
                            v->displayInfo();
                            found = true;
                        }
                    }
                    if (!found) cout << "No vehicle found with route " << r << endl;
                }
                else if (choice == 7) {
                    viewAllDrivers(vehicles);
                }
            }
        }
    }

    cout << "Exiting program.\n";
    return 0;
}



