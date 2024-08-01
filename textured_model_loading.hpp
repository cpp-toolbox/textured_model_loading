#ifndef TEXTURED_MODEL_LOADING_HPP
#define TEXTURED_MODEL_LOADING_HPP

#include "glm/glm.hpp"
#include <string>
#include <utility>
#include <vector>
#include <GLFW/glfw3.h>
#include <assimp/scene.h>

#include "model_loading.hpp"

enum TextureType { DIFFUSE, SPECULAR };

struct TextureInfo {
    TextureType type;
    std::string path;
};

class TexturedMesh : public Mesh {
  public:
    TexturedMesh(std::vector<glm::vec3> vertex_positions, std::vector<unsigned int> indices,
                 std::vector<glm::vec2> texture_coordinates, std::vector<glm::vec3> normals,
                 std::vector<TextureInfo> &used_textures)
        : Mesh(vertex_positions, indices), texture_coordinates(texture_coordinates), normals(normals),
          used_textures(used_textures) {
        assert(normals.size() == texture_coordinates.size() && texture_coordinates.size() == vertex_positions.size());
    };

    std::vector<TextureInfo> used_textures;
    std::vector<glm::vec2> texture_coordinates;
    std::vector<glm::vec3> normals;

    unsigned int vertex_attribute_object{}, vertex_buffer_object{}, element_buffer_object{};
};

struct TexturedModel {
    std::vector<TexturedMesh> meshes;
};

class TexturedModelLoader : ModelLoader {
    //    void recursively_process_nodes(aiNode *node, const aiScene *scene);
    //    std::vector<Vertex> process_mesh_vertices(aiMesh *mesh);
    //    std::vector<unsigned int> process_mesh_indices(aiMesh *mesh);
    std::pair<std::vector<glm::vec2>, std::vector<glm::vec3>> process_mesh_vertices_texture_info(aiMesh *mesh);
    std::vector<TextureInfo> process_mesh_materials(aiMesh *mesh, const aiScene *scene);
    std::vector<TextureInfo> get_texture_info_for_material(aiMaterial *material, aiTextureType type,
                                                           TextureType texture_type);

    TexturedMesh process_mesh(aiMesh *mesh, const aiScene *scene);
    void process_function(aiMesh *mesh, const aiScene *scene);
    std::vector<TexturedMesh> recursively_collected_meshes;

  public:
    TexturedModel load_model(const std::string &path);
};

#endif // TEXTURED_MODEL_LOADING_HPP