/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:25:44 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:25:47 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int		main(void)
{
	std::cout << "--- using Zombie.cpp ---\n\n";
	Zombie  zombyFather = Zombie("zombyFather");


	std::cout << "\n--- using newZombie.cpp ---\n\n";
	Zombie  *child_zomb1 = newZombie("child_zomb1");
	delete child_zomb1;
	Zombie  *child_zomb2 = newZombie("child_zomb2");
	delete child_zomb2;


	std::cout << "\n--- using randomChump.cpp ---\n";
	randomChump("randomZomb");
}
