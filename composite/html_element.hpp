#pragma once

#include <string>

#include "ihtml_component.hpp"

class HTMLElement : public IHTMLComponent
{
public:
    HTMLElement(const std::string& p_tagName)
        : IHTMLComponent{p_tagName}
    {
    }

    HTMLElement(const std::string& p_tagName, const std::string& p_innerText)
        : IHTMLComponent{p_tagName}, m_innerText{p_innerText}
    {
    }

    std::string getHTML(std::size_t p_indentLevel = 0) const override
    {
        return std::string(p_indentLevel, ' ') + "<" + m_tagName + ">" + m_innerText + "</" + m_tagName + ">";
    }

private:
    std::string m_innerText {};
};
