#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ================= MOVIE CLASS =================
class Movie {
private:
    int movieId;
    string title;
    string showTime;
    float price;

public:
    Movie() {
        movieId = 0;
        title = "";
        showTime = "";
        price = 0;
    }

    Movie(int id, string t, string time, float p) {
        movieId = id;
        title = t;
        showTime = time;
        price = p;
    }

    void displayMovie() {
        cout << movieId << ". "
             << left << setw(18) << title
             << setw(12) << showTime
             << "Rs." << price << endl;
    }

    string getTitle() {
        return title;
    }

    string getShowTime() {
        return showTime;
    }

    float getPrice() {
        return price;
    }
};


// ================= SEAT CLASS =================
class Seat {
private:
    int seatNo;
    bool isBooked;

public:
    Seat() {
        seatNo = 0;
        isBooked = false;
    }

    Seat(int no) {
        seatNo = no;
        isBooked = false;
    }

    int getSeatNo() {
        return seatNo;
    }

    bool checkAvailability() {
        return !isBooked;
    }

    void bookSeat() {
        isBooked = true;
    }

    void displaySeat() {
        if (isBooked)
            cout << "[X] ";
        else
            cout << "[" << seatNo << "] ";
    }
};


// ================= BOOKING CLASS =================
class Booking {
private:
    int numTickets;
    float totalAmount;

public:
    Booking() {
        numTickets = 0;
        totalAmount = 0;
    }

    float calculateBill(float ticketPrice, int tickets) {
        numTickets = tickets;
        totalAmount = ticketPrice * tickets;
        return totalAmount;
    }

    void displayBill(string location, string theater,
                     string movie, string showTime) {

        cout << "\n============================================\n";
        cout << "              BOOKING BILL\n";
        cout << "============================================\n";

        cout << "Location    : " << location << endl;
        cout << "Theater     : " << theater << endl;
        cout << "Movie       : " << movie << endl;
        cout << "Show Time   : " << showTime << endl;
        cout << "Tickets     : " << numTickets << endl;

        cout << "Total Amount: Rs."
             << fixed << setprecision(2)
             << totalAmount << endl;

        cout << "============================================\n";
    }

    bool confirmBooking() {

        char choice;

        cout << "\nConfirm Booking? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
            return true;

        return false;
    }

    void cancelBooking() {
        cout << "\nBooking Cancelled Successfully.\n";
    }
};


// ================= MAIN BOOKING SYSTEM =================
class TicketBookingSystem {

private:

    Movie movieList[3];
    Seat seatList[20];

    string locations[30];
    string theaters[3];

    int selectedLocation;
    int selectedTheater;
    int selectedMovie;

    int selectedSeats[20];
    int selectedSeatCount;


public:

    // ================= CONSTRUCTOR =================
    TicketBookingSystem() {

        // -------- LOCATIONS --------

        locations[0] = "Visakhapatnam";
        locations[1] = "Vijayawada";
        locations[2] = "Guntur";
        locations[3] = "Tirupati";
        locations[4] = "Nellore";
        locations[5] = "Kurnool";
        locations[6] = "Rajahmundry";
        locations[7] = "Kakinada";
        locations[8] = "Kadapa";
        locations[9] = "Anantapur";
        locations[10] = "Eluru";
        locations[11] = "Ongole";
        locations[12] = "Srikakulam";
        locations[13] = "Vizianagaram";
        locations[14] = "Machilipatnam";

        locations[15] = "Hyderabad";
        locations[16] = "Warangal";
        locations[17] = "Nizamabad";
        locations[18] = "Karimnagar";
        locations[19] = "Khammam";
        locations[20] = "Ramagundam";
        locations[21] = "Mahbubnagar";
        locations[22] = "Nalgonda";
        locations[23] = "Adilabad";
        locations[24] = "Suryapet";
        locations[25] = "Siddipet";
        locations[26] = "Miryalaguda";
        locations[27] = "Jagtial";
        locations[28] = "Mancherial";
        locations[29] = "Sangareddy";


        // -------- MOVIES --------

        movieList[0] = Movie(
            1,
            "The Paradise",
            "10:00 AM",
            200
        );

        movieList[1] = Movie(
            2,
            "OG",
            "2:00 PM",
            250
        );

        movieList[2] = Movie(
            3,
            "Peddi",
            "6:00 PM",
            220
        );


        // -------- CREATE SEATS --------

        for (int i = 0; i < 20; i++) {
            seatList[i] = Seat(i + 1);
        }

        selectedLocation = -1;
        selectedTheater = -1;
        selectedMovie = -1;
        selectedSeatCount = 0;
    }


