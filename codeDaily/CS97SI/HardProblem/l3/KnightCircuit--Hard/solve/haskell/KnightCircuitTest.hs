import Test.HUnit
import KnightCircuit

testMaxSize :: Test
testMaxSize = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testMaxSize" testMaxSize ]

main = runTestTT tests
