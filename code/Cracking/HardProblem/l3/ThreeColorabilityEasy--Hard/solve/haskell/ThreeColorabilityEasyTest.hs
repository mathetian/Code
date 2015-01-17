import Test.HUnit
import ThreeColorabilityEasy

testIsColorable :: Test
testIsColorable = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testIsColorable" testIsColorable ]

main = runTestTT tests
