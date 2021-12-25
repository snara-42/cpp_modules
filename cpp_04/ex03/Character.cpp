#include "Character.hpp"
#include <cstddef>

Character::Character(std::string const name): _name(name)
{
	for (size_t i = 0; i < k_n_materia + 1; ++i)
	{
		_materiae[i] = NULL;
	}
}

Character::~Character()
{
	for (size_t i = 0; i < k_n_materia; ++i)
	{
		delete _materiae[i];
	}
}

Character::Character(Character const &rhs): _name(rhs._name)
{
	for (size_t i = 0; i < k_n_materia + 1; ++i)
	{
		_materiae[i] = rhs._materiae[i] ? rhs._materiae[i]->clone() : NULL;
	}
}

Character &Character::operator=(Character const &rhs)
{
    if (this != &rhs)
    {
		this->_name = rhs._name;
		for (size_t i = 0; i < k_n_materia; ++i)
		{
			delete _materiae[i];
			_materiae[i] = rhs._materiae[i] ? rhs._materiae[i]->clone() : NULL;
		}
    }
    return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		throw std::runtime_error("cannot equip NULL materia");
	}
	for (size_t i = 0; i < k_n_materia; ++i)
	{
		if (!_materiae[i])
		{
			_materiae[i] = m;
			return;
		}
	}

}

void Character::unequip(int i)
{
	if (static_cast<size_t>(i) >= k_n_materia || !_materiae[i])
		return;
	_materiae[i] = NULL;
}

void Character::use(int i, ICharacter& target)
{
	if (static_cast<size_t>(i) >= k_n_materia || !_materiae[i])
		return;
	_materiae[i]->use(target);
}

size_t	Character::size() const
{
	return k_n_materia;
}

AMateria const *Character::at(size_t i) const
{
	if (i >= k_n_materia)
		throw std::out_of_range("out of range");
	return _materiae[i];
}
std::ostream &operator<<(std::ostream &ost, Character const &rhs)
{
	ost << "Character [";
	for (size_t i = 0; i < rhs.size(); ++i)
		ost << (rhs.at(i) ? rhs.at(i)->getType() : "(empty)") << " ";
	ost << "]";
	return ost;
}
