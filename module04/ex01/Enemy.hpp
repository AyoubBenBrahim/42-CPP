#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy 
{
protected:
	int				enemyHP;
	std::string		enemyType;

public:
	Enemy(void);
	Enemy(int hp, std::string const & type);
	virtual ~Enemy(void);
	Enemy(Enemy const & copy);
	Enemy & operator=(Enemy const & rhs);

	std::string		getType() const;
	int				getHP() const;

	virtual void	takeDamage(int);
};

#endif
