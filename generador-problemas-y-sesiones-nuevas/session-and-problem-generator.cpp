#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <chrono>
#include "bintree_rand.hh"

std::vector<std::string> transform_vector(std::set<std::string> problems, const std::vector<int>& vec_tree)
{
    std::vector<std::string> return_vec;
    int set_size = problems.size();
    for (const auto& elem : vec_tree)
    {
	if (elem == 0)
	{
	    return_vec.push_back("0");
	}
	else
	{
	    auto it = problems.begin();
	    std::advance(it, rand()%set_size);
	    return_vec.push_back(*it);
	}
    }
    return return_vec;
}

int main()
{
    srand(5);
    std::string prob = "Problema";
    std::string sesion = "Sesion";
    unsigned seed1 = 5;
    std::mt19937 mt_rand(seed1);

    std::ofstream output("additional_with_comments.txt", std::fstream::trunc);
    output << "PROGRAMACION 2\nIVAN CALA MESA\n\n";
    RandomUniform rand_uni(seed1);
    std::set<std::string> problem_list;
    //nuevo problema
    for (int i = 1; i <= 200;)
    {
	output << "np " << prob;
	if (i == 1 or rand_uni() >= 4)
	{
	    output << std::to_string(i);
	    problem_list.insert(prob+std::to_string(i));
	    i++;
	}
	else
	{
	    int num = mt_rand()%i;
	    if (num == 0) num++;
	    output << std::to_string(num) << "  #REPETICION";
	}
	output << std::endl;
    }

    output << std::endl;

    //nueva sesion
    for (int i = 1; i <= 28;)
    {
	if (rand_uni() >= 3)
	{
	    output << "ns " << sesion << std::to_string(i);
	    i++;
	}
	else
	{
	    output << "#REPETICION\n";
	    int num = mt_rand()%i;
	    if (num == 0) num++;
	    output << "ns " << sesion << std::to_string(num);
	}
	output << " ";
	std::vector<int> aux;
	random_tree_gen(aux, rand_uni);
	auto vec_tree = transform_vector(problem_list, aux);
	for(const auto& prob : vec_tree)
	{
	    output << prob << " ";
	}
	output << std::endl << std::endl;
    }
}
