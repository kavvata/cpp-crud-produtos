#ifndef LOGINFORM_HPP
#define LOGINFORM_HPP

#include <QDialog>

#include "ui_loginform.h"

class LoginForm : public QDialog {
    Q_OBJECT

  public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

  private:
    Ui::LoginForm *ui;
};

#endif  // LOGINFORM_HPP
