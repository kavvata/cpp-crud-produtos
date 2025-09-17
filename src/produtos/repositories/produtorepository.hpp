#ifndef INMEMORYPRODUTOREPOSITORY_HPP
#define INMEMORYPRODUTOREPOSITORY_HPP

#include <vector>
#include "../entities/produto.hpp"
#include "iprodutorepository.hpp"

class InMemoryProdutoRepository : public IProdutoRepository {
  private:
    std::vector<Produto> produtos_;
    int proximoCodigo_ = 1;

    // Private constructor
    InMemoryProdutoRepository();

    // Delete copy/move
    InMemoryProdutoRepository(const InMemoryProdutoRepository&) = delete;
    InMemoryProdutoRepository& operator=(const InMemoryProdutoRepository&) = delete;
    InMemoryProdutoRepository(InMemoryProdutoRepository&&) = delete;
    InMemoryProdutoRepository& operator=(InMemoryProdutoRepository&&) = delete;

  public:
    // Singleton accessor
    static InMemoryProdutoRepository& instance();

    // Repository methods
    std::vector<Produto> listarTodos();
    Produto* buscar(int id);
    Produto* cadastrar(Produto novoProduto);
    Produto* editar(Produto produto);
    bool remover(Produto produto);
};

#endif  // !INMEMORYPRODUTOREPOSITORY_HPP
