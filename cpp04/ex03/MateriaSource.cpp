#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        materias[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (materias[i]) {
            delete materias[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] == NULL) {
            materias[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] && materias[i]->getType() == type) {
            return materias[i]->clone();
        }
    }
    return NULL;
}
