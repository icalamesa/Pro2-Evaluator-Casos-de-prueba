#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <random>

int main()
{
    std::string prob = "Problema";
    std::string sesion = "Sesion";
    std::string usuario = "usuario";
    int n_prob, n_sesion, n_user, n_curso;
    std::cout << "Numero de problemas: ";

    std::cin >> n_prob;
    std::cout << "Numero de sesiones: ";
    std::cin >> n_sesion;
    std::cout << "Numero de cursos: " ;
    std::cin >> n_curso;
    std::cout << "Numero de usuarios: ";
    std::cin >> n_user;
    std::ifstream names("first-names.txt");
    std::set<std::string> name_list;
    
    std::string word;
    while (names >> word)
    {
	//std::cout << word << std::endl;
	name_list.insert(word);
    }

    size_t size = name_list.size();
    std::set<size_t> past;

    std::ofstream output("output.txt", std::fstream::out | std::fstream::trunc);

    output << n_prob << std::endl;
    //output problems
    for (int i = 1; i <= n_prob; i++)
    {
	output << prob + std::to_string(i) << std::endl;
    }

    //output sesiones
    output << n_sesion << std::endl;
    std::vector<std::string> session_list;
    for (int i = 1; i <= n_sesion; i++)
    {
	std::string ses = sesion + std::to_string(i);
	session_list.push_back(ses);
	output << ses << std::endl;
    }
    std::random_device rd;
    std::mt19937 random(rd());
    output << n_curso << std::endl;
    //output curso 
    for (int i = 1; i<= n_curso; i++)
    {
	int n = (random() % 7) + 1; //at least 1
	output << n << " ";
	for (int j = 0; j < n; j++)
	{
	    output << session_list[random() % session_list.size()] << " "; 
	}
	output << std::endl;
    }
    
    output << n_user << std::endl;
    for (int i = 0; i < n_user; i++)
    {
	int name_size = name_list.size();
	auto it = name_list.begin();
	std::advance(it, random() % name_size);
	output << *it << std::endl;
    }
    std::cout << "Archuvo creado como output.txt en la carpeta de ejecucion. " << std::endl;

}
