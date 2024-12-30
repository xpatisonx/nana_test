//
// Created by bpolo on 30.12.2024.
//

#include <set_1_form.hpp>
#include <nana/gui/msgbox.hpp>

set_1_form::set_1_form(window owner) : form(owner, API::make_center(owner, 300, 150),
                                            appearance(true, false, false, false, false, false, false)),
                                       layout{*this},
                                       lbl1{*this, "Podaj wartość (minimum 3 znaki):"},
                                       txt1{*this},
                                       btn_ok{*this, "OK"},
                                       btn_cancel{*this, "Anuluj"}
{
    layout.div(
        "<><weight=80% vertical <><weight=70% vertical <vertical gap=10 textboxs arrange=[25,25]>  <weight=25 gap=10 buttons>><>><>");
    layout.field("textboxs") << lbl1 << txt1;
    layout.field("buttons") << btn_ok << btn_cancel;
    layout.collocate();

    txt1.multi_lines(false);
    result = "";

    events().key_press([&](const arg_keyboard &arg)
    {
        if (arg.key == keyboard::escape)
        {
            close();
        }
    });

    btn_cancel.events().click([&]
    {
        close();
    });

    btn_ok.events().click([&]
    {
        btn_ok_clicked();
    });

    txt1.events().key_press([&](const arg_keyboard &arg)
    {
        if (arg.key == keyboard::enter)
        {
            btn_ok_clicked();
        }
        else if (arg.key == keyboard::escape)
        {
            close();
        }
    });

    txt1.focus();
}

void set_1_form::btn_ok_clicked()
{
    if (txt1.text().length() < 3)
    {
        msgbox m{ *this, "Błąd", msgbox::button_t::ok};
        m.icon(msgbox::icon_error );
        m << "Zbyt krótki tekst";
        m.show();
    }
    else
    {
        result = txt1.text();
        close();
    }
}
