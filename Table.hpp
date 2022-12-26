#pragma once

template <class T>
class Table
{
private:
	int _col;
	int _row;
	size_t _size;
	T** _table;
public:
	Table(int row, int col) : _row(row), _col(col), _size(row * col), _table(nullptr)
	{
		_table = new T*[_row];
		for (int i = 0; i < _row; ++i) _table[i] = new T[_col]();
	}
	Table(const Table& tb) : _row(tb._row), _col(tb._col), _size(tb._size)		// конструктор копировани€
	{
		_table = new T * [_row];
		for (int i = 0; i < _row; ++i) _table[i] = new T[_col]();

		// копирую массив
		for (int i = 0; i < _row; ++i)
		{
			for (int j = 0; j < _col; ++j)
			{
				_table[i][j] = tb._table[i][j];
			}
		}
	}
	~Table()
	{
		for (int i = 0; i < _row; ++i) delete[] _table[i];
		delete[] _table;
	}
	Table& operator=(const Table&) = delete; // оператор присваивани€, запрещен
	
	// от балды написал оператор (T* operator[] (int index)),
	// особенно в плане возврата значени€ - оочень удивилс€ когда он заработал! )
	// не понимаю чего он возвращает и как работает (индекса же 2!)
	//
	// ну, строки € отловил - как то
	// а что делать со столбцами, ума не приложу.
	T* operator[] (int index)
	{
		if (index >= _row && index < 0)
		{
			// здась € проверил выход за пределы массива по строкам
			// а вот по столбцам, пожалуйста - хоть в космос! ))
			throw std::runtime_error("operator[_row] ");
		}
		std::cout << "»ндекса 2, а эта надпись - одна?!!!" << std::endl;
		return _table[index];
	}

	T* operator[] (int index) const
	{
		if (index >= _row && index < 0) throw std::runtime_error("operator[_row] ");
		return _table[index];
	}

	size_t getSize() const
	{
		return static_cast<size_t>(_col) * _row;
	}
};

