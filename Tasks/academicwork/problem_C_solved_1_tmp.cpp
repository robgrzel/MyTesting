

#ifndef RunTests
	#include <vector>
	#include <cstddef>
	#include <iostream>
#else
	
	#include "problem_C.h"

#endif

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
		
		void clear() {
			items_.clear();
		}
		
		size_t width() const {
			return width_;
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
		
		void reserve(size_t const w, size_t const h) {
			width_ = w;
			height_ = h;
			items_.reserve(w * h);
		}
		
		explicit std_vector_2d(size_t const w = 0, size_t const h = 0, T const s = 0) :
				items_(w * h, s), width_(w), height_(h), s(s) {
			
		}
};


class Problem_C {
		
		size_t v;
		
		std_vector_2d <int> S;
		
		int ans = 0;
		
		std::vector <int> x;
		std::vector <int> y;
		std::vector <int> visited;
		std::vector <std::pair <int, int>> votes;
	
	
	public:
		
		Problem_C(std::vector <std::pair <int, int>> & votes) : votes(votes), v(votes.size()) {
			int p11, p12, p21, p22;
			
			S.reserve(v, v);
			
			x.resize(v, 0);
			y.resize(v, 0);
			visited.reserve(v);
			
			int o;
			for (size_t i = 0; i < v; i++) {
				p11 = votes[i].first;
				p12 = votes[i].second;
				for (size_t j = 0; j < v; j++) {
					p21 = votes[j].first;
					p22 = votes[j].second;
					
					o = int(i != j and p11 == p22 or p12 == p21);
					
					S(i, j) = S(j, i) = o;
				}
			}
			
			
			ans = solve();
		}
		
		~ Problem_C() {
			
			x.clear();
			y.clear();
			votes.clear();
			S.clear();
			visited.clear();
			
		}
	
	public:
		
		int get_ans() {
			return ans;
		}
	
	private:
		
		int solve() {
			//hungary algorithm
			//max maching
			
			int res = 0;
			for (int i = 0; i < v; i++) {
				std::fill(visited.begin(), visited.end(), 0);
				res += dfs(i) ;
			}
			
			int ans = (int) v - res / 2;
			
			return ans;
		}
		
		int dfs(int u, int d = 0) {
			//depth first search procedure
			
			int o1, o2, o3;
			int o11, o22, o33;
			int w;
			
			for (int i = 0; i < v; i++) {
				d++;
				o1 = S(u, i) and !visited[i]; //
				o2 = !y[i] or dfs(y[i], d);
				o3 = o1 * o2;
				visited[i] = o1;
				if (o3) {
					y[i] = u * o3;
					x[u] = i * o3;
					return 1;
				}
			}
			
			return 0;
		}
	
};


int problem_C(
#ifdef RunTests
		int numTestcases, int c, int d, int v, std::vector <std::pair <int, int>> votes
#endif
) {
	
	/*

	 */
	
	
	#ifndef RunTests
	
	int numTestcases, c, d;
	size_t v;
	
	std::cin >> numTestcases;
	
	std::vector <int> A(numTestcases,0);
	
	for (int i = 0; i < numTestcases; i++) {
		
		std::cin >> c >> d >> v;
		
		std::vector <std::pair<int,int>> votes(v);
		std::string s1, s2;
		int i1, i2;
		
		for (size_t j = 0; j < v; j++) {
			std::cin >> s1 >> s2;
			
			if (s1[0] == 'C') {
				i1 = -1;
			} else {
				i1 = 1;
			}
			
			if (s2[0] == 'C') {
				i2 = -1;
			} else {
				i2 = 1;
			}
			
			i1 *= stoi(s1.erase(0, 1));
			i2 *= stoi(s2.erase(0, 1));
			
			votes[j].first = i1;
			votes[j].second = i2;
			
		}
		
		
		std::cout <<Problem_C(votes).get_ans()<<std::endl;
		
	}
	
	
	#else
	
	std::cout << "########################\n";
	std::cout << c << "," << d << "," << v << "\n";
	
	Problem_C p = Problem_C(votes);
	
	std::cout << p.get_ans() << std::endl;
	#endif
	
	
	return 0;
}


#ifndef RunTests

int main() {
	
	
	return problem_C();
	
	
}

#endif