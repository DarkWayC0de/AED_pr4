#pragma once

#include <iostream>
#include <iomanip>



template <class T >
class pair_t {
private:
	int    inx_;
	T      val_;
public:
	pair_t(void):inx_(-1),val_(){

	}

	pair_t(int inx, T val):inx_(inx),val_(val){

	}

	~pair_t(void) {

	}

	void set(int inx, T val){
		inx_ = inx;
		val_ = val;
	}

	int  &get_inx(void){
		return inx_;
	}

	int  get_inx(void)const {
		return inx_;
	}

	T &get_val(void){
		return val_;
	}

	T  get_val(void) const {
		return val_;
	}

	std::ostream& write(std::ostream& os) const {
		os << "("<< std::setw(3) << inx_ << ", " ;
		val_.write(os);
		os << ")";
		return os;
	}

	std::istream& read(std::istream& is){
		is >> inx_ >> val_;
		return is;
	}
};

template<>
std::ostream& pair_t<double>::write(std::ostream& os) const {
	os << "( " << std::setw(3) << inx_ << ", " << std::setw(4) << std::fixed << std::setprecision(1) << val_ << " )";
	return os;
}


