import Test.HUnit
import FoxAndSorting

testGet :: Test
testGet = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testGet" testGet ]

main = runTestTT tests
