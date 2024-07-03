LOGIN/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:21:00 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:21:03 by aybouras         ###   ########.fr       */
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

		Zombie();
		Zombie(std::string _name);
		~Zombie();
		void		announce(void);
		std::string	getName(void);
		void		setname(std::string zName);
};

Zombie*		zombieHorde(int N, std::string name);

#endif
