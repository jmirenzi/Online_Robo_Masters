// @file image_browser.cpp
// @author Jack Mirenzi

#include "api/image_browser.hpp"
#include "api/html_writer.hpp"

namespace image_browser {

void AddFullRow(const ImageRow& row, bool first_row){
    bool first_in_row = true;
    for ( image_browser::ScoredImage  img_ : row){
        html_writer::AddImage(std::get<0>(img_),std::get<1>(img_),first_row && first_in_row);
        first_in_row=false;
    }
}

/**
 * @brief Create a Image Browser application, This function should be completely
 * self containded and should take all the necessary actions to create an image
 * web browser application.
 *
 * @param title      The title of the web application.
 * @param stylesheet The CSS style, if any.
 * @param rows       A set of ImageRow, with all the given images to show.
 */
void CreateImageBrowser(const std::string& title, const std::string& stylesheet,const std::vector<ImageRow>& rows){
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();
    bool first_row = true;
    for ( image_browser::ImageRow  row : rows){
        html_writer::OpenRow();
        image_browser::AddFullRow(row,first_row);
        first_row=false;
        html_writer::CloseRow();
    }
    html_writer::CloseBody();
    html_writer::CloseDocument();
}

}