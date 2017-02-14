#include "headerFile.h"


void createCuboid (float x, float y, float z, float height, float width, float depth, COLOR color, COLOR color2, COLOR color3, COLOR color4) {
  // GL3 accepts only Triangles. Quads are not supported
  float w=width/2,h=height/2,d=depth/2;
  static const GLfloat vertex_buffer_data [] = {
    -w, h, d,
    -w, -h, d,
    w, -h, d,
    -w, h, d,
    w, -h, d,
    w, h, d,
    w, h, d,
    w, -h, d,
    w, -h, -d,
    w, h, d,
    w, -h, -d,
    w, h, -d,
    w, h, -d,
    w, -h, -d,
    -w, -h, -d,
    w, h, -d,
    -w, -h, -d,
    -w, h, -d,
    -w, h, -d,
    -w, -h, -d,
    -w, -h, d,
    -w, h, -d,
    -w, -h, d,
    -w, h, d,
    -w, h, -d,
    -w, h, d,
    w, h, d,
    -w, h, -d,
    w, h, d,
    w, h, -d,
    -w, -h, d,
    -w, -h, -d,
    w, -h, -d,
    -w, -h, d,
    w, -h, -d,
    w, -h, d,
    -w, h, d,
    w, h, -d,
    w, h, -d,
  };

  static const GLfloat color_buffer_data [] = {
    color.r,color.g,color.b, // color 1
    color.r,color.g,color.b, // color 2
    color2.r,color2.g,color2.b, // color 3

    color2.r,color2.g,color2.b, // color 4
    color2.r,color2.g,color2.b, // color 5
    color.r,color.g,color.b, // color 6

    color2.r,color2.g,color2.b, // color 4
    color2.r,color2.g,color2.b, // color 5
    color.r,color.g,color.b, // color 6

    color.r,color.g,color.b, // color 1
    color.r,color.g,color.b, // color 2
    color2.r,color2.g,color2.b, // color 3

    color.r,color.g,color.b, // color 1
    color.r,color.g,color.b, // color 2
    color2.r,color2.g,color2.b, // color 3

    color2.r,color2.g,color2.b, // color 4
    color2.r,color2.g,color2.b, // color 5
    color.r,color.g,color.b, // color 6

    color2.r,color2.g,color2.b, // color 4
    color2.r,color2.g,color2.b, // color 5
    color.r,color.g,color.b, // color 6

    color.r,color.g,color.b, // color 1
    color.r,color.g,color.b, // color 2
    color2.r,color2.g,color2.b, // color 3

    color.r,color.g,color.b, // color 1
    color2.r,color2.g,color2.b, // color 2
    color3.r,color3.g,color3.b, // color 3

    color3.r,color3.g,color3.b, // color 4
    color4.r,color4.g,color4.b, // color 5
    color.r,color.g,color.b, // color 6

    color.r,color.g,color.b, // color 1
    color2.r,color2.g,color2.b, // color 2
    color3.r,color3.g,color3.b, // color 3

    color3.r,color3.g,color3.b, // color 4
    color4.r,color4.g,color4.b, // color 5
    color.r,color.g,color.b, // color 6
  };

  // create3DObject creates and returns a handle to a VAO that can be used later
  VAO *object = create3DObject(GL_TRIANGLES, 13*3, vertex_buffer_data, color_buffer_data, GL_FILL);
  cuboid.x = x;
  cuboid.y = y;
  cuboid.z = z;
  cuboid.height = height;
  cuboid.width = width;
  cuboid.depth = depth;
  cuboid.x_rotation_status = 0;
  cuboid.z_rotation_status = 0;
  cuboid.x_rotation_angle = 0;
  cuboid.z_rotation_angle = 0;
  cuboid.state = 0;
  cuboid.orientation = 'y';
  cuboid.prev_orientation = 'y';
  cuboid.transition = 'y';
  cuboid.object = object;
}

