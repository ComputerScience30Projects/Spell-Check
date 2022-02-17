#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

void binarySearch(std::vector<std::string> &dictionary, std::string &query)
{
    /*Lowercase Query*/
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);

    /*Binary Search for the Query*/
    size_t minIndex = 0;
    size_t maxIndex = dictionary.size();
    size_t midIndex;

    while (minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex) / 2;

        if (query == dictionary[midIndex]) //Check if query equals middle element
        {
            /*Word was located*/
            std::cout << "Word located in dictionary at " << midIndex << " !" << std::endl;
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

    /*Word was not located*/
    std::cout << "Could not locate word in dictionary!" << std::endl;
}

int main()
{
 

    /*Initilaize dictionary*/
    std::vector<std::string> dictionary;
    size_t wordNum = 0;
    std::string line;
    std::ifstream dictionaryFile("dictionary.txt");

    while (std::getline(dictionaryFile, line))
    {
        dictionary[wordNum++] = line;
    }

    std::cout << "LOADED " << wordNum << " words!"<< std::endl;

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
                break;
 
            /*Spell Check a Word(Binary Search)*/
            case 2:
                std::cout << "Please enter a word: " << std::endl;
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
                std::cout << "ERROR: INVALID SELECTION!" << std::endl;
                break;

            default:
                break;
        }
    }

    return 0;
}