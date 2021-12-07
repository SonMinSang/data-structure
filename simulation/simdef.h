#ifndef _SIM_DEF_
#define _SIM_DEF_

typedef enum SimStatusType
{
	arrival,
	start,
	end
} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime; // ���� �ð�.
	int serviceTime; // ���� �ð�.
	int startTime;	 // ���� �ð�.
	int endTime;	 // ���� �ð�: ���� �ð� + ���� �ð�.
} SimCustomer;

typedef struct QueueNodeType
{
	SimCustomer data;
	struct QueueNodeType *pLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;
	QueueNode *pFrontNode;
	QueueNode *pRearNode;
} LinkedQueue;

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif