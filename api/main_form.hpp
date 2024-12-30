//
// Created by bpolo on 30.12.2024.
//

#ifndef MAIN_FORM_HPP
#define MAIN_FORM_HPP
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/label.hpp>

using namespace nana;

class main_form : public form
{
public:
    main_form();

private:
    place layout;
    label lbl1;
    button btn1;
    label lbl2;
    button btn2;

    void btn1_clicked(const arg_click& ei);
};

#endif //MAIN_FORM_HPP
