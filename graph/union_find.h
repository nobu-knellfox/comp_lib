#pragma once

#include <vector>

namespace graph{
	using namespace std;

	class UnionFind{
	public:
		//n‚Í—v‘f”
		UnionFind(int n) :
			par(n),
			rank(n)
		{
			for (int i = 0; i < n; ++i){
				par[i] = i;
			}
		}

		//x‚Æy‚Ì‘®‚·‚éW‡‚ğŒ‹‡
		void unite(int x, int y){
			x = find(x);
			y = find(y);

			if (x == y)return;

			if (rank.at(x) < rank.at(y)){
				par.at(x) = y;
			}
			else{
				par.at(y) = x;
				if (rank.at(x) == rank.at(y))rank.at(x)++;
			}
		}

		bool same(int x, int y){
			return find(x) == find(y);
		}



	private:
		//e
		vector<int> par;

		//ª‚Ì[‚³
		vector<int> rank;

		//–Ø‚Ìª‚ğ‹‚ß‚é
		int find(int x){
			if (par.at(x) == x){
				return x;
			}
			else{
				return par.at(x) = find(par.at(x));
			}
		}
	};
}