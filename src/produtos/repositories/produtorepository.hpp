#ifndef INMEMORYPRODUTOREPOSITORY_HPP
#define INMEMORYPRODUTOREPOSITORY_HPP

#include <vector>
#include "iprodutorepository.hpp"
class InMemoryProdutoRepository : public IProdutoRepository {
  public:
    InMemoryProdutoRepository();
    std::vector<Produto> listarTodos();
    Produto* buscar(int id);
    std::vector<Produto> cadastrar(Produto novoProduto);
    std::vector<Produto> editar(Produto produto);
    std::vector<Produto> remover(Produto produto);

  private:
    std::vector<Produto> produtos_;
    int proximoCodigo_;
};

#endif  // !INMEMORYPRODUTOREPOSITORY_HPP
