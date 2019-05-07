#include <iostream>
#include <string>

#include "sparse_matrix_t.hpp"
#include "template_matrix_t.hpp"



int main (void){
    matrix_t<double> M,B,C;
    int a;
    std::cout<<"Pracica IV de AyED\n"
               "Matrices dispersas II\n";
    std::cout << "Introduce la matriz a implementar\n";
    M.read(std::cin);
    std::cout << "La matriz introducida es:\n";
    M.write(std::cout);
    int confi;
    std::cout<< "Introdice la configuracion de la matriz (COL_CONF=0/ROW_CONF=1): ";
    std::cin>>confi;

    AED::sparse_matrix_t<double> SM(M, 1E-3, confi);
    SM.write(std::cout);
    std::cout<<"Introduce una matriz para hacer la multiplicacion\n";
    B.read(std::cin);
    SM.mult(B, C);
    std::cout<<"Intruduce la columna a eliminar de la matriz: ";
    std::cin>>a;
    SM.eliminarColumna(a);
    std::cout<<"La matriz resultante es:\n";
    SM.write(std::cout);








}

