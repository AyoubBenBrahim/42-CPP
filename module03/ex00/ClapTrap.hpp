/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:24:26 by aybouras          #+#    #+#             */
/*   Updated: 2022/03/01 09:24:28 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_HPP
#define CLAP_HPP

#include <iostream>
#include <string>

class ClapTrap 
{
private:
	std::string	name;
	int			hitPoints;
	int 		energyPoints;
	int			attackDamage;
public:
    ClapTrap(void);
    ~ClapTrap(void);
    ClapTrap(std::string const & name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap &operator=(const ClapTrap &fxOverload);

    void            attack(std::string const & target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

	std::string     getName(void) const;
	unsigned int    getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

    void            setName(std::string name);
	void		    setHitPoints(int amount);
	void		    setEnergyPoints(unsigned int amount);
	void		    setAttackDamage(unsigned int amount);
};

std::ostream &operator<<(std::ostream &outStream, ClapTrap const &rhs);

#endif
