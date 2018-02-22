#include <iostream>
#include <fstream>
#include <sstream>
#include <Partio.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "tiny_obj_loader.h"
using namespace std;


template<class T>	
void createFromObj(const char* filename)
{

	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	const char* mtl_basspath = nullptr;
	std::string error = tinyobj::LoadObj(shapes, materials, filename, mtl_basspath);
	std::cout << error << std::endl;
	if(error.size() == 0){
		//count = 0;
		for(unsigned int i = 0; i < shapes.size(); ++i)
		{
			std::vector<T> &positions = shapes[i].mesh.positions;
			//std::vector<T> &normals = shapes[i].mesh.normals;
			//std::vector<T> &uvs = shapes[i].mesh.texcoords;
			std::vector<unsigned int> &indices = shapes[i].mesh.indices;

			//bool normalsExist = normals.size() > 0;
			// uvExist = uvs.size() > 0;

			std::vector<unsigned int> myIndices;
			for(unsigned int ui : indices)
			{
				myIndices.push_back(ui);
			}
			
			
			for(unsigned int j = 0; j < positions.size(); j++)
			{
				std::cout << positions.at(j) << std::endl;
			}
		}


	}
	else
	{
		std::cout << error << std::endl;
	}
	
}
int main(int argc, char* argv[])
{

	createFromObj<float>("Fidget_Spinner.obj");
	std::cout << "!!!" << std::endl;
	return 0;
}

