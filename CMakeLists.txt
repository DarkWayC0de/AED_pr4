cmake_minimum_required(VERSION 3.10)
project(pr4)

set(CMAKE_CXX_STANDARD 11)

add_executable(pr4 main_sparse_matrix.cpp sll_t.hpp sll_node_t.hpp pair_t.hpp sparse_matrix_t.hpp template_matrix_t.hpp vector_t.hpp)

