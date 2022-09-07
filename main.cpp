#include "head.h"
int main(int argc, 	char* argv[])
{
	srand((unsigned)time(NULL));
	checkParameter(argc, atoi(argv[1]), atoi(argv[2]));
	create_information(atoi(argv[1]));	
	make_events(atoi(argv[1]), atoi(argv[2]));
	return 0;
}
