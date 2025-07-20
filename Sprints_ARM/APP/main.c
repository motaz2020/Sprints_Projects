#include "App_LedCtrl_Interface.h"


int main (void)
{
	App_LedCtrl_Interface_SetUp();
	
	while(1)
	{
		App_LedCtrl_Interface_SetOnAndOffTime();
		
		App_LedCtrl_Interface_LedControl();
	}
	
	return 0;
	
}