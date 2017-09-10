#include "stdafx.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLifeTest
{
    TEST_CLASS(GameTester)
    {
    public:

        TEST_METHOD(ReadTest)
        {
            Game game(3, 3, 3, 0, 2, 3, 3, 3);
            int error = game.setState("\txxx");
            Assert::AreEqual(error, 0);
        }


        TEST_METHOD(OscilatingTest)
        {
            Game game(3, 3, 1, 0, 2, 3, 3, 3);
            int error = game.setState("oxo\toxo\toxo");
            Assert::AreEqual(error, 0);
            game.playOne();
            Assert::AreEqual(game.compareCurrentState("\0\0\0\1\1\1\0\0\0"), 1);
        }

        TEST_METHOD(MultiDimensionTest)
        {
            Game game(3, 3, 3, 0, 2, 3, 3, 3);
            int error = game.setState("oxo\txox\toxo\no\no");
            Assert::AreEqual(error, 0);
            game.playOne();
            Assert::AreEqual(game.compareCurrentState("\0\1\0"
                "\1\0\1"
                "\0\1\0"
                "\0\1\0"
                "\1\0\1"
                "\0\1\0"
                "\0\0\0"
                "\0\0\0"
                "\0\0\0"), 1);
        }

        TEST_METHOD(HeightAlignmentTest)
        {
            Game game(3, 3, 1, 0, 2, 3, 3, 3);
            int error = game.setState("xxx");
            Assert::AreEqual(error, 0);
            Assert::AreEqual(game.compareCurrentState(
                "\0\0\0"
                "\1\1\1"
                "\0\0\0"), 1);
        }

        TEST_METHOD(WidthAlignmentTest)
        {
            Game game(3, 3, 1, 0, 2, 3, 3, 3);
            int error = game.setState("x\tx\tx");
            Assert::AreEqual(error, 0);
            Assert::AreEqual(1, game.compareCurrentState(
                "\0\1\0"
                "\0\1\0"
                "\0\1\0"));
        }

        TEST_METHOD(LayerAlignmentTest)
        {
            Game game(3, 2, 3, 0, 2, 3, 3, 3);
            int error = game.setState("x\tx");
            Assert::AreEqual(error, 0);
            Assert::AreEqual(1, game.compareCurrentState(
                "\0\0\0"
                "\0\0\0"
                "\0\1\0"
                "\0\1\0"
                "\0\0\0"
                "\0\0\0"));
        }

        TEST_METHOD(DoubleDimensionLayerAlignmentTest)
        {
            Game game(3, 1, 9, 0, 2, 3, 3, 3);
            int error = game.setState("oxx\nxx\nox");
            Assert::AreEqual(error, 0);
            Assert::AreEqual(1, game.compareCurrentState(
                "\0\0\0"
                "\0\0\0"
                "\0\0\0"
                "\0\1\1"
                "\1\1\0"
                "\0\1\0"
                "\0\0\0"
                "\0\0\0"
                "\0\0\0"));
        }

        TEST_METHOD(DoubleDimensionPlayTest)
        {
            Game game(5, 1, 9, 0, 2, 3, 3, 3);
            int error = game.setState("oxx\nxx\nox");
            Assert::AreEqual(error, 0);
            Assert::AreEqual(1, game.compareCurrentState(
                "\0\0\0\0\0"
                "\0\0\0\0\0"
                "\0\0\0\0\0"
                "\0\0\1\1\0"
                "\0\1\1\0\0"
                "\0\0\1\0\0"
                "\0\0\0\0\0"
                "\0\0\0\0\0"
                "\0\0\0\0\0"));

            game.playOne();

            Assert::AreEqual(1, game.compareCurrentState(
                "\0\0\0\0\0"
                "\0\0\0\0\0"
                "\0\0\0\0\0"
                "\0\1\1\1\0"
                "\0\1\0\0\0"
                "\0\1\1\0\0"
                "\0\0\0\0\0"
                "\0\0\0\0\0"
                "\0\0\0\0\0"));
        }

    };
}