#ifndef LISTWIDGET_HPP
#define LISTWIDGET_HPP

#include <qobjectdefs.h>
#include <qtablewidget.h>
#include <QWidget>

#include "repositories/iprodutorepository.hpp"
#include "ui_listwidget.h"

class ListWidget : public QWidget {
    Q_OBJECT

  public:
    explicit ListWidget(QWidget *parent = nullptr);
    ~ListWidget();

  public slots:
    void criarProduto();
    void editarProduto(QTableWidgetItem *item);
    void selecionarProduto();

  private:
    Ui::ListWidget *ui;
    int *produto_id;
    IProdutoRepository *repo_;
    void atualizarTabela();
};

#endif  // LISTWIDGET_HPP
