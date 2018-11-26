#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <memory>

#include "ihtml_component.hpp"

using ElementPtr = std::unique_ptr<IHTMLComponent>;

class HTMLBlock : public IHTMLComponent
{
public:
    HTMLBlock(const std::string& p_tagName)
        : IHTMLComponent{p_tagName}
    {
    }

    std::string getHTML(std::size_t p_indentLevel = 0) const override
    {
        std::string indent(p_indentLevel, ' ');

        std::ostringstream result {};
        result << indent << "<" + m_tagName + ">\n";

        for(const auto& child : m_children)
        {
            result << child->getHTML(p_indentLevel + 1) << '\n';
        }

        result << indent << "</" + m_tagName + ">";

        return result.str();
    }

    void addChild(ElementPtr&& p_element)
    {
        m_children.emplace_back(std::move(p_element));
    }

private:
    std::vector<ElementPtr> m_children {};
};