/*void createCuboid (float x, float y, float z, float height, float width, float depth, COLOR color, COLOR color2, COLOR color3, COLOR color4) {
  float w=width/2,h=height/2,d=depth/2;
  static const GLfloat vertex_buffer_data [] = {
    -w, h, d,
    -w, -h, d,
    w, -h, d,
    -w, h, d,
    w, -h, d,
    w, h, d,
    w, h, d,
    w, -h, d,
    w, -h, -d,
    w, h, d,
    w, -h, -d,
    w, h, -d,
    w, h, -d,
    w, -h, -d,
    -w, -h, -d,
    w, h, -d,
    -w, -h, -d,
    -w, h, -d,
    -w, h, -d,
    -w, -h, -d,
    -w, -h, d,
    -w, h, -d,
    -w, -h, d,
    -w, h, d,
    -w, h, -d,
    -w, h, d,
    w, h, d,
    -w, h, -d,
    w, h, d,
    w, h, -d,
    -w, -h, d,
    -w, -h, -d,
    w, -h, -d,
    -w, -h, d,
    w, -h, -d,
    w, -h, d,
    -w, h, d,
    w, h, -d,
    w, h, -d,
  };

  GLfloat color_buffer_data [] = {
    color4.r,color4.g,color4.b, // color 1
    color4.r,color4.g,color4.b, // color 2
    color4.r,color4.g,color4.b, // color 3

    color4.r,color4.g,color4.b, // color 4
    color4.r,color4.g,color4.b, // color 5
    color4.r,color4.g,color4.b, // color 6

    color4.r,color4.g,color4.b, // color 1
    color4.r,color4.g,color4.b, // color 2
    color4.r,color4.g,color4.b, // color 3

    color4.r,color4.g,color4.b, // color 4
    color4.r,color4.g,color4.b, // color 5
    color4.r,color4.g,color4.b, // color 6

    color4.r,color4.g,color4.b, // color 1
    color4.r,color4.g,color4.b, // color 2
    color4.r,color4.g,color4.b, // color 3

    color4.r,color4.g,color4.b, // color 4
    color4.r,color4.g,color4.b, // color 5
    color4.r,color4.g,color4.b, // color 6

    color4.r,color4.g,color4.b, // color 1
    color4.r,color4.g,color4.b, // color 2
    color4.r,color4.g,color4.b, // color 3

    color4.r,color4.g,color4.b, // color 4
    color4.r,color4.g,color4.b, // color 5
    color4.r,color4.g,color4.b, // color 6

    color.r,color.g,color.b, // color 1
    color2.r,color2.g,color2.b, // color 2
    color3.r,color3.g,color3.b, // color 3

    color3.r,color3.g,color3.b, // color 4
    color4.r,color4.g,color4.b, // color 5
    color.r,color.g,color.b, // color 6

    color.r,color.g,color.b, // color 1
    color2.r,color2.g,color2.b, // color 2
    color3.r,color3.g,color3.b, // color 3

    color3.r,color3.g,color3.b, // color 4
    color4.r,color4.g,color4.b, // color 5
    color.r,color.g,color.b, // color 6
  };

  // create3DObject creates and returns a handle to a VAO that can be used later
  VAO *object = create3DObject(GL_TRIANGLES, 13*3, vertex_buffer_data, color_buffer_data, GL_FILL);
  cuboid.x = x;
  cuboid.y = y;
  cuboid.z = z;
  cuboid.height = height;
  cuboid.width = width;
  cuboid.depth = depth;
  cuboid.x_rotation_status = 0;
  cuboid.z_rotation_status = 0;
  cuboid.x_rotation_angle = 0;
  cuboid.z_rotation_angle = 0;
  cuboid.state = 0;
  cuboid.orientation = 'y';
  cuboid.prev_orientation = 'y';
  cuboid.transition = 0;
  cuboid.object = object;
}*/

void cuboidEngine() {
  createCuboid(Tile[0].x, Tile[0].y+2.5, Tile[0].z, 4, 2, 2, lightgreen, red, blue, sun);
}
