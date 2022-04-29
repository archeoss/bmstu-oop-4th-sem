#ifndef _ERRORS_H_
#define _ERRORS_H_
#include <cstring>
#include <exception>
#include <string>

using str = std::string;

class base_err : public std::exception {
public:
    base_err(const str &time, const str &filename, const str &classname, const str &method)
	{
        error_info = "\nTime: " + time +
                     "\tFile: " + filename +
                     "\n\tClass: " + classname +
                     "\n\tMethod: " + method;
    }

    const char *what() const noexcept override
	{
        std::string message = "\nERROR: Something is wrong with your set." + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }

protected:
    std::string error_info;
};

class bad_alloc_err : base_err {
public:
    bad_alloc_err(const str &time, const str &filename, const str &classname, const str &method)
									: base_err(time, filename, classname, method){};

    const char *what() const noexcept override
	{
        std::string message = "\nERROR: Unable to allocate memory. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class iterator_error : base_err {
public:
    iterator_error(const str &time, const str &filename, const str &classname, const str &method)
								: base_err(time, filename, classname, method){};

    const char *what() const noexcept override
	{
        std::string message = "\nERROR: Invalid iterator. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class set_range_error : public base_err
{
public:
	set_range_error(const str &time, const str &filename, const str &classname, const str &method)
			: base_err(time, filename, classname, method){};

	const char *what() const noexcept override
	{
		std::string message = "\nERROR: Index out of range. " + error_info;
		char *cmessage = new char[1 + message.size()];
		std::strcpy(cmessage, message.c_str());
		return cmessage;
	}
};
#endif // !_ERRORS_H_