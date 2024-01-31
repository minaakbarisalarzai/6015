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

// =====================   INTERP TESTS    ======================== //
                        //// NUM ClASS ////
///
TEST_CASE("Num Interp Tests") {
    // Test case 1: Basic test with a positive number
    SECTION("Positive number") {
        Num numObj1(42);
        CHECK(numObj1.interp() == 42);
    }

    // Test case 2: Basic test with a negative number
    SECTION("Negative number") {
        Num numObj2(-10);
        CHECK(numObj2.interp() == -10);
    }

    // Test case 3: Zero
    SECTION("Zero") {
        Num numObj3(0);
        CHECK(numObj3.interp() == 0);
    }

    // Test case 4: Large positive number
    SECTION("Large positive number") {
        Num numObj4(1000);
        CHECK(numObj4.interp() == 1000);
    }

    // Test case 5: Large negative number
    SECTION("Large negative number") {
        Num numObj5(-500);
        CHECK(numObj5.interp() == -500);
    }

    // Test case 6: Edge case with the minimum integer value
    SECTION("Minimum integer value") {
        Num numObj6(INT_MIN);
        CHECK(numObj6.interp() == INT_MIN);
    }

    // Test case 7: Edge case with the maximum integer value
    SECTION("Maximum integer value") {
        Num numObj7(INT_MAX);
        CHECK(numObj7.interp() == INT_MAX);
    }
}

                         //// ADD ClASS ////

//  ====================== Add Interp Tests ====================  //

TEST_CASE("Add class interp method", "[Add]") {
    // Test case 1: Adding two Num instances
    Expr* num1 = new Num(2);
    Expr* num2 = new Num(3);
    Expr* add1 = new Add(num1, num2);
    CHECK(add1->interp() == 5);

    // Clean up memory
    delete num1;
    delete num2;
    delete add1;

    // Test case 2: Adding two Variable instances (throws exception)
    Expr* var1 = new Variable("x");
    Expr* var2 = new Variable("y");
    Expr* add2 = new Add(var1, var2);
    CHECK_THROWS_AS(add2->interp(), std::runtime_error);

    // Clean up memory
    delete var1;
    delete var2;
    delete add2;

    // Test case 3: Adding a Num and a Variable (throws exception)
    num1 = new Num(5);
    var1 = new Variable("x");
    Expr* add3 = new Add(num1, var1);
    CHECK_THROWS_AS(add3->interp(), std::runtime_error);

    // Clean up memory
    delete num1;
    delete var1;
    delete add3;

    // Test case 4: Adding two Add expressions
    Expr* add4 = new Add(new Num(2), new Add(new Num(3), new Num(4)));
    CHECK(add4->interp() == 9);

    // Clean up memory
    delete add4;
    
    // Test case 5: Adding zeros
    Expr* add5 = new Add(new Num(0), new Add(new Num(0), new Num(0)));
    CHECK(add5->interp() == 0);
}

                           //// MULT ClASS ////

//  ====================== Mult Interp Tests ====================  //

// Define test cases for the interp method in the Mult class
TEST_CASE("Mult class interp method", "[MultInterp]") {
    // Test case 1: Multiplying two Num instances with positive values
    Expr* num1 = new Num(2);
    Expr* num2 = new Num(3);
    Expr* mult1 = new Mult(num1, num2);
    CHECK(mult1->interp() == 6);

    // Clean up memory
    delete num1;
    delete num2;
    delete mult1;

    // Test case 2: Multiplying two Num instances with negative values
    num1 = new Num(-2);
    num2 = new Num(-3);
    mult1 = new Mult(num1, num2);
    CHECK(mult1->interp() == 6);

    // Clean up memory
    delete num1;
    delete num2;
    delete mult1;

    // Test case 3: Multiplying two Mult expressions with positive values
    Expr* mult4 = new Mult(new Num(2), new Mult(new Num(3), new Num(4)));
    CHECK(mult4->interp() == 24);

    // Clean up memory
    delete mult4;
    
        //Test case 4: variables
        Expr* var1 = new Variable("x");
        Expr* var2 = new Variable("y");
        Mult mult2(var1, var2);
        CHECK_THROWS_AS(mult2.interp(), std::runtime_error);
        // Clean up memory
        delete var1;
        delete var2;
    
        //Test case 5: num +var
        Expr* num5 = new Num(5);
        Expr* var5 = new Variable("x");
        Mult mult3(num5, var5);

        CHECK_THROWS_AS(mult3.interp(), std::runtime_error);

        // Clean up memory
        delete num5;
        delete var5;
}

//  ====================== Variable Interp Tests ====================  //

