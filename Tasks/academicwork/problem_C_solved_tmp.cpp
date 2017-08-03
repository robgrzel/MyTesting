#ifndef RunTests


#include <complex>
	#include <iostream>
	#include <std::vector>
	#include <algorithm>
	#include <iomanip>
	#include <iterator>
	#include <cstring>

#else
	
	#include "problem_C.h"

#endif

class Strategy {
	public:
		virtual int maximumCliqueSize() = 0;
};

class HopcroftKarpStrategy : public Strategy {
	public:
		HopcroftKarpStrategy(int cats, int dogs, const std::vector <Problem_C_Vote *> & votes) {
			this->cats = cats;
			this->dogs = dogs;
			this->votes = votes;
		}
		
		int maximumCliqueSize() {
			this->bisectGraph();
			for (int i = 0; i < this->votes.size(); i++) {
				pairCats[i] = NIL;
				pairDogs[i] = NIL;
			}
			
			int matching = 0;
			
			while (this->bfs()) {
				for (std::vector <int>::iterator catIterator = this->catVotes.begin();
				     catIterator != this->catVotes.end(); catIterator++) {
					if ((pairCats[* catIterator] == NIL) && this->dfs(* catIterator)) {
						matching++;
					}
				}
			}
			return this->votes.size() - matching;
		}
	
	protected:
		const static int MAX = 1000;
		const static int NIL = -1;
		
		const static int INFINITY = 999; // this is approximate.
		
		int cats, dogs, pairCats[MAX], pairDogs[MAX], dist[MAX];
		std::vector <Problem_C_Vote *> votes;
		std::vector <int> catVotes, dogVotes;
		
		bool bfs() {
			queue <int> Q;
			for (std::vector <int>::iterator catIterator = this->catVotes.begin();
			     catIterator != this->catVotes.end(); catIterator++) {
				if (pairCats[* catIterator] == NIL) {
					dist[* catIterator] = 0;
					Q.push(* catIterator);
				} else {
					dist[* catIterator] = INFINITY;
				}
			}
			
			dist[NIL] = INFINITY;
			
			while (!Q.empty()) {
				int cat = Q.front();
				if (cat != NIL) {
					for (std::vector <int>::iterator dogIterator = this->dogVotes.begin();
					     dogIterator != this->dogVotes.end(); dogIterator++) {
						if (this->votes[cat]->disagreeableWithOpposite(this->votes[* dogIterator])) {
							if (dist[pairDogs[* dogIterator]] == INFINITY) {
								dist[pairDogs[* dogIterator]] = dist[cat] + 1;
								Q.push(pairDogs[* dogIterator]);
							}
						}
					}
				}
				Q.pop();
			}
			
			return dist[NIL] != INFINITY;
		}
		
		bool dfs(int cat) {
			if (cat != NIL) {
				for (std::vector <int>::iterator dogIterator = this->dogVotes.begin();
				     dogIterator != this->dogVotes.end(); dogIterator++) {
					if (this->votes[cat]->disagreeableWithOpposite(this->votes[* dogIterator])) {
						if (dist[pairDogs[* dogIterator]] == (dist[cat] + 1)) {
							if (dfs(pairDogs[* dogIterator])) {
								pairDogs[* dogIterator] = cat;
								pairCats[cat] = * dogIterator;
								return true;
							}
						}
					}
				}
				dist[cat] = INFINITY;
				return false;
			}
			return true;
		}
		
		void bisectGraph() {
			for (int i = 0; i < this->votes.size(); i++) {
				if (this->votes[i]->catLover())
					this->catVotes.push_back(i);
				else
					this->dogVotes.push_back(i);
			}
		}
	
};

class Problem_C_Vote {
	
	private:
		int keep, drop, side;
	
	public:
		Problem_C_Vote(const std::string keep_, const std::string & drop_) {
			side = keep_[0] == 'C' ? -1 : 1;
			keep = atoi(keep_.substr(1).c_str());
			drop = atoi(drop_.substr(1).c_str());
		}
		
		int get_keep() {
			return keep;
		}
		
		int get_drop() {
			return drop;
		}
		
