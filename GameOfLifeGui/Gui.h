#pragma once
namespace sf
{
    class RenderWindow;
}
class Gui
{
private:
    sf::RenderWindow& window;
public:
    class Builder
    {
        int width;
        int height;
        int depth;

        const char* state;
        const char* title;
        const char* texturePath;

        int liveMin;
        int liveMax;

        int birthMin;
        int birthMax;

        int mod;

        int drawDelay;

    public:

        Builder();

        void initGui();

        void setDimensions(int newWidth, int newHeight, int newDepth);
        void setInitalState(const char* newState);
        void setTitle(const char* newTitle);
        void setLiveRule(int newLiveMin, int newLiveMax);
        void setBirthRule(int newBirthMin, int newBirthMax);
        void setDrawDelay(int newDrawDelay);
        void setModularBoard(int newMod);
        void setTexture(const char *  newTexturePath);

    };


    Gui(int width, int height, int depth,
        const char* state, int mod,
        int liveMin, int liveMax,
        int birthMin, int birthMax,
        int drawDelay, const char* title, const char* texture);
    ~Gui();
};

