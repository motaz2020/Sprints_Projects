/*********************************************************************
 *1.In the ""prvIdleTask"" function:
 *		Modify the idle task to keep it always the farest deadline"
 *
 *********************************************************************/
static portTASK_FUNCTION( prvIdleTask, pvParameters )
{
	...
    
	for( ; ; )
    {
		#if( configUSE_EDF_SCHEDULER == 1)
		{
			/*E.C. Missing Changes: Modify the idle task to keep it always the farest deadline*/
			listSET_LIST_ITEM_VALUE( &( ( pxCurrentTCB )->xStateListItem ), ( pxCurrentTCB )->xTaskPeriod + xTaskGetTickCount() );
			listINSERT_END( &(xReadyTasksListEDF), &( ( pxCurrentTCB )->xStateListItem ) );
		}
		#endif
		...
        
    }
}


/*----------------------------------------------------------*/
/*********************************************************************
 * 2. In the ""xTaskIncrementTick"" function:
 * 		In every tick increment, calculate the new task deadline and 
 * 		insert it in the correct position in the EDF ready list
 *
 * 3. In the ""xTaskIncrementTick"" function:
 *   	Make sure that as soon as a new task is available in the EDF 
 * 		ready list, a context switching should take place. 
 * 		Modify preemption way as any task with sooner deadline must 
 * 		preempt task with larger deadline instead of priority
*********************************************************************/
BaseType_t xTaskIncrementTick( void )
{
    ...

    if( uxSchedulerSuspended == ( UBaseType_t ) pdFALSE )
    {
        ... 
		
        if( xConstTickCount >= xNextTaskUnblockTime )
        {
            for( ; ; )
            {
                if( listLIST_IS_EMPTY( pxDelayedTaskList ) != pdFALSE )
                {
                    ...
                }
                else
                {
                    ...

					/*E.C. Missing Changes : Calculate New Deadline*/
					#if (configUSE_EDF_SCHEDULER == 1)
						listSET_LIST_ITEM_VALUE( &( ( pxTCB )->xStateListItem ), ( pxTCB)->xTaskPeriod + xTaskGetTickCount() );
					#endif
					
                    /* Place the unblocked task into the appropriate ready
                     * list. */
                    prvAddTaskToReadyList( pxTCB );
					
					/*E.C. Missing Changes: Context Switching will always take place 
					*to always restore task with earlist deadline at head of EDF RL */
					#if (configUSE_EDF_SCHEDULER == 1)
						xSwitchRequired = pdTRUE;
					#endif
					
					...
					
                }
            }
        }
			...
    }
    else
    {
        ...
    }

    return xSwitchRequired;
}
/*-----------------------------------------------------------*/