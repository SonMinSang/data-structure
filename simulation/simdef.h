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
	int arrivalTime; // 도착 시각.
	int serviceTime; // 서비스 시간.
	int startTime;	 // 시작 시각.
	int endTime;	 // 종료 시각: 시작 시각 + 서비스 시간.
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