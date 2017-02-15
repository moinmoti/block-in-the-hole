#ifndef headerFile
#define headerFile

#include <bits/stdc++.h>
#include <irrKlang.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace irrklang;

struct VAO {
  GLuint VertexArrayID;
  GLuint VertexBuffer;
  GLuint ColorBuffer;

  GLenum PrimitiveMode;
  GLenum FillMode;
  int NumVertices;
};
typedef struct VAO VAO;

typedef struct ENTITY {
  string id;
  float x, y, z;
  float height, width, depth;
  float radius;
  float x_angle;
  float z_angle;
  bool x_rotation_status;
  bool z_rotation_status;
  float x_rotation_angle;
  float z_rotation_angle;
  string type;
  char orientation;
  char prev_orientation;
  char transition;
  int state;
  int status;
  VAO * object;
}ENTITY;

extern vector <ENTITY> Tile;
extern ENTITY cuboid;
extern map <string, ENTITY> Led;
extern int bridge1_i;
extern int bridge1_j;
extern int bridge2_i;
extern int bridge2_j;
extern int switch_i;
extern int switch_j;
extern int victory_i;
extern int victory_j;
extern vector <pair<int, int> > fragile_tiles;

typedef struct COLOR {
  float r;
  float g;
  float b;
}COLOR;

extern COLOR grey;
extern COLOR silver;
extern COLOR sun;
extern COLOR gold;
extern COLOR coingold;
extern COLOR red;
extern COLOR lightgreen;
extern COLOR darkgreen;
extern COLOR black;
extern COLOR blue;
extern COLOR darkbrown;
extern COLOR lightbrown;
extern COLOR brown1;
extern COLOR brown2;
extern COLOR brown3;
extern COLOR cratebrown;
extern COLOR cratebrown1;
extern COLOR cratebrown2;
extern COLOR skyblue2;
extern COLOR skyblue1;
extern COLOR skyblue;
extern COLOR cloudwhite;
extern COLOR cloudwhite1;
extern COLOR lightpink;
extern COLOR darkpink;
extern COLOR white;
extern COLOR scorecolor;


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}
void quit(GLFWwindow *window);
void initGLEW(void);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);
void draw3DObject (struct VAO* vao);
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);
void reshapeWindow (GLFWwindow* window, int width, int height);
void draw (GLFWwindow* window, int doM, int doV, int doP);
GLFWwindow* initGLFW (int width, int height);
void initGL (GLFWwindow* window, int width, int height);
int main (int argc, char** argv);
void createTile (float x, float y, float z, float height, float width, float depth, COLOR color, COLOR color2, COLOR color3, COLOR color4);
void gridEngine();
void createCuboid (float x, float y, float z, float height, float width, float depth, COLOR color, COLOR color2, COLOR color3, COLOR color4);
void cuboidEngine();
int isEnd();
void checkSwitch();
int checkVictory();

#endif
