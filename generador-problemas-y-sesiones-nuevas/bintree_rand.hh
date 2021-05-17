#include <iostream>
#include <random>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& vec)
{
    for (const auto& elem : vec)
    {
	std::cout << elem << ' ';
    }
}

class RandomUniform
{
    std::default_random_engine gen;
    std::uniform_int_distribution<int> rand_uniform{1, 10};
    public:
    RandomUniform()
    {
	std::random_device rand;
	gen.seed(rand());
    }
    RandomUniform(int i)
    {
	gen.seed(i);
    }
    int operator()()
    {
	return this->rand_uniform(this->gen);
    }
};

static void immersion_generator(std::vector<int>& vec, int cap, RandomUniform& random, int depth)
{
    if (cap != 0 and depth)
    {
	vec.push_back(1);
	immersion_generator(vec, cap - (cap % random()), random, depth - 1);
	immersion_generator(vec, cap - (cap % random()), random, depth - 1);
    }
    else
    {
	vec.push_back(0);
    }
}

void random_tree_gen(std::vector<int>& vec, RandomUniform& random)
{
    //int depth = random();
    int depth = 5;
    immersion_generator(vec, random(), random, depth);
}

//int main()
//{
    //RandomUniform random;
    //std::vector<int> vec;
    //random_tree_gen(vec, random);
    //print_vector(vec);
//}
