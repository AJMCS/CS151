/*
AbstractSeq.h – Defines the AbstractSeq class.
Author: AJ McDaniel
*/

#ifndef ABSTRACTSEQ_H
#define ABSTRACTSEQ_H

class AbstractSeq {
public:
    virtual int fun(int value) = 0;  // Pure virtual function to generate sequence terms
    void printSeq(int low, int high); // Prints sequence terms from low to high
    int sumSeq(int low, int high);   // Returns sum of sequence terms from low to high
};

#endif 