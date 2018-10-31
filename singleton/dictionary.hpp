#pragma once

#include <set>
#include <string>
#include <mutex>

#include "dictionary_item.hpp"

class Dictionary
{
public:
    static Dictionary& getInstance()
    {
        static Dictionary dictionary {};
        return dictionary;
    }

    void insert(const std::string& p_word, const std::string& p_meaning);
    DictionaryItem find(const std::string& p_word) const;
    void listAllWords() const;

    Dictionary(const Dictionary&) = delete;
    Dictionary& operator=(const Dictionary&) = delete;

private:
    Dictionary()
    {
    }

    std::set<DictionaryItem> m_dictionary {};
    std::mutex m_mutex;
};