		bool get_side() {
			return side;
		}
		
		bool agreeableWith(Problem_C_Vote * vote) {
			if (this->catLover() == vote->catLover()) {
				return true;
			} else {
				return this->agreeableWithOpposite(vote);
			}
		}
		
		bool agreeableWithOpposite(Problem_C_Vote * vote) {
			return ((this->keep != vote->getDrop()) && (this->drop != vote->getKeep()));
		}
		
		bool disagreeableWithOpposite(Problem_C_Vote * vote) {
			return !this->agreeableWithOpposite(vote);
		}
		
		bool fullyDisagreeableWithOpposite(Problem_C_Vote * vote) {
			return ((this->keep == vote->getDrop()) && (this->drop == vote->getKeep()));
		}
	
};

class Problem_C_Voter {
	
	private:
		
		int c;
		int d;
		
		std::vector <Problem_C_Vote *> votes;
	
	private:
		
		Strategy * getStrategy() {
			return new HopcroftKarpStrategy(c, d, votes);
		}
	
	
	public:
		Problem_C_Voter(int c, int d, size_t v) : c(c), d(d) {
			this->votes.reserve(v);
		}
		
		int max_clique_size() {
			return getStrategy()->maximumCliqueSize();
		}
		
		Problem_C_Voter & operator +=(Problem_C_Vote * vote) {
			votes.push_back(vote);
			return * this;
			
		}
	
	
};

class Problem_C_Voters {
	
	private:
		int sets;
		std::vector <Problem_C_Voter *> V;
	
	public:
		
		explicit Problem_C_Voters(int sets) : sets(sets) {
		
		}
		
		void max_clicque(std::vector <int> & ret) {
			int v;
			for (auto & i : V) {
				v = i->max_clique_size();
				ret.push_back(v);
			}
			
		}
		
		Problem_C_Voters & operator +=(Problem_C_Voter * set) {
			V.push_back(set);
			return * this;
			
		}
	
};

class Parse_Data_Problem_C {
	
	private:
		Problem_C_Voters * voters;
		
		int numTestcases;
	
	public:
		
		Problem_C_Voters * get_voters() {
			return voters;
		}
	
	private:
		void read() {
			std::string line;
			std::cin >> numTestcases;
			
			voters = new Problem_C_Voters(numTestcases);
			
			for (int i = 0; i < numTestcases; i++) {
				read_testcase();
			}
			
		}
		
		void read_testcase() {
			int c, d;
			size_t v;
			
			std::string keep, drop;
			
			Problem_C_Vote * vote;
			Problem_C_Voter * voter;
			
			
			std::cin >> c >> d >> v;
			
			voter = new Problem_C_Voter(c, d, v);
			
			for (int i = 0; i < v; i++) {
				std::cin >> keep >> drop;
				
				vote = new Problem_C_Vote(keep, drop);
				
				(* voter) += vote;
			}
			
			(* voters) += voter;
		}
	
	public:
		
		Parse_Data_Problem_C() {
			read();
		}
		
		~Parse_Data_Problem_C() {
		}
};


int problem_C(
#ifdef RunTests
		int numTestcases, int c, int d, int v, std::vector <std::pair <int, int>> V
#endif
) {
	
	/*

	 */
	
	
	#ifndef RunTests
	
	int numTestcases, c, d;
	size_t v;
	
	std::cin >> numTestcases;
	
	for (int i = 0; i < numTestcases; i++) {
		
		std::cin >> c >> d >> v;
		
		std::vector <std::pair <int, int>> V(v);
		std::string s1, s2;
		int i1, i2;
		
		for (int j = 0; j < v; j++) {
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
			
			V[j].first = i1;
			V[j].second = i2;
			
		}
		
		solve_testcase_problem_C(c, d, V);
		
		
	}
	
	#else
	
	std::cout << "########################\n";
	std::cout << c << "," << d << "," << v << "\n";
	
	solve_testcase_problem_C(c, d, V);
	
	#endif
	
	return 0;
}


#ifndef RunTests

int main() {
	
	
	return problem_C();
	
	
}

#endif