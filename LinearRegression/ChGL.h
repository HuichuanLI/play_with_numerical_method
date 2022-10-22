#pragma once
using color = char;  //����һ����ʾ��ɫ��color���ͣ�ÿ���ַ�����һ����ɫ
extern color* framebuffer;          //֡������
extern int framebuffer_width, framebuffer_height;
extern color clear_color;                //������ɫ

//��������ɫclear_color��մ�������
inline void clearWindow() {
	if (!framebuffer) return;
	for (int y = 0; y < framebuffer_height; y++)
		for (int x = 0; x < framebuffer_width; x++)
			framebuffer[y*framebuffer_width + x] = clear_color;

}
//��ʼ��һ�����ڣ�����boolֵ��ʾ�ɹ�����ʧ��
inline bool initWindow(int width, int height) {

	framebuffer = new color[width*height];
	if (!framebuffer) return false;
	framebuffer_width = width;
	framebuffer_height = height;
	clearWindow();
	return true;
}


//���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
inline void destoryWindow() {
	if (!framebuffer)return;
	delete[] framebuffer;
	framebuffer = nullptr;
}

//��ʾ֡��������ͼ��
inline void show() {
	for (int y = 0; y < framebuffer_height; y++) {
		for (int x = 0; x < framebuffer_width; x++)
			std::cout << framebuffer[y*framebuffer_width + x];
		std::cout << '\n';
	}
}

//�������ص���ɫ
inline void setPixel(const int x, const int y, color c) {
	framebuffer[y*framebuffer_width + x] = c;
}
//�õ����ص���ɫ
inline color getPixel(const int x, const int y) {
	return framebuffer[y*framebuffer_width + x];
}

inline void set_clear_color(color c) { clear_color = c; }
inline color get_clear_color() { return clear_color; }