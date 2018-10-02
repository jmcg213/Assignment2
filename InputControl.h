#include <iostream>
#include <string>

using namespace std;

class InputControl
{
    public:
        InputControl();
        ~InputControl();
        string SetInputType();
        void ReadInputFile(); //will error check and return file name
        int GetHeight();  //will error check and return height read in from file
        int GetWidth(); //will error check and return width read in from file
        double GetDensity();
        void CinHeight(); //will error check and return console entered height
        void CinWidth(); //will error check and return console entered width
        void CinDensity(); //will ask for and error check density
        bool CheckBounds(int check); //Error checking for bounds to be used in all methods
        char** CountGrid(string inputFile, char** array);
        string GetFileName();
        int width;
        int height;
        int density;
        double finDensity;
        bool goodGrid;
        string fileName;
};
