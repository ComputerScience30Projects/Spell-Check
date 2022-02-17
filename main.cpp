#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

int binarySearch(std::vector<std::string> &dictionary, std::string query)
{
    /*Lowercase Query*/
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);

    size_t minIndex = 0;
    size_t maxIndex = dictionary.size();
    size_t midIndex;

    while (minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex) / 2;

        //Check if query equals middle element
        if (query == dictionary[midIndex])
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
}

int main()
{


    
    /*Title*/
    std::cout << "|----- Spell Checker -----|\n";

    /*Main Menu Loop*/
    size_t choice;

    while (choice != 5)
    {
        std::cout << "\nMain Menu \n1: Spell Check a Word (Linear Search) \n2: Spell Check a Word (Binary Search) \n3: Spell Check Alice In Wonderland (Linear Search) \n4: Spell Check Alice In Wonderland (Binary Search) \n5: Exit \nEnter menu selection (1-5): ";
    }
}