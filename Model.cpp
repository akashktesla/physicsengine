#include "Model.h"


struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
};

void Draw(Shader& shader)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].Draw(shader);
}

void loadModel(string path)
{
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate |
		aiProcess_FlipUVs);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
		!scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
		return;
	}
	directory = path.substr(0, path.find_last_of(' / '));
	processNode(scene->mRootNode, scene);
}

Mesh processMesh(aiMesh* mesh, const aiScene* scene)
{
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		// process vertex positions, normals and texture coordinates
		[...]
		vertices.push_back(vertex);
	}
	// process indices
	[...]
	// process material
	if (mesh->mMaterialIndex >= 0)
	{
		[...]
	}
	return Mesh(vertices, indices, textures);
}

void processNode(aiNode* node, const aiScene* scene)
{
	// process all the node�s meshes (if any)
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	// then do the same for each of its children
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}


Mesh processMesh(aiMesh * mesh, const aiScene * scene)
{
		vector<Vertex> vertices;
		vector<unsigned int> indices;
		vector<Texture> textures;
		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			Vertex vertex;
			// process vertex positions, normals and texture coordinates
			[...]
			vertices.push_back(vertex);
		}
		// process indices
		[...]
		// process material
		if (mesh->mMaterialIndex >= 0)
		{
			[...]
		}
		return Mesh(vertices, indices, textures);
}