import Test.HUnit
import HyperKnight

testCountCells :: Test
testCountCells = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testCountCells" testCountCells ]

main = runTestTT tests
