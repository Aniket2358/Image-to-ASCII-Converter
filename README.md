  A Simple Image to ASCII converter built from scratch using C++. 
  
  It uses the stb_image.h library to access the image pixel's RGB values, computes the luminescence value for each pixel and maps it to the   appropriate ASCII characters.
  It converts the entire image pixel by pixel into ASCII form, so if you  want to output the whole converted image you can just call the      push_full_ascii_image() function, it write the whole ASCII image into the ASCII_image.txt file.
  If you want to shrink the image dimensions You can mention the appropriate width of your desired image size in pixels, and call the         push_shrunken_ascii_image() function.
