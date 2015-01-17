import Test.HUnit
import FlippingBitsDiv2

testGetmin :: Test
testGetmin = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testGetmin" testGetmin ]

main = runTestTT tests
