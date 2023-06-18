// hello

#include <iostream>		// import I/O Stream utilities
#include <string>		// import String utilietes (idk why is needed)

int main ()			// the program starts here							
	{				// the content of int main starts here
	std::cout << "Hello, What's your name? " ;		// print the message in the "" on the terminal
	std::string name ;		// some space in needed in memory for a string variable object called "name"
	std::cin >> name ;		// read the string called "name" from the terminal into that space
	std::cout << '\n' ;		// start a new line (after an imput it already does this so in this case we have a blank line)
	std::cout << "Nice to meet you, " << name << ", I'm you from the future." << '\n' <<'\n' ;		// print a multi-part message and leave a blank line
	std::cout << "Be aware... The best things are hidden in the dark, " << '\n' << "and you can find them only with the help of light..." << '\n' <<'\n' ; 
	}				// the content of the int main ends here
