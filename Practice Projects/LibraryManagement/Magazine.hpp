#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include <string>
#include "Book.hpp"

class Magazine : public Book
{
private:
    std::string genre;

public:
    Magazine(int book_id, std::string book_name, std::string magazine_genre, std::string book_publisher, int publication_year);

    // Copy Constructor
    Magazine(const Magazine &magazine);

    // Move Constructor
    Magazine(Magazine &&otherMagazine);

    // Operator Overloaling
    bool operator>(Magazine &rhm);
    bool operator<(Magazine &rhm);

    std::string getGenre() const;

    // Note that keywords like 'virtual' and 'override' are not allowed outside class definition
    virtual void displayBook() override;

    virtual ~Magazine();
};

#endif