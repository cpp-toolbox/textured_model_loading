# Info

Code which loads in obj models with textures using assimp to be rendered with opengl

# Dependencies

* [glad](https://github.com/opengl-toolbox/glad_opengl_3.3_core) - glad opengl function loader
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

# ASSIMP: Asset Importer
# only use obj to speed up compilation
set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ASSIMP_NO_EXPORT OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_OBJ_IMPORTER ON CACHE BOOL "" FORCE)
include_directories(external_libraries/assimp/include)
add_subdirectory(external_libraries/assimp)

# STB_H: single file libraries
include_directories(external_libraries/stb)

... 

target_link_libraries(your_project_name ... )
```
