// Include the Catch header
#include "catch.h"

// Include the header file with your classes
#include "Expr.hpp"

//  ========================== Add Tests =======================  //

TEST_CASE("Add class equals method", "[Add]") {
    // Test case 1: Adding two equal Num instances should be equal
    CHECK((new Add(new Num(2), new Num(3)))->equals(new Add(new Num(2), new Num(3))) == true);

    // Test case 2: Adding two different Num instances should not be equal
    CHECK_FALSE((new Add(new Num(5), new Num(10)))->equals(new Add(new Num(2), new Num(3))));

    // Test case 3: Adding two equal Variable instances should be equal
    CHECK((new Add(new Variable("x"), new Variable("y")))->equals(new Add(new Variable("x"), new Variable("y"))) == true);

    // Test case 4: Adding two different Variable instances should not be equal
    CHECK_FALSE((new Add(new Variable("a"), new Variable("b")))->equals(new Add(new Variable("x"), new Variable("y"))));

    // Test case 5: Adding a Num and a Variable instance should not be equal
    CHECK_FALSE((new Add(new Num(2), new Variable("x")))->equals(new Add(new Variable("x"), new Num(2))));

    // Test case 6: Adding two Add expressions with the same operands should be equal
    CHECK((new Add(new Add(new Num(2), new Num(3)), new Num(4)))->equals(new Add(new Add(new Num(2), new Num(3)), new Num(4))) == true);

    // Test case 7: Adding two Add expressions with different operand order should not be equal
    CHECK_FALSE((new Add(new Num(2), new Add(new Num(3), new Num(4))))->equals(new Add(new Add(new Num(3), new Num(4)), new Num(2))));
}

//  ========================== Mult Tests =======================  //

TEST_CASE("Mult class equals method", "[Mult]") {
    // Test case 1: Multiplying two equal Num instances should be equal
    Expr* num1 = new Num(2);
    Expr* num2 = new Num(3);
    Expr* mult1 = new Mult(num1, num2);
    CHECK(mult1->equals(mult1));

    // Clean up memory
    delete num1;
    delete num2;
    delete mult1;

    // Test case 2: Multiplying two different Num instances should  be equal
    num1 = new Num(5);
    num2 = new Num(10);
    mult1 = new Mult(num1, num2);
    CHECK(mult1->equals(mult1));

    // Clean up memory
    delete num1;
    delete num2;
    delete mult1;

    // Test case 3: Multiplying two equal Variable instances should be equal
    Expr* var1 = new Variable("x");
    Expr* var2 = new Variable("y");
    Expr* mult2 = new Mult(var1, var2);
    CHECK(mult2->equals(mult2));

    // Clean up memory
    delete var1;
    delete var2;
    delete mult2;

    // Test case 4: Multiplying two different Variable instances
    var1 = new Variable("a");
    var2 = new Variable("b");
    mult2 = new Mult(var1, var2);
    CHECK(mult2->equals(mult2));

    // Clean up memory
    delete var1;
    delete var2;
    delete mult2;

    // Test case 5: Multiplying a Num and a Variable
    num1 = new Num(2);
    var1 = new Variable("x");
    mult1 = new Mult(num1, var1);
    CHECK(mult1->equals(mult1));

    // Clean up memory
    delete num1;
    delete var1;
    delete mult1;

}

//  ========================== Num Tests =======================  //

// Define test cases for the equals method in the Num class
TEST_CASE("Num class equals method", "[Num]") {
    // Test case 1: Comparing two equal Num instances should be equal
    Expr* num1 = new Num(5);
    Expr* num2 = new Num(5);
    CHECK(num1->equals(num2));

    // Clean up memory
    delete num1;
    delete num2;

    // Test case 2: Comparing two different Num instances should not be equal
    num1 = new Num(10);
    num2 = new Num(20);
    CHECK_FALSE(num1->equals(num2));

    // Clean up memory
    delete num1;
    delete num2;

    // Test case 3: Comparing a Num instance with a Variable instance should not be equal
    num1 = new Num(2);
    Expr* var1 = new Variable("x");
    CHECK_FALSE(num1->equals(var1));

    // Clean up memory
    delete num1;
    delete var1;

    // Test case 4: Comparing a Num instance with a different Num instance should not be equal
    num1 = new Num(5);
    Expr* num3 = new Num(10);
    CHECK_FALSE(num1->equals(num3));

    // Clean up memory
    delete num1;
    delete num3;

    // Test case 5: Comparing a Num instance with a null pointer should not be equal
    num1 = new Num(7);
    CHECK_FALSE(num1->equals(nullptr));

    // Clean up memory
    delete num1;
}

//  ======================== Variable Tests =====================  //

TEST_CASE("Variable class equals method", "[Variable]") {
    // Test case 1: Comparing two equal Variable instances should be equal
    Expr* var1 = new Variable("x");
    Expr* var2 = new Variable("x");
    CHECK(var1->equals(var2));

    // Clean up memory
    delete var1;
    delete var2;

    // Test case 2: Comparing two different Variable instances should not be equal
    var1 = new Variable("a");
    var2 = new Variable("b");
    CHECK_FALSE(var1->equals(var2));

    // Clean up memory
    delete var1;
    delete var2;

    // Test case 3: Comparing a Variable instance with a Num instance should not be equal
    var1 = new Variable("x");
    Expr* num1 = new Num(5);
    CHECK_FALSE(var1->equals(num1));

    // Clean up memory
    delete var1;
    delete num1;

    // Test case 4: Comparing a Variable instance with a different Variable instance should not be equal
    var1 = new Variable("y");
    Expr* var3 = new Variable("z");
    CHECK_FALSE(var1->equals(var3));

    // Clean up memory
    delete var1;
    delete var3;

    // Test case 5: Comparing a Variable instance with a null pointer should not be equal
    var1 = new Variable("x");
    CHECK_FALSE(var1->equals(nullptr));

    // Clean up memory
    delete var1;
}
