/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:00:47 by mcreus            #+#    #+#             */
/*   Updated: 2023/11/06 14:06:15 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cerr << "Error: Number of arguments!!!" << std::endl;
    else
    {
        RPN *rpn = new RPN(av[1]);
        rpn->checkArg();
        delete (rpn);
    }
}