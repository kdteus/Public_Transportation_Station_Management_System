# Public_Transportation_Station_Management_System

## Overview
This project is a **Public Transportation Station Management System** implemented in C++ using Object-Oriented Programming (OOP) principles.  
It demonstrates the design of multiple vehicle types, passenger interactions, and driver assignments.  

The program provides:
- A **Passenger Menu** for booking seats and checking vehicle information.  
- An **Admin Menu** (password protected) for managing vehicles and drivers.  

The goal of this project is to practice OOP concepts such as **inheritance, polymorphism, encapsulation**, and to simulate a real-world transport booking scenario.  

---

## Build & Run Instruction
On Linux/macOS/WSL
```bash
g++ main.cpp -o main
./main
```
On Windows(MinGW g++)
```bash
g++ main.cpp -o main.exe
.\main.exe
```

## AI Disclosure
This project was built with the assistance of **ChatGPT** for:
- Code structuring and debugging support.
- Adding extended features (e.g., Motorbike vehicle type with *amount* instead of *capacity*).
- Generating test cases and sample drivers/passengers.


All final decisions, adjustments, and testing were done manually by the developer.  

---

## Features
### Vehicle Management
- Base class: `Vehicle`.
- Derived classes: `Bus`, `Train`, `ExpressBus`, `Airplane`, `Ship`, `Motorbike`, `Taxi`.
- Attributes: route, capacity/amount, speed, year, fuel type, status (On time / Delayed).
- Assign drivers to vehicles.

### Passenger Management
- Book seats on available vehicles.
- Track all booked rides.
- Display booking success/failure with vehicle names.

### Driver Management
- Store driver details: name, ID, license type.
- Assign drivers to vehicles.
- Admin can view all assigned drivers; if no driver exists, system displays *None*.

### Menus
- **Passenger Menu**
  - Book a seat.
  - View available routes.
  - View status of all vehicles.
  - View capacity or amount.
  - View all drivers
- **Admin Menu** (password = `1234`)
  - View all vehicle info.
  - Add new vehicles.
  - Change vehicle status.
  - Assign drivers.
  - Search vehicles by route.
  - View all drivers.

---

## Reflection
Through this project, I learned how to:
- Apply **OOP principles** effectively in C++.
- Use **virtual functions** and **overriding** to customize behaviors for different vehicle types.
- Implement **encapsulation** for passengers, drivers, and vehicles.
- Design a flexible system that can be easily extended with new features (e.g., stations, ticket pricing, or route networks).  

The main challenge was managing the **interactions** between passengers, vehicles, and drivers in a way that feels realistic but still keeps the code simple.  
With further work, the system could evolve into a full simulation or booking application.  
