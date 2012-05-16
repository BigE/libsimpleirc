#include <stdlib.h>
#include "simpleirc.h"

int simpleirc_client_connect(simpleirc_client *client)
{
	if (client->network == NULL) {
		client->errno = SIMPLEIRC_ENONETWORK;
		return(-1);
	}

	return(0);
}

char *simpleirc_client_error(simpleirc_client *client)
{
	static struct errorlist {
		int errno;
		char *error;
	} errorlist[] = {
		{0, "No Error"},
		{SIMPLEIRC_ENONETWORK, "No network is specified for the client"}
	};
	struct errorlist *e;

	for (e = errorlist; e < errorlist + sizeof(errorlist) / sizeof(errorlist[0]); e++) {
		if (e->errno == client->errno) return(e->error);
	}

	return("Unknown Error");
}

void simpleirc_client_free(simpleirc_client *client)
{
	if (client != NULL) {
		free(client);
	}
}

simpleirc_client *simpleirc_client_init()
{
	simpleirc_client *client = malloc(sizeof(simpleirc_client));
	client->errno = 0;
	return(client);
}