// Test case: Interpreting a variable without a value should throw an exception
TEST_CASE("Variable interp - No Value") {
    Variable var("x");
    
    CHECK_THROWS_AS(var.interp(), std::runtime_error);
}

// Test case: Checking if a Variable has a variable (always true)
TEST_CASE("Variable has_variable - Always True") {
    Variable var("x");

    CHECK(var.has_variable() == true);
}

//  =================== Mult hasVariable Tests ==================  //
// Test case: Multiplying two Num instances (no variable)
TEST_CASE("Mult has_variable - Two Num Instances (No Variable)") {
    Expr* num1 = new Num(5);
    Expr* num2 = new Num(10);
    Expr* mult1 = new Mult(num1, num2);

    CHECK(mult1->has_variable() == false);

    // Clean up memory
    delete num1;
    delete num2;
    delete mult1;
}

// Test case: Multiplying two Variable instances (has variable)
TEST_CASE("Mult has_variable - Two Variable Instances (Has Variable)") {
    Expr* var1 = new Variable("x");
    Expr* var2 = new Variable("y");
    Expr* mult2 = new Mult(var1, var2);

    CHECK(mult2->has_variable() == true);

    // Clean up memory
    delete var1;
    delete var2;
    delete mult2;
}

// Test case: Multiplying a Num and a Variable (has variable)
TEST_CASE("Mult has_variable - Num and Variable (Has Variable)") {
    Expr* num1 = new Num(2);
    Expr* var1 = new Variable("x");
    Expr* mult3 = new Mult(num1, var1);

    CHECK(mult3->has_variable() == true);

    // Clean up memory
    delete num1;
    delete var1;
    delete mult3;
}

// Test case: Multiplying two Mult expressions with variables
TEST_CASE("Mult has_variable - Two Mult Expressions (Has Variable)") {
    Expr* mult4 = new Mult(new Variable("x"), new Mult(new Variable("y"), new Variable("z")));

    CHECK(mult4->has_variable() == true);

    // Clean up memory
    delete mult4;
}

// Test case: Multiplying a Num and a Mult expression (has variable)
TEST_CASE("Mult has_variable - Num and Mult Expression (Has Variable)") {
    Expr* num2 = new Num(3);
    Expr* mult5 = new Mult(num2, new Mult(new Variable("a"), new Variable("b")));

    CHECK(mult5->has_variable() == true);

    // Clean up memory
    delete num2;
    delete mult5;
}

// Test case: Adding two Num instances (no variable)
TEST_CASE("Add has_variable - Two Num Instances (No Variable)") {
    Expr* num1 = new Num(5);
    Expr* num2 = new Num(10);
    Expr* add1 = new Add(num1, num2);

    CHECK(add1->has_variable() == false);

    // Clean up memory
    delete num1;
    delete num2;
    delete add1;
}

// Test case: Adding two Variable instances (has variable)
TEST_CASE("Add has_variable - Two Variable Instances (Has Variable)") {
    Expr* var1 = new Variable("x");
    Expr* var2 = new Variable("y");
    Expr* add2 = new Add(var1, var2);

    CHECK(add2->has_variable() == true);

    // Clean up memory
    delete var1;
    delete var2;
    delete add2;
}

// Test case: Adding a Num and a Variable (has variable)
TEST_CASE("Add has_variable - Num and Variable (Has Variable)") {
    Expr* num1 = new Num(2);
    Expr* var1 = new Variable("x");
    Expr* add3 = new Add(num1, var1);

    CHECK(add3->has_variable() == true);

    // Clean up memory
    delete num1;
    delete var1;
    delete add3;
}

// Test case: Adding two Add expressions with variables
TEST_CASE("Add has_variable - Two Add Expressions (Has Variable)") {
    Expr* add4 = new Add(new Variable("a"), new Add(new Variable("b"), new Variable("c")));

    CHECK(add4->has_variable() == true);

    // Clean up memory
    delete add4;
}

//  =================== Num HasVariable Tests ==================  //

// Test case: Adding a Num and an Add expression (has variable)
TEST_CASE("Add has_variable - Num and Add Expression (Has Variable)") {
    Expr* num2 = new Num(3);
    Expr* add5 = new Add(num2, new Add(new Variable("x"), new Variable("y")));

    CHECK(add5->has_variable() == true);

    // Clean up memory
    delete num2;
    delete add5;
}

//  ==================== Num hasVariable Tests ==================  //

