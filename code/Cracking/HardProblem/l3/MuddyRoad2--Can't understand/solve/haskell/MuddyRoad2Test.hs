import Test.HUnit
import MuddyRoad2

testTheCount :: Test
testTheCount = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testTheCount" testTheCount ]

main = runTestTT tests
