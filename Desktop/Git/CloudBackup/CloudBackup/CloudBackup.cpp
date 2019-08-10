<<<<<<< HEAD
#include"CloudClient.hpp"

int main()
{
	CloudClient client;
	client.Start();
=======
#include<iostream>
#include<boost/filesystem.hpp>

int main()
{
	boost::filesystem::path path("./abc/bc.txt");
	std::cout << path.extension().string() << std::endl;
	getchar();
>>>>>>> 26577221168df6daa9d1c137d1204b1cb59e4d62
	return 0;
}