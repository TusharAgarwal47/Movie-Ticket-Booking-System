#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "Movie.cpp"
#include "Seat.cpp"
#include "Customer.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "showseat.cpp"
#include "Show.cpp"
#include "payment.cpp"
#include "upipayment.cpp"
#include "cardpayment.cpp"
#include "cashpayment.cpp"
#include "pricecalculator.cpp"
#include "booking.cpp"
#include "ticketprinter.cpp"
#include "bookingservice.cpp"

using namespace std;

int main()
{
    // ==========================================
    // CINEMA
    // ==========================================

    cinema cinema("PVR Cinema");

    // ==========================================
    // MOVIES
    // ==========================================

    movie movie1("Avengers", "English", "2h 30m");
    movie movie2("Kantara", "Hindi", "2h 45m");

    // ==========================================
    // SCREEN
    // ==========================================

    screen screen1("1");

    screen1.add_seat(seat("S1", "SILVER"));
    screen1.add_seat(seat("S2", "SILVER"));
    screen1.add_seat(seat("S3", "GOLD"));
    screen1.add_seat(seat("S4", "GOLD"));
    screen1.add_seat(seat("S5", "PLATINUM"));

    cinema.add_screen(screen1);

    // ==========================================
    // SHOWS
    // ==========================================

    show show1(movie1, screen1, "6:30 PM");
    show show2(movie2, screen1, "9:30 PM");

    show1.create_show();
    show2.create_show();

    // ==========================================
    // STORE ALL SUCCESSFUL BOOKINGS
    // ==========================================

    vector<Booking*> bookings;

    // ==========================================
    // MAIN MENU
    // ==========================================

    while (true)
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "       MOVIE TICKET BOOKING         \n";
        cout << "====================================\n";

        cout << "1. View Movies\n";
        cout << "2. View Shows\n";
        cout << "3. View Seats\n";
        cout << "4. Book Ticket\n";
        cout << "5. My Ticket\n";
        cout << "6. Exit\n";

        cout << "\nEnter choice: ";

        int choice;

        // ==========================================
        // MAIN MENU INPUT VALIDATION
        // ==========================================

        if (!(cin >> choice))
        {
            cout << "\nInvalid input! Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        // ==========================================
        // 1. VIEW MOVIES
        // ==========================================

        if (choice == 1)
        {
            cout << "\n========== AVAILABLE MOVIES ==========\n";

            cout << "1. "
                 << movie1.getmovie_name()
                 << " | "
                 << movie1.getmovie_language()
                 << " | "
                 << movie1.getmovie_duration()
                 << endl;

            cout << "2. "
                 << movie2.getmovie_name()
                 << " | "
                 << movie2.getmovie_language()
                 << " | "
                 << movie2.getmovie_duration()
                 << endl;
        }

        // ==========================================
        // 2. VIEW SHOWS
        // ==========================================

        else if (choice == 2)
        {
            cout << "\n========== AVAILABLE SHOWS ==========\n";

            cout << "1. "
                 << movie1.getmovie_name()
                 << " - Screen "
                 << show1.get_Screen()->get_Screen_Num()
                 << " - "
                 << show1.get_time()
                 << endl;

            cout << "2. "
                 << movie2.getmovie_name()
                 << " - Screen "
                 << show2.get_Screen()->get_Screen_Num()
                 << " - "
                 << show2.get_time()
                 << endl;
        }

        // ==========================================
        // 3. VIEW SEATS
        // ==========================================

        else if (choice == 3)
        {
            cout << "\n========== SELECT SHOW ==========\n";

            cout << "1. "
                 << movie1.getmovie_name()
                 << " - "
                 << show1.get_time()
                 << endl;

            cout << "2. "
                 << movie2.getmovie_name()
                 << " - "
                 << show2.get_time()
                 << endl;

            cout << "Enter show choice: ";

            int showChoice;

            if (!(cin >> showChoice))
            {
                cout << "Invalid input! Please enter 1 or 2.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            show* selectedShow = nullptr;

            if (showChoice == 1)
            {
                selectedShow = &show1;
            }
            else if (showChoice == 2)
            {
                selectedShow = &show2;
            }
            else
            {
                cout << "Invalid show choice!\n";
                continue;
            }

            // ==========================================
            // SEAT LAYOUT
            // ==========================================

            cout << "\n========== SEAT LAYOUT ==========\n";

            cout << "\nSILVER\n";

            for (showseat& showSeat : selectedShow->get_showSeat())
            {
                if (showSeat.getSeat()->get_seattype() == "SILVER")
                {
                    cout << "["
                         << showSeat.getSeat()->get_seatnum()
                         << " "
                         << (showSeat.isAvailable() ? " " : "X")
                         << "] ";
                }
            }

            cout << "\n\nGOLD\n";

            for (showseat& showSeat : selectedShow->get_showSeat())
            {
                if (showSeat.getSeat()->get_seattype() == "GOLD")
                {
                    cout << "["
                         << showSeat.getSeat()->get_seatnum()
                         << " "
                         << (showSeat.isAvailable() ? " " : "X")
                         << "] ";
                }
            }

            cout << "\n\nPLATINUM\n";

            for (showseat& showSeat : selectedShow->get_showSeat())
            {
                if (showSeat.getSeat()->get_seattype() == "PLATINUM")
                {
                    cout << "["
                         << showSeat.getSeat()->get_seatnum()
                         << " "
                         << (showSeat.isAvailable() ? " " : "X")
                         << "] ";
                }
            }

            cout << "\n\n=================================\n";
            cout << "X = BOOKED, Blank = AVAILABLE\n";
        }

        // ==========================================
        // 4. BOOK TICKET
        // ==========================================

        else if (choice == 4)
        {
            // ==========================================
            // CUSTOMER DETAILS
            // ==========================================

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string customerName;
            string customerPhone;

            cout << "\n========== CUSTOMER DETAILS ==========\n";

            cout << "Enter your name: ";
            getline(cin, customerName);

            if (customerName.empty())
            {
                cout << "Name cannot be empty.\n";
                continue;
            }

            cout << "Enter your phone number: ";
            cin >> customerPhone;

            if (customerPhone.empty())
            {
                cout << "Phone number cannot be empty.\n";
                continue;
            }

            customer currentCustomer(customerName, customerPhone);

            // ==========================================
            // SELECT SHOW
            // ==========================================

            cout << "\n========== SELECT SHOW ==========\n";

            cout << "1. "
                 << movie1.getmovie_name()
                 << " - "
                 << show1.get_time()
                 << endl;

            cout << "2. "
                 << movie2.getmovie_name()
                 << " - "
                 << show2.get_time()
                 << endl;

            cout << "Enter show choice: ";

            int showChoice;

            if (!(cin >> showChoice))
            {
                cout << "Invalid input! Please enter 1 or 2.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            show* selectedShow = nullptr;

            if (showChoice == 1)
            {
                selectedShow = &show1;
            }
            else if (showChoice == 2)
            {
                selectedShow = &show2;
            }
            else
            {
                cout << "Invalid show choice!\n";
                continue;
            }

            // ==========================================
            // DISPLAY SEAT LAYOUT
            // ==========================================

            cout << "\n========== SEAT LAYOUT ==========\n";

            cout << "\nSILVER\n";

            for (showseat& showSeat : selectedShow->get_showSeat())
            {
                if (showSeat.getSeat()->get_seattype() == "SILVER")
                {
                    cout << "["
                         << showSeat.getSeat()->get_seatnum()
                         << " "
                         << (showSeat.isAvailable() ? " " : "X")
                         << "] ";
                }
            }

            cout << "\n\nGOLD\n";

            for (showseat& showSeat : selectedShow->get_showSeat())
            {
                if (showSeat.getSeat()->get_seattype() == "GOLD")
                {
                    cout << "["
                         << showSeat.getSeat()->get_seatnum()
                         << " "
                         << (showSeat.isAvailable() ? " " : "X")
                         << "] ";
                }
            }

            cout << "\n\nPLATINUM\n";

            for (showseat& showSeat : selectedShow->get_showSeat())
            {
                if (showSeat.getSeat()->get_seattype() == "PLATINUM")
                {
                    cout << "["
                         << showSeat.getSeat()->get_seatnum()
                         << " "
                         << (showSeat.isAvailable() ? " " : "X")
                         << "] ";
                }
            }

            cout << "\n\n=================================\n";
            cout << "X = BOOKED, Blank = AVAILABLE\n";

            // ==========================================
            // NUMBER OF SEATS
            // ==========================================

            int numberOfSeats;

            cout << "\nHow many seats do you want to book? ";

            if (!(cin >> numberOfSeats))
            {
                cout << "Invalid input! Please enter a number.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            if (numberOfSeats <= 0)
            {
                cout << "Number of seats must be greater than 0.\n";
                continue;
            }

            if (numberOfSeats > selectedShow->get_showSeat().size())
            {
                cout << "Invalid number of seats!\n";
                continue;
            }

            // ==========================================
            // SELECT SEATS
            // ==========================================

            vector<showseat*> selectedSeats;

            int selectedCount = 0;

            while (selectedCount < numberOfSeats)
            {
                string seatNumber;

                cout << "\nEnter seat number (e.g. S1): ";
                cin >> seatNumber;

                showseat* selectedSeat = nullptr;

                // Find seat
                for (showseat& showSeat : selectedShow->get_showSeat())
                {
                    if (showSeat.getSeat()->get_seatnum() == seatNumber)
                    {
                        selectedSeat = &showSeat;
                        break;
                    }
                }

                // ==========================================
                // INVALID SEAT
                // ==========================================

                if (selectedSeat == nullptr)
                {
                    cout << "Invalid seat number! Please try again.\n";
                    continue;
                }

                // ==========================================
                // ALREADY BOOKED
                // ==========================================

                if (!selectedSeat->isAvailable())
                {
                    cout << "Seat "
                         << seatNumber
                         << " is already booked! Please choose another seat.\n";

                    continue;
                }

                // ==========================================
                // DUPLICATE SEAT
                // ==========================================

                bool alreadySelected = false;

                for (showseat* seat : selectedSeats)
                {
                    if (seat == selectedSeat)
                    {
                        alreadySelected = true;
                        break;
                    }
                }

                if (alreadySelected)
                {
                    cout << "Seat "
                         << seatNumber
                         << " is already selected! Please choose another seat.\n";

                    continue;
                }

                // ==========================================
                // VALID SEAT
                // ==========================================

                selectedSeats.push_back(selectedSeat);
                selectedCount++;

                cout << "Seat "
                     << seatNumber
                     << " selected successfully.\n";
            }

            // ==========================================
            // PAYMENT METHOD
            // ==========================================

            cout << "\n========== PAYMENT METHOD ==========\n";

            cout << "1. UPI\n";
            cout << "2. Card\n";
            cout << "3. Cash\n";

            cout << "Enter payment choice: ";

            int paymentChoice;

            if (!(cin >> paymentChoice))
            {
                cout << "Invalid input! Please enter 1, 2 or 3.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            payment* payment = nullptr;

            if (paymentChoice == 1)
            {
                payment = new upipayment();
            }
            else if (paymentChoice == 2)
            {
                payment = new cardpayment();
            }
            else if (paymentChoice == 3)
            {
                payment = new CashPayment();
            }
            else
            {
                cout << "Invalid payment method!\n";
                continue;
            }

            // ==========================================
            // BOOK TICKET
            // ==========================================

            BookingService bookingService;

            Booking* booking =
                bookingService.bookTicket(
                    currentCustomer,
                    *selectedShow,
                    selectedSeats,
                    *payment
                );

            delete payment;

            if (booking == nullptr)
            {
                cout << "\nBooking failed.\n";
            }
            else
            {
                bookings.push_back(booking);

                cout << "\nBooking saved successfully.\n";
            }
        }

        // ==========================================
        // 5. MY TICKET
        // ==========================================

        else if (choice == 5)
        {
            if (bookings.empty())
            {
                cout << "\nNo bookings found.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string enteredName;
            string enteredPhone;

            cout << "\n========== MY TICKET ==========\n";

            cout << "Enter your name: ";
            getline(cin, enteredName);

            cout << "Enter your phone number: ";
            cin >> enteredPhone;

            bool ticketFound = false;

            for (Booking* booking : bookings)
            {
                if (booking->getCustomer()->get_name() == enteredName &&
                    booking->getCustomer()->get_phone() == enteredPhone)
                {
                    TicketPrinter printer;

                    cout << "\nTicket Found!\n";

                    printer.printTicket(*booking);

                    ticketFound = true;
                }
            }

            if (!ticketFound)
            {
                cout << "\nNo ticket found for the entered customer details.\n";
            }
        }

        // ==========================================
        // 6. EXIT
        // ==========================================

        else if (choice == 6)
        {
            cout << "\nThank you for using Movie Ticket Booking System!\n";
            break;
        }

        // ==========================================
        // INVALID MAIN MENU CHOICE
        // ==========================================

        else
        {
            cout << "\nInvalid choice! Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
