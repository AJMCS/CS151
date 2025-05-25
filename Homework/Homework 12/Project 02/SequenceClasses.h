/*
SequenceClasses.h – Defines EvenSequence and FactorialSequence subclasses.
Author: AJ McDaniel
*/

#ifndef SEQUENCECLASSES_H
#define SEQUENCECLASSES_H

#include "AbstractSeq.h"

class EvenSequence : public AbstractSeq {
public:
    int fun(int value) override;  // Returns 2 * value
};

class FactorialSequence : public AbstractSeq {
public:
    int fun(int value) override;  // Returns value! (factorial)
};

#endif 