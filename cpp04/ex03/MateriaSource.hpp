#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* materias[4];  // Максимум 4 материи

public:
    MateriaSource();
    virtual ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif
