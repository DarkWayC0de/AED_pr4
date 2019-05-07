#include <iostream>

#include "sll_t.hpp"

#define N_CHARS 26



int main(void)
{
	AED::sll_t<char> lista;
	for(int i = 0; i < N_CHARS; i++)
		lista.insert_head( new AED::sll_node_t<char>('a' + i) );

	lista.write(std::cout);
	std::cout << std::endl;

	AED::sll_node_t<char>* nodo = lista.extract_head();
	char dato = nodo->get_data();
	delete nodo;

	std::cout << "Dato 1: " << dato << std::endl;

	nodo = lista.extract_head();
	dato = nodo->get_data();
	delete nodo;

	std::cout << "Dato 2: " << dato << std::endl;

	nodo = lista.extract_head();
	dato = nodo->get_data();
	delete nodo;

	std::cout << "Dato 3: " << dato << std::endl;

	lista.write(std::cout);
	std::cout << std::endl;

	nodo = lista.extract_after(lista.head());
	dato = nodo->get_data();
	delete nodo;

	std::cout << "Dato 4: " << dato << std::endl;

	nodo = lista.extract_after(lista.head()->get_next());
	dato = nodo->get_data();
	delete nodo;

	std::cout << "Dato 5: " << dato << std::endl;

	lista.write(std::cout);
	std::cout << std::endl;

	nodo = lista.head();
	dato = nodo->get_data();

	std::cout << "Dato 6: " << dato << std::endl;

	lista.write(std::cout);
	std::cout << std::endl;

	return 0;
}
