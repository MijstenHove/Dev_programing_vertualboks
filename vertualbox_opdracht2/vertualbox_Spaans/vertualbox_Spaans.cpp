#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include<string>
#include<list>
#include<mutex>


using namespace std;


std::chrono::system_clock::time_point startdate;
std::mutex* consoleSamaphore;

void printElapsedTime(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end)
{
    std::chrono::duration<double> elapsedtime = end - start;
    std::cout << "elapsed time" << elapsedtime.count() << "seconds" << std::endl;
}


void count(int maxCounter)
{
    for (int i = 0; i < maxCounter; i++)
    {
        std::cout << i;
    }

}

int main()
{
 
    std::chrono::system_clock::time_point startdate = std::chrono::system_clock::now();
    consoleSamaphore->lock();
    consoleSamaphore = new std::mutex();
    consoleSamaphore->unlock();

    int totalcount =  1000 * 1000 * 1000;

    std::thread* countrel = new std::thread(count, totalcount);
    std::thread* countrel2 = new std::thread(count, totalcount);
    std::thread* countrel3 = new std::thread(count, totalcount);

    countrel->join();
    printElapsedTime(startdate, std::chrono::system_clock::now());
    countrel2->join();
    printElapsedTime(startdate, std::chrono::system_clock::now());
    countrel3->join();
    printElapsedTime(startdate, std::chrono::system_clock::now());


    //std::chrono::system_clock::time_point enddate = std::chrono::system_clock::now();
    //std::chrono::duration<double> elapsedtime = enddate - startdate;
    //std::cout << "elapsed time" << elapsedtime.count() << "seconds" << std::endl;
}
