#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Monster
{
private:
	std::string mName;
	int mLevel;
	int mHP;
	int mMP;

public:
	Monster(std::string name, int level, int hp, int mp) : mName{ name }, mLevel{ level }, mHP{ hp }, mMP{ mp }
	{
	}

	friend std::ostream& operator << (std::ostream& os, Monster m)
	{
		os << m.mName << " : " << m.mLevel << " , " << m.mHP << " , " << m.mMP;
		return os;
	}
};



bool LoadFile(const std::string& filename, std::vector<Monster>& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);

	try
	{
		ifs.open(filename);
	
		char buffer[1024];
	
		while (ifs.getline(buffer, 1024))
		{
			int i{};
			if (buffer[i] == '-')
			{
				continue;
			}
			std::string temp;
			std::string name;
			int level{}, hp{}, mp{};
			while (buffer[i] != ',')
			{
				name += buffer[i++];
			}
			i++;
			while (buffer[i] != ',')
			{
				temp += buffer[i++];
			}
			i++;
			level = std::stoi(temp);
			temp = "";
			while (buffer[i] != ',')
			{
				temp += buffer[i++];
			}
			i++;
			hp = std::stoi(temp);
			temp = "";
			while (buffer[i] != '\0')
			{
				temp += buffer[i++];
			}
			mp = std::stoi(temp);
			monsters.push_back({ name, level, hp, mp });
		}

		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << e.code() << " - "<< e.what() << std::endl;
		ifs.close();
		return false;
	}

	return true;
}

int main()
{
	std::vector<Monster> monsters;

	LoadFile("Data/SimpleData.txt", monsters);

	for (const auto& e : monsters)
	{
		std::cout << e << std::endl;
	}
}