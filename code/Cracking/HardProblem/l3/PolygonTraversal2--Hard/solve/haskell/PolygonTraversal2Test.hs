import Test.HUnit
import PolygonTraversal2

testCount :: Test
testCount = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testCount" testCount ]

main = runTestTT tests
