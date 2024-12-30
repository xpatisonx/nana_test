//
// Created by bpolo on 30.12.2024.
//

#ifndef SET_1_FORM_HPP
#define SET_1_FORM_HPP

#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>

using namespace nana;

class set_1_form : public form
{
public:
    set_1_form(window owner);
    std::string result;

private:
    place layout;
    label lbl1;
    textbox txt1;
    button btn_ok;
    button btn_cancel;

    void btn_ok_clicked();

};

#endif //SET_1_FORM_HPP
