#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const str &name, int grade) : _name(name), _grade(grade)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	return *this;
}

const str &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < HIGHEST_GRADE)
		throw GradeTooHighException();
	_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (_grade  + 1 > LOWEST_GRADE)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		co << GREEN << this->_name << " signed " << form.getName() << END << nl;
	}
	catch(const std::exception &e)
	{
		co << MAGENTA << this->_name << " couldn't sign " << form.getName() << " because the grade is too low.\n"END;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return RED"Bureaucrat::GradeTooHighException"END;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return RED"Bureaucrat::GradeTooLowException"END;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << GREEN << i.getName() << ", bureaucrat grade " << i.getGrade() << ".\n"END;
	return o;
}
