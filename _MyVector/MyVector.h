
#pragma once

template <typename T1>
class MyVector
{
public:
	MyVector();
	MyVector(size_t _Size);
	MyVector(size_t _Size, T1 _Data);
	MyVector(const MyVector& _Vec);
	~MyVector();

private:
	T1* DataArr;

public:
	size_t size;
	size_t capacity;

public:
	T1 operator[](size_t _index)
	{
		return DataArr[_index];
	}

	template <typename T1>
	MyVector& operator=(const MyVector& _vector)
	{
		if (_vector.capacity <= 0)
			return;

		if (_vector.size > size)
		{
			reserve(_vector.size);
		}

		for (int i = 0; i < _vector.size(); ++i)
		{
			DataArr[i] = _vector[i];
		}

		return *this;
	}

public:
	void push_back(T1 _Data);
	void resize(size_t _Size);
	void resize(size_t _Size, T1 _Data);
	void reserve(size_t _Size);

};


template<typename T1>
inline MyVector<T1>::MyVector() :
	DataArr(nullptr),
	size(0),
	capacity(0)
{
	DataArr = new T1;
}

template<typename T1>
inline MyVector<T1>::MyVector(size_t _Size)
{
	DataArr = new T1[_Size * 2];
	capacity = _Size * 2;
}

template<typename T1>
inline MyVector<T1>::MyVector(size_t _Size, T1 _Data)
{
	DataArr = new T1[_Size * 2];
	capacity = _Size * 2;

	while(size < _Size)
		DataArr[size++] = _Data;
}

template<typename T1>
inline MyVector<T1>::MyVector(const MyVector& _vec)
{
}

template<typename T1>
inline MyVector<T1>::~MyVector()
{
	if (DataArr != nullptr)
		delete[] DataArr;
}

template<typename T1>
inline void MyVector<T1>::push_back(T1 _Data)
{
	if (size >= capacity)
	{
		if (capacity == 0)
			capacity = 1;

		T1* TempArr = new T1[capacity * 2];

		for (int i = 0; i < size; ++i)
			TempArr[i] = DataArr[i];

		delete[] DataArr;
		DataArr = nullptr;
		
		DataArr = TempArr;

		capacity *= 2;		// size;0 capacity0�϶�, 1push-back�ϸ� �ƹ��͵� �ȵ�.
	}

	DataArr[size++] = _Data;
}

template<typename T1>
inline void MyVector<T1>::resize(size_t _Size)
{	// ���Ҵ��� �ʿ�
	if ((int)(capacity - _Size) <= 0)
	{
		if (capacity == 0)
			capacity = 1;

		T1* TempArr = new T1[2 * _Size];

		for (int i = 0; i < size; ++i)
			TempArr[i] = DataArr[i];

		delete[] DataArr;
		DataArr = nullptr;

		DataArr = TempArr;

		capacity = 2 * _Size;		// size;0 capacity0�϶�, 1push-back�ϸ� �ƹ��͵� �ȵ�.
	}

	while (size < _Size)
		DataArr[size++] = 0;
}

template<typename T1>
inline void MyVector<T1>::resize(size_t _Size, T1 _Data)
{
	// ���Ҵ��� �ʿ�
	if ((int)(capacity - _Size) <= 0)
	{
		if (capacity == 0)
			capacity = 1;

		T1* TempArr = new T1[2 * _Size];

		for (int i = 0; i < size; ++i)
			TempArr[i] = DataArr[i];

		delete[] DataArr;
		DataArr = nullptr;

		DataArr = TempArr;

		capacity = 2 * _Size;		// size;0 capacity0�϶�, 1push-back�ϸ� �ƹ��͵� �ȵ�.
	}

	// �A��ŭ �Ҵ�

	while (size < _Size)
		DataArr[size++] = _Data;
}

template<typename T1>
inline void MyVector<T1>::reserve(size_t _Size)
{
	if ((int)(capacity - _Size) <= 0)
	{
		if (_Size <= 0)
			return;

		T1* TempArr = new T1[_Size];

		for (int i = 0; i < size; ++i)
			TempArr[i] = DataArr[i];

		delete[] DataArr;
		DataArr = nullptr;

		DataArr = TempArr;

		capacity = _Size;
	}
}

