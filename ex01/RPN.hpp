#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>

class RPN 
{
	public:

		RPN();
        RPN(std::string const &args);
		RPN(RPN const &r);
		RPN	&operator=(RPN const &r);
		~RPN();
        bool    isNumeric(std::string const &index);
        bool    isOperator(std::string const &index);
        int     resultOperation(int operand1, int operand2, std::string const &op);
		int     checkArg();

    private:

        std::string _args;
};

#endif