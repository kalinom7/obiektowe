#include "widget.hpp"
#include <iostream>
 Widget::Widget(const std::string &name){
    this -> name = name;
 };
 Widget::~Widget(){
    for(Widget* child : children)
    {
        delete child;
    }

 };

 void Widget::add(Widget *widget){
    children.push_back(widget);
 }

 void Widget::print(int space) const{

    for(int a = 0 ; a < space; a++)
    {
        std::cout << " ";
    }
    std::cout<<name<<std::endl;
    for(Widget* child : children)
    {
        child -> print(space + 1);
    }
 };

 Button::Button(const std::string &name) : Widget(name){};
 Edit::Edit(const std::string &name) : Widget(name) {};
 
 