#include"Matrix.h"
#include "Image.h"
#include"processing.h"
#include<iostream>
#include<string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    //Argument number should be correct
    if (argc != 4 && argc != 5) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
            << "WIDTH and HEIGHT must be less than or equal to original"
            << endl;
        return 1;
    }

    //Argument number is correct,open file
    ifstream ins;
    string filename_in = argv[1];
    string filename_out = argv[2];
    int new_width = atoi(argv[3]);
   
    


    ins.open(filename_in);
    //if not open
    if (!ins.is_open()) {
        cout << "Error opening file: " << filename_in << endl;
        return 1;
    }


    Image* img = new Image;
    Image_init(img, ins);
    ins.close();
    
    
    if (new_width <= 0 || new_width > Image_width(img)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
            << "WIDTH and HEIGHT must be less than or equal to original"
            << endl;
        return 1;
    }

    //height is inputted
    if (argc == 5) {
        int new_height = atoi(argv[4]);
        if (new_height <= 0 || new_height > Image_height(img)) {
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]"
                << "\n"
                << "WIDTH and HEIGHT must be less than or equal to original"
                << endl;
            return 1;
        }

        else {
            seam_carve(img, new_width, new_height);
        }
    }

    else {
        seam_carve_width(img, new_width);
    }


    ofstream outs;
    outs.open(filename_out);
    Image_print(img, outs);

    delete img;

    return 0;

}
