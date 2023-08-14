#pragma once

#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

void ArrayEx()
{
	std::array<int, 4> myArray{ 1,2,3,4 };

	for (const auto& e : myArray)
	{
		std::cout << e << ' ';
	}
	std::cout << std::endl;

	for (std::array<int, 4>::iterator itr = myArray.begin(); itr != myArray.end(); ++itr)
	{
		std::cout << *itr << ' ';
	}

	std::cout << std::endl;

	for (int i = 0; i < myArray.size(); i++)
	{
		std::cout << myArray[i] << " ";
	}

	std::cout << std::endl;

	std::sort(myArray.begin(), myArray.end());
	std::cout << *std::min_element(myArray.begin(), myArray.end()) << std::endl;
}

void VectorEx()
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.pop_back();
	v.resize(100);

	std::sort(v.begin(), v.end());
}

void ForwardListEx()
{
	std::forward_list<int> list{ 10, 11, 1,2 };

	list.push_front(1);
	list.pop_front();

	// sequential access
	// std::cout << list[0] << std::endl;

	// std::sort(list.being(), list.end());
	list.sort();

	for (const auto& e : list)
	{
		std::cout << e << ' ';
	}

	std::cout << std::endl;
}

void ListEx()
{
	std::list<int> list{ 10, 11, 1, 2 };

	list.push_front(1);
	list.push_back(100);
	list.pop_front();
	list.pop_back();

	list.sort();

	for (const auto& e : list)
	{
		std::cout << e << ' ';
	}

	std::cout << std::endl;
}

void DequeEx()
{
	std::deque<int> deq{ 3, 4, 5 };

	deq.push_front(1);
	deq.push_back(6);

	deq.pop_front();
	deq.pop_back();

	std::sort(deq.begin(), deq.end());

	for (const auto& e : deq)
	{
		std::cout << e << ' ';
	}

	std::cout << std::endl;
}

void StackAndQueue()
{
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	std::stack<int> temp(s);
	while (!temp.empty())
	{
		std::cout << temp.top() << std::endl;
		temp.pop();
	}

	// 배열 첨자 X
	// range-based loop X
	// std::stack<int>::iterator X

	std::queue<int> q;
	
	q.push(1);
	q.push(2);
	q.push(3);

	std::queue<int> temp2(q);

	while (!temp2.empty())
	{
		std::cout << temp2.front() << ' ';
		temp2.pop();
	}

	std::cout << std::endl;

	std::priority_queue<int> pq;

	pq.push(3);
	pq.push(6);
	pq.push(1);

	std::priority_queue<int> temp3(pq);
	while (!temp3.empty())
	{
		std::cout << temp3.top() << ' ';
		temp3.pop();
	}

	std::cout << std::endl;

	struct App
	{
		int priority;
		std::string name;

		bool operator < (const App& app) const
		{
			return this->priority < app.priority;
		}
	};

	std::priority_queue<App> appQueue;
	appQueue.push({ 1, "notepad" });
	appQueue.push({ 5, "vscode" });
	appQueue.push({ 3, "calendar" });

	std::cout << appQueue.top().name << std::endl;
	
}

void SetEx()
{
	std::set<int> s;

	s.insert(1);
	s.insert(6);
	s.insert(2);
	s.insert(5);

	s.insert(1);

	for (auto e : s)
	{
		std::cout << e << std::endl;
	}

	std::unordered_set<int> us;

	us.insert(1);
	us.insert(6);
	us.insert(2);
	us.insert(5);

	for (auto e : us)
	{
		std::cout << e << std::endl;
	}
}

void MapEx()
{
	std::map<std::string, std::string> operators;

	operators.insert({ "+", "더하기연산자이면서 이항연산자입니다." });
	operators.insert({ ">>", "비트 시프트 연산자입니다." });
	operators.insert({ "new", "동적 메모리 할당 연산자입니다. delete 주의하세요." });

	std::cout << operators["+"] << std::endl;
}

void Ex1()
{
	/*ArrayEx();
	VectorEx();
	ForwardListEx();
	ListEx();
	DequeEx();*/
	//StackAndQueue();
	//SetEx();
	MapEx();
}