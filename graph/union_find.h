#pragma once

#include <vector>

namespace graph{
	using namespace std;

	class UnionFind{
	public:
		//nは要素数
		UnionFind(int n) :
			par(n),
			rank(n)
		{
			for (int i = 0; i < n; ++i){
				par[i] = i;
			}
		}

		//xとyの属する集合を結合
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
		//親
		vector<int> par;

		//根の深さ
		vector<int> rank;

		//木の根を求める
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