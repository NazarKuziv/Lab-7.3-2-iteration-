#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 7.3-2(ітерація).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest7321
{
	TEST_CLASS(UnitTest7321)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[3][3] = { { -1, 2, 3 },
							{ 4, 5, 6 },
							{ 7, 8, 9 } };

			int* pa[3] = { a[0], a[1], a[2] };
			int Row, Col;

			int No = 0;
			for (int n = 0; n < 3; n++)
				for (int k = 0; k < 3; k++)
					if (IsMinInRowN(pa, n, k, 3) && IsMaxInColK(pa, n, k, 3))
					{
						Row = n;
						Col = k;
					}

			Assert::AreEqual(Row, 2);
			Assert::AreEqual(Col, 0);
		}
	};
}
