#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <math.h>

int binarySearch(std::vector<std::string> &dictionary, std::string &query)
{
    /*Lowercase Query*/
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);

    size_t minIndex = 0;
    size_t maxIndex = dictionary.size() - 1;
    size_t midIndex;

    while (minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex) / 2;

        if (query == dictionary[midIndex]) //Check if query equals middle element
        {
            return midIndex;
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
    return -1;
}

int linearSearch(std::vector<std::string> &dictionary, std::string &query)
{
    /*Lowercase Query*/
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);

    for (size_t i = 0; i < dictionary.size(); i++)
    {
        if (dictionary[i] == query)
        {
            /*Word was located*/
            return i;
        }
    }      

    return -1;
}

int linearSearchWord(std::vector<std::string> &dictionary, std::string &query)
{
    std::cout << "Linear Search starting...\n";    
    
    /*Get Start Time*/
    std::chrono::time_point startTime = std::chrono::high_resolution_clock::now();

    int index = linearSearch(dictionary, query);

    if ( index >= 0) //If index is returned
    {
        /*Get End Time*/
        std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

        /*Calculate Time Duration in Microseconds*/
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        std::cout << query << " is IN the dictionary at position " << index << " (" << duration.count() << " microseconds).\n";
    }
    else //If error is returned
    {
        /*Get End Time*/
        std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

        /*Calculate Time Duration in Microseconds*/
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

        std::cout << query << " is NOT IN the dictionary " << "(" << duration.count() << " microseconds).\n";
    }

    return -1;
}

void binarySearchWord(std::vector<std::string> &dictionary, std::string &query)
{
    std::cout << "Binary Search starting...\n";

    /*Get Start Time*/
    std::chrono::time_point startTime = std::chrono::high_resolution_clock::now();

    int index = binarySearch(dictionary, query);

    if(index >= 0)
    {
        /*Get End Time*/
        std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

        /*Calculate Time Duration in Microseconds*/
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        
        /*Word was located*/
        std::cout << query << " is IN the dictionary at position " << index << " (" << duration.count() << " microseconds).\n";
    }
    else
    {
        /*Get End Time*/
        std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

        /*Calculate Time Duration in Microseconds*/
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        
        /*Word was not located*/
        std::cout << query << " is NOT IN the dictionary " << "(" << duration.count() << " microseconds).\n";
    }
}

void linearSearchFile(std::vector<std::string> &dictionary, std::string &filename)
{
    /*Put File Into Vector of Words*/
    std::vector<std::string> words;

    std::fstream file(filename);
    std::string word;

    /*Checking if File Opened*/
    if (!file)
    {
        std::cout << "\nERROR: Failed to open " + filename + "!\n";
        return;
    }

    while (file >> word)
    {
        /*Lowercase the Word*/
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        /*Remove Unwanted Symbols */
        // size_t pos = 0;
        // for (char c : word)
        // {
        //     if ((c < 'a') || (c > 'z'))
        //     {
        //         word.erase(pos, 1);
        //         pos--;
        //     }
        //     pos++;
        // }

        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); } ), word.end()); // From StackOverFlow couldn't reliably remove symbols from strings using my old method (https://stackoverflow.com/questions/28491954/remove-non-alphabet-characters-from-string-c?lq=1)
        
        if (!word.empty())
        {
            /*Push Word into Words*/
            words.push_back(word);   
        }
    }

    /*Binary Search All Words*/
    size_t mistakeCount = 0;

    std::cout << "Linear Search running...\n";

    /*Get Start Time*/
    std::chrono::time_point startTime = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < words.size(); i++)
    {

        if (linearSearch(dictionary, words[i]) == -1)
        {
            mistakeCount++;
        }
        
        /*Print Percentage To Complete*/
        std::cout << std::floor(((float)i + 1) / (float)words.size() * 100) << "%\n";
    }

    /*Get End Time*/
    std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

    /*Calculate Time Duration in Microseconds*/
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "Number of words not found in dictionary: " << mistakeCount << "/" << words.size() << " (" << duration.count() << " microseconds)\n";
}

void binarySearchFile(std::vector<std::string> &dictionary, std::string &filename)
{
    /*Put File Into Vector of Words*/
    std::vector<std::string> words;

    std::fstream file(filename);
    std::string word;

    /*Checking if File Opened*/
    if (!file)
    {
        std::cout << "\nERROR: Failed to open " + filename + "!\n";
        return;
    }

    while (file >> word)
    {
        /*Lowercase the Word*/
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        /*Remove Unwanted Symbols */
        // size_t pos = 0;
        // for (char c : word)
        // {
        //     if ((c < 'a') || (c > 'z'))
        //     {
        //         word.erase(pos, 1);
        //         pos--;
        //     }
        //     pos++;
        // }

        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); } ), word.end()); // From StackOverFlow couldn't reliably remove symbols from strings using my old method (https://stackoverflow.com/questions/28491954/remove-non-alphabet-characters-from-string-c?lq=1)
        
        if (!word.empty())
        {
            /*Push Word into Words*/
            words.push_back(word);   
        }
    }

    /*Binary Search All Words*/
    size_t mistakeCount = 0;

    std::cout << "Binary Search running...\n";

    /*Get Start Time*/
    std::chrono::time_point startTime = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < words.size(); i++)
    {

        if (binarySearch(dictionary, words[i]) == -1)
        {
            mistakeCount++;
        }
        
        /*Print Percentage To Complete*/
        std::cout << std::floor(((float)i + 1) / (float)words.size() * 100) << "%\n";
    }

    /*Get End Time*/
    std::chrono::time_point endTime = std::chrono::high_resolution_clock::now();

    /*Calculate Time Duration in Microseconds*/
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "Number of words not found in dictionary: " << mistakeCount << "/" << words.size() << " (" << duration.count() << " microseconds)\n";
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
        std::cout << "\nMain Menu \n1: Spell Check a Word (Linear Search) \n2: Spell Check a Word (Binary Search) \n3: Spell Check a File (Linear Search) \n4: Spell Check a File(Binary Search) \n5: Exit \nEnter menu selection (1-5): ";
        std::cin >> choice;

        switch (choice)
        {  
            /*Spell Check a Word(Linear Search)*/
            case 1:
                std::cout << "\nPlease enter a word: ";
                std::cin >> query;
                std::cout << std::endl;
                linearSearchWord(dictionary, query);
                break;
 
            /*Spell Check a Word(Binary Search)*/
            case 2:
                std::cout << "\nPlease enter a word: ";
                std::cin >> query;
                std::cout << std::endl;
                binarySearchWord(dictionary, query);
                break;

            /*Spell Check a File(Linear Search)*/
            case 3:
                std::cout << "\nPlease enter filename (Example: AliceInWonderLand.txt): ";
                std::cin >> query;
                std::cout << std::endl;
                linearSearchFile(dictionary, query);
                break;

            /*Spell Check a File(Binary Search)*/
            case 4:
                std::cout << "\nPlease enter filename (Example: AliceInWonderLand.txt): ";
                std::cin >> query;
                std::cout << std::endl;
                binarySearchFile(dictionary, query);
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