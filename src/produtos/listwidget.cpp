#include "listwidget.hpp"
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qtablewidget.h>

ListWidget::ListWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ListWidget) {
    ui->setupUi(this);
    connect(ui->novoProdutoPushButton_, &QPushButton::clicked, this, &ListWidget::criarProduto);
    connect(ui->produtosTableWidget_,
            &QTableWidget::itemDoubleClicked,
            this,
            &ListWidget::editarProduto);
}

ListWidget::~ListWidget() { delete ui; }

void ListWidget::criarProduto() {
    QMessageBox::warning(this, "Novo Produto", "TODO: Não Implementado.");
}

void ListWidget::editarProduto(QTableWidgetItem *item) {
    QMessageBox::warning(this, "Editar Produto", "TODO: Não Implementado.");
}

void ListWidget::selecionarProduto() {
    QMessageBox::warning(this, "Selecionar Produto", "TODO: Não Implementado.");
}
