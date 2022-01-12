#include <iostream>
#include <vector>
#include <memory>
#include "Book.cpp"
#include "Magazine.cpp"
#include "EmptyShelfException.cpp"

void takeOutBook(std::vector<Book> &bookShelf)
{
    // Intentionally trying to generate exception
    for (int i = 0; i < 4; i++)
    {
        if (i < bookShelf.size())
        {
            bookShelf.pop_back();
        }
        else
        {
            throw EmptyShelfException{};
        }
    }
}

int main()
{
    Book book1{1, "COSMOS", "Carl Sagan"};

    // std::cout << book1.getid() << std::endl;
    // std::cout << book1.getName() << std::endl;
    // std::cout << book1.getAuthor() << std::endl;

    const Book book2{2, "Harry Potter", "JK Rowling"};

    Book book3{5, "Astrophycis For People In a Hurry", "Neil DeGrasse Tyson"};

    // std::vector<Book> books {};
    // books.push_back(Book{3, "Physics", "Some Physycist"});
    // books.push_back(Book{4, "Chemistry", "Some Chemist"});

    // for(auto &book : books)
    // {
    //     std::cout << book.getName() << std::endl;
    //     std::cout << book.getAuthor() << std::endl;
    // }

    // book1.setRating(4);
    // book3.setRating(5);

    // bool r = book3 > book1;

    // std::cout << r << std::endl;

    Magazine magazine1{6, "Forbes", "Lifestyle"};

    // std::cout << magazine1.getName() << std::endl;
    // std::cout << magazine1.getGenre() << std::endl;
    // std::cout << magazine1.getRating() << std::endl;

    // std::vector<Magazine> magazines {};
    // magazines.push_back(Magazine{7, "time", "news"});
    // magazines.push_back(Magazine{8, "Vanity Fair", "Glamour"});

    // for(auto &magazine : magazines)
    // {
    //     std::cout << magazine.getName() << std::endl;
    //     std::cout << magazine.getGenre() << std::endl;
    // }

    Magazine magazine2{9, "National Gergraphic", "Science"};

    magazine1.setRating(4);
    magazine2.setRating(5);

    // bool r = magazine1 < magazine2;
    // std::cout << r << std::endl;

    // book1.displayBook();

    // Dynamically allocating memory using the 'new' keyword
    // Book *book4 = new Magazine{10, "Scientific American", "Science"};
    // book4->displayBook();

    // Using Smart pointer that delete themselves when we go outside scope
    // Method 1
    std::unique_ptr<Book> book5{new Book{11, "The Dragons of Eden", "Carl Sagan"}};
    // book5->displayBook();
    // Method 2 (Recommended)
    std::unique_ptr<Book> book6 = std::make_unique<Book>(12, "The Demon Haunted World", "Carl Sagan");
    // book6->displayBook();

    // Shared smart pointer that can be copied
    std::shared_ptr<Book> book7 = std::make_shared<Book>(13, "Physics", "Physics Author");
    //book7->displayBook();

    std::shared_ptr<Book> book8 = book7;
    // Use_count keeps track of copies by itself. Another type of smart pointer, 'Weak pointers' are like shared pointers but without this counter to prevent a strong
    // circular relationship
    //std::cout << book7.use_count() << std::endl;

    // Throwing exceptions using user defined class (Recommended). C++ also allows to throw premitives as exceptions as well as classes
    // that do not inherit from std::exception
    std::vector<Book> bookShelf{};
    bookShelf.push_back(book1);
    bookShelf.push_back(book2);
    bookShelf.push_back(book3);

    try
    {
        takeOutBook(bookShelf);
    }
    catch(const EmptyShelfException &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Post exception code" << std::endl;
}