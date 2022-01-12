#include <iostream>
#include "Magazine.hpp"

Magazine::Magazine(int book_id, std::string book_name, std::string magazine_genre, std::string book_publisher = "", int publication_year = 0)
    : Book{book_id, book_name, "", book_publisher, publication_year}, genre{magazine_genre} {}

Magazine::Magazine(const Magazine &magazine) : Book{magazine} {}

Magazine::Magazine(Magazine &&otherMagazine)
    : Book{std::move(otherMagazine)}, genre{std::move(otherMagazine.genre)} {}

bool Magazine::operator>(Magazine &rhm)
{
    return Book::operator>(rhm);
}

bool Magazine::operator<(Magazine &rhm)
{
    return Book::operator<(rhm);
}

std::string Magazine::getGenre() const
{
    return genre;
}

void Magazine::displayBook()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Genre: " << Magazine::genre << std::endl;
    std::cout << "Puhlisher: " << publisher << std::endl;
    std::cout << "Publication Year: " << publicationYear << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

Magazine::~Magazine() {}