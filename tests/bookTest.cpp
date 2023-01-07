//g++.exe -fdiagnostics-color=always -g .\tests\authorTest.cpp .\src\Author.cpp -o C:\Users\danie\Desktop\PROI\projekt\src\main.exe
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../src/Book.h"
#include "catch.h"

SCENARIO("Book class test")
{

    GIVEN("Example date")
    {
        Author author("Adam", "Mickiewicz");
        Book book(author, "Pan Tadeusz", 40.0, 2013, )

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