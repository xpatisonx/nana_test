//
// Created by bpolo on 30.12.2024.
//

#include <main_form.hpp>
#include <nana/gui.hpp>
#include <set_1_form.hpp>

main_form::main_form() : layout{*this},
                         lbl1{*this, "<nie ustawiono>"},
                         btn1{*this, "Ustaw"},
                         lbl2{*this, "<nie ustawiono>"},
                         btn2{*this, "Ustaw 2"}
{
    // layout.div("<abc grid=[2,2] margin=10 gap=5 width=[30%, 70%]>");
    layout.div("<><weight=80% vertical <><weight=70% vertical <vertical gap=10 textboxs arrange=[25,25]>  <weight=25 gap=10 buttons>><>><>");
    layout.field("textboxs") << lbl1 << lbl2;
    layout.field("buttons") << btn1 << btn2;
    layout.collocate();

    btn1.events().click([&](const arg_click& arg){ this->btn1_clicked(arg); });
}

void main_form::btn1_clicked(const arg_click &event_info)
{
    set_1_form s1_fm (event_info.window_handle);
    API::modal_window(s1_fm);
    if (s1_fm.result != "")
    {
        lbl1.caption(s1_fm.result);
    }
}
