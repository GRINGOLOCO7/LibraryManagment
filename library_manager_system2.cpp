#include <iostream>

// User class
class User {
public:
    // Default constructor (if user don't give any parameter)
    User() {
        std::cout << "User constructor" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "email: " << email << std::endl;
    }

    // constructor with parameters given by user
    User(std::string name, std::string email) : name(name), email(email) {
        std::cout << "User constructor" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "email: " << email << std::endl;
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

    // return (magazine or book) abstract method
    virtual void doReturn(std::string typology, std::string title, User user) {
        std::cout << "Base return" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
        std::cout << "name: " << user.getName() << std::endl;
        std::cout << "email: " << user.getEmail() << std::endl;
    }

    // checkout (magazine or book) abstract method
    virtual void checkout(std::string typology, std::string title, User user) {
        std::cout << "Base checkout" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
        std::cout << "name: " << user.getName() << std::endl;
        std::cout << "email: " << user.getEmail() << std::endl;
    }
};

// Magazine class. Inherit from Base and User
class Magazine : public Base, public User {
public:
    Magazine(std::string typology, std::string title) : Base(typology, title) {
        std::cout << "Magazine constructor" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
    }
};

// Book class. Inherit from Base and User
class Book : public Base, public User {
public:
    Book(std::string typology, std::string title) : Base(typology, title) {
        std::cout << "Book constructor" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
    }
};

// Manager class
class Manager {
public:
    void checkout(std::string typology, std::string title, User user) {
        std::cout << "Manager checkout" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
        std::cout << "name: " << user.getName() << std::endl;
        std::cout << "email: " << user.getEmail() << std::endl;
    }

    void doReturn(std::string typology, std::string title, User user) {
        std::cout << "Manager return" << std::endl;
        std::cout << "type: " << typology << std::endl;
        std::cout << "title: " << title << std::endl;
        std::cout << "name: " << user.getName() << std::endl;
        std::cout << "email: " << user.getEmail() << std::endl;
    }
};

int main() {
    // Create a new user
    User user("John", "jon@gmail.com");

    // Manager instance
    Manager manager;

    // Create a new magazine
    Magazine magazine("Magazine", "Vogue");

    // Create a new book
    Book book("Book", "Harry Potter");

    // Perform checkout using getters for typology and title
    manager.checkout(magazine.getTypology(), magazine.getTitle(), user);

    return 0;
}
