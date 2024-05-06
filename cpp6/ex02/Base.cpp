#include "Base.hpp"

Base::~Base()
{}

Base *generate(void)
{
	Base *pBase = NULL;
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			pBase = new A();
			co << "Generated: A" << nl;
			break;
		case 1:
			pBase = new B();
			co << "Generated: B" << nl;
			break;
		case 2:
			pBase = new C();
			co << "Generated: C" << nl;
			break;
		default:
			co << "Error: Unknown class" << nl;
			break;
	}
	return pBase;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		co << "Class type A" << nl;
	else if (dynamic_cast<B*>(p))
		co << "Class type B" << nl;
	else if (dynamic_cast<C*>(p))
		co << "Class type C" << nl;
	else
		co << "Unknown class type" << nl;
}

// here we have to use a try catch because a reference can not be NULL
void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		co << "Class type A" << nl;
	}
	catch (const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			co << "Class type B" << nl;
		}
		catch (const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				co << "Class type C" << nl;
			}
			catch (const std::exception& e)
			{
				co << "Unknown class type" << nl;
			}
		}
	}
}
