#ifndef PRODUTOSETTINGS_HPP
#define PRODUTOSETTINGS_HPP

#include <settings/settings.hpp>

/**
 * Application settings.
 *
 * Things like window state, recent files, etc. already included in Settings
 * class.
 *
 * Add parameters that you need using addUserSetting(<some settings item>) in
 * createUserSettings(), than it's can be accessed by Qt value(key).
 *
 * Note, start add userSectionTag() to begin of key.
 */
class ProdutoSettings : public Settings {
    Q_DECLARE_TR_FUNCTIONS(ProdutoSettings)

  public:
    ProdutoSettings();

  protected:
    void createUserSettings() override;
};

#endif  // PRODUTOSETTINGS_HPP
