#include <database.hpp>


MainDataBase::MainDataBase(MySQLConnection *sqlconn_): sqlconn(sqlconn_) {
    // sqlconn->Connect("127.0.0.1", 3306, "root", "password", "Projectdata");
}

bool MainDataBase::DeleteFromPersonTable(int id) {
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from userdata where id=?");
    // que->setInt(1,id);
    // return que->ExecuteUpdate();

    return delete_record(id);
}
bool MainDataBase::DelFromTableToken(int id) {
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from userdata where user_id=?");
    // que->setInt(1,id);
    // return que->ExecuteUpdate();

    return delete_record(id);
}

bool MainDataBase::DeleteFromPostTable(int id){
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from projectdata where project_id=?");
    // que->setInt(1,id);
    // return que->ExecuteUpdate();

    return delete_record(id);
}
bool MainDataBase::DelFromTableNotifications(RequestToPostData& data) {
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from requesttopost where user_id=? and project_id=?");
    // que->setInt(1,data.user_id);
    // que->setInt(2,data.post_id);
    // return que->ExecuteUpdate();

    return true;
}

std::vector<RequestToPostData> MainDataBase::SelectNotifications(int &user_id) {
    // //выводим оповещения-ответы на пост юзера, либо ответы на его отклики
    // MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select r.user_id, \
    // r.project_id, p.project_name, r.motivation_words, r.status from requesttopost as r \
    // inner join projectdata as p on r.project_id=p.project_id where r.user_id=? and r.status<>3 or p.user_id=?");

    // selectQuery->setInt(1,user_id);
    // selectQuery->setInt(2,user_id);
    // selectQuery->ExecuteQuery();

    // std::vector<RequestToPostData> data;
    // for (unsigned int i = 1; i <= selectQuery->GetResultRowCount(); i++)
    // {
    //     RequestToPostData temp;

    //     temp.user_id = selectQuery->getInt(i,1);
    //     temp.post_id = selectQuery->getInt(i,2);
    //     temp.project_name = selectQuery->getString(i,3);
    //     temp.motivation_words = selectQuery->getString(i,4);
    //     // int status = selectQuery->getInt(i,5);
    //     // if  (status == 1){
    //     //     temp.status = yes;
    //     //     }
    //     // else temp.status = no;
    //     temp.status = static_cast<RequestToPostData::Status>(selectQuery->getInt(i,5));
    //     data.push_back(temp);
    // }
    // return data;

    return std::vector<RequestToPostData>();
}

UserData MainDataBase::FindIntoPersonByUsername(std::string &username) {
    // MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select id, username, email, name, sur_name, user_discription, password from userdata "
    // R"( where username = ? )");

    // selectQuery->setString(1,username);
    // selectQuery->ExecuteQuery();
    // UserData data;

    // data.id = selectQuery->getInt(1,1);
    // data.username = selectQuery->getString(1,2);
    // data.email = selectQuery->getString(1,3);
    // data.name = selectQuery->getString(1,4);
    // data.sur_name = selectQuery->getString(1,5);
    // data.user_discription = selectQuery->getString(1,6);
    // data.password = selectQuery->getString(1,7);
    // return data;

    return UserData();
}

UserData MainDataBase::FindIntoPersonByID(int &id) {
    // MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select id, username, email, name, sur_name, user_discription, password from userdata "
    // R"( where id = ? )");

    // selectQuery->setInt(1,id);
    // selectQuery->ExecuteQuery();
    // UserData data;

    // data.id = selectQuery->getInt(1,1);
    // data.username = selectQuery->getString(1,2);
    // data.email = selectQuery->getString(1,3);
    // data.name = selectQuery->getString(1,4);
    // data.sur_name = selectQuery->getString(1,5);
    // data.user_discription = selectQuery->getString(1,6);
    // data.password = selectQuery->getString(1,7);
    // return data;

    UserData data;
    data.username = get_record(id)[0];
    return data;
}

ProjectData MainDataBase::SelectPostByID(int &id) {
//    MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select id, userid, project_name, team_name, post_tag, teammates, project_description, diversity from projectdata "
//    "where id=?");

//    selectQuery->setInt(1,id);
//    selectQuery->ExecuteQuery();
//    ProjectData data;

//    data.id = selectQuery->getInt(1,1);
//    data.userid = selectQuery->getInt(1,2);
//    data.project_name = selectQuery->getString(1,2);
//    data.team_name = selectQuery->getString(1,2);
//    data.post_tags.push_back(selectQuery->getString(1,2));
//    data.teammates.push_back(selectQuery->getString(1,2));
//    data.project_description = selectQuery->getString(1,2);
//    data.diversity = selectQuery->getDouble(1,2);
//     return data;

    ProjectData data;
    data.project_name = get_record(id)[0];
    return data;
}


bool InsertIntoPostTable(ProjectData &data) {
    data;
    return true;
}
bool InsertIntoPersonTable(RegisterData &data) {
    data;
    return true;
}
bool InsertIntoRequestToPostTable(RequestToPostData &data) {
    data;
    return true;
}

bool DeleteFromRequestToPostTable(RequestToPostData &data) {
    data;
    return true;
}

bool EditUserInPersonTable(UserData &data) {
    data;
    return true;
}
bool EditPostInPostTable(ProjectData &data) {
    data;
    return true;
}
bool EditRequestToPostTable(RequestToPostData &data) {
    data;
    return true;
}

bool FindIntoPersonTable(LoginData &data) {
    data;
    return true;
}

bool FindIntoPostTable(std::string &project_name) {
    project_name;
    return true;
}
NotificationData FindRequestToPostTable(int &user_id) {
    user_id;
    return NotificationData();
}

bool InsertToken(std::string &username, std::string& token) {
    return true;
}
bool FindToken(std::string &username, std::string& token) {
    return true;
}
bool DeleteToken(std::string &username) {
    return true;
}

UserData getUserProfile(std::string &username) {
    return UserData();
}
ProjectData getPost(std::string &project_name) {
    return ProjectData();
}
std::vector<ProjectData> getMultiPost(SearchData &data) {
    return std::vector<ProjectData>();
}

// fake

bool MainDataBase::add_record(int id, const std::vector<std::string>& record) {
    table_[id] = record;
}

bool MainDataBase::delete_record(int id) {
    auto it = table_.find(id);
    if (it == table_.end()) {
        return false;
    } else {
        table_.erase(it);
    }
    return true;
}

bool MainDataBase::find_record(int id) {
    if (auto it = table_.find(id) != table_.end()) {
        return true;
    } 
    return false;
}

std::vector<std::string> MainDataBase::get_record(int id) {
    auto it = table_.find(id);
    if (it == table_.end()) {
        return it->second;
    }
    return std::vector<std::string>();
}
