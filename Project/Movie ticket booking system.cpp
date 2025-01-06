#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Movie {
    string name;
    int availableSeats;
};


void displayMovies(const vector<Movie>& movies) {
    cout << "\nAvailable Movies:\n";
    for (size_t i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].name << " - Available Seats: " << movies[i].availableSeats << "\n";
    }
}

void bookTickets(vector<Movie>& movies) {
    int movieChoice, numTickets;

    displayMovies(movies);
    cout << "\nEnter the number of the movie you want to book tickets for: ";
    cin >> movieChoice;

    if (movieChoice < 1 or movieChoice > movies.size()) {
        cout << "Invalid choice! Please try again.\n";
        return;
    }

    cout << "Enter the number of tickets you want to book: ";
    cin >> numTickets;

    if (numTickets <= 0 or numTickets > movies[movieChoice - 1].availableSeats) {
        cout << "Sorry, not enough seats available or invalid number of tickets.\n";
    } else {
        movies[movieChoice - 1].availableSeats -= numTickets;
        cout << "Booking successful! " << numTickets << " tickets booked for " << movies[movieChoice - 1].name << ".\n";
    }
}


int main() {
    vector<Movie> movies = {
        {"Avengers: Endgame", 50},
        {"Inception", 40},
        {"The Dark Knight", 30},
        {"Interstellar", 20}
    };

    int choice;
    do {
        cout << "\n--- Movie Ticket Booking System ---\n";
        cout << "1. Display Available Movies\n";
        cout << "2. Book Tickets\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMovies(movies);
                break;
            case 2:
                bookTickets(movies);
                break;
            case 3:
                cout << "Thank you for using the Movie Ticket Booking System!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
