#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <ctime>
# include <algorithm>

class PmergeMe
{
    public:

        PmergeMe();
        PmergeMe(PmergeMe const &p);
        PmergeMe    &operator=(PmergeMe const &);
        ~PmergeMe();
        void    mergeInsertSort(std::vector<int> &vector);
};

#endif