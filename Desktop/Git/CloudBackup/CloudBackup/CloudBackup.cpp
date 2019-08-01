#include<iostream>
#include<boost/filesystem.hpp>

int main()
{
	boost::filesystem::path path("./abc/bc.txt");
	std::cout << path.extension().string() << std::endl;
	getchar();
	return 0;
}