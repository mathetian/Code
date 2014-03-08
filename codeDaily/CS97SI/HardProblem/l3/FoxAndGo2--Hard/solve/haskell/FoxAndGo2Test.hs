import Test.HUnit
import FoxAndGo2

testMaxKill :: Test
testMaxKill = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testMaxKill" testMaxKill ]

main = runTestTT tests
