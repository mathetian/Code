import Test.HUnit
import DengklekPaintingSquares

testNumSolutions :: Test
testNumSolutions = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testNumSolutions" testNumSolutions ]

main = runTestTT tests
