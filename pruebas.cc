#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <random>

void session_include(std::ofstream& output, std::set<std::string>& used_sessions, std::vector<std::string>& session_list, std::mt19937& random)
{
    std::string session = session_list[random() % session_list.size()];
    if (used_sessions.find(session) == used_sessions.end())
    {
	output << session << " ";
	used_sessions.insert(session);
    }
    else
    {
	session_include(output, used_sessions, session_list, random);
    }
}

int main()
{
    std::string prob = "Problema";
    std::string sesion = "Sesion";
    std::string usuario = "usuario";
    int n_prob, n_sesion, n_user, n_curso;
    std::cout << "Numero de problemas (max 221): ";

    std::cin >> n_prob;
    std::cout << "Numero de sesiones (minimo 7): ";
    std::cin >> n_sesion;
    std::cout << "Numero de cursos: " ;
    std::cin >> n_curso;
    std::cout << "Numero de usuarios: ";
    std::cin >> n_user;
    
    //randomness providers
    std::random_device rd;
    std::mt19937 random(rd());

    //inputs
    std::ifstream names("first-names.txt");
    std::ifstream problem_names("cs-words.txt");

    //outputs
    std::ofstream output("output.txt", std::fstream::trunc);

    std::set<std::string> name_list;
    std::set<std::string> used_name_list;

    std::set<std::string> problem_name_list;
    std::set<std::string> used_problem_name_list;


    //First of all, we'll insert the Users word list into a std::set. We'll make
    //use of its properties to remove words from it such that we avoid repetitions.
    std::string word;

    while (names >> word)
    {
	name_list.insert(word);
    }

    while (problem_names >> word)
    {
	problem_name_list.insert(word);
    }

    size_t size = name_list.size();
    std::set<size_t> past;


    output << n_prob << std::endl;
    //output problems
    for (int i = 1; i <= n_prob; i++)
    {
	auto it = problem_name_list.begin();
	std::advance(it, random()%problem_name_list.size());
	output << *it << std::endl;
	//extract element by grabbing its node handle and passing it on to the used word list
	used_problem_name_list.insert(problem_name_list.extract(it));
	//output << prob + std::to_string(i) << std::endl;
    }

    //output sesiones
    std::cout << "LLEGO sesiones" << std::endl;
    output << n_sesion << std::endl;
    std::vector<std::string> session_list;
    for (int i = 1; i <= n_sesion; i++)
    {
	std::string ses = sesion + std::to_string(i);
	session_list.push_back(ses);
	output << ses << std::endl;
    }
    output << n_curso << std::endl;
    //output curso 
    for (int i = 1; i<= n_curso; i++)
    {
	std::set<std::string> used_sessions;
	int n = (random() % 7) + 1; //at least 1
	output << n << " ";
	for (int j = 0; j < n; j++)
	{
	    session_include(output, used_sessions, session_list, random);
	}
	output << std::endl;
    }
    
    output << n_user << std::endl;
    for (int i = 0; i < n_user; i++)
    {
	auto it = name_list.begin();
	std::advance(it, random() % name_list.size());
	output << *it << std::endl;
	used_name_list.insert(name_list.extract(it));

    }
    std::cout << "Archivo creado como output.txt en la carpeta de ejecucion. " << std::endl;

}