TEST_CASE("Num class has_variable method", "[Num]") {
    // Test case 1: Num instance with a numeric value, should not have a variable
    Num num1(5);
    CHECK_FALSE(num1.has_variable());

    // Test case 2: Num instance with a different numeric value, should not have a variable
    Num num2(10);
    CHECK_FALSE(num2.has_variable());

    // Test case 3: Num instance with zero, should not have a variable
    Num num3(0);
    CHECK_FALSE(num3.has_variable());

    // Test case 4: Num instance with a negative value, should not have a variable
    Num num4(-3);
    CHECK_FALSE(num4.has_variable());

    // Test case 5: Num instance with a decimal value, should not have a variable
    Num num5(3.14);
    CHECK_FALSE(num5.has_variable());
}

//  ====================== Num subst Tests ====================  //

TEST_CASE("Num class subst method", "[Num]") {
    // Test case 1: Substituting with a replacement Num, should return the original Num
    Num num1(5);
    Expr* replacement1 = new Num(10);
    Expr* result1 = num1.subst("x", replacement1);
    REQUIRE(result1 != nullptr);
    CHECK(result1 == &num1);  // Check that the result is the same as the original Num

    // Clean up memory
    delete replacement1;

    // Test case 2: Substituting with a different replacement Num, should return the original Num
    Num num2(7);
    Expr* replacement2 = new Num(3);
    Expr* result2 = num2.subst("y", replacement2);
    REQUIRE(result2 != nullptr);
    CHECK(result2 == &num2);  // Check that the result is the same as the original Num

    // Clean up memory
    delete replacement2;

    // Test case 3: Substituting with a replacement variable, should return the original Num
    Num num3(3);
    Expr* replacement3 = new Variable("z");
    Expr* result3 = num3.subst("z", replacement3);
    REQUIRE(result3 != nullptr);
    CHECK(result3 == &num3);  // Check that the result is the same as the original Num

    // Clean up memory
    delete replacement3;
}

//  ====================== Add subst Tests ====================  //

TEST_CASE("Add class subst method", "[Add]") {
    // Test case 1: Substituting in an Add expression with Num operands
    Expr* num1 = new Num(2);
    Expr* num2 = new Num(3);
    Expr* add1 = new Add(num1, num2);

    Expr* replacement = new Num(5);
    Expr* result1 = add1->subst("x", replacement);

    // The result should be a new Add expression with the substituted Num operands
    REQUIRE(result1 != nullptr);
    CHECK(result1->interp() == 5);  // Check that the value is the sum of substituted Num operands
}

//  ====================== Mult subst Tests ====================  //

TEST_CASE("Mult class subst method", "[Mult]") {
    // Test case 1: Substituting in a Mult expression with Num operands
    Expr* num1 = new Num(2);
    Expr* num2 = new Num(3);
    Expr* mult1 = new Mult(num1, num2);

    Expr* replacement = new Num(6);
    Expr* result1 = mult1->subst("x", replacement);

    // The result should be a new Mult expression with the substituted Num operands
    REQUIRE(result1 != nullptr);
    CHECK(result1->interp() == 6);  // Check that the value is the product of substituted Num operands

    // Clean up memory
    delete num1;
    delete num2;
    delete mult1;
    delete replacement;
    delete result1;
}

//  =================== Variable subst Tests ==================  //

TEST_CASE("Variable class subst method", "[Variable]") {
    // Test case 1: Substituting in a Variable with matching name
    Expr* variable1 = new Variable("x");
    Expr* replacement1 = new Num(5);

    Expr* result7 = variable1->subst("x", replacement1);

    // The result should be the replacement expression
    REQUIRE(result7 != nullptr);
    CHECK(result7->interp() == 5);  // Check that the value is the value of the replacement expression

    // Clean up memory
    delete variable1;
    delete replacement1;

}

// ====================== PROVIDED TESTS ========================= //

TEST_CASE("Provided Tests", "[ProvidedTests]"){
    
    CHECK( (new Mult(new Num(3), new Num(2)))
            ->interp()==6 );
    
    CHECK( (new Add(new Add(new Num(10), new Num(15)),new Add(new Num(20),new Num(20))))
            ->interp()==65);
    
    CHECK( (new Add(new Variable("x"), new Num(1)))->has_variable() == true );
    
    CHECK( (new Mult(new Num(2), new Num(1)))->has_variable() == false );
    
    CHECK( (new Add(new Variable("x"), new Num(7)))
           ->subst("x", new Variable("y"))
          ->equals(new Add(new Variable("y"), new Num(7))) );
    
    CHECK( (new Variable("x"))
           ->subst("x", new Add(new Variable("y"),new Num(7)))
           ->equals(new Add(new Variable("y"),new Num(7))) );
    
}
