#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
	if(argc < 2) {
		std::cout<<"Please enter a valid integer"<<std::endl;
		return (-1);
	}
	std::stringstream str(argv[1]);
	int inputNumber;
	str >> inputNumber;
	if(str.fail()) {
		std::cout<<"Failed to parse entered number"<<std::endl;
	}

	//std::cout<<"You just entered:"<<inputNumber<<std::endl;
	if(inputNumber & 1) {
		std::cout<<"Number "<<inputNumber<<" is a ODD number"<<std::endl;
	}else {
		std::cout<<"Number "<<inputNumber<<" is an EVEN number"<<std::endl;
	}
	
	return 0;
}
