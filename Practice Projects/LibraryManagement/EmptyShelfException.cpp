#include <exception>

class EmptyShelfException : public std::exception
{
    public:
        virtual const char* what() const noexcept
        {
            return "Can't take out book since the shelf is empty.";
        }
};