#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <list>
#include <mutex>

#pragma region Functions Declaration Header

void PrintElapsedTime(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end);
void Count(int maxCounter);
void Example01();
void Example02();
void Example03();
void Example04();
void Example05();
void Example06();

#pragma endregion

#pragma region Global Variables

std::chrono::system_clock::time_point startDate; //Saves the time when the program starts

//Is recommended and important use always the mutex objects, using pointers o passing by reference the copy
std::mutex* consoleMutex; //mutex used for prevent the console solapation

#pragma endregion
class Inputlistener
{
private:
    static Inputlistener* instance;
    Inputlistener()
    {
    }

public:
    static Inputlistener* Instance()
    {
        if (instance == nullptr)
        {
            instance = new Inputlistener();
        }

        return instance;
    }

    void printhallo()
    {
        std::cout << "hallo " << std::endl;
    }
};
Inputlistener* Inputlistener::instance = nullptr;


int main()
{
    Inputlistener::Instance();





    //They can be initialized in the definition, but I prefer to initialize them here
    startDate = std::chrono::system_clock::now();
    consoleMutex = new std::mutex();

    int exampleUsed = 6;//Change this variable for use diferents examples

    switch (exampleUsed)
    {
    case 1:
        Example01();
        break;
    case 2:
        Example02();
        break;
    case 3:
        Example03();
        break;
    case 4:
        Example04();
        break;
    case 5:
        Example05();
        break;
    case 6:
        Example06();
        break;
    default:
        break;
    }

    std::cout << "Exaple 0" << exampleUsed << " finished" << std::endl;
    std::string text = "";
    std::getline(std::cin, text);
}

/// <summary>
/// This function receive two time points and calculate and print difference in seconds using.
/// </summary>
/// <param name="start"></param>
/// <param name="end"></param>
void PrintElapsedTime(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end)
{
    std::chrono::duration<double> elapsedTime = end - start;
    consoleMutex->lock();
    std::cout << "Elapsed time: " << elapsedTime.count() << " seconds" << std::endl;
    consoleMutex->unlock();
}

/// <summary>
/// This function counts until the indicated number is reached.
/// </summary>
/// <param name="maxCounter"></param>
void Count(int maxCounter)
{
    //std::this_thread::sleep_for(std::chrono::seconds(1)); alternative option

    for (int i = 0; i < maxCounter; i++)
    {

    }

    std::chrono::system_clock::time_point endDate = std::chrono::system_clock::now();
    PrintElapsedTime(startDate, endDate);
}

//Very Important!!! when you use Join function, the code don't block until you call Join for all Threads previously created in parent thread
//You can see this using Example01 and Example02

/// <summary>
/// In this example create 3 threads in a row, the code only stop when main thread enter in the 3 threads.
/// </summary>
void Example01()
{
    int totalCount = 1000 * 1000 * 10000;
    std::thread* Counter1 = new std::thread(Count, totalCount);
    std::thread* Counter2 = new std::thread(Count, totalCount);
    std::thread* Counter3 = new std::thread(Count, totalCount);

    Counter1->join();
    Counter2->join();
    Counter3->join();

    Count(totalCount);
}

/// <summary>
/// In this example create 3 threads but I create and Use the first and wait for finish, and create the other two.
/// </summary>
void Example02()
{
    int totalCount = 1000 * 1000 * 10000;
    std::thread* Counter1 = new std::thread(Count, totalCount);

    Counter1->join();
    std::thread* Counter2 = new std::thread(Count, totalCount);
    std::thread* Counter3 = new std::thread(Count, totalCount);
    Counter2->join();
    Counter3->join();

    Count(totalCount);
}


/// <summary>
/// In this example create 3 threads in a row, the code don't stop because y use Detach.
/// </summary>
void Example03()
{
    int totalCount = 1000 * 1000 * 10000;
    std::thread* Counter1 = new std::thread(Count, totalCount);
    std::thread* Counter2 = new std::thread(Count, totalCount);
    std::thread* Counter3 = new std::thread(Count, totalCount);

    Counter1->detach();
    Counter2->detach();
    Counter3->detach();

    Count(totalCount);
}


/// <summary>
/// This is a version of Example02 but using a list and use one by one
/// </summary>
void Example04()
{
    std::list<std::thread*>* threads = new std::list<std::thread*>();

    int totalCount = 1000 * 1000;

    for (int i = 0; i < 3; i++)
    {
        std::thread* counterThread = new std::thread(Count, totalCount);
        threads->push_back(counterThread);
        counterThread->join();
    }

    Count(totalCount);
}

/// <summary>
/// This is a version of Example03 but using a list and use one by one
/// </summary>
void Example05()
{
    std::list<std::thread*>* threads = new std::list<std::thread*>();

    int totalCount = 1000 * 1000;

    for (int i = 0; i < 3; i++)
    {
        std::thread* counterThread = new std::thread(Count, totalCount);
        threads->push_back(counterThread);
        counterThread->detach();
    }

    Count(totalCount);
}

/// <summary>
/// In this example first of all I check the max concurrency of my CPU
/// Next y create this quantity of threads + extra number, and execute all with join
/// </summary>
void Example06()
{
    unsigned int maxThreads = std::thread::hardware_concurrency();
    std::cout << maxThreads << " concurrent threads are supported." << std::endl;

    unsigned int extraThreads = 2;

    std::list<std::thread*>* threads = new std::list<std::thread*>();

    int totalCount = 1000 * 1000 + 1000000000;

    for (int i = 0; i < maxThreads + extraThreads; i++)
    {
        std::thread* counterThread = new std::thread(Count, totalCount);
        threads->push_back(counterThread);
    }

    for (std::thread* t : *threads)
    {
        t->join();
    }

    Count(totalCount);
}