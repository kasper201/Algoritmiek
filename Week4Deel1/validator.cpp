//
// Created by Kasper on 29/02/2024.
//

#include "validator.h"
#include <string>

validator::validator() {

}

validator::~validator() {

}

bool validator::validate(Stack &stack, std::string tag) {
    std::string originalTag = tag;
    if(stack.isEmpty()) {
        if(first)
        {
            stack.push(tag);
            first = false;
            return true;
        } else {
            std::cout << "stack is empty" << std::endl;
            return false;
        }
    }
    //find "/" in string
    size_t dash = tag.find("/");
    if(dash != std::string::npos) {
        tag.erase(dash, 1); // remove the '/'
        if (tag == stack.peek()) {
            stack.pop();
            return true;
        } else {
            std::cout << "Invalid XML: " << stack.peek() << " does not match " << originalTag << std::endl;
            return false;
        }
    }

    stack.push(tag); // push the tag to the stack if it's not a closing tag
    return true;
}

bool validator::setXml(Stack &stack, std::string xml) {
    size_t foundOpen = xml.find("<");
    size_t foundClose = xml.find(">", foundOpen);

    while (foundOpen != std::string::npos && foundClose != std::string::npos) { // While there are still '<' and '>' in the string
        if (xml.find("<", foundOpen+1) > foundClose) {
            std::string tag = xml.substr(foundOpen, foundClose - foundOpen + 1);
            if(!validate(stack, tag))
                return false;
        } else {
            std::cout << "Invalid XML: More '<' than '>'" << std::endl;
            return false;
        }

        // Find the next occurrence of '<' and '>'
        foundOpen = xml.find("<", foundClose);
        foundClose = xml.find(">", foundOpen);

        // check if there are more of either '<' or '>' than the other
        if(foundOpen == std::string::npos && foundClose != std::string::npos) {
            std::cout << "Invalid XML: More '>' than '<'" << std::endl;
            return false;
        } else if (foundOpen != std::string::npos && foundClose == std::string::npos) {
            std::cout << "Invalid XML: More '<' than '>'" << std::endl;
            return false;
        }
    }

    return true;
}
