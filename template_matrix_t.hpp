#pragma once 

#include <cstdio>
#include <iostream>
#include <iomanip>



template <class T>
class matrix_t{
private:
        int m_;
        int n_;
        T* v_;
        
public:
        matrix_t(void): m_(0), n_(0),v_(NULL){

        }
        
        matrix_t(int m, int n): m_(m), n_(n), v_(NULL) {
		    build();
		}
        
        ~matrix_t(void) {
            destroy();
        }
        
        void resize(int m, int n) {
            destroy();
            m_ = m;
            n_ = n;

            build();
        }
        
        T& at (int i, int j) {
            return v_[pos(i,j)];
        }

        const T& at (int i, int j) const {
            return v_[pos(i,j)];
        }        
        
		T& operator() (int i, int j) {
            return v_[pos(i,j)];
        }

        const T& operator() (int i, int j) const {
            return v_[pos(i,j)];
        }       

        int get_m(void) const {
            return m_;
        }
        
        int get_n(void) const {
            return n_;
        }
        
        std::ostream& write(std::ostream& os) const {
            os <<"Filas: "<< std::setw(4) << m_ << std::endl;
            os <<"Columnas: " <<std::setw(4) << n_ << std::endl;
            for(int i = 0; i < m_; i++){
                for(int j = 0; j < n_; j++) {
                    os << v_[pos(i, j)] << " ";
                }
                os << std::endl;
            }

            return os;
        }

        std::istream& read(std::istream &is) {
            destroy();
            std::cout<<"Introduce el numero de filas y columnas:";
            is >> m_;
            is >> n_;
            build();
            for(int i = 0; i < m_; i++){
                 for(int j = 0; j < n_; j++){
                     std::cout<<"Introduce el ["<<i+1<<","<<j+1<<"]:";
                     is >> v_[pos(i, j)];
                 }
             }
            return is;
        }
   
        int pos(int i, int j) const{
            return (i)* n_ + j ;
        }
     
private:
        
        void build(void){
            v_ = new T [m_ * n_];
        }
        
        void destroy(void) {
            if (v_)
                delete  [] v_;
        }
};

template <>
std::ostream&  matrix_t<int>::write(std::ostream& os) const {
    os <<"Filas: "<< std::setw(4) << m_ << std::endl;
    os <<"Columnas: " <<std::setw(4) << n_ << std::endl;
    for(int i = 0; i < m_; i++){
        for(int j = 0; j < n_; j++){
            os << std::setw(5) << v_[pos(i, j)] << " ";
        }
        os << std::endl;
    }
    return os;
}

template <>
std::ostream&  matrix_t<double>::write(std::ostream& os) const {
    os <<"Filas: "<< std::setw(4) << m_ << std::endl;
    os <<"Columnas: " <<std::setw(4) << n_ << std::endl;
     for(int i = 0; i < m_; i++){
         for(int j = 0; j < n_; j++)
                 os << std::setw(10)<< std::fixed << std::setprecision(4) << v_[pos(i, j)] << " ";
             
        os << std::endl;
     }
    return os;
}





