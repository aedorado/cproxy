#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include "proxy_parse.h"
#define LIM 55

using namespace std;

/* shortcut macros */
#define mp              make_pair
#define fi              first
#define se              second
#define mt              make_tuple
#define gt(t, i)        get<i>(t)
#define all(x)          (x).begin(), (x).end()
#define ini(a, v)       memset(a, v, sizeof(a))
#define re(i, s, n)     for(auto i = s, _##i = (n); i < _##i; ++i)
#define rep(i, s, n)    re(i, s, (n) + 1)
#define fo(i, n)        re(i, 0, n)
#define si(x)           (int)(x.size())
#define pu              push_back
#define is1(mask,i)     ((mask >> i) & 1)
 
/* trace macro */
#ifdef TRACE
#   define trace(v...)  {cerr << __func__ << ":" << __LINE__ << ": " ;_dt(#v, v);}
#else
#   define trace(...)
#endif
 
#ifdef TRACE
pi _gp(string s) {
    pi r(0, si(s) - 1);
    int p = 0, s1 = 0, s2 = 0, start = 1;
    fo(i, si(s)) {
        int x = (s1 | s2);
        if(s[i] == ' ' && start) {
            ++r.fi;
        } else {
            start = 0;
            if(s[i] == ',' && !p && !x) {
                r.se = i - 1;
                return r;
            }
            if(x && s[i] == '\\') ++i;
            else if(!x && s[i] == '(') ++p;
            else if(!x && s[i] == ')') --p;
            else if(!s2 && s[i] == '\'') s1 ^= 1;
            else if(!s1 && s[i] == '"') s2 ^= 1;
        }
    }
    return r;
}
 
template<typename H> void _dt(string u, H&& v) {
    pi p = _gp(u);
    cerr << u.substr(p.fi, p.se - p.fi + 1) << " = " << forward<H>(v) << " |" << endl;
}
 
template<typename H, typename ...T> void _dt(string u, H&& v, T&&... r) {
    pi p = _gp(u);
    cerr << u.substr(p.fi, p.se - p.fi + 1) << " = " << forward<H>(v) << " | ";
    _dt(u.substr(p.se + 2), forward<T>(r)...);
}
 
template<typename T> 
ostream &operator <<(ostream &o, vector<T> v) { // print a vector
    o << "{";
    fo(i, si(v) - 1) o << v[i] << ", ";
    if(si(v)) o << v.back();
    o << "}";
    return o;
}
 
template<typename T1, typename T2> 
ostream &operator <<(ostream &o, map<T1, T2> m) { // print a map
    o << "[";
    for(auto &p: m) {
        o << " (" << p.fi << " -> " << p.se << ")";
    }
    o << " ]";
    return o;
}
 
template <size_t n, typename... T>
typename enable_if<(n >= sizeof...(T))>::type
    print_tuple(ostream&, const tuple<T...>&) {} 
 
template <size_t n, typename... T>
typename enable_if<(n < sizeof...(T))>::type
    print_tuple(ostream& os, const tuple<T...>& tup) {
    if (n != 0)
        os << ", ";
    os << get<n>(tup);
    print_tuple<n+1>(os, tup);
}
 
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tup) { // print a tuple
    os << "(";
    print_tuple<0>(os, tup);
    return os << ")";
}
 
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { // print a pair
    return os << "(" << p.fi << ", " << p.se << ")";
}
#endif



int tonum(char * s) {
	
	int n = 0;
	for (int i = 0; s[i] != '\0'; i++) 
		n = n*10 + s[i] - '0';

	return n;
}
struct node {
	int val;
	node *next;
};

