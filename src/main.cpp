#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string textInput;

    while (true) {
        
        std::string innerText;
        std::cout << "Send me text to save it or send me DLT in order to delete and startover...\n Enter the text...  ";
        std::getline(std::cin, innerText);
        textInput += innerText + '\n';

        if (innerText == "DLT") {
            std::ofstream file("test.csv");

            file.close();
            textInput.clear();

            std::cout << "File cleared.\n";

        } 
        else {
             std::ofstream file("test.csv", std::ios::app);

            if (!file.is_open())
            {
                std::cerr << "Failed to open file\n";
                return 1;
            }

            file << innerText << '\n';

            file.close();
             std::cout << "Text Saved successfully, " << textInput << "!" << std::endl;
        }
       
    }

    return 0;
}