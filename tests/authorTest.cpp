//g++.exe -fdiagnostics-color=always -g .\tests\authorTest.cpp .\src\Author.cpp -o C:\Users\danie\Desktop\PROI\projekt\src\main.exe
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../src/Author.h"
#include "catch.h"

SCENARIO("Test")
{

    GIVEN("Example date")
    {
        Author author("Adam", "Mickiewicz");
        Author author2("Julian", "Tuwim");
        Author author3(author);

        SECTION("Copy constructor and comparison")
        {
            THEN("Correct values")
            {
                REQUIRE(author2 != author3);
                REQUIRE(author3 == author);
            }
        }
    }
}