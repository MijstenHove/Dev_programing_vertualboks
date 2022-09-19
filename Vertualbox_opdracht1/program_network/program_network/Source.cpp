#include <iostream>
#include <fstream>
#include <string>

int main() 
{
	std::ofstream outFile("mijs.tenhove" , std::ios::app);

	if (!outFile.is_open()) {
		std::cout << "thare is a error opening the file";

		return 1;
	}
	for (int i = 0; i < 5; i++) {
		outFile << "hola!";

		outFile.flush();
		outFile.close();
	}
	return 0;
}