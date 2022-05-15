#include "handlers.hpp"


/////////////////////////// User Handlers ///////////////////////////////
template <typename JSON>
void LoginHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    LoginData data;

    data.username = json.template get<std::string>("username", "");
    data.password = json.template get<std::string>("password", "");

    usecase->checkUser(data);
}

template <typename JSON>
void RegisterHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    RegisterData data;

    data.username = json.template get<std::string>("username", "");
    data.password = json.template get<std::string>("password", "");
    data.email = json.template get<std::string>("email", "");

    usecase->addUser(data);
}

template <typename JSON>
void EditProfileHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    UserData data;

    data.username = json.template get<std::string>("username", "");
    data.password = json.template get<std::string>("password", "");
    data.email = json.template get<std::string>("email", "");
    data.name = json.template get<std::string>("name", "");
    data.sur_name = json.template get<std::string>("sur_name", "");
    data.user_discription = json.template get<std::string>("user_discription", "");

    usecase->editUserData(data);
}

template <typename JSON>
void DelUserProfileHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    std::string data;

    data = json.template get<std::string>("username", "");

    usecase->delUserData(data);
}

template <typename JSON>
void GetUserProfileHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    std::string data;

    data = json.template get<std::string>("username", "");

    usecase->getUserData(data);
}

/////////////////////////// Posts Handlers ////////////////////////////////

template <typename JSON>
void EditPostHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    ProjectData data;

    data.project_name = json.template get<std::string>("project_name", "");
    data.team_name = json.template get<std::string>("team_name", "");
    data.post_tags = json.template get<std::vector<std::string>>("post_tags", std::vector<std::string>());
    data.teammates = json.template get<std::vector<std::string>>("teammates", std::vector<std::string>());
    data.project_description = json.template get<std::string>("project_description", "");
    data.diversity = json.template get<double>("diversity", 0.0);
    data.request_description = json.template get<std::string>("request_description", "");

    usecase->editPostToDB(data);
}

template <typename JSON>
void SearchPostHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    std::string project_name;

    project_name = json.template get<std::string>("project_name", "");

    usecase->makePostSearch(project_name);
}

template <typename JSON>
void SearchPersonHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    std::string username;

    username = json.template get<std::string>("username", "");

    usecase->makePersonSearch(username);
}



////////////////////////////////


template <typename JSON>
void DeletePostHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    std::string project_name;

    project_name = json.template get<std::string>("project_name", "");

    usecase->delPostData(project_name);
}

template <typename JSON>
void AnswerTheRequestHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    bool answer;
    RequestToPostData data;
    data.user_id  = json.template get<int>("user_id", 0);
    data.post_id  = json.template get<int>("post_id", 0);
    data.motivation_words  = json.template get<std::string>("motivation_words", "");
    answer = json.template get<bool>("answer", true);
    

    usecase->getAnswer(answer,data);
}



template <typename JSON>
void ShowNotificationsHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    int data;
   
    data  = json.template get<int>("user_id", 0);


    usecase->showAllNotifications(data);
}


template <typename JSON>
void CreatePostHandler<JSON>::handle(RequestInterface* request, ResponseInterface* response) {
    JSON json(request->get_body());
    ProjectData data;
   
    data.project_name  = json.template get<std::string>("project_name", "");
    data.project_name  = json.template get<std::string>("team_name", "");
    data.project_name  = json.template get<std::string>("project_description", "");
    data.project_name  = json.template get<std::string>("request_description", "");
    data.project_name  = json.template get<std::vector<std::string>>("post_tags", std::vector<std::string>());
    data.project_name  = json.template get<std::vector<std::string>>("teammates", std::vector<std::string>());
    data.project_name  = json.template get<double>("diversity", 0.0);
    
    usecase->addPostToDB(data);
}
