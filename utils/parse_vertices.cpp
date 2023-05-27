#include <fstream>
#include <vector>
#include <iostream>

struct Vertex {
    float x, y, z;
};

struct TexCoord {
    float x, y;
};

struct Normal {
    float x, y, z;
};

struct Face {
    Vertex v1, v2, v3;
    TexCoord t1, t2, t3;
    Normal n1, n2, n3;
};

int main(){
    std::vector<Vertex> vertices;
    std::vector<TexCoord> texCoords;
    std::vector<Normal> normals;
    std::vector<Face> faces;

    std::ifstream in("/home/paragoumba/3D models/blender/textured_cube.obj");

    if (!in.is_open()){

        std::cout << "Couldn't find file." << std::endl;
        return 1;

    }

    std::string s;

    std::cout << "std::vector<Vertex> vertices{" << std::endl;

    while (!in.eof()){

        in >> s;

        if (s == "v"){

            Vertex v{};

            in >> v.x;
            in >> v.y;
            in >> v.z;

            vertices.push_back(v);

        } else if (s == "vt"){

            TexCoord vt{};

            in >> vt.x;
            in >> vt.y;

            texCoords.push_back(vt);

        } else if (s == "vn"){

            Normal vn{};

            in >> vn.x;
            in >> vn.y;
            in >> vn.z;

            normals.push_back(vn);

        } else if (s == "f"){

            Face f{};

            int v1, v2, v3, t1, t2, t3, n1, n2, n3;

            char* buffer = new char[256];

            in.getline(buffer, 256, '/');
//            std::cout << buffer << "/";
            v1 = atoi(buffer);
            in.getline(buffer, 256, '/');
//            std::cout << buffer << "/";
            t1 = atoi(buffer);
            in >> n1;
//            std::cout << n1;

            in.getline(buffer, 256, '/');
//            std::cout << buffer << "/";
            v2 = atoi(buffer);
            in.getline(buffer, 256, '/');
//            std::cout << buffer << "/";
            t2 = atoi(buffer);
            in >> n2;
//            std::cout << n2;

            in.getline(buffer, 256, '/');
//            std::cout << buffer << "/";
            v3 = atoi(buffer);
            in.getline(buffer, 256, '/');
//            std::cout << buffer << "/";
            t3 = atoi(buffer);
            in >> n3;
//            std::cout << n3 << std::endl;

            f.v1 = vertices[v1 - 1];
            f.v2 = vertices[v2 - 1];
            f.v3 = vertices[v3 - 1];
            f.t1 = texCoords[t1 - 1];
            f.t2 = texCoords[t2 - 1];
            f.t3 = texCoords[t3 - 1];
            f.n1 = normals[n1 - 1];
            f.n2 = normals[n2 - 1];
            f.n3 = normals[n3 - 1];

            std::cout << "{vec3(" << f.v1.x << ", " << f.v1.y << ", " << f.v1.z << "), vec3(" << f.n1.x << ", " << f.n1.y << ", " << f.n1.z << "), vec2(" << f.t1.x << ", " << f.t1.y << ")}," << std::endl;
            std::cout << "{vec3(" << f.v2.x << ", " << f.v2.y << ", " << f.v2.z << "), vec3(" << f.n2.x << ", " << f.n2.y << ", " << f.n2.z << "), vec2(" << f.t2.x << ", " << f.t2.y << ")}," << std::endl;
            std::cout << "{vec3(" << f.v3.x << ", " << f.v3.y << ", " << f.v3.z << "), vec3(" << f.n3.x << ", " << f.n3.y << ", " << f.n3.z << "), vec2(" << f.t3.x << ", " << f.t3.y << ")}," << std::endl;

            faces.push_back(f);

        }
    }

    std::cout << "};" << std::endl;

}