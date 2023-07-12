// @file    main.cpp
// @author  Jack Mirenzi

#include "html_api.hpp"

int main(){

    std::vector<image_browser::ImageRow> images;
    for (int i=0; i<3;i++){
        image_browser::ImageRow row_;
        for (int j=0; j<3;j++){
            row_[j] = std::make_tuple("000"+std::to_string(i*3+j)+"00.png",(i*3.0+j+90.0)/100.0);
        }
        images.emplace_back(row_);
    }

    image_browser::CreateImageBrowser("Test_Page","style.css",images);

    return 0;
}