#include "produtosettings.hpp"

#include "settings/items/checkboxitem.hpp"
#include "settings/items/separatoritem.hpp"
#include "settings/items/spinboxitem.hpp"
#include "settings/items/textitem.hpp"

ProdutoSettings::ProdutoSettings() {
    ProdutoSettings::createUserSettings();
    initDefaults();
    readUserSettings();
}

void ProdutoSettings::createUserSettings() {
    addUserSetting(new SeparatorItem());

    auto* db_host = new TextItem("db_host", tr("Host"), "db");
    addUserSetting(db_host);

    auto* db_port = new TextItem("db_port", tr("Port"), "5432");
    addUserSetting(db_port);

    auto* db_name = new TextItem("db_name", tr("DB Nome"), "cpp-crud-produtos");
    addUserSetting(db_name);

    auto* db_user = new TextItem("db_user", tr("DB Usuário"), "myuser");
    addUserSetting(db_user);

    auto* db_password = new TextItem("db_password", tr("DB Senha"), "secret", true);
    addUserSetting(db_password);
}
