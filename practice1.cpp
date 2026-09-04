#include <iostream>
#include <vector>

using namespace std;

// a b c d 
// 0 1 2 3

int main(){
    vector<int> quizScores = {};
    quizScores.push_back(78);
    quizScores.push_back(85);
    quizScores.push_back(91);

    quizScores.insert(quizScores.begin(), 72);

    //insert 88 before 91
    int quizScoresSize = quizScores.size();
    quizScores.insert(quizScores.begin() + quizScoresSize - 1, 88);

}