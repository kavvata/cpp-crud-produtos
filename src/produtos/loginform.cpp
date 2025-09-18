#include "loginform.hpp"
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <string>
#include "repositories/userrepository.hpp"

LoginForm::LoginForm(QWidget* parent) : QWidget(parent), ui(new Ui::LoginForm) {
    ui->setupUi(this);
    connect(ui->loginPushButton_, &QPushButton::clicked, this, &LoginForm::handleLogin);
    connect(ui->usuarioLineEdit_, &QLineEdit::returnPressed, this, &LoginForm::focarSenha);
    connect(ui->senhaLineEdit_, &QLineEdit::returnPressed, this, &LoginForm::handleLogin);
}

LoginForm::~LoginForm() { delete ui; }

void LoginForm::handleLogin() {
    const auto repo = new InMemoryUserRepository();

    const std::string usuario = ui->usuarioLineEdit_->text().toStdString();
    const std::string senha = ui->senhaLineEdit_->text().toStdString();

    if (repo->login(usuario, senha)) {
        emit loginSucesso();
    } else {
        QMessageBox::warning(this, "Login Failed", "Nome de usuário ou Senha inválidos.");
    }
}

void LoginForm::focarSenha() { ui->senhaLineEdit_->setFocus(); }
