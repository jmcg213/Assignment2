#include <iostream>
#include <fstream>
#include <string>
#include "InputControl.h"
#include <fstream>

using namespace std;

InputControl::InputControl()  //constructor
{
    height = 0;
    width = 0;
    density = 0;
    finDensity = 0;
    goodGrid = true;
    fileName = '\0';
}

InputControl::~InputControl() //destructor
{

}

string InputControl::SetInputType()
{
    string input;
    while(true)
    {
        cout<<"Would you like to input a 'file' or input through the 'console'?"<<endl;
        cin>>input;
        if(input == "file")
        {
            ReadInputFile();
            break;
        }
        else if(input == "console")
        {
            CinWidth();
            CinHeight();
            CinDensity();

            input = '\0';
            break;
        }
        else
        {
            cout<<"Sorry, seems like you entered and invalid response. Try again."<<endl;
        }
    }
    return input;
}

void InputControl::ReadInputFile()
{
    string inputFile;
    while(true)
    {
        cout<<"Enter input file name: "<<endl;
        cin>>inputFile;
        ifstream file(inputFile);
        string line;
        getline(file, line);           //gets the height as it's the first input
        height = atoi(line.c_str());
        getline(file,line);             //gets the width as it's second input
        width = atoi(line.c_str());
        if(file.fail())                //checks to make sure file is valid
        {
            cout<<"Invalid File! Please try again."<<endl;
        }
        else if(CheckBounds(height) == false || CheckBounds(width) == false)
        {
            cout<<"Invalid height or width. Please enter another file."<<endl;
        }
        else
        {
            break;
        }
    }
    fileName = inputFile;
}


char** InputControl::CountGrid(string inputFile, char** array)
{
    ifstream file(inputFile);
    string line;
    int i = 0;
    while(getline(file, line))
    {
      int count = 0;
      if(i == 0 || i == 1)
      {
      }
      else
      {
        for(char curChar : line)
        {
          array[i-2][count] = curChar;
          count++;
        }
      }
      i++;
    }
    return array;
}


bool InputControl::CheckBounds(int check)
{
    if(check < 3)
    {
        cout<<"Your value can not be less than 3. Please try another value."<<endl;
        return false;
    }
    if(check > 1000)
    {
        cout<<"Your value can not be larger than 1,000. Please try another value."<<endl;
        return false;
    }
    else
    {
        return true;
    }
}

void InputControl::CinWidth()
{
    int tempWidth = 0;
    string holdInt;
    while(true)
    {
        cout<<"What would you like the width of your game board to be?: "<<endl;
        cin>>holdInt;
        tempWidth = atoi(holdInt.c_str());
        if(tempWidth < 3)
        {
            cout<<"Width cannot be less than 3. Please enter another value!"<<endl;
            continue;
        }
        if(tempWidth > 1000)
        {
            cout<<"Width cannot be greater than 1000. Please enter another value!"<<endl;
            continue;
        }
        else
        {
            break;
        }
    }
    width = tempWidth;
}

void InputControl::CinHeight()
{
    int tempHeight = 0;
    string holdInt;
    while(true)
    {
        cout<<"What would you like the height of your game board to be?: "<<endl;
        cin>>holdInt;
        tempHeight = atoi(holdInt.c_str());
        if(tempHeight < 3)
        {
            cout<<"Width cannot be less than 3. Please enter another value!"<<endl;
            continue;
        }
        if(tempHeight > 1000)
        {
            cout<<"Width cannot be greater than 1000. Please enter another value!"<<endl;
            continue;
        }
        else
        {
            break;
        }
    }
    height = tempHeight;
}

void InputControl::CinDensity()
{
    string holdInt;
    while(true)
    {
        cout<<"Enter in the density for your your grid (1-100): "<<endl;
        cin>>holdInt;
        density = atoi(holdInt.c_str());
        if(density < 1 || density > 100)
        {
            cout<<"Invalid density. Must be between 1-100. Try again"<<endl;
            continue;
        }
        else
        {
            break;
        }
    }
    finDensity = density;
}

int InputControl::GetWidth()
{
    return width;
}

int InputControl::GetHeight()
{
    return height;
}

double InputControl::GetDensity()
{
  return finDensity;
}

string InputControl::GetFileName()
{
  return fileName;
}
