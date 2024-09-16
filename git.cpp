#include <cstdio>
#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include "func.h"
#include <map>

// Библиотеки
#include <libconfig.h++>


// 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
// git push https://user:password@github.com/repo/repo.git master
// git config --global credential.helper cache
// git config credential.helper stor
// git config --unset credential.helper

// git init - Инцилизировать файл
// git add - Добавление файла
// git status - Проверка статуса
// git commit - Открывает редактор
// git commit -m = Написать комментарий
// git remote add origin "Repository" - Подключение к удалённому репозиторию
// git push = Отправка локального репозитория в удалённый репозиторий
// git pull --rebase main - Переконфигуровка ветви

using std::cin;
using std::cout;
using std::string;
using std::system;
using std::endl;

string CheckFlags(int argc, char ** argv);
void Help();                    // Помощь
void test();                    // Test

void Standart_Config(
    string  = "git config --global init.defaultBranch main",
    string  = "git config --global user.name  \"Bakamashine\" ",
    string  = "git config --global user.email ivan.fa.002@gmail.com",
    string  = "git config --global core.editor vim"
            );         // Стандартные настройки
void Self_entry();              // Самоввод команд
std::map<string, string> ReadConfig();           // Прочтение конфига с файлами
char OStype();                  // Определение ОС


// Main
auto main(int argc, char *argv[]) -> int {
system("rm -rf .git");
cout << "Проводится базовая настройка..." << endl;
Standart_Config();
std::map<string, string> arr = ReadConfig();
Func func;
while (true) {

    string b;
    std::cout << "Введите функцию (-h --help = Помощь): ";
    std::cin >>  b;

    if (b == "-f" || b == "--full") func.Full_command(arr["Package"], arr["Commentary"]);   // Good
    if (b == "-s" || b == "--self") Self_entry();          // Good
    if (b == "-h" || b == "--help") Help(); // Good
    if (b == "-q"|| b == "--queue") func.Queue_Commands(arr["Package"],
    arr["Commentary"], arr["URL"], arr["Branch"]); // Good 50%
    if (b == "--quite") system("rm -rf .git"); exit(0);
}
    return 0;
}


void  test() {
    std::cout << "Hello" << std::endl;
}

void Standart_Config(
    string branch,
    string name,
    string email,
    string editor
) {
    system(branch.c_str());
    system(name.c_str());
    system(email.c_str());
    system(editor.c_str());
    cout << "Хотите ли вы проверить настройки?" << endl;
    string otvet;
    cout << "[y/n] ";
    cin >> otvet;
    if (otvet == "y") {
        system("git config --list");
    }
}

void Self_entry() {
    cout << "Вы перешли в режим самоввода, вводите вашу команду \n Введите \"exit\" для выхода из коммандной строки \n Введите exit-all для выхода из программы " << endl;
    while (true) {
        string otvet;
        cout << ":: ";
        getline(cin, otvet);
        if (otvet == "exit") {
            break;
        }
        else if (otvet == "exit-all") exit(0);
        else {
        system(otvet.c_str());
        cout << otvet << endl;
        }
    }
}

void Help() {
    cout << "-h --help = Помощь" << endl;
    cout << "-f --full = Загрузка в удалённый репозиторий" << endl;
    cout << "-s --self = Самоввод" << endl;
    cout << "-q --queue = Ввод комманд с вашего разрешения (если не согласны, можете переписать)" << endl;
    cout << "--quite = Выход (такого флага нет)" << endl;
}
// bool flags[4];
// void CheckFlags(int argc, char** argv) {
//     for (int i = 1; i < argc; ++i) {
//         if (!strcmp(argv[i], "h")) {
//             flags[FLAG_DEBUG] = true;
//         } else if (!strcmp(argv[i], "y")) {
//             flags[FLAG_RELEASE] = true;
//         } else if (!strcmp(argv[i], "s")) {
//             flags[FLAG_LOGGER] = true;
//         } else if (!strcmp(argv[i], "q")) {
//             flags[FLAG_COMPILER] = true;
//         }
//     }
// }

// string CheckFlags(int argc, char ** argv) {
//     for (int i = 1; i < argc; i++) {
//         if (!strcmp(argv[i], "-h")) return "-h";
//         if (!strcmp(argv[i], "-f")) return "-f";
//         if (!strcmp(argv[i], "-s")) return "-s";
//         if (!strcmp(argv[i], "-q")) return "-q";

//         if (!strcmp(argv[i], "--help")) return "--help";
//         if (!strcmp(argv[i], "--full")) return "--full";
//         if (!strcmp(argv[i], "--self")) return "--self";
//         if (!strcmp(argv[i], "-q")) return "--queue";
//     }
//     return "";
// }

string CheckFlags(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        if (i + 1 != argc) {
            if (strcmp(argv[i], "-h")) {
                char* filename = argv[i+1];
                i++;
            }
        }
    }
return 0;
}
char OStype() {
    return 0;
}
std::map<string,string> ReadConfig()  {
    libconfig::Config cfg;
    cfg.readFile("config.cfg");
    string Package = cfg.lookup("Package");
    string Commentary = cfg.lookup("Commentary");
    string Branch = cfg.lookup("Branch");
    string URL_git = cfg.lookup("URL");
    std::map<string, string> arr;
    arr["Package"] = Package;
    arr["Commentary"] = Commentary;
    arr["Branch"] = Branch;
    arr["URL"] = URL_git;
    return arr;
}
