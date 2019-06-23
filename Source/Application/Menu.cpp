#include "Menu.h"

Option::Option(std::string _text) : text(_text) {}

Option::Option(std::string _text, std::function<void()> _func) : text(_text), func(_func){ 
    submenu = nullptr; 
}

Option::Option(std::string _text, Menu& _submenu) : text(_text), submenu(&_submenu){ 
    func = nullptr; 

}
Option::Option(const Option &other){ 
    text = other.text;
    func = other.func;
    submenu = other.submenu;
}

void Option::select() {
    if (func != nullptr) {
        func();
    }
    if (func == nullptr) {
        menuOpen(submenu);
    }
}