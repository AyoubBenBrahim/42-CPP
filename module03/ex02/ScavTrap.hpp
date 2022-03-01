/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:25:39 by aybouras          #+#    #+#             */
/*   Updated: 2022/03/01 09:25:41 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERENA_HPP
#define SERENA_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		~ScavTrap(void);
        ScavTrap(std::string const & _name);
		ScavTrap(ScavTrap const& copy);

		ScavTrap	&operator=(ScavTrap const &rhs);

		void	guardGate(void);
};

std::ostream &operator<<(std::ostream &outStream, ScavTrap const &rhs);

#endif
