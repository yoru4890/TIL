#include <iostream>
#include <fstream>
#include <sstream>

#pragma warning(push)
#pragma warning(disable : 26451 26495)
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#pragma warning(pop)

#include "monster.h"

using namespace rapidjson;

bool SaveToJson(const std::string& path, std::vector<Monster>& monsters)
{
	StringBuffer sb;
	PrettyWriter<StringBuffer> writer(sb);

	writer.StartObject();
	writer.Key("monsters");
	writer.StartArray();
	for (auto monster : monsters)
	{
		writer.StartObject();
		{
			writer.Key("name"); writer.String(monster.GetName().c_str());

			writer.Key("status");
			writer.StartObject();
			{
				auto status = monster.GetStatus();
				writer.Key("level"); writer.Int(status.mLevel);
				writer.Key("hp"); writer.Int(status.mHP);
				writer.Key("mp"); writer.Int(status.mMP);
			}
			writer.EndObject();

			writer.Key("items");
			writer.StartArray();
			for (auto item : monster.GetDropItems())
			{
				writer.StartObject();
				writer.Key("name"); writer.String(item.mName.c_str());
				writer.Key("gold"); writer.Int(item.mGold);
				writer.EndObject();
			}
			writer.EndArray();
		}
		writer.EndObject();
	}
	writer.EndArray();
	writer.EndObject();

	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	try
	{
		ofs.open(path);
		ofs << sb.GetString();
		ofs.close();
	}
	catch (std::ofstream::failure& e)
	{
		std::cerr << "invalid operation in SaveToJson()" << std::endl;
		std::cerr << e.what() << std::endl;
		ofs.close();
		return false;
	}

	return true;
}

bool LoadFromJson(const std::string& path, std::vector<Monster>& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	std::stringstream ss;

	try
	{
		ifs.open(path);

		ss << ifs.rdbuf();

		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << "invalid operation in LoadFromJson()" << std::endl;
		std::cerr << e.what() << std::endl;
		ifs.close();
		return false;
	}

	Document d;
	d.Parse(ss.str().c_str());
	for (auto& monObject : d["monsters"].GetArray())
	{
		Monster monster;

		monster.SetName(monObject["name"].GetString());

		Status status;

		status.mLevel = monObject["status"].GetObject()["level"].GetInt();
		status.mHP = monObject["status"].GetObject()["hp"].GetInt();
		status.mMP = monObject["status"].GetObject()["mp"].GetInt();
		monster.SetStatus(status);

		for (auto& itemObject : monObject["items"].GetArray())
		{
			Item item;
			item.mName = itemObject["name"].GetString();
			item.mGold = itemObject["gold"].GetInt();
			monster.AddDropItem(item);
		}

		monsters.push_back(monster);
	}

	return true;
}

int main()
{
	std::vector<Monster> monsters;

	Monster m;
	m.SetName("ΩΩ∂Û¿”");
	m.SetStatus({ 1,1,1 });
	m.AddDropItem({ "≤ˆ¿˚«— ¡©∏Æ", 1 });
	monsters.push_back(m);

	m.GetDropItems().clear();
	m.SetName("¥¡¥Î¿Œ∞£");
	m.SetStatus({ 5,5,5 });
	m.AddDropItem({ "πﬂ≈È", 2 });
	m.AddDropItem({ "¥¡¥Î ∞°¡◊", 5 });
	monsters.push_back(m);

	m.GetDropItems().clear();
	m.SetName("æ«∏∂");
	m.SetStatus({ 10,10,10 });
	m.AddDropItem({ "≥Ø∞≥", 10 });
	m.AddDropItem({ "º’≈È", 5 });
	monsters.push_back(m);

	SaveToJson("Data/monsters.json", monsters);

	monsters.clear();
	LoadFromJson("Data/monsters.json", monsters);
}