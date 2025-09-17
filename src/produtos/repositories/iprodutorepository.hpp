#ifndef IPRODUTOREPOSITORY_HPP
#define IPRODUTOREPOSITORY_HPP

#include <vector>
#include "../entities/produto.hpp"

class IProdutoRepository {
  public:
    virtual ~IProdutoRepository() = default;
    virtual std::vector<Produto> listarTodos() = 0;
    virtual Produto* buscar(int id) = 0;
    virtual Produto* cadastrar(Produto novoProduto) = 0;
    virtual Produto* editar(Produto produto) = 0;
    virtual bool remover(Produto produto) = 0;
};

#endif  // !IPRODUTOREPOSITORY_HPP
