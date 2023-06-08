#pragma once

#include <vector>

#include "DataTypes.h"

class Mesh {
private:
    std::vector<DataTypes::Vertex> vertices;
    std::vector<uint32_t> indices;
    std::vector<DataTypes::Texture> textures;

    uint32_t vertexArrayObject, vertexBufferObject, elementBufferObject;

public:
    Mesh(): vertexArrayObject(0), vertexBufferObject(0), elementBufferObject(0) { }
    Mesh(const std::vector<DataTypes::Vertex>& vertices, const std::vector<uint32_t>& indices, const std::vector<DataTypes::Texture>& textures);
    ~Mesh();

    void setup_mesh();
    void set_vertices(const std::vector<DataTypes::Vertex>& vertices);
    void set_indices(const std::vector<uint32_t>& indices);
    void set_textures(const std::vector<DataTypes::Texture>& textures);

    void destroy();
};