#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>

int linearSearch(std::vector<std::string> &dictionary, std::string &query)
{
    /*Lowercase Query*/
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);


    std::cout << "Binary Search starting...\n";    
    
    /*Get Start Time*/
    std::chrono::time_point startTime = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < dictionary.size(); i++)
    {
        if (dictionary[i] == query)
        {
            /*Get End Time*/
            std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

            /*Calculate Time Duration in Microseconds*/
            std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

            /*Word was located*/
            std::cout << query << " is IN the dictionary at position " << i << " (" << duration.count() << " microseconds).\n";
            return 0;
        }
    }      

    /*Get End Time*/
    std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

    /*Calculate Time Duration in Microseconds*/
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << query << " is NOT IN the dictionary " << "(" << duration.count() << " microseconds).\n";

    return -1;
}

int binarySearch(std::vector<std::string> &dictionary, std::string &query)
{
    /*Lowercase Query*/
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);

    /*Binary Search for the Query*/
    size_t minIndex = 0;
    size_t maxIndex = dictionary.size();
    size_t midIndex;

    std::cout << "Binary Search starting...\n";

    /*Get Start Time*/
    std::chrono::time_point startTime = std::chrono::high_resolution_clock::now();

    while (minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex) / 2;

        if (query == dictionary[midIndex]) //Check if query equals middle element
        {
            /*Get End Time*/
            std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

            /*Calculate Time Duration in Microseconds*/
            std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
            
            /*Word was located*/
            std::cout << query << " is IN the dictionary at position " << midIndex << " (" << duration.count() << " microseconds).\n";
            return 0;
        }
        else if (query > dictionary[midIndex]) //check if query is greater than the mid element
        {
            minIndex = midIndex + 1;
        }
        else //if it isnt then its less
        {
            maxIndex = midIndex - 1;
        }
    }

    /*Get End Time*/
    std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

    /*Calculate Time Duration in Microseconds*/
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    
    /*Word was not located*/
    std::cout << query << " is NOT IN the dictionary " << "(" << duration.count() << " microseconds).\n";
    return -1;
}

int main()
{
 

    /*Initilaize dictionary*/
    std::vector<std::string> dictionary;
    std::string line;
    std::ifstream dictionaryFile("dictionary.txt");

    while (std::getline(dictionaryFile, line))
    {
        dictionary.push_back(line);
    }

    /*Title*/
    std::cout << "|----- Welcome to Spell Checker -----|\n";

    /*Main Menu Loop*/
    size_t choice;
    std::string query;

    while (choice != 5)
    {
        std::cout << "\nMain Menu \n1: Spell Check a Word (Linear Search) \n2: Spell Check a Word (Binary Search) \n3: Spell Check Alice In Wonderland (Linear Search) \n4: Spell Check Alice In Wonderland (Binary Search) \n5: Exit \nEnter menu selection (1-5): ";
        std::cin >> choice;

        switch (choice)
        {  
            /*Spell Check a Word(Linear Search)*/
            case 1:
                std::cout << "\nPlease enter a word: ";
                std::cin >> query;
                std::cout << std::endl;
                linearSearch(dictionary, query);
                break;
 
            /*Spell Check a Word(Binary Search)*/
            case 2:
                std::cout << "\nPlease enter a word: ";
                std::cin >> query;
                std::cout << std::endl;
                binarySearch(dictionary, query);
                break;

            /*Spell Check Alice In Wonderland(Linear Search)*/
            case 3:
                break;

            /*Spell Check Alice In Wonderland(Binary Search)*/
            case 4:
                break;
            
            /*Exit*/
            case 5:
                break;

            default:
                std::cout << "\nERROR: INVALID SELECTION!\n";
                exit(EXIT_FAILURE);
                break;
        }
    }

    return 0;
}