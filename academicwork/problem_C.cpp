#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>

#ifndef RunTests


#else
	
	#include "problem_C.h"

#endif

class Node {
	
	private:
		int k, d, s;
	
	public:
		Node(const int s_, const int k_, const int d_) {
			s = s_;
			k = k_;
			d = d_;
		}
		
		int keep() {
			return k;
		}
		
		int drop() {
			return d;
		}
		
		int side() {
			return s;
		}
		
		
		bool is_same_side(Node * edge) {
			return (keep() != edge->drop()) and (drop() != edge->keep());
		}
		
		bool is_not_same_side(Node * edge) {
			return !is_same_side(edge);
		}
	
};

class Strategy {
	public:
		virtual int maximum_clique() = 0;
};

class Hopcroft_Karp : public Strategy {
	
	protected:
		const static int MAX = 1000;
		const static int NIL = -1;
		const static int INF = 999; // this is approximate.
		
		int c, d;
		int cpair[MAX]{};
		int dpair[MAX]{};
		int dist[MAX]{};
		
		std::vector <Node *> cliques;
		std::vector <int> cnodes;
		std::vector <int> dnodes;
	
	public:
		Hopcroft_Karp(int c, int d, std::vector <Node *> & cliques) : c(c), d(d), cliques(cliques) {
		
		}
		
		int maximum_clique() override {
			bisect_graph();
			for (int i = 0; i < cliques.size(); i++) {
				cpair[i] = NIL;
				dpair[i] = NIL;
			}
			
			int match = 0;
			bool match_;
			
			while (bfs()) {
				
				for (int & catIterator : cnodes) {
					match_ = cpair[catIterator] == NIL and dfs(catIterator);
					match += static_cast<int>(match_);
				}
			}
			
			return (int) cliques.size() - match;
		}
	
	protected:
		
		bool bfs() {
			
			std::queue <int> Q;
			
			int o;
			for (int & citer : cnodes) {
				if (cpair[citer] == NIL) {
					Q.push(citer);
					o = 0;
				} else {
					o = INF;
				}
				
				dist[citer] = o;
			}
			
			dist[NIL] = INF;
			
			int c, d;
			bool notSameSide;
			bool isInfDist;
			Node * s1, * s2;
			
			while (!Q.empty()) {
				c = Q.front();
				if (c != NIL) {
					for (int & diter : dnodes) {
						s1 = cliques[c];
						s2 = cliques[diter];
						notSameSide = s1->is_not_same_side(s2);
						if (notSameSide) {
							d = dpair[diter];
							isInfDist = dist[d] == INF;
							if (isInfDist) {
								dist[d] = dist[c] + 1;
								Q.push(d);
							}
						}
					}
				}
				
				Q.pop();
			}
			
			return dist[NIL] != INF;
		}
		
		bool dfs(int c) {
			int cdist, ddist;
			int dd;
			bool isEqDist;
			bool isNeqSide;
			Node * cnode, * dnode;
			if (c != NIL) {
				for (int & d : dnodes) {
					dd = dpair[d];
					cnode = cliques[c];
					dnode = cliques[d];
					cdist = dist[c] + 1;
					ddist = dist[dd];
					isNeqSide = cnode->is_not_same_side(dnode);
					isEqDist = ddist == cdist;
					if (isNeqSide and isEqDist) {
						if (dfs(dpair[d])) {
							dpair[d] = c;
							cpair[c] = d;
							return true;
						}
					}
				}
				dist[c] = INF;
				return false;
			}
			
			return true;
		}
		
		void bisect_graph() {
			bool isNegSide;
			for (int i = 0; i < cliques.size(); i++) {
				isNegSide = cliques[i]->side() == -1;
				if (isNegSide)
					cnodes.push_back(i);
				else
					dnodes.push_back(i);
			}
		}
	
};


class Graph {
	
	private:
		
		int c;
		int d;
		
		std::vector <Node *> cliques;
	
	private:
		
		Strategy * get_strategy() {
			return new Hopcroft_Karp(c, d, cliques);
		}
	
	
	public:
		Graph(int c_, int d_, size_t v_) : c(c_), d(d_) {
			cliques.reserve(v_);
		}
		
		int maximum_clique() {
			return get_strategy()->maximum_clique();
		}
		
		
		void add_node(Node * side) {
			cliques.push_back(side);
			
		}
		
		Graph & operator +=(Node * node) {
			add_node(node);
			return * this;
		}
	
};


class Problem_C {
	
	private:
		
		std::vector <Graph> testcases;
		unsigned long numTestcases{};
	
	public:
		
		Problem_C() {
			read();
		}
	
	public:
		
		
		void get_num_satisfied(std::vector <int> & ret) {
			int v;
			for (Graph g : testcases) {
				v = g.maximum_clique();
				ret.push_back(v);
			}
			
		}
	
	private:
		void read() {
			std::cin >> numTestcases;
			
			testcases.reserve(numTestcases);
			
			for (int i = 0; i < numTestcases; i++) {
				read_testcase();
			}
			
		}
		
		void read_testcase() {
			int c, d;
			
			size_t v;
			
			
			std::cin >> c >> d >> v;
			
			Graph * graph;
			Node * node;
			std::string keep, drop;
			int side_, keep_, drop_;
			
			
			graph = new Graph(c, d, v);
			for (int i = 0; i < v; i++) {
				std::cin >> keep >> drop;
				side_ = keep[0] == 'C' ? -1 : 1;
				keep = keep.substr(1);
				drop = drop.substr(1);
				keep_ = atoi(keep.c_str());
				drop_ = atoi(drop.c_str());
				node = new Node(side_, keep_, drop_);
				
				(* graph) += node;
			}
			
			
			testcases.push_back(* graph);
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
	
	Problem_C problemc = Problem_C();
	std::vector <int> satisfied;
	problemc.get_num_satisfied(satisfied);
	
	for (int s : satisfied) {
		std::cout << s << std::endl;
	}
	
	
	#else
																															
	std::cout << "########################\n";
	std::cout << c << "," << d << "," << v << "\n";
	
	Problem_C problemc = Problem_C();
	std::vector <int> satisfied;
	problemc.get_num_satisfied(satisfied);
	
	for (int s : satisfied) {
		std::cout << s << std::endl;
	}
	
	#endif
	
	return 0;
}


#ifndef RunTests

int main() {
	
	
	return problem_C();
	
	
}

#endif