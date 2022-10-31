#pragma once
#include<iostream>
class illegalParameterValue
{
private:
	std::string message;
public:
	illegalParameterValue() :
		message("Illegal parameter value") {}
	illegalParameterValue(std::string theMessage) {
		message = theMessage;
	}
	void outputMessage() {
		std::cout << message << "\n";
	}

};