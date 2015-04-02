#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <locale>
#include <string>
using namespace std;
map<char,char> mapping;


//First do a quick run to find simple cases
void quickFind(map<int,string> & cipher, map<size_t,vector<string> >  & dict, map<int,string> & deciphered){
	cout << "Starting quickfind..." << endl;
	map<int,string>::iterator it;
	for(it = cipher.begin(); it != cipher.end(); ++it){
		cout << "Current word: " << it->second << endl;
		if(dict[it->second.length()].size() == 1){
			cout << "Only one possibility" << endl;
			for(size_t i = 0; i < it->second.length(); i++){
				mapping[it->second[i]] = dict[it->second.length()][0][i];
			}
		} else {
			cout << "Many possibilities" << endl;
			map<char,vector<int> > freq;
			bool repeat = false;
			for(size_t i = 0; i < it->second.length(); i++){
				freq[it->second[i]].push_back(i);
				if(freq[it->second[i]].size() > 1){
					repeat = true;
				}
			}
			cout << "Finished getting letter frequencies..." << endl;
			if(repeat){
				map<char,vector<int> >::iterator f_it; 
				vector<string>::iterator d_it;
				vector<int>::iterator char_pos;
				char * prev;
				vector<string> matches;
				for(d_it = dict[it->second.length()].begin();d_it != dict[it->second.length()].end(); ++d_it){
					bool match = true;
					for(f_it = freq.begin(); f_it != freq.end() && match; ++f_it){
						prev = NULL;
						for(char_pos = f_it->second.begin(); char_pos != f_it->second.end() && match; ++char_pos){
							if(prev == NULL){
								prev = &((*d_it)[*char_pos]);
							} else {
								match = *prev == (*d_it)[*char_pos];
							}
						}
					}
					if(match){
						matches.push_back(*d_it);
					}
				}
				if(matches.size() == 1){
					for(size_t i = 0; i < it->second.length(); i++){
						mapping[it->second[i]] = matches[0][i];
					}
					cout << "Match was: " << matches[0] << endl;
					deciphered[it->first] = matches[0];
				}
			}
		}
	}
}

void substitute(map<int,string> & cipher, map<size_t,vector<string> >  & dict, map<int,string> & deciphered){
	int loops = 30;
	while(loops-- && (deciphered.size() != cipher.size())){
		for(map<int,string>::iterator it = cipher.begin(); it != cipher.end(); ++it){
			cout << "Current word: " << it->first << " -> " <<  it->second << endl;
			if(deciphered.find(it->first) != deciphered.end()){
				cout << "already decyphered: " << deciphered[it->first] << endl;
				continue;
			}
			vector<string> matches;
			for(vector<string>::iterator s_it = dict[it->second.length()].begin(); s_it != dict[it->second.length()].end(); ++s_it){
				bool match = true;
				for(size_t i = 0; i < it->second.length() && match; i++){
					if(mapping.find(it->second[i]) != mapping.end()) {
						match = mapping[(it->second)[i]] == (*s_it)[i];
					}
				}
				if(match){
					matches.push_back(*s_it);
				}
			}
			if(matches.size() == 1){
					for(size_t i = 0; i < it->second.length(); i++){
						mapping[it->second[i]] = matches[0][i];
					}
					cout << "Match was: " << matches[0] << endl;
					deciphered[it->first] = matches[0];
			} else {
				cout << "Had more matches..." << endl;
				for(vector<string>::iterator p_it = matches.begin(); p_it != matches.end(); ++p_it){
				    cout << *p_it << endl;
				}
			}
		}
	}
}


int main() {
	map<int,string> cipher;
	map<int,string> deciphered;
    string str;
    ifstream myfile;
    map<size_t,vector<string> > dict;
    map<size_t,map<int,map<char,int> > > dict_freq;
    myfile.open("dictionary.lst");
    //build dict
    if (myfile.is_open()) {
        while ( getline (myfile,str) ) {
			std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            dict[str.length()].push_back(str);
            for(std::string::size_type i = 0; i < str.size(); ++i) {
				dict_freq[str.length()][i][str[i]]++;
			}
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }
    int i = 0;
    while(cin >> str) {
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        cipher[i] = str;
        i++;
    }
    quickFind(cipher,dict,deciphered);
    substitute(cipher,dict,deciphered);
    map<char,char>::iterator map_it;
    for(map_it = mapping.begin(); map_it != mapping.end();++map_it){
		cout << map_it->first << " => " << map_it->second << endl;
	}
	for(map<int,string>::iterator dec_it = deciphered.begin(); dec_it != deciphered.end(); ++dec_it){
		cout << dec_it->second << " ";
	}
    return 0;
}