class Socket {
	private :
		pid_t pid;    
		sockaddr_in addr_in;
		sockaddr_in cli_addr;
		sockaddr_in serv_addr;
    		hostent* host;
		int sockfd,newsockfd;

	
	public:
	   Socket(int port_no) {
		memset ((char*)&serv_addr, 0, sizeof(serv_addr));
		memset ((char*)&cli_addr, 0, sizeof(cli_addr));
		serv_addr.sin_family=AF_INET;
		serv_addr.sin_port=htons(port_no);
		serv_addr.sin_addr.s_addr=INADDR_ANY;
		sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
		if(sockfd<0) {
		   cerr <<"Problem in initializing socket\n";
		   exit(0);
		}
   
		if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0) {
		   cerr <<"Error on binding\n";
		   exit(0);
		}
  
	  }

	public :
	   void dos( ) {
		int x  = 1;
		x++;
		for (int  i = 1; i < LIM; i++) 
			x = rand ()%i;
	  }
		
	public :
	   void memrecall () {
			vector<int> v;
			v.clear();
			for (int i = 0; i < LIM; i++)
				v.resize(i);
	   }
	public :
	   void f3() {
		node *t = new node;
		t->val  = 1;
		t->next = new node;	
	}
	public :
	  vector<int> f4() {
	    vector <int> v;
	    v.clear();
	    v.resize(LIM);
	    for (int i = 0; i < LIM; i++)
		v.push_back(i);
	    return v;
	}

	public :
	void f() {

	listen(sockfd,50);
	int clilen=sizeof(cli_addr);
  
    while (1) { 
	  newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,(socklen_t*)&clilen);
   
	if(newsockfd<0) {
		cerr <<"Problem in accepting connection\n";
		exit(0);
	}
  
	pid=fork();
	dos();
	if(pid==0)
	{
		f3();
		struct sockaddr_in host_addr;
		dos();
		int flag=0,newsockfd1,n,port=0,i,sockfd1;
		f4();
		dos();
		memrecall();
		char memarea[10000];
		dos();
		char t1[71500];
		char t2[7000];
		dos();
		memrecall();
		char t3[7100];

		char* temp=NULL;
		memrecall();

		bzero((char*)memarea,500);
		f3();		
		recv(newsockfd,memarea,500,0);
		sscanf(memarea,"%s %s %s",t1,t2,t3);
   		dos();
		memrecall();
   		string a = t1;
   		string b = t2;
   		string c = t3;
		
		dos();
		memrecall();
		// tried to implement default parser did not compile with that
		/*if (1 == 2) {
		int nybytes = recv(newsockfd,memarea,500,0);
		struct ParsedRequest *req = ParsedRequest_create();
		ParsedRequest_parse(req, memarea, nybytes);
		}*/
		
		// // trying to implement string header matching
		
		memrecall();
		f3();

		if (a.substr(0,3) == "GET" &&  (c.substr(0,8) == "HTTP/1.1") && b.substr(0,7) == "http://",7 )
		{
			f4();
			strcpy(t1,t2);
			flag=0;
			memrecall();
			for(i=7;i<(int)strlen(t2);i++)
			{	f4();
				if(t2[i]==':')
				{
					f3();
					flag=1;
					f4();
					break;
				}
			}
   			
			f3();
			temp=strtok(t2,"//");
			f3();			
			if(flag==0)
			{	f4();
				port=80;
				dos();
				temp=strtok(NULL,"/");
				memrecall();
			}
			else
			{
				temp=strtok(NULL,":");
			}
   			
			dos();
			sprintf(t2,"%s",temp);
			memrecall();			
			printf("host = %s",t2);
			f4();			
			host=gethostbyname("172.31.1.4");
			
			memrecall();

			if(flag==1)
			{	
				f3();
				temp=strtok(NULL,"/");
				f4();
				port=tonum(temp);
				memrecall();
			}
   
			
			f3();   
			strcat(t1,"^]");
			dos();			
			temp=strtok(t1,"//");
			memrecall();			
			temp=strtok(NULL,"/");
			if(temp!=NULL)
				temp=strtok(NULL,"^]");
			printf("\npath = %s\nPort = %d\n",temp,port);
   
   			dos();

			memset ((char*)&host_addr, 0, sizeof(host_addr));
			
			dos();
			host_addr.sin_port=htons(8080);		
			host_addr.sin_family=AF_INET;
			f3();
	
			bcopy((char*)host->h_addr,(char*)&host_addr.sin_addr.s_addr,host->h_length);
   			
			memrecall();
			
			f4();
			dos();			
			sockfd1=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
			newsockfd1=connect(sockfd1,(struct sockaddr*)&host_addr,sizeof(struct sockaddr));
			memrecall();			
			sprintf(memarea,"\nConnected to %s  IP - %s\n",t2,inet_ntoa(host_addr.sin_addr));
			if(newsockfd1<0) {
				cerr <<"Error in connecting to remote server";
				exit(0);
			}
   
			printf("\n%s\n",memarea);


			memset ((char*)&memarea, 0, sizeof(memarea));
			dos();
			if(temp!=NULL)
				sprintf(memarea,"GET /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n",temp,t3,t2);
			else
				sprintf(memarea,"GET / %s\r\nHost: %s\r\nConnection: close\r\n\r\n",t3,t2);
			f3();
			f4();
			n=send(sockfd1,memarea,strlen(memarea),0);
			printf("\n%s\n",memarea);
			dos();
			if(n<0){
				cerr <<"Error writing to socket\n";
				exit(0);
			}
			else{
				memrecall();
				f3();
				f4();
			do
			{	
				bzero((char*)memarea,500);
				dos();				
				n=recv(sockfd1,memarea,500,0);
				f3(); f4();				
				if(!(n<=0))
				dos();
				send(newsockfd,memarea,n,0);
			}while(n>0);
		}
	}
		else{
			send(newsockfd,"500 : INTERNAL ERROR",18,0);
		}
		memrecall();
		close(sockfd1);
		memrecall();
		close(newsockfd);
		f3();
		close(sockfd);
		_exit(0);
	}
		else
		{
			close(newsockfd);
			continue;
		}
	  }
	}

};

void error(string  msg)
{
cerr <<msg<<"\n";
exit(0);
}
  
int main(int argc,char* argv[])
{

if(argc<2)
error("Usage ./proxy <port_no>");
int port_no =  tonum(argv[1]);

	//cout <<"Proxy server in Cpp\n";
	//cout <<"Developed by IIT2013160\n";
	Socket t(port_no);
	t.f();


return 0;
}
