#pragma once

#include <iostream>
#include <cmath>

#include "template_matrix_t.hpp"
#include "vector_t.hpp"
#include "pair_t.hpp"
#include "sll_node_t.hpp"
#include "sll_t.hpp"


namespace AED{

enum  {COL_CONF, ROW_CONF};

template<class T>
class sparse_matrix_t {
	private:
		int m_;
		int n_;
		int conf_;
        vector_t<sll_t<pair_t<T>>> dispersa_;
	public:
        sparse_matrix_t(void):m_(0),n_(0),conf_(NULL),dispersa_(){

        }
		sparse_matrix_t(const matrix_t<T>& M, double eps, int conf):m_(M.get_m()),n_(M.get_n()),conf_(conf),dispersa_(){
            dispersa_.resize((conf)?m_:n_);
            for (int i = 0; i <((conf_)?m_:n_); ++i) {
                for (int j =((conf_)?n_-1:m_-1); j>=0; --j){
                    if(!zero(M.at((conf_)?i:j,(conf_)?j:i),eps)){
                        pair_t<T> aux(j,M((conf_)?i:j,(conf_)?j:i));
                        dispersa_[i].insert_head(new AED::sll_node_t<pair_t<T>>(aux));
                    }
                }
            }
		}

		~sparse_matrix_t(void) {

        }

		std::ostream& write(std::ostream& os){
            sll_node_t<pair_t<T>> *aux;
			os	<<"La matriz dispersa en ";
			(conf_)?os<<"ROW_CONF":os<< "COL_CONF";
			os <<" es de: \nFilas: "<< m_ << std::endl;
			os <<"Columnas: "<<n_<<std::endl;
			for (int i = 0; i <dispersa_.size() ; ++i) {
                (conf_)?os<<"Fila ["<<i+1<<"]:":os<<"Columna ["<<i+1<<"]:";
                aux=dispersa_[i].head();
                while(aux!=NULL){
                    os<<"\tIndice: "<<aux->get_data().get_inx()+1<<" Valor: "<< std::setw(4) << std::fixed << std::setprecision(1) <<aux->get_data().get_val();
                    aux=(aux->get_next());
                }
                os<<std::endl;
			}
			return os;
		}
        void mult(const matrix_t<T>& A, matrix_t<T>& B){
            if(n_==A.get_m()) {
                B.resize(m_, A.get_n());
                for (int l = 0; l <m_ ; ++l) {
                    for (int i = 0; i <A.get_n(); ++i) {
                        B(l,i)=0;
                    }
                }
                for (int i = 0; i < m_; ++i) {
                    for (int j = 0; j < A.get_n(); ++j) {
                        for (int k = 0; k <n_; ++k) {
                            B(i, j) += at(i, k) * A.at(k, j);
                        }
                    }
                }
                std::cout<<"La matriz resultante es\n";
                B.write(std::cout);
            } else{
                std::cout<<"La multiplicacion no se puede realizar porque  no coinciden las columnas de la dispersa con las filas de la matriz densa\n";
            }
        }
        void eliminarColumna(int col){
            sll_node_t<pair_t<T>> *aux;
            if(conf_){//ROW
                int cont;
                for (int i = 0; i <m_ ; ++i) {

                    if(!zero(at(i,col-1),1E-3)){
                        sll_node_t<pair_t<T>> * aux;
                        aux=dispersa_[i].head();
                        while (aux!=NULL){
                            if(aux->get_data().get_inx()==col-1){
                                aux=dispersa_[i].head();
                                for (int j = 0; j <cont-i; ++j) {
                                    aux=(aux->get_next());
                                }
                                aux->set_next(aux->get_next()->get_next());
                                //dispersa_[i].extract_after(aux); da el mismo fallo
                                break;
                            }
                            cont++;
                            aux=(aux->get_next());
                        }
                    }
                }
            }else{
                dispersa_[col-1].~sll_t();
            }
        }
private:
    bool inline zero(const double &E, double eps){
        return (fabs(E)<eps);
        }

    T at(int i, int j){
        sll_node_t<pair_t<T>> *aux;
        aux=dispersa_[(conf_)?i:j].head();
        while (aux!=NULL){
            if(aux->get_data().get_inx()==((conf_)?j:i)){
                return(aux->get_data().get_val());
            }
            aux=(aux->get_next());
        }
        return(0.0);
    }
};

}
