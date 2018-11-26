#include <iostream>
#include <vector>
#include <memory>

#include "ihtml_component.hpp"
#include "html_element.hpp"
#include "html_block.hpp"

int main()
{
    auto header = std::make_unique<HTMLElement>("h1", "Section header");
    auto firstParagraph = std::make_unique<HTMLElement>(
        "p",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. " \
        "Proin nibh augue, suscipit a, scelerisque sed, lacinia in, mi.");

    auto secondParagraph = std::make_unique<HTMLElement>(
        "p",
        "Donec venenatis, turpis vel hendrerit interdum, " \
        "dui ligula ultricies purus, sed posuere libero dui id orci.");

    std::cout << "First paragraph HTML code: \n";
    std::cout << firstParagraph->getHTML() << '\n';

    auto section = std::make_unique<HTMLBlock>("section");
    section->addChild(std::move(header));
    section->addChild(std::move(firstParagraph));
    section->addChild(std::move(secondParagraph));

    std::cout << "\nSection HTML code: \n";
    std::cout << section->getHTML() << '\n';

    HTMLBlock body {"body"};
    body.addChild(std::move(section));

    std::cout << "\nBody HTML code: \n";
    std::cout << body.getHTML() << '\n';
}
