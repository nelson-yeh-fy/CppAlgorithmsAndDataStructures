#ifndef CH1_MYVECTORCHAR_H
#define CH1_MYVECTORCHAR_H
class myVectorChar {
private:
	int size;
	long capacity;
	char* items;
public:
	myVectorChar() {
		size = 0;
		capacity = 2;
		items = new char[capacity];
	}
	~myVectorChar() {
		if (items)
			delete[] items;
	}
	void doubleSize();
	void halfSize();
	int begin();
	int end();
	void push_back(char c);
	void insert();
};

void demoMyVectorChar1();
#endif //CH1_MYVECTORCHAR_H