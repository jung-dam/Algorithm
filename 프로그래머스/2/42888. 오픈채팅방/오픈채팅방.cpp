#include <string>
#include <vector>
#include <sstream>
#include <iostream> 
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> user;
    vector<pair<string,string>> result;
    
    for( int i = 0; i < record.size(); i++)
    {
        string input, id, name;
        stringstream strstream;
        strstream.str(record[i]); //strstream에 record로 초기화
        strstream >> input >> id >> name;
        if(input == "Enter")
        {
            user[id] = name; //(id,name)쌍으로 저장
            result.push_back(make_pair(id, "들어왔습니다."));
        }
        if(input == "Leave")
        {
            result.push_back(make_pair(id, "나갔습니다."));
        }
        if(input == "Change")
        {
            user[id] = name;
            //userinfo.push_back(make_pair(id, name));
        }
        
    }
    for (int i = 0; i < result.size();i++) 
    {
		answer.push_back(user[result[i].first] + "님이 " + result[i].second);
	}
    return answer;
}