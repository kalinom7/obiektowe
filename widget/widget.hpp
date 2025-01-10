#include <string>
#include <vector>

class Widget{
    private:
    std::string name;
    std::vector<Widget*> children;
    
    public:
    Widget(const std::string &name);
    ~Widget();
    void add(Widget* widget);
    void print(int space = 0) const;
    
};

class Button : public Widget{
    private:

    public:
    Button(const std::string &name);

};

class Edit : public Widget{
    private:
    public:
    Edit(const std::string &name);
};