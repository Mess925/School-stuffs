# include "AMateria.hpp"
# include "Cure.hpp"

int main() {
	AMateria *cure = new Cure();
	AMateria *cure1 = cure;
	AMateria *cure2(cure);
}
