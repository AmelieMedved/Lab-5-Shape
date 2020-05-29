#pragma once
#include "Shape.h"

template <class T>
class Simplex : public  Shape
{
private:
	int height;
	T** data;

public:
	Simplex();
	Simplex(int _height, T _data);
	Simplex(const Simplex& obj);
	~Simplex();
	std::ostream& Print(std::ostream& out) override;
	float Volume() override { throw; }
	float Area() override { throw; }

	int GetHeight();
	T GetData();
	void SetHeight(int _height);

	bool operator ==(const Simplex& obj);
};


Simplex<char>::Simplex()
{
	height = 5;
	data = new char* [height];
	for (int i = 0; i < height; i++)
		data[i] = new char[height];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			data[i][j] = '^';
}

template<class T>
Simplex<T>::Simplex(int _height, T _data)
{
	height = _height + 1;

	data = new T * [height];
	for (int i = 0; i < height; i++)
		data[i] = new T[height];


	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			data[i][j] = _data;
}

template<class T>
Simplex<T>::Simplex(const Simplex& obj)
{
	if (data != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] data[i];
		delete[] data;
	}
	height = obj.height;

	data = new T * [height];
	for (int i = 0; i < height; i++)
		data[i] = new T[height];


	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			data[i][j] = obj.data[i][j];
}

template<class T>
Simplex<T>::~Simplex()
{
	if (data != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] data[i];
		delete[] data;
		data = 0;
		height = 0;
	}
}

template<class T>
int Simplex<T>::GetHeight()
{
	return height - 1;
}

template<class T>
T Simplex<T>::GetData()
{
	if (data != nullptr)
	{
		return (data[0][0]);
	}
	else
		throw - 1;
}

template<class T>
void Simplex<T>::SetHeight(int _height)
{
	T tmp = this->Getval();
	if (data != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] data[i];
		delete[] data;
	}
	height = _height + 1;


	data = new T * [height];
	for (int i = 0; i < height; i++)
		data[i] = new T[height];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			data[i][j] = tmp;
}

template<class T>
std::ostream& Simplex<T>::Print(std::ostream& out)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < i; j++)
			out << data[i][j];
		out << std::endl;
	}
	return out;
}

template<class T>
bool Simplex<T>::operator==(const Simplex& obj)
{
	if (height == obj.height && data[0][0] == obj.data[0][0])
		return true;
	return false;
}