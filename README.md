# Info

Code which loads in obj models with textures using assimp to be rendered with opengl

# Dependencies

* [glm](https://github.com/g-truc/glm) - to hold vertex data
* [shader pipeline](https://github.com/opengl-toolbox/shader_pipeline) - for drawing with opengl
* [assimp](https://github.com/assimp/assimp) - for loading obj files
* [stb](https://github.com/nothings/stb) - for loading images

# CMake

```
...

# GLM: opengl mathematics
include_directories(external_libraries/glm)
add_subdirectory(external_libraries/glm)

... 

target_link_libraries(your_project_name ...)
```
