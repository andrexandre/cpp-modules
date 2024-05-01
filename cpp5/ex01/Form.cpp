#include "Form.hpp"

Form::Form(const str &name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
}

Form::~Form()
{
}

Form &Form::operator=(Form const &rhs)
{
	this->_isSigned = rhs._isSigned;
	return *this;
}

const str &Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return RED"Form::GradeTooHighException"END;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return RED"Form::GradeTooLowException"END;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	str isSignedStr = "n't";
	if (i.getIsSigned() == true)
		isSignedStr.clear();
	o << CYAN << i.getName() << ", is" << isSignedStr << " signed, SignGrade " \
	<< i.getSignGrade() << ", ExecGrade " << i.getExecGrade() << ".\n"END;
	return o;
}
