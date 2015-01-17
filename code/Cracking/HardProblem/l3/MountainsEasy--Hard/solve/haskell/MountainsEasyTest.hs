import Test.HUnit
import MountainsEasy

testCountPlacements :: Test
testCountPlacements = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testCountPlacements" testCountPlacements ]

main = runTestTT tests
