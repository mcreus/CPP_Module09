/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:58:53 by mcreus            #+#    #+#             */
/*   Updated: 2023/11/06 16:09:19 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(PmergeMe const &p)
{
    *this = p;
}

PmergeMe    &PmergeMe::operator=(PmergeMe const &)
{
    return (*this);
}

PmergeMe::~PmergeMe()
{

}

void    PmergeMe::mergeInsertSort(std::vector<int> &vector)
{
    if (vector.size() <= 1)
    {
        return ;
    }

    size_t  middle = vector.size() / 2;
    std::vector<int>    left(vector.begin(), vector.begin() + middle);
    std::vector<int>    right(vector.begin() + middle, vector.end());
    mergeInsertSort(left);
    mergeInsertSort(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), vector.begin());
}