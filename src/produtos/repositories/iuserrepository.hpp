#ifndef IUSERREPOSITORY_HPP
#define IUSERREPOSITORY_HPP

#include <string>

class IUserRepository {
  public:
    virtual bool login(const std::string& username, const std::string& password) = 0;
    virtual ~IUserRepository() = default;
};

#endif  // !IUSERREPOSITORY_HPP
