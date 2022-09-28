// treats_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// #include that dos the random 
#include <iostream>
#include <thread>

using namespace std;

static bool done = false;

void thetimer(){
    using namespace std::literals::chrono_literals;
    cout << "start" << endl;
    while (!done)
    {
        cout << "question...." << endl;
        std::this_thread::sleep_for(5s);
    }
}


int main(){
    

    thread questions(thetimer);

    std::cin.get();
    done = true;

    questions.join();

    std::cin.get();

}

void einumeraterakatreat() {
    // 5 sec timer 
    // if question is ansertt new question end start agen
    // question good add poins else do noting 
    // if timer is 0 change question 
    // make a input menerger 
}


