#pragma once

#include <string>

class Developer
{
public:
	std::string mName;
	int mStartYear;
};

class Programmer : public Developer
{
public:
	void Coding() {};
	void Debugging() {}; 
};

class Designer : public Developer
{
public:
	void Documentation() {};
	void Presentation() {};
};

class ChiefProgramer : public Programmer
{
public:
	void Architecture() {};
	void Scheduling() {};
};