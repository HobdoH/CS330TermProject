/*  Term Project for CS330: Memory Management Simulation Part A
    Language: C++
    Complier: CodeBlocks
    Written November 2019
    Written By Ethan Scime
*/
#include <stdio.h>    //
#include <stdlib.h>   //
#include <iostream>   // Standard libraries I use in projects
#include <time.h>     // Used for getting random numbers every time with rand()
#include <queue>      // Used for storing work numbers if the go into queues

using namespace std;

void printQueue(queue<int> q) // Created this to print a queue without popping entire the queue
{
    while(!q.empty()) //while the queue is not empty a while loop happens
    {
        cout << " "<< q.front();    //Used to print queue
        q.pop();                    //Pops the values that aren't needed to the queue can be displayed
    }
    cout << endl;                   //Ends the line
}

int main()
{
    queue<int> queueA;                      //
    queue<int> queueB;                      //
    queue<int> queueC;                      //Initializing the queues used in the code
    int partA=0; int partB=0; int partC=0;  //Initializing Integers for storage
    int randomNum=0;                        //Initializing the value that will store the random number or I
    int Ajob=0, Bjob=0, Cjob=0;             //Initializing Counts for jobs completed
    srand(54);                              //Setting seed for random values from rand. 54 Can be changed to anything

    for(int i=1;i<101;i++)                  //Used for the problem of generating 100 iterations of random numbers(starts at 1 and ends at 101 due to 0 modulo 5 is 0 and caused errors)
    {
        randomNum = rand() % 200;           //Generates random number
        if(randomNum <= 49 && randomNum>=0) //If statements used with context from problem with random number being I, this being the 0-49 for Class Jobs and entering queues
        {                                         //        ^
            if(randomNum <= 25 && randomNum>=0)  //Same as above
            {
                queueA.push(randomNum);          //Pushes I into the back of the queue A for A class jobs
                partA = 1;                       //Signals that partition A is full

            }
            if(randomNum >= 26 && randomNum <= 39)  //Same if statement for if I is in-between two numbers
            {
                queueB.push(randomNum);         //Pushes I into the back of the queue B for B class jobs
                partB = 1;                      //Signals that partition B is full
            }

            if(randomNum >= 40 && randomNum <= 49) //Same if statement for if I is in-between two numbers to represent class C jobs entering queues
            {
                queueC.push(randomNum);         //Pushes I into the back of the queue C for C class jobs
                partC=1;                        //Signals that partition C is full
            }
        }
        if(randomNum>=50 && randomNum<=100)     //This if statement if for the range of 50-100 and is used for determining if jobs are completed if Partition is full
            {
                if(randomNum<=75 && randomNum>=50) // If statement used for completing current job in partition B
                {
                    if(!queueA.empty())            //Checking if the queue is not empty so no errors occur
                    {
                        queueA.pop();              // Pops the oldest value of the queue A
                        partA=0;                   // Sets partition A to be empty
                        Ajob++;                    // Increments amount of A class jobs completed
                    }

                }
                if(randomNum>=76 && randomNum<=89) // If statement used for completing current job in partition B
                {
                    if(!queueB.empty())            //Checks if queue is empty so no errors occur when emptying(you can't pop an empty queue)
                    {
                        queueB.pop();              // Pops the oldest value in queue B
                        partB=0;                   // Sets partition B to be empty
                        Bjob++;                    // Increments amount of B class jobs completed
                    }

                }
                if(randomNum>=90 && randomNum<=100) // If statement used for completing current job in partition C
                {
                    if(!queueC.empty())             // Checks if queue is empty so no errors occur when emptying(you can't pop an empty queue)
                    {
                        queueC.pop();               // Pops the oldest value in queue C
                        partC=0;                    // Sets partition C to be empty
                        Cjob++;                     // Increments amount of C class jobs completed
                    }

                }
            }

        if(i%5==0)                                  // Used for getting data printed out every 5 time the for loop looped
        {
            cout << "Queue A Status:" ;             // <-|All of the cout's and printQueue's are used for the same purpose
            printQueue(queueA);                     // <-| that is to display the current status of all the queue that needs
            cout << "Queue B Status:";              // <-| to be printed out every fifth iteration
            printQueue(queueB);                     // <-|
            cout << "Queue C Status:";              // <-|
            printQueue(queueC);                     // <-|
            if(partA==0)                                //
            {                                           //  This if else statement is used to let the user know if the Partition A
                cout << "Partition A is empty" << endl; //  is empty or filled
            }                                           //
            else                                        //
            {                                           //
                cout << "Partition A is full" << endl;  //
            }
            if(partB==0)                                //
            {                                           // This if else statement is used to let the user know if the Partition B
                cout << "Partition B is empty" << endl; // is empty or filled
            }                                           //
            else                                        //
            {                                           //
                cout << "Partition B is full" << endl;  //
            }
            if(partC==0)                                //
            {                                           // This if else statement is used to let the user know if the Partition C
                cout << "Partition C is empty" << endl; // is empty or filled
            }                                           //
            else                                        //
            {                                           //
                cout << "Partition C is full" << endl;  //
            }
            cout << "Class A jobs done:" << Ajob << endl;   // These three cout's lets the user know how many jobs has been completed
            cout << "Class B jobs done:" << Bjob << endl;   // of type, A class, B class, and C class
            cout << "Class C jobs done:" << Cjob << endl;   //
        }
    }
    return 0;
}
