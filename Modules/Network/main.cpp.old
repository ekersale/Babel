#include "UNetwork.h"
#include <iostream>

int main(int ac, char **av)
{
  UNetwork *srv;
  UNetwork *clt;
  int id1;
  int id2;

  if (av[1][0] == 'S')
    {
      srv = new UNetwork(AF_INET, SOCK_DGRAM, "UDP");
      // srv->createSocket("UDP", SOCK_DGRAM);
      srv->bindSocket(av[2]); //port
    }
  else
    {
      clt = new UNetwork(AF_INET, SOCK_DGRAM, "UDP");
      //clt->createSocket("UDP", SOCK_DGRAM);
      id2 = clt->connectToSocket(av[2], av[3]); //host port
    }

  while (42)
    if (av[1][0] == 'S') //passif = server
      {
  	id1 = srv->recvFromSocket(); //premier recu, socket settée sur id1
  	srv->sendToSocket(id1, av[3], strlen(av[3])); // revoir à id1
	puts(srv->get_string());
      }
    else //demande = client
      {
    	clt->sendToSocket(id2, av[4], strlen(av[4])); //envoie à id2 séttée sur une socket par connect
    	clt->recvFromSocket();// recoit de n'importe qui qui connait
    	puts(clt->get_string());
      }
  return (0);
}

/*
int main(int ac, char **av)
{
  UNetwork *srv;
  UNetwork *clt;
  int id1;
  int id2;

  if (av[1][0] == 'S')
    {
      srv = new UNetwork(AF_INET, SOCK_STREAM, "TCP");
      puts("a");
      srv->bindSocket(av[2]);
      puts("b");
      srv->listenSocket(10);
      id1 = srv->acceptSocket(); //accept crée une socket client
      printf("%d :id2\n", id1);
    }
  else
    {
      clt = new UNetwork(AF_INET, SOCK_STREAM, "TCP");
      clt->bindSocket(av[2]);
      id2 = clt->connectSocket(av[2], av[3]); // se connec
      printf("%d :id2\n", id2);
    }

  while (42)
    if (av[1][0] == 'S') //passif = server
      {
 	srv->recvSocket(id1); //on lit l'id1 de l'accept
  	srv->sendSocket(id1, av[3]);
  	puts(srv->get_string());
      }
    else //demande = client
      {
    	clt->sendSocket(id2, av[4]); //idem
	clt->recvSocket(id2);
    	puts(clt->get_string());
      }
  return (0);
}

*/
