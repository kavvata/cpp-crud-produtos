#ifndef INMEMORYUSERREPOSITORY_HPP
#define INMEMORYUSERREPOSITORY_HPP

#include <unordered_map>
#include "iuserrepository.hpp"

class InMemoryUserRepository : public IUserRepository {
  public:
    InMemoryUserRepository();

    bool login(const std::string& username, const std::string& password) override;

  private:
    std::unordered_map<std::string, std::string> users_;
};

#endif  // !INMEMORYUSERREPOSITORY_HPP
