#include <fstream>
#include <iostream>
#include <string>

// User class
class User {
public:
    // Default constructor (if user don't give any parameter)
    User() {
        std::cout << "User constructor" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "email: " << email << std::endl;
        // add user to users.txt file
        std::ofstream file("users.txt", std::ios::app);
        file << name << " " << email << std::endl;
        file.close();
    }

    // constructor with parameters given by user
    User(std::string name, std::string email) : name(name), email(email) {
        std::cout << "User constructor" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "email: " << email << std::endl;
        // add user to users.txt file
        std::ofstream file("users.txt", std::ios::app);
        file << name << " " << email << std::endl;
        file.close();
    }

    // Getters for protected members
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

protected:
    // protected so nested classes can access them, but not the outside world
    std::string name = "No name";
    std::string email = "No email";
};


// abstract Base class: blue print for Magazine or Book classes. Magazine and Book classes will be "chidrens of Base".
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

protected: // protected so nested classes can access them, but not the outside world
    std::string typology = "No typology";
    std::string title = "No title";
};

// Magazine class. Inherit from Base
class Magazine : public Base {
public:
    Magazine(std::string typology, std::string title) : Base(typology, title) {
        std::cout << "Magazine constructor" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
        // add magazine to magazines.txt file
        std::ofstream file("magazines.txt", std::ios::app);
        file << typology << " " << title << std::endl;
        file.close();
    }
};

// Book class. Inherit from Base
class Book : public Base {
public:
    Book(std::string typology, std::string title) : Base(typology, title) {
        std::cout << "Book constructor" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
        // add book to books.txt file
        std::ofstream file("books.txt", std::ios::app);
        file << typology << " " << title << std::endl;
        file.close();
    }
};

// Manager class
class Manager {
public:
    // For dropdown menu:
    void getUsers() {
        std::cout << "Manager get users" << std::endl;
        //oper users.txt file and print all users
        std::ifstream file("users.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    void getBooks() {
        std::cout << "Manager get books" << std::endl;
        //oper books.txt file and print all books
        std::ifstream file("books.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    void getMagazines() {
        std::cout << "Manager get magazines" << std::endl;
        //oper magazines.txt file and print all magazines
        std::ifstream file("magazines.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    void getCheckouts() {
        std::cout << "Manager get checkouts" << std::endl;
        //oper checkouts.txt file and print all checkouts
        std::ifstream file("checkouts.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }

    // creat tetemlate funcion to search a book
    template <typename T>
    void searchBook(T title) {
        std::cout << "Manager search book" << std::endl;
        //oper books.txt file and search for a book
        std::ifstream file("books.txt");
        std::string line;
        while (std::getline(file, line)) {
            if (line.find(title) != std::string::npos) {
                std::cout << line << std::endl;
            }
        }
        file.close();
    }


    // Actions
    void checkout(std::string typology, std::string title, User user) {
        std::cout << "Manager checkout" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
        std::cout << "name: " << user.getName() << std::endl;
        std::cout << "email: " << user.getEmail() << std::endl;
        // add checkout to checkouts.txt file in form of user, typology, title
        std::ofstream file("checkouts.txt", std::ios::app);
        file << user.getName() << " " << user.getEmail() << " " << typology << " " << title << std::endl;
        file.close();
    }

    void doReturn(std::string typology, std::string title, User user) {
        std::cout << "Manager return" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
        std::cout << "name: " << user.getName() << std::endl;
        std::cout << "email: " << user.getEmail() << std::endl;
        // remove checkout from checkouts.txt file
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
        // add book or magazine to books.txt or magazines.txt file
        if (typology == "Book") {
            std::ofstream file("books.txt", std::ios::app);
            file << typology << " " << title << std::endl;
            file.close();
        } else if (typology == "Magazine") {
            std::ofstream file("magazines.txt", std::ios::app);
            file << typology << " " << title << std::endl;
            file.close();
        }
    }
};

int main() {
    //create while true dropdown menu
    while (true)
    {
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
        std::cout << "10. search Book" << std::endl;
        std::cout << "Choose an option: ";
        int option;
        std::cin >> option;
        if (option == 1)
        {
            Manager manager;
            manager.getUsers();
        }
        else if (option == 2)
        {
            Manager manager;
            manager.getBooks();
        }
        else if (option == 3)
        {
            Manager manager;
            manager.getMagazines();
        }
        else if (option == 4)
        {
            Manager manager;
            manager.getCheckouts();
        }
        else if (option == 5) // Checkout
        {
            std::string typology;
            std::string title;
            std::string name;
            std::string email;
            std::cout << "Enter typology: ";
            std::cin >> typology;
            std::cin.ignore(); // This will clear any newline left in the buffer after the previous input
            std::cout << "Enter title: ";
            std::getline(std::cin, title); // Read the full title, including spaces
            std::cout << "Enter name: ";
            std::getline(std::cin, name); // Read full name
            std::cout << "Enter email: ";
            std::getline(std::cin, email); // Read full email
            User user(name, email);
            Manager manager;
            manager.checkout(typology, title, user);
        }
        else if (option == 6) // Return
        {
            std::string typology;
            std::string title;
            std::string name;
            std::string email;
            std::cout << "Enter typology: ";
            std::cin >> typology;
            std::cin.ignore(); // Clear the buffer after reading typology
            std::cout << "Enter title: ";
            std::getline(std::cin, title); // Read the full title, including spaces
            std::cout << "Enter name: ";
            std::getline(std::cin, name); // Read full name
            std::cout << "Enter email: ";
            std::getline(std::cin, email); // Read full email
            User user(name, email);
            Manager manager;
            manager.doReturn(typology, title, user);
        }
        else if (option == 7) // Add book
        {
            std::string typology = "Book";
            std::string title;
            std::cout << "Enter title: ";
            std::cin.ignore(); // Clear buffer before reading title
            std::getline(std::cin, title); // Read full title, including spaces
            Book book(typology, title);
        }
        else if (option == 8) // Add magazine
        {
            std::string typology = "Magazine";
            std::string title;
            std::cout << "Enter title: ";
            std::cin.ignore(); // Clear buffer before reading title
            std::getline(std::cin, title); // Read full title, including spaces
            Magazine magazine(typology, title);
        }
        // add user
        else if (option == 9)
        {
            std::string name;
            std::string email;
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter email: ";
            std::cin >> email;
            User user(name, email);
        }
        // search book
        else if (option == 10)
        {
            std::string title;
            std::cout << "Enter title: ";
            std::cin.ignore(); // Clear buffer before reading title
            std::getline(std::cin, title); // Read full title, including spaces
            Manager manager;
            manager.searchBook(title);
        }
        else if (option == 0) // Exit
        {
            break;
        }
        // add space to better print understanding
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
