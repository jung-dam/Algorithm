#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp( pair<int,int> m1, pair<int, int> m2 )
{
    //재생횟수 같으면 고유번호 오름차순
    if (m1.first == m2.first)
    {
       return  m1.second < m2.second;
    }
    else
    {
        return m1.first > m2.first;
    }
    
}
bool cmp1(pair<string, int> m1, pair<string, int> m2)
{
    //장르별 재생횟수 내림차순
     return  m1.second > m2.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> umap;
    unordered_map<string, vector<pair<int,int>>> musiclist;
    vector<pair<string, int>> sort_musiclist;

    for (int i = 0; i < genres.size(); i++)
    {
        //장르별 재생횟수 분류
        umap[genres[i]] += plays[i]; //(key,element) (장르, 횟수)

        //플레이리스트 (장르,횟수,고유번호)
        musiclist[genres[i]].push_back(make_pair(plays[i], i));

    }

  
       for (auto &m : musiclist)
    {
        sort(m.second.begin(), m.second.end(), cmp);
    }

	sort_musiclist.assign(umap.begin(), umap.end());
	//==vector <pair<string, int>> v(umap.begin(),umap.end());
	sort(sort_musiclist.begin(), sort_musiclist.end(), cmp1);

	for (int a = 0; (a < sort_musiclist.size()); a++)
	{
		for (auto z = musiclist.begin(); z != musiclist.end(); z++)
		{
			//장르별 재생횟수 순서대로 플레이리스트에서 장르 같을 때
			if ((sort_musiclist[a].first) == (z->first))
			{
				for (int j = 0; j < ( z->second.size() ) && (j < 2) ; j++)
				{

					answer.push_back(z->second[j].second);
				}
			}
		}
	}



    return answer;
}