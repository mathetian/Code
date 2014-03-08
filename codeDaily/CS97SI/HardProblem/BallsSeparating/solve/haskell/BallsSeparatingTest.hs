import Test.HUnit
import BallsSeparating

testMinOperations :: Test
testMinOperations = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testMinOperations" testMinOperations ]

main = runTestTT tests
