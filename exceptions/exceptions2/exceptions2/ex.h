#pragma once
#include <stdexcept>
#include <exception>
class ex : public std::domain_error {
	using domain_error::domain_error;
};