#ifndef LOGINFORM_HPP
#define LOGINFORM_HPP

#include <QWidget>

#include "ui_loginform.h"

class LoginForm : public QWidget {
    Q_OBJECT

  public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

  signals:
    void loginSucesso();

  public slots:
    void handleLogin();

  private:
    Ui::LoginForm *ui;
};

#endif  // LOGINFORM_HPP
