#include "Screen.h"
#include <iostream>

using namespace std;

Screen::Screen(int width, int height)
{
    m_pixels = new char[width * height];
    m_width = width;
    m_height = height;
}

void Screen::Draw(char _char, int x, int y)
{
    int index = (y * m_width) + (x % m_width);
    m_pixels[index] = _char;
    return;
}

void Screen::Display()
{
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            int index = (i * m_width) + (j % m_width);
            cout<<m_pixels[index];
        }
        cout<<"\n";
    }
    return;
}

char Screen::GetPixel(int x, int y)
{
    if (x > m_width || y > m_height)
    {
        throw "ERROR: Out of bounds!";
    }
    int index = (y * m_width) + (x % m_width);
    return m_pixels[index];
}