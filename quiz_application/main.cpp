#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold a quiz question
struct Question {
    string questionText;
    vector<string> options;
    char correctOption;
};

// Function to display a question and get user input
char askQuestion(const Question& q) {
    cout << q.questionText << endl;
    for (int i = 0; i < q.options.size(); ++i) {
        cout << char('A' + i) << ". " << q.options[i] << endl;
    }
    cout << "Your answer: ";
    char answer;
    cin >> answer;
    return toupper(answer);
}

// Main function to run the quiz
int main() {
    // Sample questions
    vector<Question> quiz = {
        {"What is the capital of France?", {"Paris", "London", "Rome", "Berlin"}, 'A'},
        {"What is 5 + 7?", {"10", "12", "14", "15"}, 'B'},
        {"Which language is used for system programming?", {"Python", "Java", "C++", "JavaScript"}, 'C'}
    };

    cout << "Welcome to the Quiz Application!" << endl;
    int score = 0;

    // Ask each question
    for (const auto& q : quiz) {
        char userAnswer = askQuestion(q);
        if (userAnswer == q.correctOption) {
            cout << "Correct!" << endl;
            ++score;
        } else {
            cout << "Wrong! The correct answer was " << q.correctOption << "." << endl;
        }
        cout << endl;
    }

    // Display final score
    cout << "Quiz completed!" << endl;
    cout << "Your final score is: " << score << "/" << quiz.size() << endl;

    return 0;
}
