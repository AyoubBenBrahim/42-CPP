LOGIN/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:25:30 by aybouras          #+#    #+#             */
/*   Updated: 2022/03/01 09:25:32 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
        FragTrap(std::string const & _name);
		FragTrap(FragTrap const& copy);
        void highFivesGuys(void);

		FragTrap	&operator=(FragTrap const &rhs);

		
};

std::ostream &operator<<(std::ostream &outStream, FragTrap const &rhs);


#endif
