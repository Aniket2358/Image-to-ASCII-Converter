#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include<iostream>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

// Call this function to shrink and push your ascii Image into the text file
void push_shrunken_ascii_image
(
    vector<char>&ascii_image, 
    vector<char>&shrunken_ascii_image ,
    int width ,
    int height ,
    int desierd_width
){

    int new_width  =  desierd_width;
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

    ofstream output("ASCII_image.txt");
    for(int i = 0; i < new_height ;  i++){
        for(int j = 0 ; j < new_width ; j++){
            int index = i*new_width + j ;
              output << shrunken_ascii_image[index];
        }
          output << '\n';
    }
    output.close();
}

/*Call this function to push the full ascii image into the text file| I will not recommend calling this funtion
if the image is larger than 700x700 pixles, as the output may not be clearly visible in a standerd windows text editiot*/
void push_full_ascii_image
(
    vector<char>&ascii_image,
    int width ,
    int height
)
{
  ofstream output("ASCII_image.txt");

   for(int i = 0; i < height ;  i++){
        for(int j = 0 ; j < width ; j++){
            int index = i*width + j ;
              output << ascii_image[index] ;
        }
          output << '\n';
    }

    output.close();
}



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

    //luminensence and ascii char converter| Calcultaes luminensence| Maps the ascii character 
    for(int i = 0; i < width*height*3 ; i = i + 3){
        double lumi = image[i]*0.299
        + image[i+1]*0.587
        + image[i+2]*0.114;
        
        int idx = lumi*(ascii_char.length() -1)/255;
        ascii_image.push_back(ascii_char[idx]);
    }
 
    //push_full_ascii_image(ascii_image , width , height);
    push_shrunken_ascii_image(ascii_image , shrunken_ascii_image , width , height , 1000);

    stbi_image_free(image);
    return 0;
}
