#include <memory>
#include <array>

//Not plain old data (POD)
class Foo 
{
public:
	Foo();
};

//This is plain old data (POD)
struct Foo2
{
	/*
	char y; //adds 1 byte to 4 byte chunk
	char X; //adds 1 byte to 4 byte chunk
	int z; //wants to add 4 bytes to chunk but it cant fit it so it uses another 4 byte chunk (8 bytes have been used)
	*/

	// #pragma pack(push, 1) will guarentee smallest packet size (use this for sending packets)

	//Foo2(); Dont write functions in structs! It will no longer be (POD)
	int m_x; //Now the size is 4 bytes (size of int);
	int m_y; //Now the size is 8 bytes (size of int);
	int m_z; //Now the size is 12 bytes (size of int);

	int* ptr; //ptr will always be 4 bytes, so now the struct is 16 bytes

	void Bar() //This function adds nothing to the structs size
	{

	}

	/*
	V-Table has been added to the struct, size is not predictable/guarenteed anymore. 
	When sending packets we NEED TO KNOW the guarenteed size of the struct. 
	*/
	virtual void Bar2()
	{

	}
};

#pragma pack(push, 1)

struct Foo3
{
	int x;
	int y;
	int z;
};

int main()
{

	Foo3 f;
	f.x = 1;
	f.y = 2;
	f.z = 3;

	std::array<char, sizeof(Foo3)> buffer3;

	char* data = buffer3.data();
	data = (char*)(&f);

	/*
	The object is destroyed and its memory deallocated when either
	of the following happens: unique_ptr managing the object is 
	destroyed. unique_ptr managing the object is assigned another 
	pointer via operator= or reset().
	*/
	std::unique_ptr<int> intPtr = std::make_unique<int>(5);
	std::unique_ptr<int> intPtr2 = std::move(intPtr);

	/*
	The object is destroyed using delete-expression or a 
	custom deleter that is supplied to shared_ptr during construction. 
	A shared_ptr can share ownership of an object while storing a pointer to another object.
	*/
	std::shared_ptr<int> intPtr3 = std::make_shared<int>(5);

	/*
	Can essentially observe a shared ptr. std::weak_ptr is a 
	smart pointer that holds a non - owning("weak") reference to 
	an object that is managed by std::shared_ptr.It must be converted 
	to std::shared_ptr in order to access the referenced object.
	*/
	std::weak_ptr<int> sharedPtr = intPtr3;
	
	//Dont use this!
	char buffer[1024];

	//Never do this!
	sizeof(buffer); //We use this to figure out how many bytes there are.

	//This is just as fast!
	std::array<char, 1024> buffer2;

	//use this if you want the ptr.
	buffer2.data(); 

	return 0;
}