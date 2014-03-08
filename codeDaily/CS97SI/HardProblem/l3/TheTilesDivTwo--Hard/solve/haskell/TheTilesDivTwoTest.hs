import Test.HUnit
import TheTilesDivTwo

testFind :: Test
testFind = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testFind" testFind ]

main = runTestTT tests
