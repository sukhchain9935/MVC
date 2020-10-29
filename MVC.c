#include <stdbool.h>

void init();
int btn_view();
void btn_model(int clicked);
void btn_controller(int clicked);
int display_element();

typedef struct
{
    int x1, x2;
    int y1, y2;
    bool click;
    int color;

    void (*model)(int); 
    int (*view)(); 
    void (*controller)(int); 
} Button;
Button button;

void init() {
    button.model = &btn_model;
    button.view = &btn_view;
    button.controller = &btn_controller;
}

int btn_view() 
{
    return display_element();
}

void btn_model(int clicked)
{
    if (clicked == 1)
    {
        button.click = true;
        button.color = 1; // Secondary;
    } else {
        button.click = false;
        button.color = 0; // Primary;
    }
}

void btn_controller(int clicked)
{
    if (clicked)
    {
        btn_model(clicked);
    }
}

int display_element()
{
    return 1;
}
