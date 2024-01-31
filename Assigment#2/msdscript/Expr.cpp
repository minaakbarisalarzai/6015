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


int Num::interp() {
    return val;
}


bool Num::has_variable() {
    return false;
}

Expr* Num::subst(const std::string&, Expr* replacement) {
    //Return a new Num object with the same value (val) as the original Num.
    //return this
    return this;
    //return new Num(val);
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


int Add::interp() {
    //The sum of the interpreted values of the left-hand side and the right-hand side
    return lhs->interp() + rhs->interp();
}


bool Add::has_variable() {
    //If either side has a variable
    return lhs->has_variable() || rhs->has_variable();
}


Expr* Add::subst(const std::string& varName, Expr* replacement) {
    // Recursively substitute in the left and right operands
    //The lhs and rhs operands of the new Add expression are the results of substituting the variable (varName) with the replacement expression (replacement) in the original operands
    
    return new Add(lhs->subst(varName, replacement), rhs->subst(varName, replacement));
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

int Mult::interp() {
    //The product of the interpreted values of the left-hand side and the right-hand side
    return lhs->interp() * rhs->interp();
}

bool Mult::has_variable() {
    //Return if either side has a variable
    return lhs->has_variable() || rhs->has_variable();
}


Expr* Mult::subst(const std::string& varName, Expr* replacement) {
    // Recursively substitute in the left and right operands
    //The lhs and rhs operands of the new Mult expression are the results of substituting the variable (varName) with the replacement expression (replacement) in the original operands
    return new Mult(lhs->subst(varName, replacement), rhs->subst(varName, replacement));
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


int Variable::interp() {
    // Throws a runtime error
    throw std::runtime_error("No value for variable");
}

bool Variable::has_variable() {
    //Always true
    return true;
}

Expr* Variable::subst(const std::string& varName, Expr* replacement) {
    if (name == varName) {
        // If the variable name matches the specified variable name, return the replacement expression
        return replacement;
    } else {
        // If the variable name does not match, create a new Variable expression with the same name
        //Return this
        return this;
        //return new Variable(name);
    }
}

//  ============================= END ==========================  //
