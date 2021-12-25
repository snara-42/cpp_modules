#include "MateriaSource.hpp"
#include <cstddef>
#include <stdexcept>

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < k_n_materia + 1; ++i)
	{
		_materiae[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < k_n_materia; ++i)
	{
		delete _materiae[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const &rhs)
{
	for (size_t i = 0; i < k_n_materia + 1; ++i)
	{
		_materiae[i] = rhs._materiae[i] ? rhs._materiae[i]->clone() : NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    if (this != &rhs)
	{
		for (size_t i = 0; i < k_n_materia; ++i)
		{
			delete _materiae[i];
			_materiae[i] = rhs._materiae[i] ? rhs._materiae[i]->clone() : NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		throw std::runtime_error("cannot learn NULL materia");
	}
	for (size_t i = 0; i < k_n_materia; ++i)
	{
		if (!_materiae[i])
		{
			_materiae[i] = m->clone();
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) const
{
	for (size_t i = 0; i < k_n_materia; ++i)
	{
		if (_materiae[i] && _materiae[i]->getType() == type)
		{
			return _materiae[i]->clone();
		}
	}
	return NULL;

}

size_t	MateriaSource::size() const
{
	size_t i;
	for (i = 0; _materiae[i] && i < k_n_materia; ++i)
		;
	return i;
}

AMateria const *MateriaSource::at(size_t i) const
{
	if (i >= k_n_materia)
		throw std::out_of_range("out of range");
	return _materiae[i];
}

std::ostream &operator<<(std::ostream &ost, MateriaSource const &rhs)
{
	ost << "MateriaSource [";
	for (size_t i = 0; rhs.at(i) && i < rhs.size(); ++i)
		ost << rhs.at(i)->getType() << " ";
	ost << "]";
	return ost;
}
