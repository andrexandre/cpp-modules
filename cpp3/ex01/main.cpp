#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap st("S. Guy");
	st.attack("them");
	st.takeDamage(5);
	st.beRepaired(5);
	return 0;
}
