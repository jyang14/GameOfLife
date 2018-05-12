#pragma once

#include "GL/glew.h"
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Game.h"
#include "camera3.h"

class game_render3
{
    static const float vertices[12 * 8 * 3];

    int time_;
    int draw_delay_;

    GLuint vbo_;
    GLuint vao_;

    sf::Shader cube_shader_;
    sf::Texture cube_texture_;

    Game &game_;

    camera3 &camera_;

    glm::mat4 *models_;

public:

    void render(int ms);

    int init(const char* texture_path, const char* vert_shader_path, const char* frag_shader_path);

    game_render3(Game &game, camera3 &camera, int draw_delay);
    game_render3(game_render3 &other) = delete;
    game_render3(game_render3 &&other) = delete;

    game_render3 & operator=(game_render3 &other) = delete;
    game_render3 & operator=(game_render3 &&other) = delete;
    ~game_render3();
};

