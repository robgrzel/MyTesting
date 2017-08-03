#include "ToDoCore.h"

#include <string>

using std::string;

#include <gmock/gmock.h>

using ::testing::Eq;

#include <gtest/gtest.h>

using ::testing::Test;


namespace ToDoCore {
	namespace testing {
		class ToDoUnitTest : public Test {
			protected:
				ToDoUnitTest() {
				}
				
				~ToDoUnitTest() {
				}
				
				virtual void SetUp() {
				}
				
				virtual void TearDown() {
				}
				
				
				ToDo list;
				
				static const size_t taskCount = 3;
				static const string tasks[taskCount];
		};
		
		const string ToDoUnitTest::tasks[taskCount] = {"write code",
		                                               "compile",
		                                               "test"};
		
		
		TEST_F(ToDoUnitTest, constructor_createsEmptyList) {
			EXPECT_THAT(list.size(), Eq(size_t(0)));
		}
		
		TEST_F(ToDoUnitTest, addTask_threeTimes_sizeIsThree) {
			list.addTask(tasks[0]);
			list.addTask(tasks[1]);
			list.addTask(tasks[2]);
			
			EXPECT_THAT(list.size(), Eq(taskCount));
		}
		
		TEST_F(ToDoUnitTest, getTask_withOneTask_returnsCorrectString) {
			list.addTask(tasks[0]);
			
			ASSERT_THAT(list.size(), Eq(size_t(1)));
			EXPECT_THAT(list.getTask(0), Eq(tasks[0]));
		}
		
		TEST_F(ToDoUnitTest, getTask_withThreeTasts_returnsCorrectStringForEachIndex) {
			list.addTask(tasks[0]);
			list.addTask(tasks[1]);
			list.addTask(tasks[2]);
			
			ASSERT_THAT(list.size(), Eq(taskCount));
			EXPECT_THAT(list.getTask(0), Eq(tasks[0]));
			EXPECT_THAT(list.getTask(1), Eq(tasks[1]));
			EXPECT_THAT(list.getTask(2), Eq(tasks[2]));
		}
		
	} // namespace ToDo
} // namespace ToDoCore
