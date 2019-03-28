#pragma once
#include <gl/glew.h>
#include "Texture.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "glm.hpp"

#include <string>

#include <windows.h>
#include <gl/GL.h>

class Texture;

class ObjModel
{
private:

	glm::vec3 position = glm::vec3(0, 0, 50);

	class MaterialInfo
	{
	public:
		MaterialInfo();
		std::string name;
		Texture* texture;
		Texture* bumpMap;

		bool hasTexture;
	};

	class ObjGroup
	{
	public:
		std::string name;
		int start;
		int end;
		int materialIndex;

	};

	std::vector<ObjGroup*> groups;
	std::vector<MaterialInfo*> materials;
	GLuint _vertexArray;

	void loadMaterialFile(std::string fileName, std::string dirName);

public:
	ObjModel(std::string filename, glm::vec3 position);
	~ObjModel(void);

	void draw();

	void moveObject(int x, int y, int z);
	void resize(double facX, double facY, double facZ);

	glm::vec3 getPosition();

};

