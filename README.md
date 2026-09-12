# 🎬 Movie Ticket Booking System

A menu-driven **Movie Ticket Booking System** developed in C++ using Object-Oriented Programming concepts. The system simulates the process of viewing movies and shows, checking seat availability, booking seats, making payments, printing tickets, and cancelling bookings.

## 📌 Problem Statement

Design and implement a small movie ticket booking system for a single cinema using C++. The system should allow customers to view available movies and their shows, check the seat layout of a selected show, book one or more available seats, make payments using different payment methods, print the confirmed ticket, and cancel an existing booking.

The system should ensure that already booked seats cannot be booked again and that a booking is confirmed only when the payment is successful.

## 🎯 Objectives

* Manage movies, screens, shows, seats, customers, and bookings.
* Display available movies and their corresponding shows.
* Display the seat layout with available and booked seats.
* Allow customers to book one or more seats.
* Calculate ticket prices according to seat category.
* Support multiple payment methods.
* Confirm bookings only after successful payment.
* Generate a unique booking ID for every booking.
* Print booking/ticket details.
* Allow customers to cancel their bookings and make seats available again.
* Handle invalid inputs and booking errors without crashing the program.

## ⚙️ Functions / Features Used

### 1. View Movies

Displays the movies currently available in the cinema.

### 2. View Shows

Displays the shows available for a selected movie, including:

* Screen
* Start time

### 3. View Seat Layout

Displays the seats of a selected show and their current status:

* `AVAILABLE`
* `BOOKED`

Seats are divided into categories:

| Category | Price |
| -------- | ----: |
| Silver   |  ₹150 |
| Gold     |  ₹250 |
| Platinum |  ₹400 |

### 4. Book Tickets

The customer can:

* Enter customer details.
* Select one or more seats.
* Check whether seats are available.
* Calculate the total ticket price.
* Proceed to payment.

Already booked seats are rejected.

### 5. Payment System

The system supports different payment methods:

* UPI
* Card
* Cash

Payment is implemented using an abstract `payment` class and derived payment classes.

A booking is **not confirmed if payment fails**.

### 6. Ticket Generation

After successful payment, the system generates a unique booking ID and displays:

* Booking ID
* Customer details
* Movie
* Screen
* Show time
* Selected seats
* Total amount
* Booking status

### 7. View My Ticket

Customers can search for their booking using their customer details and view their confirmed ticket.

### 8. Cancel Booking

A confirmed booking can be cancelled. The seats associated with that booking become available again.

## 🏗️ Project Structure

```text
Movie-Ticket-Booking-System/
│
├── main.cpp
│
├── Movie.cpp
├── Cinema.cpp
├── Screen.cpp
├── Seat.cpp
├── Show.cpp
├── showseat.cpp
├── Customer.cpp
│
├── booking.cpp
├── bookingservice.cpp
│
├── payment.cpp
├── upipayment.cpp
├── cardpayment.cpp
├── cashpayment.cpp
│
├── pricecalculator.cpp
├── ticketprinter.cpp
│
├── README.md
├── LICENSE
└── .gitignore
```

## 🧩 Main Classes

| Class             | Responsibility                                    |
| ----------------- | ------------------------------------------------- |
| `movie`           | Stores movie information                          |
| `seat`            | Represents individual cinema seats                |
| `screen`          | Manages seats belonging to a screen               |
| `cinema`          | Manages screens in the cinema                     |
| `show`            | Represents a movie show                           |
| `showseat`        | Maintains seat availability for a particular show |
| `customer`        | Stores customer information                       |
| `Booking`         | Stores booking details and status                 |
| `BookingService`  | Handles the booking process                       |
| `payment`         | Abstract base class for payments                  |
| `upipayment`      | Handles UPI payment                               |
| `cardpayment`     | Handles card payment                              |
| `CashPayment`     | Handles cash payment                              |
| `pricecalculator` | Calculates total ticket price                     |
| `TicketPrinter`   | Prints ticket details                             |

## 🧠 Object-Oriented Programming Concepts

### Encapsulation

Data members of classes are kept private and accessed through public member functions.

### Abstraction

The `payment` class provides a common payment interface without exposing the implementation details of individual payment methods.

### Inheritance

Payment classes inherit from the `payment` base class.

```text
payment
   │
   ├── upipayment
   ├── cardpayment
   └── CashPayment
```

### Runtime Polymorphism

The `pay()` function is overridden in the derived payment classes and called through the base `payment` reference.

### Composition

Used where one object strongly owns another object.

Examples:

* `Cinema → Screen`
* `Screen → Seat`
* `Show → ShowSeat`

### Aggregation

Used where objects can exist independently.

Examples:

* `Show → Movie`
* `Booking → ShowSeat`

### Association

Used between objects that interact with each other.

Example:

```text
Customer ↔ BookingService
```

### Static Data Member

A static booking ID counter is used to generate unique booking IDs.

Example:

```text
BK1001
BK1002
BK1003
```

## 🔄 Booking Flow

```text
Customer
   ↓
Select Movie
   ↓
Select Show
   ↓
View Seats
   ↓
Select Seats
   ↓
Check Availability
   ↓
Calculate Price
   ↓
Select Payment Method
   ↓
Payment Successful?
   ├── No → Booking Not Confirmed
   │
   └── Yes
        ↓
   Book Seats
        ↓
   Generate Booking ID
        ↓
   Print Ticket
```

## 💰 Pricing

The ticket price depends on the seat category:

```text
SILVER    → ₹150
GOLD      → ₹250
PLATINUM  → ₹400
```

The `pricecalculator` class calculates the total amount based on the selected seats.

## 🛡️ Error Handling

The system handles common cases such as:

* Selecting an already booked seat.
* Selecting an invalid seat.
* Selecting the same seat multiple times.
* Failed payment.
* Invalid menu input.
* Invalid customer/booking information.

## 🛠️ Technologies Used

* **Language:** C++
* **Concepts:** Object-Oriented Programming
* **Interface:** Menu-driven console application
* **Compiler:** G++ / GCC
* **Version Control:** Git & GitHub

## ▶️ How to Run

Compile the project using:

```bash
g++ main.cpp -o main
```

Run the program:

```bash
./main
```

## 📚 Academic Concepts Demonstrated

This project demonstrates practical implementation of:

* Classes and Objects
* Constructors
* Encapsulation
* Abstraction
* Inheritance
* Runtime Polymorphism
* Function Overloading
* Composition
* Aggregation
* Association
* Static Members
* Dynamic Memory
* Vectors
* Modular Programming
* Exception/Error Handling
* SOLID Design Principles

## 📄 License

This project is licensed under the MIT License.
