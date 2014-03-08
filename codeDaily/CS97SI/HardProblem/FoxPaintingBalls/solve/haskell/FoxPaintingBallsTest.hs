import Test.HUnit
import FoxPaintingBalls

testTheMax :: Test
testTheMax = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testTheMax" testTheMax ]

main = runTestTT tests
