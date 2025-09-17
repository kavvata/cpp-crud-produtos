#ifndef LISTWIDGET_HPP
#define LISTWIDGET_HPP

#include <qobjectdefs.h>
#include <qtablewidget.h>
#include <QWidget>

#include "entities/produto.hpp"
#include "repositories/iprodutorepository.hpp"
#include "ui_listwidget.h"

class ListWidget : public QWidget {
    Q_OBJECT

  public:
    explicit ListWidget(QWidget *parent = nullptr);
    ~ListWidget();

  signals:
    void mostrarFormularioProduto(Produto *produto = nullptr);

  public slots:
    void criarProduto();
    void editarProduto(QTableWidgetItem *item);

  private:
    Ui::ListWidget *ui;
    int *produto_id;
    IProdutoRepository *repo_;
    void atualizarTabela();
};

#endif  // LISTWIDGET_HPP
