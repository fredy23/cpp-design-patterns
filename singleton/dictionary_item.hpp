#pragma once

#include <string>

class DictionaryItem
{
public:
    DictionaryItem() = default;
    DictionaryItem(const std::string& p_word, const std::string& p_meaning)
        : m_word{p_word}, m_meaning{p_meaning}
    {
    }

    std::string getWord() const
    {
        return m_word;
    }

    std::string getMeaning() const
    {
        return m_meaning;
    }

    bool operator<(const DictionaryItem& p_other) const
    {
        return m_word < p_other.m_word;
    }

    operator bool() const
    {
        return !m_word.empty();
    }

private:
    std::string m_word {};
    std::string m_meaning {};
};
