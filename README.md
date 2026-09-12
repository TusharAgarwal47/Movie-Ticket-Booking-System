# Movie Ticket Booking System

## Problem Statement

The objective of this project is to develop a menu-driven Movie Ticket Booking System in C++ for a single cinema.

The system allows customers to view movies and shows, check seat availability, select seats, calculate ticket prices, make payments, print tickets, view bookings, and cancel bookings.

The system prevents customers from booking already booked seats. A booking is confirmed only after successful payment. On cancellation, the booked seats become available again.

## Features

- View available movies
- View movie shows
- Display seat layout
- Book one or multiple seats
- Prevent duplicate/already booked seats
- Silver, Gold and Platinum seat categories
- UPI, Card and Cash payment
- Payment failure handling
- Automatic booking ID generation
- Print ticket
- View booked tickets
- Cancel booking
- Release seats after cancellation
- Input validation

## Technologies Used

- C++
- Object-Oriented Programming
- C++17
- Console-based interface

## OOP Concepts Used

- Encapsulation
- Abstraction
- Inheritance
- Runtime Polymorphism
- Compile-time Polymorphism
- Composition
- Aggregation
- Association
- Static Data Members
- `this` pointer

## Main Classes

- Movie
- Seat
- Screen
- Cinema
- Show
- ShowSeat
- Customer
- Booking
- BookingService
- Payment
- UpiPayment
- CardPayment
- CashPayment
- PriceCalculator
- TicketPrinter

## How to Run

Compile the project using:

```bash
g++ main.cpp -o movie_booking

Project Structure:

Movie-Ticket-Booking-System/
├── main.cpp
├── Movie.cpp
├── Seat.cpp
├── Screen.cpp
├── Cinema.cpp
├── Show.cpp
├── ShowSeat.cpp
├── Customer.cpp
├── Booking.cpp
├── BookingService.cpp
├── Payment.cpp
├── UpiPayment.cpp
├── CardPayment.cpp
├── CashPayment.cpp
├── PriceCalculator.cpp
├── TicketPrinter.cpp
├── README.md
└── .gitignore
