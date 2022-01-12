#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book
{
protected:
    int id, publicationYear, rating;
    std::string name, author, publisher;

public:
    Book(int book_id, std::string book_name, std::string book_author, std::string book_publisher, int publication_year);

    // Copy constructor (If we have a move constructor, we must define it. It can be empty if we don't have raw pointers to deal with)
    Book(const Book &book);

    // Move constructor
    Book(Book &&otherBook);

    //We'll overload the '>' operator based on rating
    bool operator>(const Book &rhb) const;

    //We'll also overload the '<' operator based on rating
    bool operator<(const Book &rhb) const;

    // 'const' lets the compiler know this function doesn't modify anything
    int getid() const;

    std::string getName() const;

    std::string getAuthor() const;

    int getRating() const;

    void setPublisher(std::string book_publisher);

    void setRating(int book_rating);

    // 'virtual' keyword allows us to implement polymorphism
    virtual void displayBook();
    
    // If we use virtual function, we should have a virtual desturctor
    virtual ~Book();
};

#endif
