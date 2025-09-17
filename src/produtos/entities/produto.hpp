#ifndef PRODUTO_HPP
#define PRODUTO_HPP
#include <string>
#include "unidademedida.hpp"

struct Produto {
    static constexpr int SEM_CODIGO = -1;

    int codigo;
    std::string nome;
    double preco;
    int quantidade;
    UnidadeMedida unidadeMedida;

    Produto() : codigo{SEM_CODIGO}, nome{}, preco{0.0}, quantidade{0}, unidadeMedida{} {}
    Produto(int c, const std::string& n, double p, int q, UnidadeMedida um)
        : codigo{c}, nome{n}, preco{p}, quantidade{q}, unidadeMedida{um} {}
    Produto(const std::string& n, double p, int q)
        : codigo{SEM_CODIGO}, nome{n}, preco{p}, quantidade{q} {}
};
#endif  // !PRODUTO_HPP
