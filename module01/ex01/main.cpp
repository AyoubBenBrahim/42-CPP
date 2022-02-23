/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:21:09 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:21:11 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int		main(void)
{
	Zombie*  zHorde = zombieHorde(4, "fatherOfZombies");
	
	delete [] zHorde;

	return (0);
}
