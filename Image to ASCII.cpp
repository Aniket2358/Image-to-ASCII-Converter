#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include<iostream>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

int main(){
    int width, height, channels;

    unsigned char* image = stbi_load(
        "photo.jpg",
        &width,
        &height,
        &channels,
        3
    );

    if (image == nullptr) {
    cerr << "Error loading image: " << stbi_failure_reason();
    return 1;
}
  

    vector<char>ascii_image;
    vector<char>shrunken_ascii_image;
    string ascii_char = "@$B8&#*oahkbdp:,. ";

    for(int i = 0; i < width*height*3 ; i = i + 3){
        double lumi = image[i]*0.299
        + image[i+1]*0.587
        + image[i+2]*0.114;
        
        int idx = lumi*(ascii_char.length() -1)/255;
        ascii_image.push_back(ascii_char[idx]);
    }

    int new_width  = 100;
    int new_height = height*new_width/width;

    for (int i = 0; i < new_height; i++)
    {
        for (int j = 0; j < new_width; j++)
        {
            int initial_x = j*width/new_width;
            int initial_y = i*height/new_height;

            int index = initial_y*width + initial_x ;
            shrunken_ascii_image.push_back(ascii_image[index]);
        }
        
    }
    


    ofstream output("ascii_art.txt");

    for(int i = 0; i < new_height ;  i++){
        for(int j = 0 ; j < new_width ; j++){
            int index = i*new_width + j ;
              output << shrunken_ascii_image[index] << " " ;
        }
          output << '\n';
    }

    output.close();
    
    stbi_image_free(image);
    return 0;
}