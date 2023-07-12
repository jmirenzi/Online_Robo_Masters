// @file html_writer.cpp
// @author Jack Mirenzi

#include <fmt/core.h>

#include "api/html_writer.hpp"


namespace html_writer {

void OpenDocument(){
    fmt::print("<!DOCTYPE html>\n<html>\n");
}


void CloseDocument(){
    fmt::print("</html>\n");
}


void AddCSSStyle(const std::string& stylesheet){
    fmt::print("<head>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"{}\" />\n</head>\n",stylesheet);
}


void AddTitle(const std::string& title){
    fmt::print("<title>{}</title>\n",title);
}


void OpenBody(){
    fmt::print("<body>\n");
}


void CloseBody(){
    fmt::print("</body>\n");
}


void OpenRow(){
    fmt::print("<div class=\"row\">\n");
}


void CloseRow(){
    fmt::print("</div>\n\n");
}

void AddImage(const std::string& img_path, float score, bool highlight){
    if (highlight)
        fmt::print("<div class=\"column\" style=\"border: 5px solid green;\">\n<h2>{0}</h2>\n<img src=\"data/{0}\" />\n<p>score = {1:.2f}</p>\n</div>\n",img_path,score);
    else
        fmt::print("<div class=\"column\">\n<h2>{0}</h2>\n<img src=\"data/{0}\" />\n<p>score = {1:2}</p>\n</div>\n",img_path,score);
}

}  // namespace html_writer