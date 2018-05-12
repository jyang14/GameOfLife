#pragma once
#include <cstdint>
class cube3
{
    uint32_t triangles_;

public:
    int get_triangle_count() const;

    void render() const;

    cube3(int x, int y, int z);
    cube3(cube3 &other) = delete;
    cube3(cube3 &&other) = delete;

    cube3 & operator=(cube3 &other) = delete;
    cube3 & operator=(cube3 &&other) = delete;
    ~cube3();
};
