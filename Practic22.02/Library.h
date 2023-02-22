#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
Разработайте программу «Библиотека».
Создайте структуру «Книга» (название, автор, издательство,
жанр). Создайте массив из 10 книг. Реализуйте для него
следующие возможности:
*/

class Library
{
	static const int SIZE = 25;
	static const int SIZE_BOOKS = 10;
	struct Book {
		char name[SIZE];
		char author[SIZE];
		char publish[SIZE];
		char genre[SIZE];
	};
	Book books[SIZE_BOOKS];

	void Sort(int id) {
		for (int i = 0; i < SIZE_BOOKS; i++) {
			for (int j = 0; j < SIZE_BOOKS - 1; j++) {
				if ((id) ?
					strcmp(books[j].author, books[j + 1].author) > 0:
				(id == 0) ?
					strcmp(books[j].name, books[j + 1].name) > 0:
				strcmp(books[j].publish, books[j + 1].publish) > 0
					) {
					swap(books[j], books[j + 1]);
				}
			}
		}
	}
	void Find(const char* s, int id) {
		for (int i = 0; i < SIZE_BOOKS; i++) {
			if ((id) ? !strcmp(books[i].name, s) :
				!strcmp(books[i].author, s)) {
				cout << endl << books[i].name << " "
					<< books[i].author << " "
					<< books[i].publish << " "
					<< books[i].genre << endl << endl;
			}
		}
	}
	char* Edit() {
		char y_n;
		char* temp;
		temp = new char[SIZE];

		cout << "yes(y) or no(n) -> "; cin >> y_n;
		cin.ignore();
		if (y_n == 'y') {
			gets_s(temp, SIZE);
			return temp;
		}
		return nullptr;
	}
public:
	Library() {
		string str;
		for (int i = 0; i < SIZE_BOOKS; i++) {
			str = "name" + to_string(i * rand() % 10);
			strcpy_s(books[i].name, str.c_str());
			str = "author" + to_string(i * rand() % 10);
			strcpy_s(books[i].author, str.c_str());
			str = "publish" + to_string(i * rand() % 10);
			strcpy_s(books[i].publish, str.c_str());
			str = "genre" + to_string(i * rand() % 10);
			strcpy_s(books[i].genre, str.c_str());
		}
	}
	//■ Редактировать книгу;
	void EditBook(int id) {
		char* temp;
		if (temp = Edit())strcpy_s(books[id].name, temp);
		if (temp = Edit())strcpy_s(books[id].author, temp);
		if (temp = Edit())strcpy_s(books[id].publish, temp);
		if (temp = Edit())strcpy_s(books[id].genre, temp);
	}
	//■ Печать всех книг;
	void PrintBooks() {
		for (int i = 0; i < SIZE_BOOKS; i++) {
			cout << books[i].name << " " << books[i].author << " "
				<< books[i].publish << " " << books[i].genre << endl;
		}
	}

	//■ Поиск книг по автору;
	void FindAuthor(const char* a) {
		Find(a, 0);
	}
	//■ Поиск книги по названию;
	void FindName(const char* a) {
		Find(a, 1);
	}

	//■ Сортировка массива по названию книг;	
	void SortName() {
		Sort(0);
	}
	//■ Сортировка массива по автору;
	void SortAuthor() {
		Sort(1);
	}
	//■ Сортировка массива по издательству.
	void SortPublish() {
		Sort(3);
	}

};

