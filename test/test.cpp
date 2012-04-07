#include "fuck_game_server_engine.h"

int main()
{
	fengine fe;

	typedef tcpsocket<cirle_buffer<int8_t, 1024>, selector> mysocket;
	typedef netmsg<std::vector<int8_t>> mymsg;
	typedef std::list<mymsg> mymsgcontainer;
	typedef std::list<std::pair<mysocket, mymsg>> myelecontainer;
	typedef std::list<mysocket> mysocketlist;

	typedef socket_link<mysocket> mysocketlink;
	typedef thread_link<mymsg, mymsgcontainer, mysocketlink> mythreadlink;
	typedef netlink<mythreadlink> mynetlink;

	typedef socket_container<mysocket, selector, mysocketlist> mysocketcontainer;
	typedef thread_container<mymsg, mysocket, myelecontainer, mysocketcontainer> mythreadcontainer;
	typedef netserver<mythreadcontainer> mynetserver;

	mynetlink nl;
	mynetserver ns;

	// server
	tcp_socket_server_param ssp;
	ssp.ip = "127.0.0.1";
	ssp.port = 2012;
	ns.ini(ssp);

	// client
	tcp_socket_link_param slp;
	slp.ip = "127.0.0.1";
	slp.port = 2012;
	nl.ini(slp);

	int32_t i = 0;
	while (1)
	{
		mymsg m;
		m.write_int32(i);
		nl.send_msg(m);
		i++;
		fsleep(100);
	}

	return 0;
}