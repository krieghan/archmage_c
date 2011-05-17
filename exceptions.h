#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class CannotDoThat : public std::exception {
public:
	std::string message;
	CannotDoThat(std::string message){
		this->message = message;
	}
};

class TooManyResults : public std::exception {
public:
	std::string message;
	TooManyResults(std::string message){
		this->message = message;
	}
};

class NoResults : public std::exception {
public:
	std::string message;
	NoResults(std::string message){
		this->message = message;
	}
};

#endif