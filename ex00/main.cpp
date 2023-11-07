/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:39:14 by mcreus            #+#    #+#             */
/*   Updated: 2023/11/02 17:27:45 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange	*btc =	new BitcoinExchange;

    if (ac == 2)
	    btc->checkFile(av[1]);
    else
    {
        std::cerr << "Error : could not open file" << std::endl;
    }
	delete (btc);
	return (0);
}