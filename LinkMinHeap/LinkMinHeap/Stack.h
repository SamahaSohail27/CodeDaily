//#include <cstdlib>

template<typename T>
class Stack
{
	T* data;
	int capacity;
	int top;
	void reSize(int);
public:
	Stack();
	Stack(int c);
	Stack(const Stack<T>&);
	Stack& operator = (const Stack<T>&);
	~Stack();
	void push(T);
	T pop();
	T stackTop() const;
	bool isFull() const;
	bool isEmpty() const;
	int getCapacity() const;
	int getNumberOfElements() const;

};
template<typename T>
Stack<T>::Stack()
{
	data = nullptr;
	capacity = 0;
	top = -1;

}

template<typename T>
Stack<T>::Stack(int c)
{
	capacity = c;
	data = new T[c];
	top = -1;

}

template<typename T>
void Stack<T>::reSize(int newCapacity)
{
	//cout << "resize called: " << endl;
	Stack<T> temp;
	temp.capacity = newCapacity;
	temp.data = new T[temp.capacity];
	temp.top = top;

	for (int i = 0; i <= temp.top; i++)
	{
		temp.data[i] = data[i];
	}

	this->~Stack();
	data = temp.data;
	top = temp.top;
	capacity = temp.capacity;
	temp.data = nullptr;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& obj)
{
	capacity = obj.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		data[i] = obj.data[i];
	}
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (this->data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	if (obj.data != NULL)
	{
		capacity = obj.capacity;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			data[i] = obj.data[i];
		}

	}
	return *this;
}

template<typename T>
void Stack<T>::push(T value)
{
	if (capacity == 0)
	{
		reSize(1);
	}
	else if (isFull())
	{
		reSize(capacity * 2);
	}
	top++;
	data[top] = value;

}

template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		return 0;
	}

	if ((top + 1) == (capacity / 4))
	{
		reSize(capacity / 2);
	}
	T var;
	var = data[top];
	top--;
	return var;
}

template<typename T>
T Stack<T>::stackTop() const
{
	if (isEmpty())
	{
		return 0;
	}
	return data[top];
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	if (top < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	//return top == 0;
}

template<typename T>
bool Stack<T>::isFull() const
{
	if ((top + 1) == capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
	//return top == capacity;
}
template<typename T>
int Stack<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
int Stack<T>::getNumberOfElements() const
{
	return (top + 1);
}


template<typename T>
Stack<T>::~Stack()
{
	if (!data)
		return;
	else
	{
		delete[] data;
		data = nullptr;
		capacity = 0;
		top = 0;
	}
}

