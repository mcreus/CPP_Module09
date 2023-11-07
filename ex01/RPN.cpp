/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:37:16 by mcreus            #+#    #+#             */
/*   Updated: 2023/11/06 14:03:02 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	
}

RPN::RPN(std::string const &args)
{
	this->_args = args;
}

RPN::RPN(RPN const &r)
{
	*this= r;
}

RPN &RPN::operator=(RPN const &r)
{
	_args = r._args;
	return (*this);
}

RPN::~RPN()
{

}

bool	RPN::isNumeric(std::string const &index)
{
	if (index.find_first_not_of("123456789") == std::string::npos)
		return (true);
	else
		return (false);
}

bool    RPN::isOperator(std::string const &index)
{
    if (index == "+" || index == "-" || index == "/" || index == "*")
        return (true);
    else
        return (false);
}

int RPN::resultOperation(int operand1, int operand2, std::string const &op)
{
    int res = 0;
    if (op == "+")
        res = operand1 + operand2;
    else if (op == "-")
        res = operand1 - operand2;
    else if (op == "*")
        res = operand1 * operand2;
    else if (op == "/")
    {
        if (operand2 == 0)
            return (0);
        else
            res = operand1 / operand2;
    }
    return (res);
}

int	RPN::checkArg()
{
    std::stack<int>         stack;
	std::string		        index;
	std::istringstream	iss(this->_args);
	while (iss >> index)
	{
		if (isNumeric(index))
            stack.push(std::atoi(index.c_str()));
        else if (isOperator(index))
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Number of operands is not good" << std::endl;
                return (0);
            }
            else
            {
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();
                stack.push(resultOperation(operand1, operand2, index));
            }
        }
        else
        {
            std::cerr << "Error: Not good RPN" << std::endl;
            return (0);
        }
	}
    if (stack.size() == 1) 
    {
        std::cout << stack.top() << std::endl;
        return (0);
    } 
    else 
    {
        std::cerr << "Error: Invalid RPN expression." << std::endl;
        return (0);
    }
}