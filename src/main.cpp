#include <iostream>
#include <string>
#include <fstream>
#include "Time.h"

int main()
{
    Time t1(0, 0, 0);

    while (true)
    {
        std::string innerText;

        std::cout << "Enter Seconds or DLT to reset): ";
        std::getline(std::cin, innerText);

        if (innerText == "DLT")
        {
            std::ofstream file("test.csv");
            file.close();

            t1 = Time(0, 0, 0);

            std::cout << "File cleared.\n";
            continue;
        }

        // try to add seconds
        int seconds = 0;

        try
        {
            seconds = std::stoi(innerText);
        }
        catch (...)
        {
            std::cout << "Invalid number!\n";
            continue;
        }

        // do the calculations
        t1 = t1 + seconds;

        // save result into file
        std::ofstream file("test.csv", std::ios::app);

        if (!file.is_open())
        {
            std::cerr << "Failed to open file\n";
            return 1;
        }

        file << t1 << "," << seconds << '\n';

        file.close();

        std::cout << "Saved: " << t1 << " (+"
                  << seconds << "s)" << std::endl;
    }

    return 0;
}