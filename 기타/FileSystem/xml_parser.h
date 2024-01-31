#pragma once
#include <string>
#include <vector>
#include <regex>
#include <fstream>

class Sprite
{
public:
	std::string n;
	int x;
	int y;
	int w;
	int h;

	friend std::ostream& operator << (std::ostream& os, Sprite s)
	{
		os << s.n << " " << s.x << " " << s.y << " " << s.w << " " << s.h;

		return os;
	}
};

void LoadXML(const char* filename, std::vector<Sprite>& sprites)
{
	/*sprites.clear();
	std::ifstream file(filename, std::ifstream::binary);
	std::string line;
	std::regex pattern("\"([^\"]*)\"");

	while (!file.eof())
	{
		std::getline(file, line);

		size_t result = line.find("<sprite");
		if (result != std::string::npos)
		{
			std::sregex_iterator current(line.begin(), line.end(), pattern);
			std::sregex_iterator end;

			Sprite s;
			s.n = (*current)[1];
			current++;
			s.x = std::stoi((*current)[1]);
			current++;
			s.y = std::stoi((*current)[1]);
			current++;
			s.w = std::stoi((*current)[1]);
			current++;
			s.h = std::stoi((*current)[1]);

			sprites.push_back(s);
		}
	}

	file.close();*/

	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);

	try
	{
		ifs.open(filename);

		std::string line;

		std::getline(ifs, line);

		while(!ifs.eof())
		{
			while(std::getline(ifs, line, '<'))
			{
				std::getline(ifs, line, ' ');
				if(line == "sprite")
				{
					Sprite s;

					std::getline(ifs, line, '"');
					std::getline(ifs, line, '"');

					s.n = line;

					std::getline(ifs, line, '"');
					std::getline(ifs, line, '"');

					s.x = std::stoi(line);

					std::getline(ifs, line, '"');
					std::getline(ifs, line, '"');

					s.y = std::stoi(line);

					std::getline(ifs, line, '"');
					std::getline(ifs, line, '"');

					s.w = std::stoi(line);

					std::getline(ifs, line, '"');
					std::getline(ifs, line, '"');

					s.h = std::stoi(line);

					sprites.push_back(s);
				}
			}
		}
		
		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << e.code() << " - " << e.what() << std::endl;
		ifs.close();
	}

}

void XMLTest()
{
	std::vector<Sprite> sprites;

	LoadXML("Data/mydata.xml", sprites);

	for (const auto& e : sprites)
	{
		std::cout << e << std::endl;
	}
}