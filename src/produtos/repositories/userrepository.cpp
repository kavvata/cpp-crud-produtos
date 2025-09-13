#include "userrepository.hpp"

InMemoryUserRepository::InMemoryUserRepository() {
    users_["admin"] = "SuperSenha";  // NOTE: usuario fixture.
}

bool InMemoryUserRepository::login(const std::string& username, const std::string& password) {
    auto it = users_.find(username);
    return it != users_.end() && it->second == password;
}
