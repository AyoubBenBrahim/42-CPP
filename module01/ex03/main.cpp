/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:22:32 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:34 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
// #define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
int main()
{

	Weapon wp = Weapon("Weapon type11111111");
	HumanA Toto("Toto", wp);
	Toto.attack();
	wp.setType("Weapon typeAAAAAAAA");
	Toto.attack();

	std::cout << "\n";

	Weapon wpp = Weapon("Weapon type22222222");
	HumanB Foo("Foo");
	Foo.setWeapon(wpp);
	Foo.attack();
	wpp.setType("Weapon typeBBBBBBBB");
	Foo.attack();
	wpp.setType("Weapon typeCCCCCCCC");
	Foo.attack();
}
#endif

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
