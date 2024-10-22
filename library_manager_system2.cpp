#include <fstream>
#include <iostream>
#include <string>

// User class
class User {
public:
    // Default constructor (if user doesn't give any parameter)
    User() {
        std::cout << "User constructor" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "email: " << email << std::endl;
        // Add user to users.txt file
        std::ofstream file("users.txt", std::ios::app);
        file << name << " " << email << std::endl;
        file.close();
    }

    // Constructor with parameters given by user
    User(std::string name, std::string email) : name(name), email(email) {
        std::cout << "User constructor" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "email: " << email << std::endl;
        // Add user to users.txt file
        std::ofstream file("users.txt", std::ios::app);
        file << name << " " << email << std::endl;
        file.close();
    }

    // Getters for protected members
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

protected:
    std::string name = "No name";
    std::string email = "No email";
};

// Abstract Base class
class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
    }

    Base(std::string typology, std::string title) : typology(typology), title(title) {
        std::cout << "Base constructor" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
    }

    // Getter methods to access protected members
    std::string getTypology() const { return typology; }
    std::string getTitle() const { return title; }

protected:
    std::string typology = "No typology";
    std::string title = "No title";
};

// Magazine class inheriting from Base
class Magazine : public Base {
public:
    Magazine(std::string typology, std::string title) : Base(typology, title) {
        std::cout << "Magazine constructor" << std::endl;
        // Add magazine to magazines.txt file
        std::ofstream file("magazines.txt", std::ios::app);
        file << typology << " " << title << std::endl;
        file.close();
    }
};

// Book class inheriting from Base with "author" and "year"
class Book : public Base {
public:
    Book(std::string typology, std::string title, std::string author, int year)
        : Base(typology, title), author(author), year(year) {
        std::cout << "Book constructor" << std::endl;
        // Add book to books.txt file
        std::ofstream file("books.txt", std::ios::app);
        file << typology << " " << title << " " << author << " " << year << std::endl;
        file.close();
    }

private:
    std::string author;
    int year;
};

// Manager class
class Manager {
public:
    void getUsers() {
        std::cout << "Manager get users" << std::endl;
        std::ifstream file("users.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }

    void getBooks() {
        std::cout << "Manager get books" << std::endl;
        std::ifstream file("books.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }

    void getMagazines() {
        std::cout << "Manager get magazines" << std::endl;
        std::ifstream file("magazines.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }

    void getCheckouts() {
        std::cout << "Manager get checkouts" << std::endl;
        std::ifstream file("checkouts.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }

    // Template function to search a book by title, author, or year
    template <typename T>
    void searchBook(T query) {
        std::cout << "Manager search book" << std::endl;
        std::ifstream file("books.txt");
        std::string line;
        while (std::getline(file, line)) {
            if (line.find(query) != std::string::npos) {
                std::cout << line << std::endl;
            }
        }
        file.close();
    }

    // Checkout action
    void checkout(std::string typology, std::string title, User user) {
        std::cout << "Manager checkout" << std::endl;
        std::ofstream file("checkouts.txt", std::ios::app);
        file << user.getName() << " " << user.getEmail() << " " << typology << " " << title << std::endl;
        file.close();
    }

    // Return action
    void doReturn(std::string typology, std::string title, User user) {
        std::ifstream file("checkouts.txt");
        std::string line;
        std::ofstream temp("temp.txt");
        while (std::getline(file, line)) {
            if (line != user.getName() + " " + user.getEmail() + " " + typology + " " + title) {
                temp << line << std::endl;
            }
        }
        file.close();
        temp.close();
        remove("checkouts.txt");
        rename("temp.txt", "checkouts.txt");
    }
};

int main() {
    while (true) {
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Get users" << std::endl;
        std::cout << "2. Get books" << std::endl;
        std::cout << "3. Get magazines" << std::endl;
        std::cout << "4. Get checkouts" << std::endl;
        std::cout << "5. Checkout" << std::endl;
        std::cout << "6. Return" << std::endl;
        std::cout << "7. Add book" << std::endl;
        std::cout << "8. Add magazine" << std::endl;
        std::cout << "9. Add user" << std::endl;
        std::cout << "10. Search book by title/author/year" << std::endl;
        std::cout << "Choose an option: ";
        int option;
        std::cin >> option;

        if (option == 1) {
            Manager manager;
            manager.getUsers();
        } else if (option == 2) {
            Manager manager;
            manager.getBooks();
        } else if (option == 3) {
            Manager manager;
            manager.getMagazines();
        } else if (option == 4) {
            Manager manager;
            manager.getCheckouts();
        } else if (option == 5) {
            std::string typology, title, name, email;
            std::cout << "Enter typology: ";
            std::cin >> typology;
            std::cin.ignore();
            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            User user(name, email);
            Manager manager;
            manager.checkout(typology, title, user);
        } else if (option == 6) {
            std::string typology, title, name, email;
            std::cout << "Enter typology: ";
            std::cin >> typology;
            std::cin.ignore();
            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            User user(name, email);
            Manager manager;
            manager.doReturn(typology, title, user);
        } else if (option == 7) {
            std::string typology = "Book", title, author;
            int year;
            std::cout << "Enter title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter author: ";
            std::getline(std::cin, author);
            std::cout << "Enter year: ";
            std::cin >> year;
            Book book(typology, title, author, year);
        } else if (option == 8) {
            std::string typology = "Magazine", title;
            std::cout << "Enter title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            Magazine magazine(typology, title);
        } else if (option == 9) {
            std::string name, email;
            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            User user(name, email);
        } else if (option == 10) {
            std::cout << "Enter title/author/year to search: ";
            std::cin.ignore();
            std::string query;
            std::getline(std::cin, query);
            Manager manager;
            manager.searchBook(query);
        } else if (option == 0) {
            break;
        }
    }
    return 0;
}
