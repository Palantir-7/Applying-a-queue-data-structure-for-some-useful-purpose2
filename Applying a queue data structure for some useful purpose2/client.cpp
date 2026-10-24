//Elizabeth Fanton COSC-III 10/22/26
//Applying a queue data structure for some useful purpose

#include<iostream>
#include<queue>
#include<string>

using namespace std;



struct Job
{
	string jobIdentifier;
	int remainingTime;
};

//prototypes
void createJob(queue<Job>* runnableQueue, queue<Job>* sleepingQueue);
void displayRunnableQueue(queue<Job>* printedQueue);
void executeJob(queue<Job>& runnableQueue);
void displaySleepingQueue(queue<Job>* printedQueue2);
void moveJob(queue<Job>& runnableQueue, queue<Job>& sleepingQueue);

int main()
{
	queue<Job> runnableQueue;
	queue<Job> sleepingQueue;
	int menuChoice = 0;

	//menu output
	while (true)
	{
		cout << "Please select an option from the menu below: " << endl;
		cout << "1 - create and add a job to the runnable queue" << endl;
		cout << "2 - display the runnable queue" << endl;
		cout << "3 - exacute a job from the front of the queue" << endl;
		cout << "4 - display the sleepingQueue" << endl;
		cout << "5 - move a job from sleepingQueue to runnableQueue" << endl;
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			//call createJob function
			createJob(&runnableQueue, &sleepingQueue);
			break;
		case 2:
			//call displayRunnableQueue
			displayRunnableQueue(&runnableQueue);
			break;
		case 3:
			//call executeJob
			executeJob(runnableQueue);
			break;
		case 4:
			//call displaySleepingQueue
			displaySleepingQueue(&sleepingQueue);
			break;
		case 5:
			//call moveJob
			moveJob(runnableQueue, sleepingQueue);
			break;
		}

	}
	return 0;
}

//functions
//Creating a job and adding to the runnable queue :
void createJob(queue<Job>* runnableQueue, queue<Job>* sleepingQueue)//<- accesses queue in main?
{
	Job dummyJob;
	int numberOfJobs = 5;
	string jobName;
	int rTime = 0;
	cout << "Please enter a job: " << endl;
	cin >> jobName;
	cout << "And the remaining time: " << endl;
	cin >> rTime;
	cout << endl;
	if (runnableQueue->size() < numberOfJobs)
	{
		dummyJob.jobIdentifier = jobName;
		dummyJob.remainingTime = rTime;
		runnableQueue->push(dummyJob);
	}
	else
	{
		dummyJob.jobIdentifier = jobName;
		dummyJob.remainingTime = rTime;
		sleepingQueue->push(dummyJob);
	}

};

void displayRunnableQueue(queue<Job>* printedQueue)
{
	queue<Job> savedQueue = *printedQueue;
	while (!savedQueue.empty())
	{
		cout << savedQueue.front().jobIdentifier << " " << savedQueue.front().remainingTime << endl;
		savedQueue.pop();
	}
}

void executeJob(queue<Job>& runnableQueue)
{
	Job tempJob;
	//runnableQueue.dequeue();
	if (!runnableQueue.empty())
	{
		tempJob = runnableQueue.front();
		runnableQueue.pop();
	}
	else
		cout << endl << "ERROR! the queue is empty!" << endl;

}

void displaySleepingQueue(queue<Job>* printedQueue2)
{
	cout << "Displaying sleepingQueue: " << endl;
	queue<Job> savedQueue = *printedQueue2;
	while (!savedQueue.empty())
	{
		cout << savedQueue.front().jobIdentifier << " " << savedQueue.front().remainingTime << endl;
		savedQueue.pop();
	}
}

void moveJob(queue<Job>& runnableQueue, queue<Job>& sleepingQueue)
{
	int numberOfJobs = 5;
	if (runnableQueue.size() >= numberOfJobs)
	{
		cout << endl << "Error! there is not enough room in \"runnableQueue\" queue." << endl;
	}
	else
	{
		Job dummyJob = sleepingQueue.front();
		if (!sleepingQueue.empty())
		{
			dummyJob = sleepingQueue.front();
			sleepingQueue.pop();
		}
		runnableQueue.push(dummyJob);
	}
}