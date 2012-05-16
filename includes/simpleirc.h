/*
 * File:   libsimpleirc.h
 * Author: eric
 *
 * Created on May 2, 2012, 1:23 PM
 */

#ifndef SIMPLEIRC_H
#define	SIMPLEIRC_H

#ifdef	__cplusplus
extern "C" {
#endif

	enum simpleirc_errno {
		SIMPLEIRC_ENONETWORK
	};

	typedef struct s_simpleirc_network {
		char *server;
		int port;
		char *nick;
	} simpleirc_network;

	typedef struct s_simpleirc_client {
		int sock;
		simpleirc_network *network;
		enum simpleirc_errno errno; // Used whenever an error occurs
	} simpleirc_client;

	// Function defs
	int simpleirc_client_connect(simpleirc_client *);
	void simpleirc_client_free(simpleirc_client *);
	simpleirc_client *simpleirc_client_init();


#ifdef	__cplusplus
}
#endif

#endif	/* SIMPLEIRC_H */

