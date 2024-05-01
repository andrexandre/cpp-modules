#ifndef FORM_HPP
#define FORM_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const str &name, int signGrade, int execGrade);
		Form(Form const &src);
		~Form();
		Form &operator=(Form const &rhs);

		const str &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &signer);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const str _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
