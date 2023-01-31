/*
	Containers are covered in this file

	1. Array : Part of STL Library benefit of using this over C array is that you get
	access to iterator and algo using this over C array.

	eg: std::array<int, 5> arr1 {1,2,3,4,5};  // double curly braces required in C++ 11 but C++ 14 and further only single

	2. Vector : Stored in Contiguous memory, fast to store data at end of vector just like array but adding data somewhere in 
	middle is not that efficient.

	3. Deque:Deque is double ended queue (expansion and contraction can happen both end). It has Dynamic size, handled
	automatically, elems not stored in contiguous memory. Direct elem access is const time, rapid insertion and deletion
	at front and back (const time). Insertion or removal of elements is linear time.

	4. List: List is bi directional (similar to doubly linked list). So rapid insertion and deletion of elems anywhere in list.

	5. Forward list : Singly linked list. only forward direction. no concept of back.

	6. Set, Map, Set, Queue, Priority Queue still needs to be look into
*/

#include "6Stl.h"
#include "player.h"

#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

/* START: Local functions to display */
static void display2(const std::vector<int>& vec)
{
	std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << " "; });
	std::cout << std::endl;
}

template <typename t>
static void display(const std::vector<t>& vec)
{
	
	for (const auto& elem : vec)
	{
		std::cout << elem << " ";
	}

	std::cout << std::endl;
}

/* END: Local functions to display */

void testArray(void)
{
	std::array<int, 5> arr{ 2,2,1,6,5 };

	std::array<std::string, 5> str{
		std::string("arjun"),
		"joii",     // this will be converted to std::string itself because we storing in std array.
		std::string("karan"),
		std::string("mini mom")
	};

	// some of common methods

	std::cout << "size is " << arr.size() << std::endl;
	std::cout << "element at 0th and 1st place " << arr.at(0) << " " << arr[1] << std::endl;
	std::cout << "elem at front and back are : " << arr.front() << " " << arr.back() << std::endl;

	// data returns address of first element of array
	int* ptr = arr.data();
	std::cout << *ptr++ << " " << * ptr << std::endl; // print 1st and 2nd elem in array
	
	//sort
	std::sort(arr.begin(), arr.end());
	// now display arr to see sorted array

	// min and max element , need to use iterator data type as we are using algo here or just use auto
	std::array<int, 5>::iterator min_num = std::min_element(arr.begin(), arr.end());
	auto max_num = std::max_element(arr.begin(), arr.end());

	std::cout << "min and max numbers are " << *min_num << " " << *max_num << std::endl;

	// adjacent_find to find to values adjacent to each other eg 2 ,3 

	// accumulate to add all elems of an array, eg accumulate(arr.begin(), arr.end(), 0); // 0 is added to total as well,
	// include <numeric> for this to work
}


void testVector(void)
{
	std::vector<int> vec{ 1,2,3,4,5 };
	display2(vec);

	vec = { 5,6,7,8 };
	display2(vec);

	std::vector<int> vec1(10, 100); // to create a vector of 10 100s in it
	display2(vec1);


	// vectors have a max size and capacity associated with them.
	// where max size is total storage size possible and also capacity is current storage capacity.
	// if we try to go above current storage capacity then it will increase automatically by some numbers 
	// and stay that much until we dont go over that capacity limit again.  we cant go over max storage size.

	std::cout << "vector size, max size and current capacity are " << vec.size() << " " << vec.max_size()
		<< " " << vec.capacity() << std::endl;

	//  here .at is better as it does boundry checking.
	vec[0] = 10;
	vec.at(1) = 100;

	vec.push_back(13); // to add new element at end.

	// we can use emplace_back for classes then we can just provide constructor values without name of class

	std::vector<Player> person = {
		{"Arjun", 30},
		{"Joii", 31}
	};

	person.push_back(Player("mom", 50));
	person.emplace_back("Karan", 25);
	display(person);

	//there is erase algo as well example
	// vec.erase(vec.begin(), vec.begin()+2); 
	// vec1.swap(vec);

	std::vector<int> vec3{ 1,2,3,4,5 };
	std::vector<int> vec4{ 10,20,30 };

	// params are start and end of vec that needs to be added, 3rd param where to add and last is condition need to pass to add
	std::copy_if(vec3.begin(), vec3.end(), std::back_inserter(vec4), [](int x) {return 1; });
	display(vec4);

	// inserting a vec inside another vec at nth location

	vec3 = { 1,2,3,4,5 };
	vec4 = { 10,20,30 };

	display(vec3);
	display(vec4);
	// find first location of 3 in vec3
	auto it = std::find(vec3.begin(), vec3.end(), 3);

	if (it != vec.end())
	{
		vec3.insert(it, vec4.begin(), vec4.end());
	}

	display(vec3);
	display(vec4);
}

/* Double ended queue

quite similar to vector with an additional feature that what all we  can do at back of a vector can be done at front of 
a deque too. same Algos available with add ons of push_front, emplace_front, pop_front and more. so front is added along
with back in deque compared to Vector.
*/
void testDeque(void)
{

}

/* good when there is lot of insertion and removal but direct access is not needed because no quick lookup like 
vectors is present */
void testList(void)
{
	std::list<int> listData{ 1,2,3,4,5 };

}