#include <list>
#include <iostream>

using namespace std;
std::list<int> intersection(const std::list<int> &l1, const std::list<int> &l2)
{
    if (l1.empty() || l2.empty())
    {
        std::exit(-1);
    }
    list<int> return_list;

    list<int> l1_copy;

    for (auto &elem : l1)
    {
        l1_copy.push_back(elem);
    }
    list<int> l2_copy;
    for (auto &elem : l2)
    {
        l2_copy.push_back(elem);
    }

    l1_copy.sort();
    l2_copy.sort();

    auto it1 = l1_copy.begin();
    auto it2 = l2_copy.begin();

    while (it1 != l1_copy.end() && it2 != l2_copy.end())
    {
        if (*it1 == *it2)
        {
            return_list.push_back(*it1);
            it1++;
            it2++;
        }
        else if (*it1 < *it2)
        {
            it1++;
        }
        else
        {
            it2++;
        }
    }

    return return_list;
}

int main()
{
    list<int> gqlist1 = {1, 2, 4, 5};
    list<int> gqlist2 = {3, 4, 5, 6, 7};
    list<int> returned_inter = intersection(gqlist1, gqlist2);

    for (auto &elem : returned_inter)
    {
        std::cout << elem << " ";
    }
}