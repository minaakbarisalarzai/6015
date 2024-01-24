#include "catch.h"
#include "Expr.hpp"

//  ========================== EXPR CLASS =======================  //

//Destructor - will be implemented in the future
Expr::~Expr() {
}

//  ========================== NUM CLASS =======================  //

//Constructor
Num::Num(int val) {
    this->val = val;
}

// Implementation of equals method in Num class
bool Num::equals(Expr *e) {
    if (Num *numOther = dynamic_cast<Num*>(e)) {
        // Check if the other expression is a Num and the values are equal
        return (numOther != nullptr) && (val == numOther->val);
    } else {
        // When the other expression is not a Num
        return false;
    }
}


//  ========================== ADD CLASS =======================  //

// Constructor implementation
Add::Add(Expr *lhs, Expr *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

// Implementation of equals method in Add class
bool Add::equals(Expr* e){
    //Match the types/classses
    if (const Add* otherAdd = dynamic_cast<const Add*>(e)) {
        //recursively compares other left hand side with current left had side similarly for right hand side
        return lhs->equals(otherAdd->lhs) && rhs->equals(otherAdd->rhs);
    }
    return false;
}

//  ========================== MULT CLASS =======================  //

// Constructor implementation
Mult::Mult(Expr *lhs, Expr *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

// Implementation of equals method in Mult class
bool Mult::equals(Expr* e) {
    //Change the type/class
    if (const Mult* otherMult = dynamic_cast<Mult*>(e)) {
        return lhs->equals(otherMult->lhs) && rhs->equals
        (otherMult->rhs);
    }
    return false;
}

//  ======================== Variable CLASS =====================  //

// Constructor implementation
Variable::Variable(const std::string name) : name(name) {}

// Implementation of equals method in Variable class
bool Variable::equals(Expr *e) {
    if (Variable *other = dynamic_cast<Variable*>(e)) {
        // Check if names are equal
        return name == other->name;
    }
    return false;
}

//  ============================= END ==========================  //
