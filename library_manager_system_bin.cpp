/*
I provided ChatGPT with library_manager_system2.cpp
and asked it to generate a similar program.
The generated program is LibraryManagment/library_manager_system_bin.cpp.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

class Book {
public:
    std::string typology;
    std::string title;

    Book() : typology("Book"), title("No title") {}
    Book(std::string typology, std::string title) : typology(typology), title(title) {}

    // Serialize method for binary file (marked as const)
    void serialize(std::ofstream& out) const {
        size_t len = typology.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len)); // Write typology size
        out.write(typology.c_str(), len);                            // Write typology

        len = title.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len)); // Write title size
        out.write(title.c_str(), len);                               // Write title
    }

    // Deserialize method for binary file
    void deserialize(std::ifstream& in) {
        size_t len;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));   // Read typology size
        typology.resize(len);
        in.read(&typology[0], len);                            // Read typology

        in.read(reinterpret_cast<char*>(&len), sizeof(len));   // Read title size
        title.resize(len);
        in.read(&title[0], len);                               // Read title
    }

    // Print the book details
    void print() const {
        std::cout << "Typology: " << typology << ", Title: " << title << std::endl;
    }
};

// Manager class for handling book operations
class Manager {
public:
    std::vector<Book> books; // To store loaded books from file

    // Load books from a text file
    void loadBooksFromTxt(const std::string& filename) {
        std::ifstream file(filename);
        std::string typology, title;
        while (file >> typology) {
            std::getline(file, title); // Read title with spaces
            books.emplace_back(typology, title);
        }
        file.close();
    }

    // Load books from a binary file
    void loadBooksFromBin(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        while (file.peek() != EOF) { // Read until end of file
            Book book;
            book.deserialize(file);
            books.push_back(book);
        }
        file.close();
    }

    // Save a single book to a text file (append mode)
    void saveBookToTxt(const Book& book, const std::string& filename) {
        std::ofstream file(filename, std::ios::app);
        file << book.typology << " " << book.title << std::endl;
        file.close();
    }

    // Save a single book to a binary file (append mode)
    void saveBookToBin(const Book& book, const std::string& filename) {
        std::ofstream file(filename, std::ios::binary | std::ios::app);
        book.serialize(file);
        file.close();
    }

    // Display all books
    void displayBooks() {
        std::cout << "Books in the system:" << std::endl;
        for (const auto& book : books) {
            book.print();
        }
    }
};

// Function to measure performance
template <typename Func>
void measureTime(const std::string& format, Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << format << " operation took " << elapsed.count() << " seconds." << std::endl;
}

int main() {
    Manager manager;

    std::string txtFile = "books.txt";
    std::string binFile = "books.bin";

    int option;
    while (true) {
        std::cout << "1. Load books from .txt" << std::endl;
        std::cout << "2. Load books from .bin" << std::endl;
        std::cout << "3. Add new book" << std::endl;
        std::cout << "4. Display all books" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 1) {
            measureTime("TXT Load", [&]() { manager.loadBooksFromTxt(txtFile); });
        }
        else if (option == 2) {
            measureTime("BIN Load", [&]() { manager.loadBooksFromBin(binFile); });
        }
        else if (option == 3) {
            std::string title;
            std::cin.ignore(); // Clear buffer
            std::cout << "Enter book title: ";
            std::getline(std::cin, title);

            Book book("Book", title);
            measureTime("TXT Save", [&]() { manager.saveBookToTxt(book, txtFile); });
            measureTime("BIN Save", [&]() { manager.saveBookToBin(book, binFile); });
        }
        else if (option == 4) {
            manager.displayBooks();
        }
        else if (option == 5) {
            break;
        }
        std::cout << std::endl;
    }

    return 0;
}
