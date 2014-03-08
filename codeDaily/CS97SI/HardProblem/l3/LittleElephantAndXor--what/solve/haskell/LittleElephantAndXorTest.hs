import Test.HUnit
import LittleElephantAndXor

testGetNumber :: Test
testGetNumber = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testGetNumber" testGetNumber ]

main = runTestTT tests
