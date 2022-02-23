/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:23:55 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:23:59 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Karen.hpp"

int main()
{
	Karen karen;

	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");
	karen.~Karen();
}
