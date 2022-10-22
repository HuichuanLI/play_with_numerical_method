#include <iostream>

using color = char;  //����һ����ʾ��ɫ��color���ͣ�ÿ���ַ�����һ����ɫ
color *framebuffer{nullptr};          //֡������
int framebuffer_width, framebuffer_height;
color clear_color{' '};                //������ɫ

#if 1

#include "ChGL.h"

#else
bool initWindow(int width, int height);  //��ʼ��һ�����ڣ�����boolֵ��ʾ�ɹ�����ʧ��
void clearWindow();               //��մ�������
void destoryWindow();             //���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
void show();                      //��ʾ֡��������ͼ��
void setPixel(const int x, const int y, color c = ' ');            //�������ص���ɫ
color getPixel(const int x, const int y);                       //�������ص���ɫ
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }


bool initWindow(int width, int height) {

    framebuffer = new color[width*height];
    if (!framebuffer) return false;
    framebuffer_width = width;
    framebuffer_height = height;
    clearWindow();
    return true;
}




//���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
void destoryWindow() {
    if (!framebuffer)return;
    delete[] framebuffer;
    framebuffer = nullptr;
}

//��ʾ֡��������ͼ��
void show() {
    for (int y = 0; y < framebuffer_height; y++) {
        for (int x = 0; x < framebuffer_width; x++)
            std::cout << framebuffer[y*framebuffer_width + x];
        std::cout << '\n';
    }
}

void setPixel(const int x, const int y, color c) {
    framebuffer[y*framebuffer_width + x] = c;
}

color getPixel(const int x, const int y) {
    return framebuffer[y*framebuffer_width + x];
}
#endif