#pragma once
#include "server_utils.hpp"


class MainDataBase
{
 public:
    explicit MainDataBase() = default;
    
    void connectToDataBase();

    virtual bool InsertIntoPostTable(PostData &data);
    virtual bool InsertIntoPersonTable(RegisterData &data);
    virtual bool InsertIntoRequestToPostTable(RequestToPostData &data);

    virtual bool DeleteFromPostTable(PostData &data);
    virtual bool DeleteFromPersonTable(std::string &data);
    virtual bool DeleteFromRequestToPostTable(RequestToPostData &data);
    virtual bool DeleteFromTable();

    virtual bool EditUserInPersonTable(UserData &data);

    virtual bool FindIntoPersonTable(LoginData &data);

    virtual UserData getUserProfile(std::string &username);

 private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createPostTable();
    bool createPersonTable();
    bool createRequestToPostTable();
};
