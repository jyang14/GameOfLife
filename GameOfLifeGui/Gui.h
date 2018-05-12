#pragma once
namespace sf
{
    class RenderWindow;
}
class gui
{
private:
    sf::RenderWindow& window_;
public:
    class builder
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

    public:

        builder();

        void init_gui();

        void set_dimensions(int newWidth, int newHeight, int newDepth);
        void set_inital_state(const char* newState);
        void set_title(const char* newTitle);
        void set_live_rule(int newLiveMin, int newLiveMax);
        void set_birth_rule(int newBirthMin, int newBirthMax);
        void set_draw_delay(int newDrawDelay);
        void set_modular_board(int newMod);
        void set_texture(const char *  newTexturePath);

    };


    gui(int width, int height, int depth,
        const char* state, int mod,
        int liveMin, int liveMax,
        int birthMin, int birthMax,
        int drawDelay, const char* title, const char* texture);
    ~gui();
};

