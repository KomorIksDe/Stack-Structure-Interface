#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "MyStack.h"

struct MainMenu {
    MyStack<int> foo;
    std::vector<int> bar;

    void showStack() {
        if(bar.empty())
            return;

        for(int i = 0; i < bar.size(); i++)
            std::cout<<bar[i]<<" ";
    }

    void showMainMenu() {
        system("cls");

        std::cout<<"S T A C K"<<std::endl;
        std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
        showStack();
        std::cout<<std::endl<<"-------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Current size: "<<foo.size()<<std::endl;
        std::cout<<"Empty: ";

        if(foo.empty())
            std::cout<<"Yes"<<std::endl<<std::endl;
        else
            std::cout<<"No"<<std::endl<<std::endl;

        std::cout<<"What do you want to do with it?"<<std::endl;
        std::cout<<"[1].push()"<<std::endl;
        std::cout<<"[2].pop()"<<std::endl;
        std::cout<<"[3].top()"<<std::endl;
        std::cout<<"[4].clear()"<<std::endl;
        std::cout<<"[5].Exit"<<std::endl;

        getUserInput();
    }

    void pushCase() {
        int number;

        std::cout<<"What do you want to push to the top (integer): ";
        std::cin>>number;
        bar.push_back(number);
        foo.push(number);
        std::cout<<"Success"<<std::endl;
        Sleep(1000);
    }

    void popCase() {
        if(foo.empty()) {
            std::cout<<"There's nothing to pop!"<<std::endl;
        }
        else {
            foo.pop();
            bar.pop_back();
            std::cout<<"Success"<<std::endl;
        }

        Sleep(1000);
    }

    void topCase() {
        if(foo.empty())
            std::cout<<"There's no top element!"<<std::endl;
        else
            std::cout<<"Top element: "<<foo.top()<<std::endl;

        Sleep(1000);
    }

    void clearCase() {
        if(foo.empty())
            std::cout<<"There's nothing to clear!"<<std::endl;
        else {
            foo.clear();
            bar.clear();
            std::cout<<"Success"<<std::endl;
        }

        Sleep(1000);
    }

    void getUserInput() {
        char choice = getch();

        std::cout<<std::endl;

        switch(choice) {
        case '1':
            pushCase();
            break;

        case '2':
            popCase();
            break;

        case '3':
            topCase();
            break;

        case '4':
            clearCase();
            break;

        case '5':
            exit(1);
            break;

        default:
            std::cout<<"There's no such an option!"<<std::endl;
            Sleep(1000);
            break;
        }
    }
};

int main() {
    MainMenu menu;

    while(true) {
        menu.showMainMenu();
    }

    return 0;
}
