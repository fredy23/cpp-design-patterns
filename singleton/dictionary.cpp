#include <iostream>
#include <algorithm>
#include <string>

#include "dictionary.hpp"
#include "dictionary_item.hpp"

void Dictionary::insert(const std::string& p_word, const std::string& p_meaning)
{
    std::lock_guard<std::mutex> guard {m_mutex};
    m_dictionary.emplace(p_word, p_meaning);
}

DictionaryItem Dictionary::find(const std::string& p_word) const
{
    auto it = std::find_if(m_dictionary.begin(), m_dictionary.end(), [&p_word](const DictionaryItem& p_item)
    {
        return p_item.getWord() == p_word;
    });

    if(it != m_dictionary.end())
    {
        return *it;
    }

    return DictionaryItem();
}

void Dictionary::listAllWords() const
{
    for(const auto& item : m_dictionary)
    {
        std::cout << item.getWord() << " - " << item.getMeaning() << '\n';
    }
}
