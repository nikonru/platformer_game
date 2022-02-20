#include "b2GLDraw.h"
#include <cstdio>
#include <cstdarg>
#include <cstring>

constexpr int TILE_SIZE_X = 50; // in pixel
constexpr int TILE_SIZE_Y = TILE_SIZE_X; // in pixel
constexpr int PIXSEL_PER_METER = (2*TILE_SIZE_X);

constexpr float screen_width = 1080;
constexpr float screen_height = 720;

using namespace sf;

void b2GLDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    glPushMatrix();
    glLoadIdentity();
        glTranslatef( -1, 1, 0 );
        glScalef(1/screen_width, -1/screen_height, 1);
        glColor4f(color.r, color.g, color.b, 0.5f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < vertexCount; i++) {
            b2Vec2 v = vertices[i];
            glVertex2f(v.x * PIXSEL_PER_METER, v.y * PIXSEL_PER_METER);
        }
        glEnd();
    glPopMatrix();
}

void b2GLDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    glPushMatrix();
    glLoadIdentity();
        glTranslatef( -1, 1, 0 );
        glScalef(1/screen_width, -1/screen_height, 1);
        glColor4f(color.r, color.g, color.b, 0.5f);
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < vertexCount; i++) {
            b2Vec2 v = vertices[i];
            glVertex2f(v.x * PIXSEL_PER_METER, v.y * PIXSEL_PER_METER);
        }
        glEnd();
    glPopMatrix();
}

void b2GLDraw::DrawCircle(const b2Vec2& center, float radius, const b2Color& color) {
    const float k_segments = 16.0f;
    //const int vertexCount = 16;
    const float k_increment = 2.0f * b2_pi / k_segments;
    float theta = 0.0f;
    glPushMatrix();
    glLoadIdentity();
        glTranslatef( -1, 1, 0 );
        glScalef(1/screen_width, -1/screen_height, 1);
        glColor4f(color.r, color.g, color.b, 1);
        glBegin(GL_LINE_LOOP);
        //GLfloat glVertices[vertexCount * 2];
        for (int32 i = 0; i < k_segments; ++i) {
            b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
            glVertex2f(v.x * PIXSEL_PER_METER, v.y * PIXSEL_PER_METER);
            theta += k_increment;
        }
        glEnd();
    glPopMatrix();
}

void b2GLDraw::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color) {
    const float k_segments = 16.0f;
    //const int vertexCount = 16;
    const float k_increment = 2.0f * b2_pi / k_segments;
    float theta = 0.0f;
    glPushMatrix();
    glLoadIdentity();
        glTranslatef( -1, 1, 0 );
        glScalef(1/screen_width, -1/screen_height, 1);
        glColor4f(color.r, color.g, color.b, 0.5f);
        glBegin(GL_TRIANGLE_FAN);
        //GLfloat glVertices[vertexCount * 2];
        for (int32 i = 0; i < k_segments; ++i) {
            b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
            glVertex2f(v.x * PIXSEL_PER_METER, v.y * PIXSEL_PER_METER);
            theta += k_increment;
        }
        glEnd();
    glPopMatrix();
    DrawSegment(center, center + radius*axis, color);
}

void b2GLDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
    glPushMatrix();
    glLoadIdentity();
        glTranslatef( -1, 1, 0 );
        glScalef(1/screen_width, -1/screen_height, 1);
        glColor4f(color.r, color.g, color.b, 1);
        glBegin(GL_LINES);
        glVertex2f(p1.x * PIXSEL_PER_METER, p1.y * PIXSEL_PER_METER);
        glVertex2f(p2.x * PIXSEL_PER_METER, p2.y * PIXSEL_PER_METER);
        glEnd();
    glPopMatrix();
}

void b2GLDraw::DrawPoint(const b2Vec2& p, float size, const b2Color& color) {
    if (size) {} // fix unused

    glPushMatrix();
    glLoadIdentity();
        glTranslatef( -1, 1, 0 );
        glScalef(1/screen_width, -1/screen_height, 1);
        glColor4f(color.r, color.g, color.b, 1);
        glPointSize(1.0f);
        glBegin(GL_POINTS);
        glVertex2f(p.x * PIXSEL_PER_METER, p.y * PIXSEL_PER_METER);
        glEnd();
    glPopMatrix();
}

void b2GLDraw::DrawString(int x, int y, const char *string, ...) {
    // TODO:
    if (x) {} // fix unused
    if (y) {}
    if (string) {}
}

void b2GLDraw::DrawAABB(b2AABB* aabb, const b2Color& c) {
    glPushMatrix();
    glLoadIdentity();
        glTranslatef( -1, 1, 0 );
        glScalef(1/screen_width, -1/screen_height, 1);
        glColor4f(c.r, c.g, c.b, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(aabb->lowerBound.x * PIXSEL_PER_METER, aabb->lowerBound.y * PIXSEL_PER_METER);
        glVertex2f(aabb->upperBound.x * PIXSEL_PER_METER, aabb->lowerBound.y * PIXSEL_PER_METER);
        glVertex2f(aabb->upperBound.x * PIXSEL_PER_METER, aabb->upperBound.y * PIXSEL_PER_METER);
        glVertex2f(aabb->lowerBound.x * PIXSEL_PER_METER, aabb->upperBound.y * PIXSEL_PER_METER);
        glEnd();
    glPopMatrix();
}

void b2GLDraw::DrawTransform(const b2Transform& xf) {
    
    b2Vec2 p1 = xf.p, p2;
    const float k_axisScale = 0.0f;
    
    p2 = p1 + k_axisScale * xf.q.GetXAxis();
    DrawSegment(p1, p2, b2Color(1, 0, 0));
    
    p2 = p1 + k_axisScale * xf.q.GetYAxis();
    DrawSegment(p1, p2, b2Color(0, 1, 0));
}