    // ================= WELCOME SCREEN =================
    void welcomeScreen() {

        cout << "\n\n";

        cout << "============================================\n";
        cout << "                                            \n";
        cout << "        MOVIE TICKET BOOKING SYSTEM         \n";
        cout << "                                            \n";
        cout << "              Welcome!                      \n";
        cout << "                                            \n";
        cout << "============================================\n";

        cout << "      Book Your Movie Tickets Easily        \n";
        cout << "============================================\n";
    }


    // ================= DISPLAY LOCATIONS =================
    void displayLocations() {

        cout << "\n============================================\n";
        cout << "             SELECT LOCATION\n";
        cout << "============================================\n";

        for (int i = 0; i < 30; i++) {

            cout << setw(2) << i + 1
                 << ". "
                 << locations[i];

            if ((i + 1) % 3 == 0)
                cout << endl;
            else
                cout << "\t";
        }

        cout << "\n============================================\n";
    }


    // ================= SELECT LOCATION =================
    bool selectLocation() {

        int choice;

        displayLocations();

        cout << "\nEnter location choice (1-30): ";
        cin >> choice;

        if (choice < 1 || choice > 30) {

            cout << "\nInvalid location choice!\n";
            return false;
        }

        selectedLocation = choice - 1;

        cout << "\nLocation Selected: "
             << locations[selectedLocation]
             << endl;

        return true;
    }


    // ================= DISPLAY THEATERS =================
    void displayTheaters() {

        cout << "\n============================================\n";
        cout << "              SELECT THEATER\n";
        cout << "============================================\n";

        cout << "Location: "
             << locations[selectedLocation]
             << "\n\n";

        cout << "1. PVR Cinemas\n";
        cout << "2. INOX\n";
        cout << "3. Cinepolis\n";

        cout << "============================================\n";
    }


    // ================= SELECT THEATER =================
    bool selectTheater() {

        int choice;

        displayTheaters();

        cout << "\nEnter theater choice (1-3): ";
        cin >> choice;

        if (choice < 1 || choice > 3) {

            cout << "\nInvalid theater choice!\n";
            return false;
        }

        selectedTheater = choice - 1;

        if (selectedTheater == 0)
            theaters[0] = "PVR Cinemas";

        else if (selectedTheater == 1)
            theaters[1] = "INOX";

        else
            theaters[2] = "Cinepolis";

        cout << "\nTheater Selected: ";

        if (selectedTheater == 0)
            cout << "PVR Cinemas";

        else if (selectedTheater == 1)
            cout << "INOX";

        else
            cout << "Cinepolis";

        cout << endl;

        return true;
    }


    // ================= DISPLAY MOVIES =================
    void displayMovies() {

        cout << "\n============================================\n";
        cout << "             AVAILABLE MOVIES\n";
        cout << "============================================\n";

        cout << left
             << setw(5) << "No."
             << setw(18) << "Movie"
             << setw(12) << "Time"
             << "Price\n";

        cout << "--------------------------------------------\n";

        for (int i = 0; i < 3; i++) {

            movieList[i].displayMovie();
        }

        cout << "============================================\n";
    }


    // ================= SELECT MOVIE =================
    bool selectMovie() {

        int choice;

        cout << "\nEnter movie choice (1-3): ";
        cin >> choice;

        if (choice < 1 || choice > 3) {

            cout << "\nInvalid movie choice!\n";
            return false;
        }

        selectedMovie = choice - 1;

        cout << "\nMovie Selected: "
             << movieList[selectedMovie].getTitle()
             << endl;

        cout << "Show Time: "
             << movieList[selectedMovie].getShowTime()
             << endl;

        cout << "Ticket Price: Rs."
             << movieList[selectedMovie].getPrice()
             << endl;

        return true;
    }


    // ================= DISPLAY SEATS =================
    void displaySeats() {

        cout << "\n============================================\n";
        cout << "               SEAT LAYOUT\n";
        cout << "============================================\n";

        cout << "[X] = Booked\n\n";

        for (int i = 0; i < 20; i++) {

            seatList[i].displaySeat();

            if ((i + 1) % 5 == 0)
                cout << endl;
        }

        cout << "============================================\n";
    }


