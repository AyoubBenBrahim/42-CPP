/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:20:20 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:20:24 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie
{
	private:
		std::string		name;

	public:

		Zombie(std::string _name);
		~Zombie();
		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
