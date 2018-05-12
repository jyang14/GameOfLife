#pragma once
#include "Game.h"


class gui3
{
    int width_;
    int height_;
    int depth_;

    const char* state_;
    const char* title_;
    const char* texture_path_;

    int live_min_;
    int live_max_;

    int birth_min_;
    int birth_max_;

    int modular_board_;

    int draw_delay_;

    int show(Game& game) const;
public:
    gui3();

    void set_dimensions(int new_width, int new_height, int new_depth);
    void set_inital_state(const char* new_state);
    void set_title(const char* new_title);
    void set_live_rule(int new_live_min, int new_live_max);
    void set_birth_rule(int new_birth_min, int new_birth_max);
    void set_draw_delay(int new_draw_delay);
    void set_modular_board(int new_mod);
    void set_texture(const char* new_texture_path);

    int show_gui() const;
};
