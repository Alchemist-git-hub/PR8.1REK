#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1REK/pr8.1rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRecursive
{
    TEST_CLASS(StringTests)
    {
    public:
        TEST_METHOD(TestSearchPair_No)
        {
            Assert::IsTrue(SearchPair("hello no world"));
        }

        TEST_METHOD(TestSearchPair_On)
        {
            Assert::IsTrue(SearchPair("hello on world"));
        }

        TEST_METHOD(TestSearchPair_NotFound)
        {
            Assert::IsFalse(SearchPair("hello world"));
        }


        TEST_METHOD(TestReplaceNo_OnePair)
        {
            char* result = ReplaceNo("hello no world");

            Assert::IsTrue(strcmp("hello *** world", result) == 0);

            delete[] result;
        }

        TEST_METHOD(TestReplaceNo_MultiplePairs)
        {
            char* result = ReplaceNo("nonono");

            Assert::IsTrue(strcmp("*********", result) == 0);

            delete[] result;
        }
    };
}
