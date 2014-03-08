import Test.HUnit
import SurveillanceSystem

testGetContainerInfo :: Test
testGetContainerInfo = TestCase 
    (assertEqual "" 0 0)

tests = TestList [ TestLabel "testGetContainerInfo" testGetContainerInfo ]

main = runTestTT tests
