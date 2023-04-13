#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct task
{
	uint8_t step;
	uint8_t totalSteps;
	char *name;
	struct task *next;
};

void addTask( struct task **taskList, char *name, int totalSteps );
void runNextTask( struct task **taskList );

int main( void )
{
	struct task *currentTask = NULL;
	char nameInput[16];
	uint8_t stepsInput;
	int computationCycles = 0;
	do
	{
		printf( "Name : " );
		(void)scanf( "%s", nameInput );
		printf( "Steps : " );
		(void)scanf( "%hhu", &stepsInput );
		addTask( &currentTask, nameInput, stepsInput );
		printf( "Run cycles (-1 to stop) : " );
		(void)scanf( "%d", &computationCycles );
		for( int i = 0; i < computationCycles; i++ )
		{
			runNextTask( &currentTask );
		}
	} while( computationCycles >= 0 );

	return 0;
}

void addTask( struct task **taskList, char *name, int totalSteps )
{
	struct task *newTask = (struct task *)calloc( 1, sizeof( struct task ) );
	newTask->name = (char *)calloc( strlen( name ) + 1, sizeof( char ) );
	strcpy( newTask->name, name );
	newTask->totalSteps = totalSteps;

	if( *taskList == NULL )
	{
		newTask->next = newTask;
		*taskList = newTask;
	}
	else
	{
		newTask->next = ( *taskList )->next;
    (*taskList)->next = newTask;
	}
}

void runNextTask( struct task **taskList )
{
	if( *taskList == NULL )
    {
        printf( "No tasks to run.\n" );
        return;
    }
    struct task *currentTask = (*taskList)->next;
    currentTask->step++;
    printf( "Running %8s (%3hhu/%3hhu)...\n", currentTask->name, currentTask->step, currentTask->totalSteps );
    if( currentTask->step == currentTask->totalSteps )
    {
        if( currentTask == currentTask->next )
        {
            *taskList = NULL;
        }
        else
        {
            (*taskList)->next = currentTask->next;
        }
        free( currentTask->name );
        free( currentTask );
    }
    else
    {
        *taskList = currentTask;
    }
}
