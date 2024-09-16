#include <ctime>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using std::string;
class Func {
    string name_file = "README.md";
    string commentary = "commit";
    string git_url = "https://github.com/Bakamashine/test2";
    string branch = "main";
    public:


        void Full_command(
            string name_file = "README.md",
            string commentary = "commit",
            string git_url = "https://github.com/Bakamashine/test2",
            string branch = "main"
) {

            string git_init = "git init";
            string git_commentary = "git commit -m " + commentary;
            string git_add = "git add " + name_file;
            string git_remote = "git remote add origin " + git_url;
            string git_push = "git push https://Bakamashine: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@github.com/Bakamashine/test2.git";
            string git_rebase = "git pull --rebase origin " + branch;
            system(git_init.c_str());             // Инцилизация локального репозитория
            system(git_remote.c_str());     // Подключение к удалённому репозиторию
            system(git_rebase.c_str());     // Переконфигуровка локального репозитория
            system(git_add.c_str());        // Добавления файла(-ов)
            system(git_commentary.c_str()); // Добавления комментария
            system(git_push.c_str());       // Отправка файлов в удалённый репозиторий

        }
void Queue_Commands(
            string name_file = "README.md",
            string commentary = "commit",
            string git_url = "https://github.com/Bakamashine/test2",
            string branch = "main"
) {
    int i = 0;
    string git_init = "git init";
    string git_commentary = "git commit -m " + commentary;
    string git_add = "git add " + name_file;
    string git_remote = "git remote add origin " + git_url;
    string git_push = "git push https://Bakamashine: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@github.com/Bakamashine/test2.git";
    string git_rebase = "git pull --rebase origin " + branch;
        std::vector<string> arr = {git_init, git_remote, git_rebase, git_add,
        git_commentary, git_push };

    while(true) {
        std::cout << "Вы согласны с вводом такой команды? [y/n] \n Введите \"exit\" для выхода из коммандной строки \n Введите \"exit-all\" для выхода из программы " << std::endl;
        std::cout << "Команда: " << arr[i] << std::endl;
        std::cout << ":: ";
        string otvet;
        std::string query;
        std::cin >> otvet;
        if (otvet == "y" or otvet == "yes") {
            system(arr[i].c_str());
        }
        if(otvet == "n" or otvet == "no") {
            std::cout << "Хорошо, перепишите команду " << std::endl;
            std::cout << ":: ";
            getline(std::cin, query);
            system(query.c_str());
        }
         if(otvet == "exit") break;
         if(otvet == "exit-all") exit(0);
        else std::cout << "Вы ввели что-то не то...";
        i++;
    }
}
};
