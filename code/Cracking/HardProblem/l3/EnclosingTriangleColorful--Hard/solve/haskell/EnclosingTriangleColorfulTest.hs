import Test.HUnit
import EnclosingTriangleColorful

testGetNumber :: Test
testGetNumber = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testGetNumber" testGetNumber ]

main = runTestTT tests
