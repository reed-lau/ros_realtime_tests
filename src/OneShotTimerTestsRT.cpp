#include "RosOneShotTimerTestsFixture.h"
#include "PrioritySwitcher.h"

class RosOneShotTimerTestsRT : public RosOneShotTimerTestsFixture {
protected:

	static void SetUpTestCase()
	{
		setupSucceeded = false;
		ASSERT_EQ(switchToRealtimePriority(), 0);
		RosOneShotTimerTestsFixture::SetUpTestCase();
		setupSucceeded = true;
	}
};

TEST_F(RosOneShotTimerTestsRT, MaxLatencySmallerThan400MicroSecond)
{
	for(int i = 0; i < amountTimeouts; i++)
	{
		ASSERT_LE(maxLatencyMs[i], 400);
	}
}

TEST_F(RosOneShotTimerTestsRT, AverageLatencySmallerThan400MicroSecond)
{
	for(int i = 0; i < amountTimeouts; i++)
	{
		ASSERT_LE(avgLatencyMs[i], 400);
	}
}

TEST_F(RosOneShotTimerTestsRT, NoNegativeLatencies)
{
	for(int i = 0; i < amountTimeouts; i++)
	{
		ASSERT_GE(minLatencyMs[i], 0);
	}
}
