#pragma once

#include <string>

class IHTMLComponent
{
public:
    virtual std::string getHTML(std::size_t p_indentLevel = 0) const = 0;
    virtual ~IHTMLComponent() = default;

protected:
    IHTMLComponent(const std::string& p_tagName)
        : m_tagName{p_tagName}
    {
    }

    std::string m_tagName {};
};
