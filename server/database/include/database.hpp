#pragma once

#include "idatabase.hpp"
#include "server_utils.hpp"
#include "dbconnection.hpp"

// fake
#include <map>


class MainDataBase: public IMainDataBase 
{
 public:
    // MainDataBase() = default;
    MainDataBase(MySQLConnection *sqlconn_);

    bool InsertIntoPostTable(ProjectData &data) override;
    bool InsertIntoPersonTable(UserData &data) override;
    bool InsertIntoRequestToPostTable(RequestToPostData &data) override;

    bool DeleteFromPostTable(int id) override;
    bool DeleteFromPersonTable(int id) override;
    bool DeleteFromRequestToPostTable(RequestToPostData &data) override;
    bool DelFromTableToken(int id) override;
    bool DelFromTableNotifications(RequestToPostData& data) override;

    bool EditUserInPersonTable(UserData &data) override;
    bool EditPostInPostTable(ProjectData &data) override;
    bool EditRequestToPostTable(RequestToPostData &data) override;


    bool FindIntoPersonTable(LoginData &data) override;
    UserData FindIntoPersonByUsername(std::string &username) override;
    bool FindIntoPersonByID(int &id) override;
    bool FindIntoPostTable(std::string &project_name) override;
    NotificationData FindRequestToPostTable(int &user_id) override;

    bool InsertToken(std::string &username, std::string& token) override;
    bool FindToken(std::string &username, std::string& token) override;
    bool DeleteToken(std::string &username) override;

    UserData getUserProfile(std::string &username) override;
    ProjectData getPost(std::string &project_name) override;
    std::vector<ProjectData> getMultiPost(SearchData &data) override;

    std::vector<RequestToPostData> SelectNotifications(int &user_id) override;
    ProjectData SelectPostByID(int &id) override;

    ~MainDataBase() = default;

 private:
    MySQLConnection *sqlconn;

    // fake bd
    std::unordered_map<int, std::vector<std::string>> table_;

    bool add_record(int id, const std::vector<std::string>& record);
    bool delete_record(int id);
    bool find_record(int id);
    std::vector<std::string> get_record(int id);
};