    // ================= SELECT SEATS =================
    bool selectSeats(int numberOfTickets) {

        selectedSeatCount = 0;

        for (int i = 0; i < numberOfTickets; i++) {

            int seatNumber;

            cout << "\nEnter seat number for ticket "
                 << i + 1 << ": ";

            cin >> seatNumber;

            if (seatNumber < 1 || seatNumber > 20) {

                cout << "Invalid seat number!\n";
                return false;
            }

            int index = seatNumber - 1;

            // Check availability

            if (!seatList[index].checkAvailability()) {

                cout << "Seat "
                     << seatNumber
                     << " is already booked!\n";

                return false;
            }

            // Check duplicate selection

            for (int j = 0; j < selectedSeatCount; j++) {

                if (selectedSeats[j] == seatNumber) {

                    cout << "You already selected Seat "
                         << seatNumber
                         << "!\n";

                    return false;
                }
            }

            selectedSeats[selectedSeatCount] =
                seatNumber;

            selectedSeatCount++;
        }

        return true;
    }


    // ================= BOOK SEATS =================
    void bookSelectedSeats() {

        for (int i = 0;
             i < selectedSeatCount;
             i++) {

            int seatNumber =
                selectedSeats[i];

            seatList[seatNumber - 1].bookSeat();
        }
    }


    // ================= GET THEATER NAME =================
    string getTheaterName() {

        if (selectedTheater == 0)
            return "PVR Cinemas";

        else if (selectedTheater == 1)
            return "INOX";

        else
            return "Cinepolis";
    }


    // ================= RUN SYSTEM =================
    void run() {

        // Welcome screen

        welcomeScreen();


        // Step 1: Select Location

        if (!selectLocation())
            return;


        // Step 2: Select Theater

        if (!selectTheater())
            return;


        // Step 3: Display Movies

        displayMovies();


        // Step 4: Select Movie

        if (!selectMovie())
            return;


        // Step 5: Display Seats

        displaySeats();


        // Step 6: Number of Tickets

        int numberOfTickets;

        cout << "\nEnter number of tickets: ";
        cin >> numberOfTickets;


        // Validate tickets

        if (numberOfTickets <= 0 ||
            numberOfTickets > 20) {

            cout << "\nInvalid number of tickets!\n";
            cout << "Please enter between 1 and 20.\n";

            return;
        }


        // Step 7: Select Seats

        if (!selectSeats(numberOfTickets)) {

            cout << "\nSeat selection failed.\n";
            cout << "Please restart the booking.\n";

            return;
        }


        // Step 8: Create Booking

        Booking booking;


        float total =
            booking.calculateBill(
                movieList[selectedMovie].getPrice(),
                numberOfTickets
            );


        // Step 9: Display Bill

        booking.displayBill(
            locations[selectedLocation],
            getTheaterName(),
            movieList[selectedMovie].getTitle(),
            movieList[selectedMovie].getShowTime()
        );


        // Display selected seats

        cout << "Selected Seats: ";

        for (int i = 0;
             i < selectedSeatCount;
             i++) {

            cout << selectedSeats[i];

            if (i < selectedSeatCount - 1)
                cout << ", ";
        }

        cout << endl;


        // Step 10: Confirm Booking

        if (booking.confirmBooking()) {

            // Book seats only after confirmation

            bookSelectedSeats();


            cout << "\n============================================\n";
            cout << "             BOOKING CONFIRMED!\n";
            cout << "============================================\n";

            cout << "Location : "
                 << locations[selectedLocation]
                 << endl;

            cout << "Theater  : "
                 << getTheaterName()
                 << endl;

            cout << "Movie    : "
                 << movieList[selectedMovie].getTitle()
                 << endl;

            cout << "Show Time: "
                 << movieList[selectedMovie].getShowTime()
                 << endl;

            cout << "Seats    : ";

            for (int i = 0;
                 i < selectedSeatCount;
                 i++) {

                cout << selectedSeats[i]
                     << " ";
            }

            cout << endl;

            cout << "Total    : Rs."
                 << fixed
                 << setprecision(2)
                 << total
                 << endl;

            cout << "\nThank you for booking!\n";

        }

        else {

            booking.cancelBooking();
        }


        // Step 11: Updated Seats

        cout << "\nUpdated Seat Status:\n";

        displaySeats();
    }
};


// ================= MAIN FUNCTION =================
int main() {

    TicketBookingSystem system;

    system.run();

    return 0;
}
