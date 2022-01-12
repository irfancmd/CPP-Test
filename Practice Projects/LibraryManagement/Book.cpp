#include<iostream>
#include "Book.hpp"

Book::Book(int book_id, std::string book_name, std::string book_author, std::string book_publisher = "", int publication_year = 0)
    : id{book_id}, name{book_name}, author{book_author}, publisher{book_publisher}, publicationYear{publication_year}
{
    // We'll not give the book any rating during its creation
    rating = 0;
}

Book::Book(const Book &book) {}

Book::Book(Book &&otherBook)
        : id{std::__exchange(otherBook.id, 0)}, publicationYear{std::__exchange(otherBook.publicationYear, 0)}, rating{std::__exchange(otherBook.rating, 0)}, // 'exchange' for non-class type
        name{std::move(otherBook.name)}, author{std::move(otherBook.author)}, publisher{std::move(otherBook.publisher)} {} // 'move' for class type

bool Book::operator>(const Book &rhb) const
{
    return (*this).rating > rhb.rating;
}

bool Book::operator<(const Book &rhb) const
{
    return (*this).rating < rhb.rating;
}

int Book::getid() const
{
    return id;
}

std::string Book::getName() const
{
    return name;
}

std::string Book::getAuthor() const
{
    return author;
}

int Book::getRating() const
{
    return rating;
}

void Book::setPublisher(std::string book_publisher)
{
    publisher = book_publisher;
}

void Book::setRating(int book_rating)
{
    rating = book_rating;
}

void Book::displayBook()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Puhlisher: " << publisher << std::endl;
    std::cout << "Publication Year: " << publicationYear << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

Book::~Book() {}