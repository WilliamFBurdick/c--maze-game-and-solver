#ifndef SCREEN_H
#define SCREEN_H

class Screen {
    protected:
        char* m_pixels;
        int m_width;
        int m_height;
    public:
        Screen(int width, int height);
        void Draw(char _char, int x, int y);
        void Display();
        char GetPixel(int x, int y);
};

#endif