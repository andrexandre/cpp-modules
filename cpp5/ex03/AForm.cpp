#include "AForm.hpp"

AForm::AForm(const str &name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &rhs)
{
	this->_isSigned = rhs._isSigned;
	return *this;
}

const str &AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() <= _execGrade)
		this->beExecuted();
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return RED"Form::GradeTooHighException"END;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return RED"Form::GradeTooLowException"END;
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return RED"Form::FormNotSignedException"END;
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	str isSignedStr = "n't";
	if (i.getIsSigned() == true)
		isSignedStr.clear();
	o << CYAN << i.getName() << " is" << isSignedStr << " signed, SignGrade " \
	<< i.getSignGrade() << ", ExecGrade " << i.getExecGrade() << ".\n"END;
	return o;
}
