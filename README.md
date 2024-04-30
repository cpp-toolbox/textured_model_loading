# Info

Code which loads in obj models with textures using assimp to be rendered with opengl

# Depdendencies

* [glm](https://github.com/g-truc/glm)

# CMake

```
...

# GLM: opengl mathematics

include_directories(external_libraries/glm)
add_subdirectory(external_libraries/glm)

... 

target_link_libraries(your_project_name ...)
```
