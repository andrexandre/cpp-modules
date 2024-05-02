#ifndef AFORM_HPP
#define AFORM_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const str &name, int signGrade, int execGrade);
		AForm(AForm const &src);
		virtual ~AForm();
		AForm &operator=(AForm const &rhs);

		const str &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &signer);
		void execute(Bureaucrat const &executor) const;
		virtual void beExecuted() const = 0;

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
		class FormNotSignedException : public std::exception
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

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif
