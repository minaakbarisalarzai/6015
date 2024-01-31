#ifndef Expr_hpp
#define Expr_hpp

//  ========================== EXPR CLASS =======================  //

class Expr {
public:
    virtual bool equals(Expr *e) = 0;
    virtual ~Expr();
    virtual int interp()=0;
    virtual bool has_variable()=0;
    virtual Expr* subst(const std::string& varName, Expr* replacement)=0;
};

//  ========================== NUM CLASS =======================  //

class Num : public Expr {
public:
    int val;
    // Constructor
    Num(int val);
    // Declaration of equals method
    virtual bool equals(Expr *e) override;
    // Declaration of the interp method
    virtual int interp() override;
    virtual bool has_variable() override;
    virtual Expr* subst(const std::string& varName, Expr* replacement) override;
};

//  ========================== ADD CLASS =======================  //

class Add : public Expr {
public:
    Expr *lhs;
    Expr *rhs;
    // Constructor
    Add(Expr *lhs, Expr *rhs);
    virtual bool equals(Expr* e) override ;
    virtual int interp() override;
    virtual bool has_variable() override;
    virtual Expr* subst(const std::string& varName, Expr* replacement) override;
};

//  ========================== MULT CLASS =======================  //

class Mult : public Expr {
public:
    Expr *lhs;
    Expr *rhs;
    // Constructor
    Mult(Expr *lhs, Expr *rhs);
    // Implement the equals function
    virtual bool equals(Expr* e) override;
    virtual int interp() override;
    virtual bool has_variable() override;
    virtual Expr* subst(const std::string& varName, Expr* replacement) override;
    
};

//  ======================= Variable CLASS =====================  //

class Variable : public Expr {
public:
    std::string name;
    // Constructor
    Variable(const std::string name);
    // Implementation of equals method
    virtual bool equals(Expr *e) override;
    virtual int interp() override;
    virtual bool has_variable() override;
    virtual Expr* subst(const std::string& varName, Expr* replacement) override;
};
#endif
//  ========================== THE END =======================  //
