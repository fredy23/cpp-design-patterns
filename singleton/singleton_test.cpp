#include <iostream>

#include "dictionary.hpp"

void insertSomeWords()
{
    Dictionary& dictionary = Dictionary::getInstance();

    dictionary.insert(
        "dog",
        "a common animal with four legs, especially kept " \
        "by people as a pet or to hunt or guard things");

    dictionary.insert(
        "guitar",
        "a musical instrument, usually made of wood, with six " \
        "strings and a long neck, played with the fingers or a plectrum");

    dictionary.insert(
        "orange",
        "a round sweet fruit that has a thick orange skin " \
        "and an orange centre divided into many parts"
    );
}

void findSomeWords()
{
    const Dictionary& dictionary = Dictionary::getInstance();

    std::string wordsList[] =
    {
        "apple",
        "guitar",
        "book",
    };

    for(const auto& word : wordsList)
    {
        std::cout << "Searching for word '" << word << "'...\n";
        auto item = dictionary.find(word);

        if(item)
        {
            std::cout << "Found word '" << word << "'\n";
            std::cout << item.getWord() << " - " << item.getMeaning() << '\n';
        }
        else
        {
            std::cout << "Can't find word '" << word << "'\n";
        }
    }
}

int main()
{
    insertSomeWords();
    findSomeWords();

    const Dictionary& dictionary = Dictionary::getInstance();

    std::cout << "\nList of all words in dictionary:\n";

    dictionary.listAllWords();
}
