#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLifeTest
{		
	TEST_CLASS(SanityTester)
	{
	public:
		
		TEST_METHOD(SanityTest)
		{
            Assert::AreEqual(1 + 1, 2);
		}

	};
}