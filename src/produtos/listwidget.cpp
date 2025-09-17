#include "listwidget.hpp"
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qtablewidget.h>
#include "repositories/produtorepository.hpp"

ListWidget::ListWidget(QWidget* parent) : QWidget(parent), ui(new Ui::ListWidget) {
    ui->setupUi(this);
    connect(ui->novoProdutoPushButton_, &QPushButton::clicked, this, &ListWidget::criarProduto);
    connect(ui->produtosTableWidget_,
            &QTableWidget::itemDoubleClicked,
            this,
            &ListWidget::editarProduto);

    this->repo_ = &InMemoryProdutoRepository::instance();

    atualizarTabela();
}

ListWidget::~ListWidget() { delete ui; }

void ListWidget::atualizarTabela() {
    auto produtos = repo_->listarTodos();

    ui->produtosTableWidget_->setRowCount(static_cast<int>(produtos.size()));

    for (int row = 0; row < produtos.size(); ++row) {
        const auto& p = produtos[row];

        ui->produtosTableWidget_->setItem(row, 0, new QTableWidgetItem(QString::number(p.codigo)));
        ui->produtosTableWidget_->setItem(
            row, 1, new QTableWidgetItem(QString::fromStdString(p.unidadeMedida.descricao)));
        ui->produtosTableWidget_->setItem(
            row, 2, new QTableWidgetItem(QString::number(p.preco, 'f', 2)));
        ui->produtosTableWidget_->setItem(
            row, 3, new QTableWidgetItem(QString::number(p.quantidade)));
        ui->produtosTableWidget_->setItem(
            row, 4, new QTableWidgetItem(QString::fromStdString(p.nome)));
    }
}

void ListWidget::criarProduto() { emit mostrarFormularioProduto(); }

void ListWidget::editarProduto(QTableWidgetItem* item) {
    int row = item->row();
    QTableWidgetItem* idCell = ui->produtosTableWidget_->item(row, 0);
    if (!idCell) return;

    int id = idCell->text().toInt();

    Produto* p = this->repo_->buscar(id);

    emit mostrarFormularioProduto(p);
}
