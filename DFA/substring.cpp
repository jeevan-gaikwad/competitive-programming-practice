#include<iostream>
#include<vector>
#include<string>

#define FAILED 1

struct Dfa_char {

	char ch;
	int index;
};

struct DFA {

	std::vector<std::vector<int> > dfa_mat; //OR use int** and initialize it later
	std::string pattern;
	int current_dfa_state;

	DFA(std::string str);
	void construct_dfa_for_substring();
	void print_mat();
	bool check_char_with_dfa(char ch);
	bool check_substring(std::string& input);

};

DFA::DFA(std::string str):pattern(str) {
		//initialize DFA matrix
		dfa_mat.resize(str.size());
		for(int i=0 ; i < str.size(); i++) {
			dfa_mat[i].resize(str.size());
		}
}

void DFA::construct_dfa_for_substring() {
	//dfa_mat[0][0] = 1; //hard coded for start state
	int pattern_length = pattern.size();
	int pattern_ptr = 0;
	for(int i=0; i< pattern_length; i++) {
		for(int j=0; j< pattern_length; j++) {
			if(pattern[pattern_ptr] == pattern[j] ) {
				dfa_mat[i][j] = i +1; // to move to the next state
			}else if(pattern[j] == pattern[0]) {
				dfa_mat[i][j] = 1; //to come back to state 1
			}
		}
		pattern_ptr++;
	}

}

void DFA::print_mat() {
	std::cout<<"  ";
	for(int i=0; i< pattern.size(); i++) {
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	for(int i=0; i<pattern.size(); i++) {
		std::cout<<i<<" ";
		for(int j=0; j<pattern.size(); j++) {
			std::cout<<dfa_mat[i][j]<<" "; 
		}
		std::cout<<std::endl;
	}
}

bool DFA::check_char_with_dfa(char ch) {
	size_t index = 	pattern.find(ch, 0); //start from 0
	if( index != std::string::npos) { //char is present in the expected pattern
		//lets check with DFA
		current_dfa_state = dfa_mat[current_dfa_state][index];				//VERY IMP STATEMENT
		if(current_dfa_state == pattern.size()) { //complete pattern found
			return true;
		}
		
	}else {
		return false;
	}
}

bool DFA::check_substring(std::string& input) {

	int pattern_pointer=0;
	current_dfa_state = 0; //put DFA in start state before we begin
	for(int i=0; i < input.size(); i++) {
		bool is_found = check_char_with_dfa(input[i]);
		if(is_found) {
			std::cout<<"String ACCEPTED"<<std::endl;
			return true;
		}
	}
	std::cout<<"String REJECTED"<<std::endl;
	return false;
}

int main(void) {

	DFA dfa1("gaikwad");
	dfa1.construct_dfa_for_substring();
	dfa1.print_mat();
	std::string input1("this is gggaikwadd family");
	dfa1.check_substring(input1);

	DFA dfa2("aaapa");
	dfa2.construct_dfa_for_substring();
	dfa2.print_mat();
	std::string input2("sample string aapapa test");
	dfa2.check_substring(input2);

	return 0;
}
