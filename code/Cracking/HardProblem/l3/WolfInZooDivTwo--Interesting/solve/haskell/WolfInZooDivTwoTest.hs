import Test.HUnit
import WolfInZooDivTwo

testCount :: Test
testCount = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testCount" testCount ]

main = runTestTT tests
