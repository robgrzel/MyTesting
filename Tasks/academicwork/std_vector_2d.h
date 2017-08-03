//
// Created by robgrzel on 14.06.17.
//

#ifndef UTILS_STD_VECTOR_2D_H
#define UTILS_STD_VECTOR_2D_H

#include <iostream>
#include <vector>
#include <cstring>
#include "templates.h"

template<class T>
class std_vector_2d {
	private:
		std::vector <T> items_;
		size_t width_;
		size_t height_;
		T s;
		
		const size_t idx(const size_t x, const size_t y) const {
			return y * width_ + x;
		}
	
	public:
		
		void fill(const T s){
			memset(&items_[0], s, items_.size() * sizeof items_[0]);
		}
		
		size_t width() const {
			return width_;
		}
		
		size_t height() const {
			return height_;
		}
		
		T & operator [](const size_t x) {
			return items_[x];
		}
		
		T & operator ()(const size_t x, const size_t y) {
			return items_[idx(x, y)];
		}
		
		T const & operator ()(const size_t x, const size_t y) const {
			return items_[idx(x, y)];
		}
		
		size_t size() const {
			return width_ * height_;
		}
		
		T * buffer() {
			return & items_[0];
		}
		
		T const * buffer() const {
			return & items_[0];
		}
		
		void print(const char * name, bool printRaw) {
			
			if (printRaw) {
				for (int i = 0; i < height_; i++) {
					for (int j = 0; j < width_; j++) {
						std::cout << operator ()(j, i) << ",";
					}
					std::cout << std::endl;
				}
			} else {
				printf("%s = [\n", name);
				for (int i = 0; i < height_; i++) {
					printf("[%d] : ", i);
					for (int j = 0; j < width_; j++) {
						std::cout << operator ()(j, i) << ",";
					}
					std::cout << std::endl;
				}
				std::cout << "]" << std::endl;
			}
		}
		
		void print_row(const char * name, const int row) {
			for (int j = 0; j < width_; j++) {
				printf("%s(%d,%d)=%f\n", name, row, j, operator ()(j, row));
			}
			
		}
		
		void print_col(const char * name, const int col) {
			for (int j = 0; j < height_; j++) {
				printf("%s(%d,%d)=%f\n", name, j, col, operator ()(col, j));
			}
			
		}
		
		std::vector <T> slice(int n, int begin = 0, int end = -1, char axis = 0) {
			std::vector <T> vec;
			
			if (axis) {
				
				if (end == -1) {
					end = width_;
				}
				
				vec.resize(end - begin);
				for (int i = begin, j = 0; i < end; i++, j++) {
					vec[j] = operator ()(i, n);
				}
				
			} else {
				
				if (end == -1) {
					end = height_;
				}
				vec.resize(end - begin);
				for (int i = begin, j = 0; i < end; i++, j++) {
					vec[j] = operator ()(n, i);
				}
				
			}
			
			return vec;
		}
		
		std::vector <T> slicex(int n, int end = -1, int begin = 0) {
			return slice(n, begin, end, 1);
		}
		
		
		std::vector <T> slicey(int n, int end = -1, int begin = 0) {
			return slice(n, begin, end, 0);
		}
		
		void fromfile(std::string pathFile, char delim = ' ') {
			
			std::fstream fs(pathFile, std::ios::in);
			
			if (!fs) {
				std::cout << "Error opening file\n";
				
				return;
			}
			
			size_t size[2];
			
			size[0] = file_line_count(pathFile.c_str(), delim);
			size[1] = file_lines_count(pathFile.c_str());
			
			resize(size[0], size[1]);
			
			T a;
			
			int i = 0;
			
			bool doBreak = false;
			
			while (true) {
				for (int j = 0; j < size[0]; j++) {
					fs >> a;
					if (fs.eof()) {
						doBreak = true;
						break;
					} else {
						operator ()(j, i) = a;
					}
				}
				if (doBreak) {
					break;
				} else {
					i++;
				}
			}
			
			fs.close();
			
			
		}
		
		void resize(size_t const w, size_t const h) {
			width_ = w;
			height_ = h;
			items_.resize(w * h);
		}
		
		void reserve(size_t const w, size_t const h) {
			width_ = w;
			height_ = h;
			items_.reserve(w * h);
		}
		
		explicit std_vector_2d(size_t const w = 0, size_t const h = 0, T const s = 0) :
				items_(w * h, s), width_(w), height_(h), s(s) {
			
		}
};


#endif //UTILS_STD_VECTOR_2D_H
