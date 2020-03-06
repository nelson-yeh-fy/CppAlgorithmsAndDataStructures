#ifndef CH1_MYVECTORCHAR_H
#define CH1_MYVECTORCHAR_H
class myVectorChar {
private:
	int m_size;
	int m_max_size;
	int m_capacity;
	char* m_items;
public:
	myVectorChar() {
		m_size = 0;
		m_max_size = INT_MAX;
		m_capacity = 2;
		m_items = new char[m_capacity];
	}
	~myVectorChar() {
		if (m_items)
			delete[] m_items;
	}

	// ---
	// Capacity
	// ---
	int size() { return m_size; }
	int max_size() { return m_max_size; }
	int capacity() { return m_capacity; }
	bool resize(int nsize);
	bool empty() { return m_size == 0; }
	void reserve(int nsize);
	void shrink_to_fit(int nsize);

	void doubleSize();
	int begin();
	int end();
	void push_back(char c);
	void insert();
	void print();
};

void demoMyVectorChar1();
#endif //CH1_MYVECTORCHAR_H