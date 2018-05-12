#include "game_render3.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.inl>

#ifdef _DEBUG
#include <iostream>
#endif

//#include <cmath>
//#include <cstring>

const float game_render3::vertices[] = {
    // positions            //normals               // texture coords,
    -0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,    0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,    1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,    1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,    1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,    0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,    0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,    1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,    0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,    0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,    0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,    1.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,    1.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    0.0f, 1.0f,

     0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,    1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,     1.0f,  0.0f,  0.0f,    0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,    0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,    0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,     1.0f,  0.0f,  0.0f,    1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,    1.0f, 1.0f,

    -0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,    0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,    1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,    1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,    1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,    0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,    0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,     0.0f,  1.0f,  0.0f,    0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,     0.0f,  1.0f,  0.0f,    1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,    1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,    1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,    0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,     0.0f,  1.0f,  0.0f,    0.0f, 1.0f
};

void game_render3::render(const int ms)
{
    time_ += ms;

    if (time_ > draw_delay_)
    {
#ifdef _DEBUG
        std::cout << ms << std::endl;
#endif
        time_ = 0;
        game_.playOne();
    }

    sf::Texture::bind(&cube_texture_);
    sf::Shader::bind(&cube_shader_);

    cube_shader_.setUniform("texture1", cube_texture_);
    cube_shader_.setUniform("view", sf::Glsl::Mat4(value_ptr(camera_.get_view_matrix())));

    glBindVertexArray(vao_);

    const auto width = game_.get_width();
    const auto height = game_.get_height();
    game_.for_each_alive([&](const int row, const int column, const int layer)
    {
        cube_shader_.setUniform("model", sf::Glsl::Mat4(value_ptr(models_[layer * width * height + row * width + column])));
        glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
    });

    sf::Shader::bind(nullptr);
}

int game_render3::init(const char* texture_path, const char* vert_shader_path, const char* frag_shader_path)
{
    if (!cube_texture_.loadFromFile(texture_path))
        return -1;

    // Attempt to generate a mipmap for our cube texture
    // We don't check the return value here since
    // mipmapping is purely optional in this example
    cube_texture_.generateMipmap();

    if (!cube_shader_.loadFromFile(vert_shader_path, frag_shader_path))
        return -1;

    sf::Shader::bind(&cube_shader_);
    cube_shader_.setUniform("projection", sf::Glsl::Mat4(value_ptr(camera3::get_perspective_matrix())));

    sf::Shader::bind(nullptr);

    return 0;
}

game_render3::game_render3(Game &game, camera3 &camera, const int draw_delay)
    : time_(0), draw_delay_(draw_delay), vbo_(0), vao_(0), game_(game), camera_(camera)
{
    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);

    glBindVertexArray(vao_);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position atribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), static_cast<void*>(nullptr));
    glEnableVertexAttribArray(0);

    // normal attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    const auto width = game_.get_width();
    const auto height = game_.get_height();
    const auto depth = game_.get_depth();
    models_ = new glm::mat4[width * height * depth];

    for (auto row = 0; row < height; row++)
        for (auto column = 0; column < width; column++)
            for (auto layer = 0; layer < depth; layer++)
                models_[layer * width * height + row * width + column] = translate(glm::mat4(), glm::vec3(column - game_.get_width() / 2, -row, layer - game_.get_height() / 2));

}

game_render3::~game_render3()
{
    delete[] models_;
    glDeleteBuffers(1, &vbo_);
    glDeleteVertexArrays(1, &vao_);

}