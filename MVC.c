#include <stdbool.h>

typedef struct
{
    int x1, x2;
    int y1, y2;
    bool click;
    int color;

    void (*model)(int); 
    void (*view)(int); 
    void (*controller)(int); 
} Button;
Button button;

view();
model();
controller();

init() {
    button.model = &model;
    button.view = &view;
    button.controller = &controller;
}

view() 
{
    display_element();
}

model(int clicked)
{
    if (clicked == 1)
    {
        button.click = true;
        button.color = "secondary";
    } else {
        button.click = false;
        button.color = "primary";
    }
}

controller(int clicked)
{
    if (clicked)
    {
        model(clicked);
    }
}
