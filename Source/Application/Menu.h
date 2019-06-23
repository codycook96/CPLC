#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <functional>

class Menu;

void menuOpen(Menu* m);

class Option {
private:
    std::string text;
    std::function<void()> func;
    Menu* submenu;

public:
    Option(std::string _text);
    Option(std::string _text, std::function<void()> _func);
    Option(std::string _text, Menu& _menu);
    Option(const Option &_option);

    void select();
};

class OptionList{
    private:
    

    public:

};

class Menu{
    private:
        Menu* parent;
        std::vector<Option> options;

    public:
        Menu(std::vector<Option> o) : options(o) {}
        Menu(std::vector<Option> o, Menu* p) : options(o), parent(p) {}
    
    
    void open(){
        bool run = true;
        //while(run){
            for (int i = 0; i < options.size(); i++) {
                options.at(i).select();
            }	
        //}		
    }
    
    //void draw()
    
};

void menuOpen(Menu* m) {
    m->open();
}

#endif