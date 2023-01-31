/*
	STL are made of 
	1. Containers (for storage, eg array, vector, stack)
	2. Algorithms (for processiing, eg max, count, sort, accumulate)
	3. Iterators (similar to ptr for generating sequence of elements
	from Containers eg, forward, reverse).

	Types of Container:

	1. Sequence (array, vector, list, forward_list, deque)
	2. Associative (set, multi set, map, multi map)
	3. Adapter(Stack, Queue, Priority queue)


*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>

#include "player.h"
#include "5Stl.h"

#define NEXT_LINE std::cout << std::endl;
void testFunctionTemplate(void)
{
	int a = 10;
	int b = 29;
	
	// its better to give int in next line which telles compiler
	// data type is int
	int val = greaterNumber<int>(a, b);
	
	printTwoNumbers<int, float>(1, 3.15f);
}

void testClassTemplate(void)
{
	item <std::string, int>itemObj{ "arjun", 30 };
	std::cout << itemObj.get_name() << " ";
	std::cout << itemObj.get_value()<< "\r\n";

	item <int, std::string>itemObj1{ 31, "joti" };
	std::cout << itemObj1.get_name() << " ";
	std::cout << itemObj1.get_value() << "\r\n";

	// here first param we added in template as object itself.
	item <item<std::string, int>, std::string> splObj{ {"Arjun", 30}, "Prof" };
	std::cout << "This is from special object " << splObj.get_name().get_name()
		<< " " << splObj.get_name().get_value() << " " << splObj.get_value() << "\r\n";
	
	// vector of item class
	std::vector<item <std::string, int>> vecItem;

	vecItem.push_back(item<std::string, int> {"arjun", 30});
	vecItem.push_back(item<std::string, int> {"Joii.Joe", 31});
	vecItem.push_back(item<std::string, int> {"Supreet mom kalsi", 50});
	
	for (const auto v : vecItem)
	{
		static int i = 0;
		std::cout << "Item no. " << i << " name is ";
		std::cout << v.get_name() << "\r\n";

		i++;
	}
}

// not used just defined for learning purpose
void testStructTemplate(void)
{
	myPair <float, int>pair1{ 13.0f, 10 };
	myPair <int, std::string>pair2{ 1, "hello world\r\n" };

	std::vector<myPair<int, std::string>> myPairVec;
}

void testArrayTemplate(void)
{
	const int numOfElements = 5;
	arra <int,numOfElements>arr{ 0 };
	std::cout << "array size is " << arr.getSize() << std::endl;
	std::cout << arr << std::endl;

	for (auto i = 0; i < numOfElements; i++)
	{
		arr[i] = i;
	}
	std::cout << arr << std::endl;
}

void testIterator(void)
{
	// Vector is a template class in STL of CPP
	std::vector<int> vec{ 1,2,3,4,5 };

	//std::vector<int>::iterator it = vec.begin();
	//above line is how an iterator is created but with
	// help of auto it becomes much easier
	auto it = vec.begin();

	// we use & as otherwise it will copy which is less efficient
	while(it != vec.end())
	{
		std::cout << *it << " ";
		it++;
	}

	NEXT_LINE;
	std::vector<int>::reverse_iterator rIt = vec.rbegin();
	while (rIt != vec.rend())
	{
		std::cout << *rIt << " ";
		rIt++;
	}
	NEXT_LINE;
}

/*
* Set cant have duplicate items so while printing it will skip
* those and also 
*/
void testIteratorSet(void)
{
	std::set<char> suits{ 'a', 'r', 'a', 'j', 'u', 'n'};

	auto it = suits.begin();
	while (it != suits.end())
	{
		std::cout << *it++ << " ";
	}
	std::cout << std::endl;
}

void testIterators1(void)
{
	std::vector<int> vec{ 1,2,3,4,5 };

	std::vector<int>::const_iterator it = vec.begin();
	//or other way is 
	//auto it = vec.cbegin();

	while (it != vec.end())
	{
		std::cout << *it++ << " ";
	}
	NEXT_LINE;
}

/*
List in STL is equivalent to C programming doubly linked list
Forward list in STL is C programming single singly linked  list
*/
void testIteratorList(void)
{
	// const reverse iterator over a list 
	std::list<std::string> nameList{ "Arjun", "joti", "zora", "supreet" };

	auto it = nameList.crbegin();

	while (it != nameList.crend())
	{
		std::cout << *it << " ";
		it++;
	}
	NEXT_LINE;
}

/*
* Map is one of the associative container which means it 
* has key and value pair
*/
void testIteratorMap(void)
{
	std::map<std::string, std::string> speciality{
		{"arjun", "coding"},
		{"Joti",  "tang karna"},
		{"Momma", "cooking"}
	};
		
	auto it = speciality.cbegin();
	while (it != speciality.cend())
	{
		std::cout << "key and value are : " << it->first << " " << it->second << std::endl;
		it++;
	}

	std::cout << std::endl;
}

/*	Algorithms
*/

void testAlgoFind(void)
{
	std::vector<int> data{ 1,2,3,4,5 };
	auto loc = std::find(data.begin(), data.end(), 6);

	if (loc == data.end()) {
		std::cout << "Data not found " << std::endl;
	}
	else {
		std::cout << "Data found " << *loc << std::endl;
	}

	std::list<Player> person{
		{"Arjun", 30},
		{"Joti", 31},
		{"Karan", 25}
	};

	// find Joti in list
	auto p = std::find(person.begin(), person.end(), Player("Joti", 31));
	if (p == person.end())
	{
		std::cout << "Person not found" << std::endl;
	}
	else {
		std::cout << "Person found" << std::endl;
	}
}

// algo count is similar to find

/* count_if*/
void testAlgoCountIf(void)
{
	std::list<Player> person = {
		{"arjun", 30},
		{"Joii", 31},
		{"Karan", 25}
	};

	// here we are using lambda expression
	int num = std::count_if(person.begin(), person.end(), 
							[](Player& p) { if (p.health >= 30)return 1; return 0; });
	cout << "People with age equal or over 30 are " << num << std::endl;
}

/* replace 
usage as replace (vec.begin(), vec.end(), 1, 100); 

this will replace all 1s with 100s in a container.
*/

/* all_of
* 
*  all_of(vec.begin(), vec.end(), here lambda function);
* 
* if true for all then return 1 otherwise 0

same way there is any_of
*/

void testAlgoTransform(void)
{
	std::string str { "this is in lower case originally" };
	std::cout << str << std::endl;

	// params are input first, input last, output first, and unary operation
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	
	std::cout << str << std::endl;
}