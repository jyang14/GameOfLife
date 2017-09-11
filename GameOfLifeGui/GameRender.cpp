#include "GameRender.h"

void GameRender::drawBoundingBox()
{

    glColor3f(1, 0, 0);
    glLineWidth(1);

    glBegin(GL_LINE_LOOP);

    glVertex3f((float) (width - width / 2), 1.0f, (float) (depth - depth / 2));
    glVertex3f((float) (-width / 2), 1.0f, (float) (depth - depth / 2));
    glVertex3f((float) (-width / 2), 1.0f, (float) (-depth / 2));
    glVertex3f((float) (width - width / 2), 1.0f, (float) (-depth / 2));

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f((float) (width - width / 2), 1.0f - height, (float) (depth - depth / 2));
    glVertex3f((float) (-width / 2), 1.0f - height, (float) (depth - depth / 2));
    glVertex3f((float) (-width / 2), 1.0f - height, (float) (-depth / 2));
    glVertex3f((float) (width - width / 2), 1.0f - height, (float) (-depth / 2));

    glEnd();

    glBegin(GL_LINES);

    glVertex3f((float) (width - width / 2), 1.0f, (float) (depth - depth / 2));
    glVertex3f((float) (width - width / 2), 1.0f - height, (float) (depth - depth / 2));

    glVertex3f((float) (-width / 2), 1.0f, (float) (depth - depth / 2));
    glVertex3f((float) (-width / 2), 1.0f - height, (float) (depth - depth / 2));

    glVertex3f((float) (-width / 2), 1.0f, (float) (-depth / 2));
    glVertex3f((float) (-width / 2), 1.0f - height, (float) (-depth / 2));

    glVertex3f((float) (width - width / 2), 1.0f, (float) (-depth / 2));
    glVertex3f((float) (width - width / 2), 1.0f - height, (float) (-depth / 2));

    glEnd();
}

void GameRender::render()
{
    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 20);

    for (int row = 0; row < height; row++)
        for (int column = 0; column < width; column++)
            for (int layer = 0; layer < depth; layer++)
                if (boards[gen % 2].isOccupied(row, column, layer))
                    manager.render(row, column, layer);


    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    drawBoundingBox();
}

GameRender::GameRender(int width, int height, int depth, int mod, int liveMin, int liveMax, int birthMin, int birthMax)
    :Game(width, height, depth, mod, liveMin, liveMax, birthMin, birthMax), manager(width, height, depth)
{
}

GameRender::~GameRender()
{
}
